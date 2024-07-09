/*
 Copyright 2018 Google Inc.
 Copyright 2023-2024 LunarG, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#include "device.h"

#include <algorithm>
#include <cinttypes>
#include <fstream>
#include <iomanip>

#include "cdl.h"
#include "checkpoint.h"
#include "semaphore_tracker.h"
#include "util.h"

namespace crash_diagnostic_layer {

Device::Device(Context& context, VkPhysicalDevice vk_gpu, VkDevice device, DeviceExtensionsPresent& extensions_present,
               std::unique_ptr<DeviceCreateInfo> device_create_info)
    : context_(context),
      vk_physical_device_(vk_gpu),
      vk_device_(device),
      extensions_present_(extensions_present),
      device_create_info_(std::move(device_create_info)) {
    auto device_layer_data = GetDeviceLayerData(DataKey(device));
    device_dispatch_table_ = device_layer_data->dispatch_table;

    context_.Dispatch().GetPhysicalDeviceProperties(vk_gpu, &physical_device_properties_);

    uint32_t count = 0;
    context_.Dispatch().GetPhysicalDeviceQueueFamilyProperties(vk_physical_device_, &count, nullptr);
    if (count > 0) {
        queue_family_properties_.resize(count);
        context_.Dispatch().GetPhysicalDeviceQueueFamilyProperties(vk_physical_device_, &count,
                                                                   queue_family_properties_.data());
    }
    if (extensions_present_.nv_device_diagnostic_checkpoints) {
        checkpoints_ = std::make_unique<DiagnosticCheckpointMgr>(*this);
    } else if (extensions_present_.amd_buffer_marker) {
        checkpoints_ = std::make_unique<BufferMarkerCheckpointMgr>(*this);
    }
    // Create a semaphore tracker
    if (context_.GetSettings().track_semaphores) {
        semaphore_tracker_ = std::make_unique<SemaphoreTracker>(*this);
    }
}

void Device::Destroy() {
    for (auto& item : queues_) {
        item.second->Destroy();
    }
    queues_.clear();
}

Device::~Device() { Destroy(); }

Context& Device::GetContext() const { return context_; }

VkPhysicalDevice Device::GetVkGpu() const { return vk_physical_device_; }

VkDevice Device::GetVkDevice() const { return vk_device_; }

const Logger& Device::Log() const { return context_.Log(); }

bool Device::HasCheckpoints() const {
    return extensions_present_.nv_device_diagnostic_checkpoints || extensions_present_.amd_buffer_marker;
}

void Device::FreeCommandBuffers(VkCommandPool command_pool, uint32_t command_buffer_count,
                                const VkCommandBuffer* command_buffers) {
    Dispatch().FreeCommandBuffers(vk_device_, command_pool, command_buffer_count, command_buffers);
}

void Device::AddCommandBuffer(VkCommandBuffer vk_command_buffer) {
    std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
    assert(std::find(command_buffers_.begin(), command_buffers_.end(), vk_command_buffer) == command_buffers_.end());
    command_buffers_.push_back(vk_command_buffer);
}

void Device::DumpCommandBuffers(YAML::Emitter& os) const {
    auto dump_cbs = context_.GetSettings().dump_command_buffers;
    // Sort command buffers by submit info id
    std::map<uint64_t /* queue seq */, std::vector<CommandBuffer*>> sorted_command_buffers;
    std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
    for (auto cb : command_buffers_) {
        auto p_cmd = GetCommandBuffer(cb);
        if (p_cmd && p_cmd->IsPrimaryCommandBuffer()) {
            bool dump_this_cb = false;
            switch (dump_cbs) {
                case DumpCommands::kAll:
                    dump_this_cb = true;
                    break;
                case DumpCommands::kRunning:
                    dump_this_cb = p_cmd->GetCommandBufferState() == CommandBufferState::kSubmittedExecutionIncomplete;
                    break;
                case DumpCommands::kPending:
                    dump_this_cb = p_cmd->WasSubmittedToQueue() &&
                                   p_cmd->GetCommandBufferState() != CommandBufferState::kSubmittedExecutionNotStarted;
                    break;
            }
            if (dump_this_cb) {
                sorted_command_buffers[p_cmd->GetQueueSeq()].push_back(p_cmd);
            }
        }
    }
    os << YAML::Key << "CommandBuffers" << YAML::Value << YAML::BeginSeq;
    for (auto& it : sorted_command_buffers) {
        for (auto p_cmd : it.second) {
            p_cmd->DumpContents(os, context_.GetSettings());
        }
    }
    os << YAML::EndSeq;
    assert(os.good());
}

