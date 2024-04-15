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
#include <iomanip>

#include "cdl.h"
#include "util.h"

namespace crash_diagnostic_layer {

const VkDeviceSize kBufferMarkerBufferSize = kBufferMarkerEventCount * sizeof(uint32_t);
const VkDeviceSize kBuffermarkerHeapSize = 64 * 1024 * 1024;

// =================================================================================================
// Support functions
// =================================================================================================
bool FindMemoryType(const VkPhysicalDeviceMemoryProperties* p_mem_props, uint32_t type_bits,
                    VkMemoryPropertyFlags flags, uint32_t* p_index) {
    bool found = false;
    for (uint32_t i = 0; i < p_mem_props->memoryTypeCount; ++i) {
        if (type_bits & 1) {
            if (flags == (p_mem_props->memoryTypes[i].propertyFlags & flags)) {
                if (p_index) {
                    *p_index = i;
                }
                found = true;
                break;
            }
        }
        type_bits >>= 1;
    }
    return found;
}

VkResult CreateHostBuffer(VkDevice device, const VkPhysicalDeviceMemoryProperties* p_mem_props,
                          VkDeviceSize buffer_size, VkBuffer* p_buffer, VkDeviceSize heap_offset,
                          VkDeviceMemory* p_heap) {
    assert(p_buffer != nullptr);
    buffer_size = std::max<VkDeviceSize>(buffer_size, 256);
    if (heap_offset + buffer_size >= kBuffermarkerHeapSize) {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    VkBufferCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    create_info.pNext = nullptr;
    create_info.flags = 0;
    create_info.size = buffer_size;
    create_info.usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices = nullptr;

    auto dispatch_table = GetDeviceLayerData(DataKey(device))->dispatch_table;
    VkResult vk_res = dispatch_table.CreateBuffer(device, &create_info, nullptr, p_buffer);
    assert(VK_SUCCESS == vk_res);
    if (vk_res != VK_SUCCESS) {
        return vk_res;
    }

    VkMemoryRequirements mem_reqs = {};
    dispatch_table.GetBufferMemoryRequirements(device, *p_buffer, &mem_reqs);

    if (*p_heap == VK_NULL_HANDLE) {
        VkMemoryPropertyFlags mem_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT |
                                          VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD;

        uint32_t memory_type_index = UINT32_MAX;
        bool found_memory = FindMemoryType(p_mem_props, mem_reqs.memoryTypeBits, mem_flags, &memory_type_index);

        if (!found_memory) {
            std::cerr << "CDL Warning: No device coherent memory found, results "
                         "might not be accurate."
                      << std::endl;
            mem_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;

            found_memory = FindMemoryType(p_mem_props, mem_reqs.memoryTypeBits, mem_flags, &memory_type_index);
        }

        assert(found_memory);
        if (!found_memory) {
            dispatch_table.DestroyBuffer(device, *p_buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }

        VkMemoryAllocateInfo alloc_info = {};
        alloc_info.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        alloc_info.pNext = nullptr;
        alloc_info.allocationSize = kBuffermarkerHeapSize;
        alloc_info.memoryTypeIndex = memory_type_index;
        vk_res = dispatch_table.AllocateMemory(device, &alloc_info, nullptr, p_heap);
        assert(VK_SUCCESS == vk_res);
        if (vk_res != VK_SUCCESS) {
            dispatch_table.DestroyBuffer(device, *p_buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }
    }

    vk_res = dispatch_table.BindBufferMemory(device, *p_buffer, *p_heap, heap_offset);
    assert(VK_SUCCESS == vk_res);
    if (vk_res != VK_SUCCESS) {
        dispatch_table.FreeMemory(device, *p_heap, nullptr);
        dispatch_table.DestroyBuffer(device, *p_buffer, nullptr);
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return VK_SUCCESS;
}

void DestroyBuffer(VkDevice device, VkBuffer buffer) {
    auto dispatch_table = GetDeviceLayerData(DataKey(device))->dispatch_table;
    dispatch_table.DestroyBuffer(device, buffer, nullptr);
}

// =================================================================================================
// Device
// =================================================================================================
Device::Device(Context& context, VkPhysicalDevice vk_gpu, VkDevice device, DeviceExtensionsPresent& extensions_present)
    : context_(context), vk_physical_device_(vk_gpu), vk_device_(device), extensions_present_(extensions_present) {
    // Set the dispatch tables
    auto instance_layer_data = GetInstanceLayerData(DataKey(context_.GetInstance()));
    instance_dispatch_table_ = instance_layer_data->dispatch_table;
    auto device_layer_data = GetDeviceLayerData(DataKey(device));
    device_dispatch_table_ = device_layer_data->dispatch_table;

    uint32_t count = 0;
    instance_dispatch_table_.GetPhysicalDeviceQueueFamilyProperties(vk_physical_device_, &count, nullptr);
    if (count > 0) {
        queue_family_properties_.resize(count);
        instance_dispatch_table_.GetPhysicalDeviceQueueFamilyProperties(vk_physical_device_, &count,
                                                                        queue_family_properties_.data());
    }

    // Get memory properties
    instance_dispatch_table_.GetPhysicalDeviceMemoryProperties(vk_gpu, &memory_properties_);

    // Get device properties
    instance_dispatch_table_.GetPhysicalDeviceProperties(vk_gpu, &physical_device_properties_);

    // Get proc address for vkCmdWriteBufferMarkerAMD
    if (extensions_present.amd_buffer_marker) {
        pfn_vkCmdWriteBufferMarkerAMD_ = (PFN_vkCmdWriteBufferMarkerAMD)device_dispatch_table_.GetDeviceProcAddr(
            device, "vkCmdWriteBufferMarkerAMD");
    }
    if (extensions_present.ext_device_fault) {
        pfn_vkGetDeviceFaultInfoEXT =
            (PFN_vkGetDeviceFaultInfoEXT)device_dispatch_table_.GetDeviceProcAddr(device, "vkGetDeviceFaultInfoEXT");
    }

    pfn_vkFreeCommandBuffers_ =
        (PFN_vkFreeCommandBuffers)device_dispatch_table_.GetDeviceProcAddr(device, "vkFreeCommandBuffers");

    // Create a submit tracker
    submit_tracker_ = std::make_unique<SubmitTracker>(*this);

    // Create a semaphore tracker
    semaphore_tracker_ = std::make_unique<SemaphoreTracker>(*this, context_.TracingAllSemaphores());
}

Device::~Device() {}

void Device::SetDeviceCreateInfo(std::unique_ptr<DeviceCreateInfo> device_create_info) {
    device_create_info_ = std::move(device_create_info);
}

Context& Device::GetContext() const { return context_; }

VkPhysicalDevice Device::GetVkGpu() const { return vk_physical_device_; }

VkDevice Device::GetVkDevice() const { return vk_device_; }

const Logger& Device::Log() const { return context_.Log(); }

bool Device::HasBufferMarker() const { return extensions_present_.amd_buffer_marker; }

const std::vector<VkQueueFamilyProperties>& Device::GetVkQueueFamilyProperties() const {
    return queue_family_properties_;
}

VkResult Device::CreateBuffer(VkDeviceSize size, VkBuffer* p_buffer, void** cpu_mapped_address) {
    std::lock_guard<std::mutex> lock(marker_buffers_mutex_);
    VkResult vk_res =
        CreateHostBuffer(vk_device_, &memory_properties_, size, p_buffer, current_heap_offset_, &marker_buffers_heap_);
    if (vk_res == VK_SUCCESS) {
        *cpu_mapped_address = (void*)((uintptr_t)marker_buffers_heap_mapped_base_ + current_heap_offset_);
        current_heap_offset_ += size;
    }
    return vk_res;
}

VkResult Device::AcquireMarkerBuffer() {
    // No need to lock on marker_buffers_mutex_, already locked on callsite.
    MarkerBuffer marker_buffer = {};
    marker_buffer.size = kBufferMarkerBufferSize;
    marker_buffer.heap_offset = current_heap_offset_;
    current_heap_offset_ += kBufferMarkerBufferSize;

    VkResult vk_res = CreateHostBuffer(vk_device_, &memory_properties_, marker_buffer.size, &marker_buffer.buffer,
                                       marker_buffer.heap_offset, &marker_buffers_heap_);
    if (vk_res != VK_SUCCESS) {
        return vk_res;
    }
    if (marker_buffers_heap_mapped_base_ == nullptr) {
        vk_res = device_dispatch_table_.MapMemory(vk_device_, marker_buffers_heap_, 0, kBuffermarkerHeapSize, 0,
                                                  &marker_buffers_heap_mapped_base_);
        assert(VK_SUCCESS == vk_res);
        if (vk_res != VK_SUCCESS) {
            device_dispatch_table_.FreeMemory(vk_device_, marker_buffers_heap_, nullptr);
            device_dispatch_table_.DestroyBuffer(vk_device_, marker_buffer.buffer, nullptr);
            return VK_ERROR_INITIALIZATION_FAILED;
        }
    }
    marker_buffer.cpu_mapped_address = (void*)((uintptr_t)marker_buffers_heap_mapped_base_ + marker_buffer.heap_offset);
    marker_buffers_.push_back(marker_buffer);
    return VK_SUCCESS;
}

bool Device::AllocateMarker(Marker* marker) {
    // If there is a recycled marker, use it.
    if (marker->type == MarkerType::kUint32) {
        std::lock_guard<std::mutex> lock(recycled_markers_u32_mutex_);
        if (recycled_markers_u32_.size() > 0) {
            *marker = recycled_markers_u32_.back();
            recycled_markers_u32_.pop_back();
            return true;
        }
    } else {
        std::lock_guard<std::mutex> lock(recycled_markers_u64_mutex_);
        if (recycled_markers_u64_.size() > 0) {
            *marker = recycled_markers_u64_.back();
            recycled_markers_u64_.pop_back();
            return true;
        }
    }

    std::lock_guard<std::mutex> mlock(marker_buffers_mutex_);
    // Check if we have the required marker already allocated
    auto marker_index_inc = (marker->type == MarkerType::kUint32) ? 0 : 1;
    auto marker_buffer_index = (current_marker_index_ + marker_index_inc) / kBufferMarkerEventCount;

    // Out of space, allocate a new buffer
    if (marker_buffer_index >= marker_buffers_.size()) {
        // zakerinasab: This causes a glitch if CDL is on while a user plays
        // the game. If CDL goes to be activated for end users, this should be
        // done out of markers_buffers_mutex_ lock in a predictive mode.
        if (AcquireMarkerBuffer() != VK_SUCCESS) {
            return false;
        }
        assert(marker_buffer_index < marker_buffers_.size());
        if (marker->type == MarkerType::kUint64) {
            // Make sure current_marker_index_ is even
            current_marker_index_ = ((current_marker_index_ + 1) & -2);
        }
    }
    auto& marker_buffer = marker_buffers_.back();
    marker->buffer = marker_buffer.buffer;
    marker->offset = (current_marker_index_ % kBufferMarkerEventCount) * sizeof(uint32_t);
    marker->cpu_mapped_address = (void*)((uintptr_t)marker_buffer.cpu_mapped_address + marker->offset);
    current_marker_index_ += 1 + marker_index_inc;
    return true;
}

void Device::FreeMarker(const Marker marker) {
    if (marker.type == MarkerType::kUint32) {
        std::lock_guard<std::mutex> lock(recycled_markers_u32_mutex_);
        recycled_markers_u32_.push_back(marker);
    } else {
        std::lock_guard<std::mutex> lock(recycled_markers_u64_mutex_);
        recycled_markers_u64_.push_back(marker);
    }
}

void Device::FreeCommandBuffers(VkCommandPool command_pool, uint32_t command_buffer_count,
                                const VkCommandBuffer* command_buffers) {
    if (pfn_vkFreeCommandBuffers_ == nullptr) {
        return;
    }
    pfn_vkFreeCommandBuffers_(vk_device_, command_pool, command_buffer_count, command_buffers);
}

void Device::CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                     VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker) {
    if (pfn_vkCmdWriteBufferMarkerAMD_ == nullptr) {
        return;
    }

    pfn_vkCmdWriteBufferMarkerAMD_(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

void Device::AddCommandBuffer(VkCommandBuffer vk_command_buffer) {
    std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
    assert(std::find(command_buffers_.begin(), command_buffers_.end(), vk_command_buffer) == command_buffers_.end());
    command_buffers_.push_back(vk_command_buffer);
}

void Device::DumpCommandBuffers(YAML::Emitter& os, const char* section_name, CommandBufferDumpOptions options,
                                bool dump_all_command_buffers) const {
    // Sort command buffers by submit info id
    std::map<uint64_t /* submit_info_id*/, std::vector<CommandBuffer*>> sorted_command_buffers;
    std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
    for (auto cb : command_buffers_) {
        auto p_cmd = GetCommandBuffer(cb);
        if (p_cmd && p_cmd->IsPrimaryCommandBuffer()) {
            if (dump_all_command_buffers ||
                (p_cmd->HasBufferMarker() && p_cmd->WasSubmittedToQueue() && !p_cmd->CompletedExecution())) {
                sorted_command_buffers[p_cmd->GetSubmitInfoId()].push_back(p_cmd);
            }
        }
    }
    os << YAML::Key << section_name << YAML::Value << YAML::BeginSeq;
    for (auto& it : sorted_command_buffers) {
        for (auto p_cmd : it.second) {
            p_cmd->DumpContents(os, options);
        }
    }
    YAML::EndSeq;
}

void Device::DumpAllCommandBuffers(YAML::Emitter& os, CommandBufferDumpOptions options) const {
    DumpCommandBuffers(os, "AllCommandBuffers", options, true /* dump_all_command_buffers */);
}

void Device::DumpIncompleteCommandBuffers(YAML::Emitter& os, CommandBufferDumpOptions options) const {
    DumpCommandBuffers(os, "IncompleteCommandBuffers", options, false /* dump_all_command_buffers */);
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
    bool has_buffer_markers;
    {
        std::lock_guard<std::mutex> lock(command_pools_mutex_);
        assert(command_pools_.find(vk_pool) != command_pools_.end());
        command_pools_[vk_pool]->AllocateCommandBuffers(allocate_info, command_buffers);
        has_buffer_markers = command_pools_[vk_pool]->HasBufferMarkers();
    }
    // TODO locking here?
    // create command buffers tracking data
    for (uint32_t i = 0; i < allocate_info->commandBufferCount; ++i) {
        VkCommandBuffer vk_cmd = command_buffers[i];

        auto cmd = std::make_unique<CommandBuffer>(*this, vk_pool, vk_cmd, allocate_info, has_buffer_markers);
        cmd->SetInstrumentAllCommands(context_.InstrumentAllCommands());

        SetCommandBuffer(vk_cmd, std::move(cmd));
        AddCommandBuffer(vk_cmd);
    }
}

// Write out information about an invalid command buffer reset.
void Device::DumpCommandBufferStateOnScreen(CommandBuffer* p_cmd, YAML::Emitter& os) const {
    Log().Error("Invalid Command Buffer Usage");
    Log().Error("Reset of VkCommandBuffer in use by GPU: %s",
                GetObjectName((uint64_t)p_cmd->GetVkCommandBuffer()).c_str());
    auto submitted_fence = p_cmd->GetSubmittedFence();

    // If there is a fence associated with this command buffer, we check
    // that it's status is signaled.
    if (submitted_fence != VK_NULL_HANDLE) {
        auto fence_status = device_dispatch_table_.WaitForFences(vk_device_, 1, &submitted_fence, VK_TRUE, 0);
        if (VK_TIMEOUT == fence_status) {
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
    p_cmd->DumpContents(error_report, CommandBufferDumpOption::kDumpAllCommands);
    error_report << YAML::EndMap;
    Log().Error(error_report.c_str());
    os << error_report.c_str();
}

bool Device::ValidateCommandBufferNotInUse(CommandBuffer* p_cmd, YAML::Emitter& os) {
    assert(p_cmd);
    if (p_cmd->HasBufferMarker() && p_cmd->WasSubmittedToQueue() && !p_cmd->CompletedExecution()) {
        DumpCommandBufferStateOnScreen(p_cmd, os);
        return false;
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
    context_.MakeOutputPath();
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

void Device::RegisterQueueFamilyIndex(VkQueue queue, uint32_t queueFamilyIndex) {
    std::lock_guard<std::mutex> lock(queue_family_index_trackers_mutex_);
    queue_family_index_trackers_[queue] = queueFamilyIndex;
}

uint32_t Device::GetQueueFamilyIndex(VkQueue queue) {
    std::lock_guard<std::mutex> lock(queue_family_index_trackers_mutex_);
    assert(queue_family_index_trackers_.find(queue) != queue_family_index_trackers_.end());
    return queue_family_index_trackers_[queue];
}

void Device::RegisterHelperCommandPool(uint32_t queueFamilyIndex, VkCommandPool commandPool) {
    std::lock_guard<std::mutex> lock(helper_command_pools_mutex_);
    helper_command_pools_[queueFamilyIndex] = commandPool;
}

VkCommandPool Device::GetHelperCommandPool(uint32_t queueFamilyIndex) {
    std::lock_guard<std::mutex> lock(helper_command_pools_mutex_);
    assert(helper_command_pools_.find(queueFamilyIndex) != helper_command_pools_.end());
    return helper_command_pools_[queueFamilyIndex];
}

VkCommandPool Device::GetHelperCommandPool(VkQueue vk_queue) {
    assert(context_.TrackingSemaphores() == true);
    if (vk_queue == VK_NULL_HANDLE) {
        return VK_NULL_HANDLE;
    }
    uint32_t queue_family_index = GetQueueFamilyIndex(vk_queue);
    return GetHelperCommandPool(queue_family_index);
}

void Device::EraseCommandPools() {
    std::lock_guard<std::mutex> lock(helper_command_pools_mutex_);
    for (auto& item : helper_command_pools_) {
        device_dispatch_table_.DestroyCommandPool(vk_device_, item.second, nullptr);
    }
    helper_command_pools_.clear();
}

//////////////////////////////////////
void Device::AddObjectInfo(uint64_t handle, ObjectInfoPtr info) {
    return object_info_db_.AddObjectInfo(handle, std::move(info));
}

void Device::AddExtraInfo(uint64_t handle, ExtraObjectInfo info) { return object_info_db_.AddExtraInfo(handle, info); }

std::string Device::GetObjectName(uint64_t handle, HandleDebugNamePreference handle_debug_name_preference) const {
    return object_info_db_.GetObjectName(handle, handle_debug_name_preference);
}

std::string Device::GetObjectInfo(uint64_t handle) const { return object_info_db_.GetObjectInfo(handle); }

std::string Device::GetObjectInfoNoHandleTag(uint64_t handle) const {
    return object_info_db_.GetObjectInfoNoHandleTag(handle);
}

YAML::Emitter& Device::Print(YAML::Emitter& os) const {
    os << YAML::Key << "Device" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "vkHandle" << YAML::Value << GetObjectInfo((uint64_t)vk_device_);
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

    os << YAML::Key << "deviceExtensions" << YAML::Value << YAML::BeginSeq;
    const auto& create_info = device_create_info_->original;
    for (uint32_t i = 0; i < create_info.enabledExtensionCount; ++i) {
        os << create_info.ppEnabledExtensionNames[i];
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;  // Device

    DumpDeviceFaultInfo(os);

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
    if (!extensions_present_.ext_device_fault || !pfn_vkGetDeviceFaultInfoEXT) {
        return;
    }
    auto fault_counts = vku::InitStruct<VkDeviceFaultCountsEXT>();
    VkResult result = pfn_vkGetDeviceFaultInfoEXT(vk_device_, &fault_counts, nullptr);
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
    binary_data.resize(fault_counts.vendorBinarySize);

    auto fault_info = vku::InitStruct<VkDeviceFaultInfoEXT>();
    fault_info.pAddressInfos = fault_counts.addressInfoCount == 0 ? nullptr : address_infos.data();
    fault_info.pVendorInfos = fault_counts.vendorInfoCount == 0 ? nullptr : vendor_infos.data();
    fault_info.pVendorBinaryData =
        fault_counts.vendorBinarySize == 0 ? nullptr : reinterpret_cast<void*>(binary_data.data());

    result = pfn_vkGetDeviceFaultInfoEXT(vk_device_, &fault_counts, &fault_info);
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
        os << YAML::Key << "Vendor Infos" << YAML::Value << YAML::BeginSeq;
        for (uint32_t vendor = 0; vendor < fault_counts.vendorInfoCount; ++vendor) {
            os << YAML::BeginMap;
            os << YAML::Key << "Description" << YAML::Value << vendor_infos[vendor].description;
            os << YAML::Key << "Fault Code" << YAML::Value << Uint64ToStr(vendor_infos[vendor].vendorFaultCode);
            os << YAML::Key << "Fault Data" << YAML::Value << Uint64ToStr(vendor_infos[vendor].vendorFaultData);
            os << YAML::EndMap;  // Vendor Info
        }
        os << YAML::EndSeq;
    }
    if (fault_counts.vendorBinarySize > 0) {
        os << YAML::Key << "Vendor Binary Data" << YAML::Value << YAML::BeginSeq << YAML::Hex;
        // TODO This is going to be huge
        for (uint32_t byte = 0; byte < fault_counts.vendorBinarySize; ++byte) {
            os << binary_data[byte];
        }
        os << YAML::Dec << YAML::EndSeq;
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

void Device::PostSubmit(VkQueue queue, VkResult result) {
    bool dump = IsVkError(result) || context_.CountSubmit();
    if (dump) {
        context_.DumpDeviceExecutionState(vk_device_);
    }
}

VkResult Device::QueueSubmitWithoutTrackingSemaphores(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits,
                                                      VkFence fence) {
    VkResult result = device_dispatch_table_.QueueSubmit(queue, submitCount, pSubmits, fence);
    PostSubmit(queue, result);
    return result;
}

VkResult Device::QueueSubmit2WithoutTrackingSemaphores(VkQueue queue, uint32_t submitCount,
                                                       const VkSubmitInfo2* pSubmits, VkFence fence) {
    VkResult result;
    if (device_dispatch_table_.QueueSubmit2) {
        result = device_dispatch_table_.QueueSubmit2(queue, submitCount, pSubmits, fence);
    } else {
        result = device_dispatch_table_.QueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    }
    PostSubmit(queue, result);
    return result;
}

std::vector<VkCommandBuffer> Device::AllocHelperCBs(VkCommandPool vk_command_pool, uint32_t count) {
    std::vector<VkCommandBuffer> new_buffers(count, VK_NULL_HANDLE);

    auto cb_allocate_info = vku::InitStruct<VkCommandBufferAllocateInfo>();
    cb_allocate_info.commandPool = vk_command_pool;
    cb_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cb_allocate_info.commandBufferCount = count;

    auto result = device_dispatch_table_.AllocateCommandBuffers(vk_device_, &cb_allocate_info, new_buffers.data());
    if (result != VK_SUCCESS) {
        new_buffers.clear();
        return new_buffers;
    }
    for (uint32_t i = 0; i < count; i++) {
        SetDeviceLoaderData(vk_device_, new_buffers[i]);
    }
    return new_buffers;
}

VkResult Device::QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(submit_info.pCommandBuffers[command_buffer_index]);
            if (cmd != nullptr) {
                cmd->QueueSubmit(queue, fence);
            }
        }
    }
    VkResult result;

    if (!context_.TrackingSemaphores()) {
        return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    VkCommandPool vk_pool = GetHelperCommandPool(queue);
    if (vk_pool == VK_NULL_HANDLE) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    bool trace_all_semaphores = context_.TracingAllSemaphores();
    auto queue_submit_id = GetNextQueueSubmitId();
    auto semaphore_tracking_submits = reinterpret_cast<VkSubmitInfo*>(alloca(sizeof(VkSubmitInfo) * submitCount));

    std::vector<VkCommandBuffer> new_buffers = AllocHelperCBs(vk_pool, 2 * submitCount);
    if (new_buffers.empty()) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        // Add the semaphore tracking command buffers to the beginning and the end
        // of the queue submit info.
        semaphore_tracking_submits[submit_index] = pSubmits[submit_index];
        auto cb_count = pSubmits[submit_index].commandBufferCount;
        VkCommandBuffer* extended_cbs = (VkCommandBuffer*)alloca((cb_count + 2) * sizeof(VkCommandBuffer));
        semaphore_tracking_submits[submit_index].pCommandBuffers = extended_cbs;
        semaphore_tracking_submits[submit_index].commandBufferCount = cb_count + 2;

        extended_cbs[0] = new_buffers[submit_index];
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            extended_cbs[cb_index + 1] = pSubmits[submit_index].pCommandBuffers[cb_index];
        }
        extended_cbs[cb_count + 1] = new_buffers[submit_index + 1];

        auto submit_info_id =
            submit_tracker_->RegisterSubmitInfo(queue_submit_id, &semaphore_tracking_submits[submit_index]);
        StoreSubmitHelperCommandBuffersInfo(submit_info_id, vk_pool, extended_cbs[0], extended_cbs[cb_count + 1]);
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            auto command_buffer = GetCommandBuffer(pSubmits[submit_index].pCommandBuffers[cb_index]);
            assert(command_buffer != nullptr);
            if (command_buffer) {
                command_buffer->SetSubmitInfoId(submit_info_id);
            }
        }

        RecordSubmitStart(queue_submit_id, submit_info_id, extended_cbs[0]);
        RecordSubmitFinish(queue_submit_id, submit_info_id, extended_cbs[cb_count + 1]);

        if (trace_all_semaphores) {
            LogSubmitInfoSemaphores(queue, submit_info_id);
        }
    }

    result = device_dispatch_table_.QueueSubmit(queue, submitCount, semaphore_tracking_submits, fence);

    PostSubmit(queue, result);
    return result;
}

VkResult Device::QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferInfoCount;
             ++command_buffer_index) {
            auto cmd = crash_diagnostic_layer::GetCommandBuffer(
                submit_info.pCommandBufferInfos[command_buffer_index].commandBuffer);
            if (cmd != nullptr) {
                cmd->QueueSubmit(queue, fence);
            }
        }
    }
    VkResult result;

    if (!context_.TrackingSemaphores()) {
        return QueueSubmit2WithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    VkCommandPool vk_pool = GetHelperCommandPool(queue);
    if (vk_pool == VK_NULL_HANDLE) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return QueueSubmit2WithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    bool trace_all_semaphores = context_.TracingAllSemaphores();
    auto queue_submit_id = GetNextQueueSubmitId();
    auto semaphore_tracking_submits = reinterpret_cast<VkSubmitInfo2*>(alloca(sizeof(VkSubmitInfo) * submitCount));

    std::vector<VkCommandBuffer> new_buffers = AllocHelperCBs(vk_pool, 2 * submitCount);
    if (new_buffers.empty()) {
        Log().Error(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return QueueSubmit2WithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        // Add the semaphore tracking command buffers to the beginning and the end
        // of the queue submit info.
        semaphore_tracking_submits[submit_index] = pSubmits[submit_index];
        auto cb_count = pSubmits[submit_index].commandBufferInfoCount;
        VkCommandBufferSubmitInfo* extended_cbs =
            (VkCommandBufferSubmitInfo*)alloca((cb_count + 2) * sizeof(VkCommandBufferSubmitInfo));
        semaphore_tracking_submits[submit_index].pCommandBufferInfos = extended_cbs;
        semaphore_tracking_submits[submit_index].commandBufferInfoCount = cb_count + 2;

        extended_cbs[0] = vku::InitStruct<VkCommandBufferSubmitInfo>();
        extended_cbs[0].commandBuffer = new_buffers[submit_index];
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            extended_cbs[cb_index + 1] = pSubmits[submit_index].pCommandBufferInfos[cb_index];
        }
        extended_cbs[cb_count + 1] = vku::InitStruct<VkCommandBufferSubmitInfo>();
        extended_cbs[cb_count + 1].commandBuffer = new_buffers[submit_index + 1];

        auto submit_info_id =
            submit_tracker_->RegisterSubmitInfo(queue_submit_id, &semaphore_tracking_submits[submit_index]);
        StoreSubmitHelperCommandBuffersInfo(submit_info_id, vk_pool, extended_cbs[0].commandBuffer,
                                            extended_cbs[cb_count + 1].commandBuffer);
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            auto command_buffer = GetCommandBuffer(pSubmits[submit_index].pCommandBufferInfos[cb_index].commandBuffer);
            assert(command_buffer != nullptr);
            if (command_buffer) {
                command_buffer->SetSubmitInfoId(submit_info_id);
            }
        }

        RecordSubmitStart(queue_submit_id, submit_info_id, extended_cbs[0].commandBuffer);
        RecordSubmitFinish(queue_submit_id, submit_info_id, extended_cbs[cb_count + 1].commandBuffer);

        if (trace_all_semaphores) {
            LogSubmitInfoSemaphores(queue, submit_info_id);
        }
    }

    if (device_dispatch_table_.QueueSubmit2) {
        result = device_dispatch_table_.QueueSubmit2(queue, submitCount, pSubmits, fence);
    } else {
        result = device_dispatch_table_.QueueSubmit2KHR(queue, submitCount, pSubmits, fence);
    }

    PostSubmit(queue, result);
    return result;
}

VkResult Device::QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                 VkFence fence) {
    VkResult result;
    bool track_semaphores = context_.TrackingSemaphores();
    // If semaphore tracking is not requested, pass the call to the dispatch table
    // as is.
    if (!track_semaphores) {
        result = device_dispatch_table_.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
        PostSubmit(queue, result);
        return result;
    }

    auto qbind_sparse_id = GetNextQueueBindSparseId();
    bool trace_all_semaphores = context_.TracingAllSemaphores();
    if (track_semaphores && trace_all_semaphores) {
        LogBindSparseInfosSemaphores(queue, bindInfoCount, pBindInfo);
    }

    // Ensure the queue is registered before and we know which command pool use
    // for this queue. If not, pass the call to dispatch table.
    VkCommandPool vk_pool = GetHelperCommandPool(queue);
    if (vk_pool == VK_NULL_HANDLE) {
        Log().Warning("device handle not found for queue 0x" PRIx64
                      ", Ignoring semaphore signals in vkQueueBindSparse call.",
                      (uint64_t)queue);
        result = device_dispatch_table_.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
        PostSubmit(queue, result);
        return result;
    }

    // If we don't need to expand the bind sparse info, pass the call to dispatch
    // table.
    PackedBindSparseInfo packed_bind_sparse_info(queue, bindInfoCount, pBindInfo);
    if (!ShouldExpandQueueBindSparseToTrackSemaphores(&packed_bind_sparse_info)) {
        result = device_dispatch_table_.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
        PostSubmit(queue, result);
        return result;
    }

    ExpandedBindSparseInfo expanded_bind_sparse_info(&packed_bind_sparse_info);
    ExpandBindSparseInfo(&expanded_bind_sparse_info);

    // For each VkSubmitInfo added to the expanded vkQueueBindSparse, check if
    // pNext should point to a VkTimelineSemaphoreSubmitInfoKHR struct.
    size_t tsinfo_it = 0;
    for (int i = 0; i < expanded_bind_sparse_info.submit_infos.size(); i++) {
        if (expanded_bind_sparse_info.has_timeline_semaphore_info[i]) {
            expanded_bind_sparse_info.submit_infos[i].pNext =
                &expanded_bind_sparse_info.timeline_semaphore_infos[tsinfo_it++];
        }
    }

    // For each VkSubmitInfo added to the expanded vkQueueBindSparse, reserve a
    // command buffer and put in the submit.
    // Allocate the required command buffers
    auto num_submits = (uint32_t)expanded_bind_sparse_info.submit_infos.size();

    std::vector<VkCommandBuffer> helper_cbs = AllocHelperCBs(vk_pool, num_submits);
    if (helper_cbs.empty()) {
        // Silently pass the call to the dispatch table.
        result = device_dispatch_table_.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
        PostSubmit(queue, result);
        return result;
    }

    uint32_t next_wait_helper_submit = 0;
    for (uint32_t i = 0; i < num_submits; i++) {
        auto& exp_info = expanded_bind_sparse_info.submit_infos[i];
        exp_info.pCommandBuffers = &helper_cbs[i];
        exp_info.commandBufferCount = 1;

        RecordBindSparseHelperSubmit(qbind_sparse_id, &exp_info, vk_pool);

        if (exp_info.signalSemaphoreCount > 0) {
            // Rip out semaphore signal operations from signal helper submit. We
            // needed this info to correctly record the signal semaphore markers, but
            // we don't need the helper submits to signal the semaphores that are
            // already signalled in a bind sparse info.
            exp_info.signalSemaphoreCount = 0;
            exp_info.pSignalSemaphores = nullptr;
            exp_info.pNext = nullptr;
        } else {
            // This is a wait helper submit. We need to signal the wait binary
            // semaphores that the helper submit is waiting on.
            exp_info.signalSemaphoreCount =
                (uint32_t)expanded_bind_sparse_info.wait_binary_semaphores[next_wait_helper_submit].size();
            exp_info.pSignalSemaphores =
                expanded_bind_sparse_info.wait_binary_semaphores[next_wait_helper_submit].data();
            next_wait_helper_submit++;
        }
    }

    uint32_t next_bind_sparse_info_index = 0;
    uint32_t available_bind_sparse_info_counter = 0;
    uint32_t next_submit_info_index = 0;
    VkResult last_bind_result = VK_SUCCESS;
    for (int i = 0; i < expanded_bind_sparse_info.queue_operation_types.size(); i++) {
        if (expanded_bind_sparse_info.queue_operation_types[i] == crash_diagnostic_layer::kQueueSubmit) {
            // Send all the available bind sparse infos before submit info. Signal the
            // fence only if the last bind sparse info is included.
            if (available_bind_sparse_info_counter) {
                VkFence bind_fence = VK_NULL_HANDLE;
                if (bindInfoCount == next_bind_sparse_info_index + available_bind_sparse_info_counter) {
                    bind_fence = fence;
                }
                result = device_dispatch_table_.QueueBindSparse(queue, available_bind_sparse_info_counter,
                                                                &pBindInfo[next_bind_sparse_info_index], bind_fence);
                if (result != VK_SUCCESS) {
                    last_bind_result = result;
                    break;
                }
                next_bind_sparse_info_index += available_bind_sparse_info_counter;
                available_bind_sparse_info_counter = 0;
            }
            // Send the submit info
            result = device_dispatch_table_.QueueSubmit(
                queue, 1, &expanded_bind_sparse_info.submit_infos[next_submit_info_index], VK_NULL_HANDLE);
            if (result != VK_SUCCESS) {
                Log().Warning(
                    "helper vkQueueSubmit failed while tracking semaphores in a vkQueueBindSparse call. Semaphore "
                    "values in the final report might be wrong. Result: 0x%08x",
                    result);
                break;
            }
            next_submit_info_index++;
        } else {
            available_bind_sparse_info_counter++;
        }
    }
    if (last_bind_result != VK_SUCCESS) {
        Log().Warning(
            "QueueBindSparse: Unexpected VkResult = 0x%8x after submitting %d bind sparse infos and %d "
            " helper submit infos to the queue. Submitting the remained bind sparse infos at once.",
            last_bind_result, next_bind_sparse_info_index, next_submit_info_index);
        return device_dispatch_table_.QueueBindSparse(queue, bindInfoCount - next_bind_sparse_info_index,
                                                      &pBindInfo[next_bind_sparse_info_index], fence);
    }
    // If any remaining bind sparse infos, submit them all.
    if (bindInfoCount > next_bind_sparse_info_index + available_bind_sparse_info_counter) {
        return device_dispatch_table_.QueueBindSparse(queue, bindInfoCount - next_submit_info_index,
                                                      &pBindInfo[next_bind_sparse_info_index], fence);
    }
    PostSubmit(queue, last_bind_result);
    return last_bind_result;
}

void Device::StoreSubmitHelperCommandBuffersInfo(SubmitInfoId submit_info_id, VkCommandPool vk_pool,
                                                 VkCommandBuffer start_marker_cb, VkCommandBuffer end_marker_cb) {
    assert(context_.TrackingSemaphores() == true);
    submit_tracker_->StoreSubmitHelperCommandBuffersInfo(submit_info_id, vk_pool, start_marker_cb, end_marker_cb);
}

VkResult Device::RecordSubmitStart(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer cb) {
    assert(context_.TrackingSemaphores() == true);
    auto commandBufferBeginInfo = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result = device_dispatch_table_.BeginCommandBuffer(cb, &commandBufferBeginInfo);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return result;
    }

    submit_tracker_->RecordSubmitStart(qsubmit_id, submit_info_id, cb);

    result = device_dispatch_table_.EndCommandBuffer(cb);
    assert(result == VK_SUCCESS);
    return result;
}

VkResult Device::RecordSubmitFinish(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer cb) {
    assert(context_.TrackingSemaphores() == true);
    auto commandBufferBeginInfo = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result = device_dispatch_table_.BeginCommandBuffer(cb, &commandBufferBeginInfo);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return result;
    }

    submit_tracker_->RecordSubmitFinish(qsubmit_id, submit_info_id, cb);
    submit_tracker_->CleanupSubmitInfos();
    result = device_dispatch_table_.EndCommandBuffer(cb);
    assert(result == VK_SUCCESS);
    return result;
}

void Device::LogSubmitInfoSemaphores(VkQueue vk_queue, SubmitInfoId submit_info_id) {
    assert(context_.TrackingSemaphores() == true);
    assert(context_.TracingAllSemaphores() == true);
    if (submit_tracker_->SubmitInfoHasSemaphores(submit_info_id)) {
        std::string semaphore_log = submit_tracker_->GetSubmitInfoSemaphoresLog(vk_device_, vk_queue, submit_info_id);
        Log().Info(semaphore_log);
    }
}

VkResult Device::RecordBindSparseHelperSubmit(QueueBindSparseId qbind_sparse_id, const VkSubmitInfo* vk_submit_info,
                                              VkCommandPool vk_pool) {
    auto commandBufferBeginInfo = vku::InitStruct<VkCommandBufferBeginInfo>();
    VkResult result =
        device_dispatch_table_.BeginCommandBuffer(vk_submit_info->pCommandBuffers[0], &commandBufferBeginInfo);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        Log().Warning("failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        return result;
    }

    assert(context_.TrackingSemaphores() == true);
    submit_tracker_->CleanupBindSparseHelperSubmits();
    submit_tracker_->RecordBindSparseHelperSubmit(qbind_sparse_id, vk_submit_info, vk_pool);

    result = device_dispatch_table_.EndCommandBuffer(vk_submit_info->pCommandBuffers[0]);
    assert(result == VK_SUCCESS);
    return result;
}

bool Device::ShouldExpandQueueBindSparseToTrackSemaphores(PackedBindSparseInfo* packed_bind_sparse_info) {
    assert(context_.TrackingSemaphores() == true);

    packed_bind_sparse_info->semaphore_tracker = GetSemaphoreTracker();
    return BindSparseUtils::ShouldExpandQueueBindSparseToTrackSemaphores(packed_bind_sparse_info);
}

void Device::ExpandBindSparseInfo(ExpandedBindSparseInfo* bind_sparse_expand_info) {
    return BindSparseUtils::ExpandBindSparseInfo(bind_sparse_expand_info);
}

void Device::LogBindSparseInfosSemaphores(VkQueue vk_queue, uint32_t bind_info_count,
                                          const VkBindSparseInfo* bind_infos) {
    assert(context_.TrackingSemaphores() == true);
    assert(context_.TracingAllSemaphores() == true);
    auto log = BindSparseUtils::LogBindSparseInfosSemaphores(*this, vk_device_, vk_queue, bind_info_count, bind_infos);
    Log().Info(log);
}

}  // namespace crash_diagnostic_layer