void Device::SetCommandPool(VkCommandPool vk_command_pool, CommandPoolPtr command_pool) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    assert(command_pools_.find(vk_command_pool) == command_pools_.end());
    command_pools_[vk_command_pool] = std::move(command_pool);
}

CommandPool* Device::GetCommandPool(VkCommandPool vk_command_pool) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    if (command_pools_.find(vk_command_pool) == command_pools_.end()) {
        return nullptr;
    }
    return command_pools_[vk_command_pool].get();
}

void Device::AllocateCommandBuffers(VkCommandPool vk_pool, const VkCommandBufferAllocateInfo* allocate_info,
                                    VkCommandBuffer* command_buffers) {
    {
        std::lock_guard<std::mutex> lock(command_pools_mutex_);
        assert(command_pools_.find(vk_pool) != command_pools_.end());
        command_pools_[vk_pool]->AllocateCommandBuffers(allocate_info, command_buffers);
    }
    // TODO locking here?
    // create command buffers tracking data
    for (uint32_t i = 0; i < allocate_info->commandBufferCount; ++i) {
        VkCommandBuffer vk_cmd = command_buffers[i];

        auto cmd = std::make_unique<CommandBuffer>(*this, vk_pool, vk_cmd, allocate_info, HasCheckpoints());
        cmd->SetInstrumentAllCommands(context_.GetSettings().instrument_all_commands);

        SetCommandBuffer(vk_cmd, std::move(cmd));
        AddCommandBuffer(vk_cmd);
    }
}

// Write out information about an invalid command buffer reset.
void Device::DumpCommandBufferStateOnScreen(CommandBuffer* p_cmd, YAML::Emitter& os) const {
    Log().Error("Invalid Command Buffer Usage: Reset of VkCommandBuffer in use by GPU: %s",
                GetObjectName((uint64_t)p_cmd->GetVkCommandBuffer()).c_str());
    auto submitted_fence = p_cmd->GetSubmittedFence();

    // If there is a fence associated with this command buffer, we check
    // that it's state is signaled.
    if (submitted_fence != VK_NULL_HANDLE) {
        auto fence_state = Dispatch().WaitForFences(vk_device_, 1, &submitted_fence, VK_TRUE, 0);
        if (VK_TIMEOUT == fence_state) {
            Log().Error("Reset before fence was set: %s", GetObjectName((uint64_t)submitted_fence).c_str());
        } else {
            Log().Error("Fence was set: %s", GetObjectName((uint64_t)submitted_fence).c_str());
        }
    }

    // Dump this specific command buffer to console with all commands.
    // We do this because this is a race between the GPU and the logging and
    // often the logger will show the command buffer as completed where as
    // if we write a single command buffer it's less likely the GPU has completed.
    YAML::Emitter error_report;
    error_report << YAML::BeginMap << YAML::Key << "InvalidCommandBuffer" << YAML::Value;
    p_cmd->DumpContents(error_report, context_.GetSettings());
    error_report << YAML::EndMap;
    Log().Error(error_report.c_str());
    os << error_report.c_str();
}

bool Device::ValidateCommandBufferNotInUse(CommandBuffer* p_cmd, YAML::Emitter& os) {
    assert(p_cmd);
    if (!HangDetected()) {
        if (p_cmd->HasCheckpoints() && p_cmd->WasSubmittedToQueue() && !p_cmd->CompletedExecution()) {
            DumpCommandBufferStateOnScreen(p_cmd, os);
            return false;
        }
    }
    return true;
}

bool Device::ValidateCommandBufferNotInUse(VkCommandBuffer vk_command_buffer, YAML::Emitter& os) {
    auto p_cmd = GetCommandBuffer(vk_command_buffer);
    assert(p_cmd != nullptr);
    if (p_cmd != nullptr) {
        return ValidateCommandBufferNotInUse(p_cmd, os);
    }
    // If for any reason we can't find the command buffer information,
    // don't break the application.
    return true;
}

void Device::ValidateCommandPoolState(VkCommandPool vk_command_pool, YAML::Emitter& os) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    assert(command_pools_.find(vk_command_pool) != command_pools_.end());
    // Only validate primary command buffers. If a secondary command buffer is
    // hung, CDL catches the primary command buffer that the hung cb was recorded
    // to.
    auto command_buffers = command_pools_[vk_command_pool]->GetCommandBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
    for (auto vk_cmd : command_buffers) {
        auto p_cmd = GetCommandBuffer(vk_cmd);
        if (p_cmd != nullptr) {
            ValidateCommandBufferNotInUse(p_cmd, os);
        }
    }
}

void Device::ResetCommandPool(VkCommandPool vk_command_pool) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    assert(command_pools_.find(vk_command_pool) != command_pools_.end());
    std::vector<VkCommandBufferLevel> cb_levels{VK_COMMAND_BUFFER_LEVEL_PRIMARY, VK_COMMAND_BUFFER_LEVEL_SECONDARY};
    for (auto cb_level : cb_levels) {
        auto command_buffers = command_pools_[vk_command_pool]->GetCommandBuffers(cb_level);
        for (auto vk_cmd : command_buffers) {
            auto p_cmd = GetCommandBuffer(vk_cmd);
            if (p_cmd != nullptr) {
                p_cmd->Reset();
            }
        }
    }
}

void Device::DeleteCommandPool(VkCommandPool vk_command_pool) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    std::lock_guard<std::recursive_mutex> lock_commands(command_buffers_mutex_);
    assert(command_pools_.find(vk_command_pool) != command_pools_.end());
    std::vector<VkCommandBufferLevel> cb_levels{VK_COMMAND_BUFFER_LEVEL_PRIMARY, VK_COMMAND_BUFFER_LEVEL_SECONDARY};
    for (auto cb_level : cb_levels) {
        auto command_buffers = command_pools_[vk_command_pool]->GetCommandBuffers(cb_level);
        for (auto vk_cmd : command_buffers) {
            auto p_cmd = GetCommandBuffer(vk_cmd);
            if (p_cmd != nullptr) {
                command_buffers_.erase(std::remove(command_buffers_.begin(), command_buffers_.end(), vk_cmd),
                                       command_buffers_.end());
                DeleteCommandBuffer(vk_cmd);
            }
        }
    }
    command_pools_.erase(vk_command_pool);
}

void Device::DeleteCommandBuffers(VkCommandPool vk_pool, const VkCommandBuffer* vk_cmds, uint32_t cb_count) {
    GetCommandPool(vk_pool)->FreeCommandBuffers(cb_count, vk_cmds);
    {
        std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
        for (uint32_t i = 0; i < cb_count; ++i) {
            command_buffers_.erase(std::remove(command_buffers_.begin(), command_buffers_.end(), vk_cmds[i]),
                                   command_buffers_.end());
            DeleteCommandBuffer(vk_cmds[i]);
        }
    }
}

void Device::CreatePipeline(uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos,
                            VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lock(pipelines_mutex_);
    for (uint32_t i = 0; i < createInfoCount; ++i) {
        PipelinePtr pipeline = std::make_unique<Pipeline>(pPipelines[i], pCreateInfos[i]);
        pipelines_[pPipelines[i]] = std::move(pipeline);
    }
}

void Device::CreatePipeline(uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos,
                            VkPipeline* pPipelines) {
    std::lock_guard<std::mutex> lock(pipelines_mutex_);
    for (uint32_t i = 0; i < createInfoCount; ++i) {
        PipelinePtr pipeline = std::make_unique<Pipeline>(pPipelines[i], pCreateInfos[i]);
        pipelines_[pPipelines[i]] = std::move(pipeline);
    }
}

const Pipeline* Device::FindPipeline(VkPipeline pipeline) const {
    std::lock_guard<std::mutex> lock(pipelines_mutex_);
    const Pipeline* p_pipeline = nullptr;
    auto it = pipelines_.find(pipeline);
    if (it != pipelines_.end()) {
        p_pipeline = it->second.get();
    }
    return p_pipeline;
}

// Write out the shader modules referenced by this pipeline.
void Device::DumpShaderFromPipeline(VkPipeline pipeline) const {
    std::lock_guard<std::mutex> lock_pipe(pipelines_mutex_);
    std::lock_guard<std::mutex> lock_shader(shader_modules_mutex_);

    auto pipe = pipelines_.find(pipeline);
    if (pipe != pipelines_.end()) {
        auto& bound_shaders = pipe->second->GetBoundShaders();
        for (auto& bound_shader : bound_shaders) {
            auto module = shader_modules_.find(bound_shader.module);
            if (module != shader_modules_.end()) {
                auto prefix = "PIPELINE_" + GetObjectName((uint64_t)pipeline, kPreferDebugName) + "_SHADER_";
                module->second->DumpShaderCode(prefix);
            } else {
                Log().Error("Unknown VkShaderModule handle: 0x%08X", bound_shader.module);
            }
        }
    } else {
        Log().Error("Unknown VkPipeline handle: 0x%08X", pipeline);
    }
}

void Device::DeletePipeline(VkPipeline pipeline) {
    std::lock_guard<std::mutex> lock(pipelines_mutex_);
    pipelines_.erase(pipeline);
}

void Device::CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModule* pShaderModule,
                                int shader_module_load_options) {
    // Parse the SPIR-V for relevant information, does not copy the SPIR-V
    // binary.
    ShaderModulePtr shader_module =
        std::make_unique<ShaderModule>(GetContext(), *pShaderModule, shader_module_load_options, pCreateInfo->codeSize,
                                       reinterpret_cast<const char*>(pCreateInfo->pCode), context_.GetOutputPath());

    // Add extra name information for shaders, used to give them names even if
    // they don't have explict debug names.
    AddExtraInfo((uint64_t)(*pShaderModule), std::make_pair("file", shader_module->GetSourceFile()));
    AddExtraInfo((uint64_t)(*pShaderModule), std::make_pair("entry", shader_module->GetEntryPoint()));

    std::lock_guard<std::mutex> lock(shader_modules_mutex_);
    shader_modules_[*pShaderModule] = std::move(shader_module);
}

const ShaderModule* Device::FindShaderModule(VkShaderModule shader_module) const {
    std::lock_guard<std::mutex> lock(shader_modules_mutex_);

    const ShaderModule* p_shader_module = nullptr;
    auto it = shader_modules_.find(shader_module);
    if (it != shader_modules_.end()) {
        p_shader_module = it->second.get();
    }
    return p_shader_module;
}

void Device::DeleteShaderModule(VkShaderModule shaderModule) {
    std::lock_guard<std::mutex> lock(shader_modules_mutex_);
    shader_modules_.erase(shaderModule);
}

void Device::RegisterQueue(VkQueue vk_queue, uint32_t queueFamilyIndex, uint32_t queueIndex) {
    std::lock_guard<std::mutex> lock(queues_mutex_);

    if (queues_.find(vk_queue) != queues_.end()) {
        return;
    }

    auto queue = std::make_shared<Queue>(*this, vk_queue, queueFamilyIndex, queueIndex,
                                         queue_family_properties_[queueFamilyIndex]);

    queues_[vk_queue] = std::move(queue);
}

Device::QueuePtr Device::GetQueue(VkQueue queue) {
    std::lock_guard<std::mutex> lock(queues_mutex_);
    auto it = queues_.find(queue);
    assert(it != queues_.end());
    return it == queues_.end() ? nullptr : it->second;
}

Device::ConstQueuePtr Device::GetQueue(VkQueue queue) const {
    std::lock_guard<std::mutex> lock(queues_mutex_);
    auto it = queues_.find(queue);
    assert(it != queues_.end());
    return it == queues_.end() ? nullptr : it->second;
}

std::vector<Device::QueuePtr> Device::GetAllQueues() {
    std::vector<QueuePtr> qs;
    std::lock_guard<std::mutex> lock(queues_mutex_);
    qs.reserve(queues_.size());
    for (auto& entry : queues_) {
        qs.push_back(entry.second);
    }
    return qs;
}

std::vector<Device::ConstQueuePtr> Device::GetAllQueues() const {
    std::vector<ConstQueuePtr> qs;
    std::lock_guard<std::mutex> lock(queues_mutex_);
    qs.reserve(queues_.size());
    for (auto& entry : queues_) {
        qs.push_back(entry.second);
    }
    return qs;
}

void Device::AddObjectInfo(uint64_t handle, VkObjectType type, const char* name) {
    return object_info_db_.AddObjectInfo(handle, type, name);
}

void Device::AddExtraInfo(uint64_t handle, ExtraObjectInfo info) { return object_info_db_.AddExtraInfo(handle, info); }

std::string Device::GetObjectName(uint64_t handle, HandleDebugNamePreference handle_debug_name_preference) const {
    return object_info_db_.GetObjectName(handle, handle_debug_name_preference);
}

std::string Device::GetObjectInfo(uint64_t handle) const { return object_info_db_.GetObjectInfo(handle); }

bool Device::UpdateIdleState() {
    bool result = true;
    auto queues = GetAllQueues();
    for (auto& q : queues) {
        bool q_result = q->UpdateIdleState();
        result &= q_result;
    }
    return result;
}

void Device::DeviceFault() {
    if (hang_detected_.exchange(true)) {
        // already hung.
        return;
    }
    if (checkpoints_) {
        checkpoints_->Update();
    }
    context_.DumpDeviceExecutionState(*this);
    // prevent the watchdog from firing when we've already detected a fault
    context_.StopWatchdogTimer();
}

void Device::WatchdogTimeout(bool dump_prologue, YAML::Emitter& os) {
    if (hang_detected_.exchange(true)) {
        // already hung.
        return;
    }
    if (checkpoints_) {
        checkpoints_->Update();
    }
    context_.DumpDeviceExecutionState(*this, dump_prologue, CrashSource::kWatchdogTimer, os);
}

YAML::Emitter& Device::Print(YAML::Emitter& os, const std::string& error_report) {
    UpdateIdleState();
    os << YAML::Key << "Device" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "handle" << YAML::Value << GetObjectInfo((uint64_t)vk_device_);
    os << YAML::Key << "deviceName" << YAML::Value << physical_device_properties_.deviceName;

    auto majorVersion = VK_VERSION_MAJOR(physical_device_properties_.apiVersion);
    auto minorVersion = VK_VERSION_MINOR(physical_device_properties_.apiVersion);
    auto patchVersion = VK_VERSION_PATCH(physical_device_properties_.apiVersion);
    std::stringstream api;
    api << majorVersion << "." << minorVersion << "." << patchVersion << " ("
        << Uint32ToStr(physical_device_properties_.apiVersion) << ")";
    os << YAML::Key << "apiVersion" << YAML::Value << api.str();

    std::stringstream icd;
    icd << Uint32ToStr(physical_device_properties_.driverVersion) << " (" << physical_device_properties_.driverVersion
        << ")";
    os << YAML::Key << "driverVersion" << YAML::Value << icd.str();
    os << YAML::Key << "vendorID" << YAML::Value << Uint32ToStr(physical_device_properties_.vendorID);
    os << YAML::Key << "deviceID" << YAML::Value << Uint32ToStr(physical_device_properties_.deviceID);

    os << YAML::Key << "extensions" << YAML::Value << YAML::BeginSeq;
    const auto& create_info = device_create_info_->original;
    for (uint32_t i = 0; i < create_info.enabledExtensionCount; ++i) {
        os << create_info.ppEnabledExtensionNames[i];
    }
    os << YAML::EndSeq;

    DumpDeviceFaultInfo(os);

    os << YAML::Key << "Queues" << YAML::BeginSeq;
    auto queues = GetAllQueues();
    for (auto& q : queues) {
        q->Print(os);
    }
    os << YAML::EndSeq;

    if (semaphore_tracker_) {
        semaphore_tracker_->DumpWaitingThreads(os);
    }
    if (!error_report.empty()) {
        os << error_report;
    }
    DumpCommandBuffers(os);
    os << YAML::EndMap;  // Device
    assert(os.good());
    return os;
}

static const char address_fault_strings[][32] = {
    "No Fault",
    "Invalid Read",
    "Invalid Write",
    "Invalid Execute",
    "Unknown Instruction Pointer",
    "Invalid Instruction Pointer",
    "Instruction Pointer Fault",
};

static void DumpAddressRecord(YAML::Emitter& os, const vku::sparse::range<VkDeviceAddress>& range,
                              const DeviceAddressRecord& rec) {
    os << YAML::BeginMap;
    os << YAML::Key << "begin" << YAML::Value << Uint64ToStr(range.begin);
    os << YAML::Key << "end" << YAML::Value << Uint64ToStr(range.end);
    os << YAML::Key << "type" << YAML::Value << rec.object_type;
    std::stringstream handle;
    handle << Uint64ToStr(rec.object_handle) << "[" << rec.object_name << "]";
    os << YAML::Key << "handle" << YAML::Value << handle.str();
    os << YAML::Key << "currentlyBound" << YAML::Value << (rec.binding_type == VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT);
    // TODO when
    os << YAML::EndMap;
}

void Device::DumpDeviceFaultInfo(YAML::Emitter& os) const {
    if (!extensions_present_.ext_device_fault) {
        return;
    }
    auto fault_counts = vku::InitStruct<VkDeviceFaultCountsEXT>();
    VkResult result = Dispatch().GetDeviceFaultInfoEXT(vk_device_, &fault_counts, nullptr);
    if (result != VK_SUCCESS) {
        // TODO: log
        return;
    }
    if (fault_counts.addressInfoCount == 0 && fault_counts.vendorInfoCount == 0 && fault_counts.vendorBinarySize == 0) {
        // TODO: log
        return;
    }
    std::vector<VkDeviceFaultAddressInfoEXT> address_infos;
    std::vector<VkDeviceFaultVendorInfoEXT> vendor_infos;
    std::vector<uint8_t> binary_data;
    address_infos.resize(fault_counts.addressInfoCount);
    vendor_infos.resize(fault_counts.vendorInfoCount);
    binary_data.resize(static_cast<size_t>(fault_counts.vendorBinarySize));

    auto fault_info = vku::InitStruct<VkDeviceFaultInfoEXT>();
    fault_info.pAddressInfos = fault_counts.addressInfoCount == 0 ? nullptr : address_infos.data();
    fault_info.pVendorInfos = fault_counts.vendorInfoCount == 0 ? nullptr : vendor_infos.data();
    fault_info.pVendorBinaryData =
        fault_counts.vendorBinarySize == 0 ? nullptr : reinterpret_cast<void*>(binary_data.data());

    result = Dispatch().GetDeviceFaultInfoEXT(vk_device_, &fault_counts, &fault_info);
    if (result != VK_SUCCESS && result != VK_INCOMPLETE) {
        // TODO: log
        return;
    }

    os << YAML::Key << "DeviceFaultInfo" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "description" << YAML::Value << fault_info.description;
    if (fault_counts.addressInfoCount > 0) {
        os << YAML::Key << "faultAddressRanges" << YAML::Value << YAML::BeginSeq;
        for (uint32_t addr = 0; addr < fault_counts.addressInfoCount; ++addr) {
            auto& info = address_infos[addr];

            vku::sparse::range range(address_infos[addr].reportedAddress & ~(address_infos[addr].addressPrecision - 1),
                                     address_infos[addr].reportedAddress | (address_infos[addr].addressPrecision - 1));

            os << YAML::BeginMap;
            os << YAML::Key << "type" << YAML::Value << address_fault_strings[info.addressType];
            os << YAML::Key << "begin" << YAML::Value << Uint64ToStr(range.begin);
            os << YAML::Key << "end" << YAML::Value << Uint64ToStr(range.end);

            auto lower = address_map_.lower_bound(range);
            auto upper = address_map_.upper_bound(range);
            if (lower != upper) {
                os << YAML::Key << "matchingAddressRecords" << YAML::Value << YAML::BeginSeq;
                for (auto iter = lower; iter != upper; ++iter) {
                    DumpAddressRecord(os, iter->first, iter->second);
                }
                os << YAML::EndSeq;
            }
            if (lower != address_map_.begin()) {
                --lower;
                os << YAML::Key << "priorAddressRecord" << YAML::Value;
                DumpAddressRecord(os, lower->first, lower->second);
            }
            if (upper != address_map_.end()) {
                os << YAML::Key << "nextAddressRecord" << YAML::Value;
                DumpAddressRecord(os, upper->first, upper->second);
            }
            os << YAML::EndMap;
        }
        os << YAML::EndSeq;
    }
    if (fault_counts.vendorInfoCount > 0) {
        os << YAML::Key << "VendorInfos" << YAML::Value << YAML::BeginSeq;
        for (uint32_t vendor = 0; vendor < fault_counts.vendorInfoCount; ++vendor) {
            os << YAML::BeginMap;
            os << YAML::Key << "description" << YAML::Value << vendor_infos[vendor].description;
            os << YAML::Key << "faultCode" << YAML::Value << Uint64ToStr(vendor_infos[vendor].vendorFaultCode);
            os << YAML::Key << "faultData" << YAML::Value << Uint64ToStr(vendor_infos[vendor].vendorFaultData);
            os << YAML::EndMap;  // Vendor Info
        }
        os << YAML::EndSeq;
    }
    if (fault_counts.vendorBinarySize > 0) {
        const char* kVendorFile = "vendor_binary.dat";
        std::filesystem::path out_path = context_.GetOutputPath() / kVendorFile;
        std::ofstream outfile(out_path, std::ios_base::out | std::ios_base::binary);
        outfile.write((char*)fault_info.pVendorBinaryData, static_cast<std::streamsize>(fault_counts.vendorBinarySize));
        outfile.close();

        os << YAML::Key << "vendorBinaryFile" << YAML::Value << kVendorFile;
    }
    os << YAML::EndMap;  // DeviceFaultInfo
    assert(os.good());
}

void Device::MemoryBindEvent(const DeviceAddressRecord& rec, bool multi_device) {
    // Because log callbacks are instance level, we'll get a stream of events
    // for all devices in the system. Th.secondis code assumes there's only one.
    // If there are multiple devices, each will need to filter events by looking
    // up the vulkan handle. This will be slow.
    assert(!multi_device);

    vku::sparse::range<VkDeviceAddress> range(rec.base, rec.base + rec.size);
    address_map_.overwrite_range(std::make_pair(range, rec));
}

std::unique_ptr<Checkpoint> Device::AllocateCheckpoint(uint32_t initial_value) {
    return checkpoints_ ? checkpoints_->Allocate(initial_value) : nullptr;
}

}  // namespace crash_diagnostic_layer
