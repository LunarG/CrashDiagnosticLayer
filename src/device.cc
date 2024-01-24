/*
 Copyright 2018 Google Inc.

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
#include <iomanip>
#include <iostream>

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
Device::Device(Context* context, VkPhysicalDevice vk_gpu, VkDevice device, DeviceExtensionsPresent& extensions_present)
    : context_(context), vk_physical_device_(vk_gpu), vk_device_(device), extensions_present_(extensions_present) {
    // Set the dispatch tables
    auto instance_layer_data = GetInstanceLayerData(DataKey(context_->GetInstance()));
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
    submit_tracker_ = std::make_unique<SubmitTracker>(this);

    // Create a semaphore tracker
    semaphore_tracker_ = std::make_unique<SemaphoreTracker>(this, context_->TracingAllSemaphores());
}

Device::~Device() {}

void Device::SetDeviceCreateInfo(std::unique_ptr<DeviceCreateInfo> device_create_info) {
    device_create_info_ = std::move(device_create_info);
}

Context* Device::GetContext() const { return context_; }

VkPhysicalDevice Device::GetVkGpu() const { return vk_physical_device_; }

VkDevice Device::GetVkDevice() const { return vk_device_; }

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

void Device::DumpCommandBuffers(std::ostream& os, CommandBufferDumpOptions options,
                                bool dump_all_command_buffers) const {
    // Sort command buffers by submit info id
    std::map<uint64_t /* submit_info_id*/, std::vector<CommandBuffer*>> sorted_command_buffers;
    std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
    for (auto cb : command_buffers_) {
        auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(cb);
        if (p_cmd && p_cmd->IsPrimaryCommandBuffer()) {
            if (dump_all_command_buffers ||
                (p_cmd->HasBufferMarker() && p_cmd->WasSubmittedToQueue() && !p_cmd->CompletedExecution())) {
                sorted_command_buffers[p_cmd->GetSubmitInfoId()].push_back(p_cmd);
            }
        }
    }
    for (auto& it : sorted_command_buffers) {
        for (auto p_cmd : it.second) {
            p_cmd->DumpContents(os, options);
            os << "\n";
        }
    }
}

void Device::DumpAllCommandBuffers(std::ostream& os, CommandBufferDumpOptions options) const {
    os << "AllCommandBuffers:\n";
    DumpCommandBuffers(os, options, true /* dump_all_command_buffers */);
}

void Device::DumpIncompleteCommandBuffers(std::ostream& os, CommandBufferDumpOptions options) const {
    os << "IncompleteCommandBuffers:";
    DumpCommandBuffers(os, options, false /* dump_all_command_buffers */);
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

void Device::AllocateCommandBuffers(VkCommandPool vk_command_pool, const VkCommandBufferAllocateInfo* allocate_info,
                                    VkCommandBuffer* command_buffers) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    assert(command_pools_.find(vk_command_pool) != command_pools_.end());
    command_pools_[vk_command_pool]->AllocateCommandBuffers(allocate_info, command_buffers);
}

// Write out information about an invalid command buffer reset.
void Device::DumpCommandBufferStateOnScreen(CommandBuffer* p_cmd, std::ostream& os) const {
    GetContext()->GetLogger()->LogError("Invalid Command Buffer Usage");
    GetContext()->GetLogger()->LogError("Reset of VkCommandBuffer in use by GPU: %s",
                                        GetObjectName((uint64_t)p_cmd->GetVkCommandBuffer()).c_str());
    auto submitted_fence = p_cmd->GetSubmittedFence();

    // If there is a fence associated with this command buffer, we check
    // that it's status is signaled.
    if (submitted_fence != VK_NULL_HANDLE) {
        auto fence_status = device_dispatch_table_.WaitForFences(vk_device_, 1, &submitted_fence, VK_TRUE, 0);
        if (VK_TIMEOUT == fence_status) {
            GetContext()->GetLogger()->LogError("Reset before fence was set: %s",
                                                GetObjectName((uint64_t)submitted_fence).c_str());
        } else {
            GetContext()->GetLogger()->LogError("Fence was set: %s", GetObjectName((uint64_t)submitted_fence).c_str());
        }
    }

    // Dump this specific command buffer to console with all commands.
    // We do this because this is a race between the GPU and the logging and
    // often the logger will show the command buffer as completed where as
    // if we write a single command buffer it's less likely the GPU has completed.
    std::stringstream error_report;
    error_report << "InvalidCommandBuffer:\n";
    p_cmd->DumpContents(error_report, CommandBufferDumpOption::kDumpAllCommands);
    GetContext()->GetLogger()->LogError(error_report.str().c_str());
    os << error_report.str();
}

bool Device::ValidateCommandBufferNotInUse(CommandBuffer* p_cmd, std::ostream& os) {
    assert(p_cmd);
    if (p_cmd->HasBufferMarker() && p_cmd->WasSubmittedToQueue() && !p_cmd->CompletedExecution()) {
        DumpCommandBufferStateOnScreen(p_cmd, os);
        return false;
    }
    return true;
}

bool Device::ValidateCommandBufferNotInUse(VkCommandBuffer vk_command_buffer, std::ostream& os) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(vk_command_buffer);
    assert(p_cmd != nullptr);
    if (p_cmd != nullptr) {
        return ValidateCommandBufferNotInUse(p_cmd, os);
    }
    // If for any reason we can't find the command buffer information,
    // don't break the application.
    return true;
}

void Device::ValidateCommandPoolState(VkCommandPool vk_command_pool, std::ostream& os) {
    std::lock_guard<std::mutex> lock(command_pools_mutex_);
    assert(command_pools_.find(vk_command_pool) != command_pools_.end());
    // Only validate primary command buffers. If a secondary command buffer is
    // hung, CDL catches the primary command buffer that the hung cb was recorded
    // to.
    auto command_buffers = command_pools_[vk_command_pool]->GetCommandBuffers(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
    for (auto vk_cmd : command_buffers) {
        auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(vk_cmd);
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
            auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(vk_cmd);
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
            auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(vk_cmd);
            if (p_cmd != nullptr) {
                command_buffers_.erase(std::remove(command_buffers_.begin(), command_buffers_.end(), vk_cmd),
                                       command_buffers_.end());
                crash_diagnostic_layer::DeleteCommandBuffer(vk_cmd);
            }
        }
    }
    command_pools_.erase(vk_command_pool);
}

void Device::DeleteCommandBuffers(const VkCommandBuffer* vk_cmds, uint32_t cb_count) {
    {
        std::lock_guard<std::recursive_mutex> lock(command_buffers_mutex_);
        for (uint32_t i = 0; i < cb_count; ++i) {
            command_buffers_.erase(std::remove(command_buffers_.begin(), command_buffers_.end(), vk_cmds[i]),
                                   command_buffers_.end());
            crash_diagnostic_layer::DeleteCommandBuffer(vk_cmds[i]);
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
                // TODO(aellem) Error, unknown shader module.
            }
        }
    } else {
        // TODO(aellem) Error, unknown pipeline.
    }
}

void Device::DeletePipeline(VkPipeline pipeline) {
    std::lock_guard<std::mutex> lock(pipelines_mutex_);
    pipelines_.erase(pipeline);
}

void Device::CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModule* pShaderModule,
                                int shader_module_load_options) {
    GetContext()->MakeOutputPath();
    // Parse the SPIR-V for relevant information, does not copy the SPIR-V
    // binary.
    ShaderModulePtr shader_module = std::make_unique<ShaderModule>(
        GetContext(), *pShaderModule, shader_module_load_options, pCreateInfo->codeSize,
        reinterpret_cast<const char*>(pCreateInfo->pCode), GetContext()->GetOutputPath());

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

std::vector<VkCommandPool> Device::ReturnAndEraseCommandPools() {
    std::vector<VkCommandPool> command_pools;
    std::lock_guard<std::mutex> lock(helper_command_pools_mutex_);
    auto itr = helper_command_pools_.begin();
    while (itr != helper_command_pools_.end()) {
        command_pools.push_back(itr->second);
        itr = helper_command_pools_.erase(itr);
    }
    return command_pools;
}

//////////////////////////////////////
void Device::AddObjectInfo(uint64_t handle, ObjectInfoPtr info) {
    return object_info_db_.AddObjectInfo(handle, std::move(info));
}

void Device::AddExtraInfo(uint64_t handle, ExtraObjectInfo info) { return object_info_db_.AddExtraInfo(handle, info); }

std::string Device::GetObjectName(uint64_t handle, HandleDebugNamePreference handle_debug_name_preference) const {
    return object_info_db_.GetObjectName(handle, handle_debug_name_preference);
}

std::string Device::GetObjectInfo(uint64_t handle, const std::string& indent) const {
    return object_info_db_.GetObjectInfo(handle, indent);
}

std::string Device::GetObjectInfoNoHandleTag(uint64_t handle, const std::string& indent) const {
    return object_info_db_.GetObjectInfoNoHandleTag(handle, indent);
}

std::ostream& Device::Print(std::ostream& stream) const {
    std::ios_base::fmtflags f(stream.flags());

    const char* t = "\n  ";
    stream << "\nDevice:" << GetObjectInfo((uint64_t)vk_device_, t) << t << "deviceName: \""
           << physical_device_properties_.deviceName << "\"";

    auto majorVersion = VK_VERSION_MAJOR(physical_device_properties_.apiVersion);
    auto minorVersion = VK_VERSION_MINOR(physical_device_properties_.apiVersion);
    auto patchVersion = VK_VERSION_PATCH(physical_device_properties_.apiVersion);
    stream << t << "apiVersion: \"" << std::dec << majorVersion << "." << minorVersion << "." << patchVersion << " (0x"
           << std::hex << std::setfill('0') << std::setw(8) << physical_device_properties_.apiVersion << ")\"";

    stream << t << "driverVersion: \"" << std::hex << std::setfill('0') << std::setw(8)
           << physical_device_properties_.driverVersion << std::dec << " (" << physical_device_properties_.driverVersion
           << ")\"";
    stream << t << "vendorID: \"" << std::hex << std::setfill('0') << std::setw(8)
           << physical_device_properties_.vendorID << "\"";
    stream << t << "deviceID: \"" << std::hex << std::setfill('0') << std::setw(8)
           << physical_device_properties_.deviceID << "\"";

    stream << t << "deviceExtensions:";
    const char* tt = "\n    ";
    auto p_device_create_info = device_create_info_->original_create_info;
    for (uint32_t i = 0; i < p_device_create_info.enabledExtensionCount; ++i) {
        stream << tt << "- \"" << p_device_create_info.ppEnabledExtensionNames[i] << "\"";
    }
    stream << "\n";

    stream.flags(f);

    DumpDeviceFaultInfo(stream);

    return stream;
}

const char address_fault_strings[][32] = {
    "No Fault",
    "Invalid Read",
    "Invalid Write",
    "Invalid Execute",
    "Unknown Instruction Pointer",
    "Invalid Instruction Pointer",
    "Instruction Pointer Fault",
};

void Device::DumpDeviceFaultInfo(std::ostream& os) const {
    if (extensions_present_.ext_device_fault && nullptr != pfn_vkGetDeviceFaultInfoEXT) {
        VkDeviceFaultCountsEXT fault_counts = {VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT, nullptr, 0, 0, 0UL};
        VkResult result = pfn_vkGetDeviceFaultInfoEXT(vk_device_, &fault_counts, nullptr);
        if (result == VK_SUCCESS) {
            if (fault_counts.addressInfoCount > 0 || fault_counts.vendorInfoCount > 0 ||
                fault_counts.vendorBinarySize > 0) {
                std::vector<VkDeviceFaultAddressInfoEXT> address_infos;
                std::vector<VkDeviceFaultVendorInfoEXT> vendor_infos;
                std::vector<uint8_t> binary_data;
                address_infos.resize(fault_counts.addressInfoCount);
                vendor_infos.resize(fault_counts.vendorInfoCount);
                binary_data.resize(fault_counts.vendorBinarySize);
                VkDeviceFaultInfoEXT vk_device_fault_info{
                    VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT,
                    nullptr,
                    "",
                    fault_counts.addressInfoCount == 0 ? nullptr : address_infos.data(),
                    fault_counts.vendorInfoCount == 0 ? nullptr : vendor_infos.data(),
                    fault_counts.vendorBinarySize == 0 ? nullptr : reinterpret_cast<void*>(binary_data.data())};
                result = pfn_vkGetDeviceFaultInfoEXT(vk_device_, &fault_counts, &vk_device_fault_info);
                if (result == VK_SUCCESS || result == VK_INCOMPLETE) {
                    os << "  Device Fault Info:\n";
                    os << "    Description: " << vk_device_fault_info.description << "\n";
                    if (fault_counts.addressInfoCount > 0) {
                        os << "    Address Info: " << std::to_string(fault_counts.addressInfoCount) << "\n";
                        for (uint32_t addr = 0; addr < fault_counts.addressInfoCount; ++addr) {
                            VkDeviceAddress lower_address =
                                (address_infos[addr].reportedAddress & ~(address_infos[addr].addressPrecision - 1));
                            VkDeviceAddress upper_address =
                                (address_infos[addr].reportedAddress | (address_infos[addr].addressPrecision - 1));
                            os << "      [" << std::setfill(' ') << std::setw(4) << addr << "] "
                               << address_fault_strings[static_cast<uint32_t>(address_infos[addr].addressType)]
                               << " in address range [0x" << std::hex << lower_address << " - 0x" << std::hex
                               << upper_address << "]\n";
                        }
                    }
                    if (fault_counts.vendorInfoCount > 0) {
                        os << "    Vendor Info: " << std::to_string(fault_counts.vendorInfoCount) << "\n";
                        for (uint32_t vendor = 0; vendor < fault_counts.vendorInfoCount; ++vendor) {
                            os << "      [" << std::setfill(' ') << std::setw(4) << vendor << "] Code 0x" << std::hex
                               << vendor_infos[vendor].vendorFaultCode << " | Data 0x" << std::hex
                               << vendor_infos[vendor].vendorFaultData << " : " << vendor_infos[vendor].description
                               << "\n";
                        }
                    }
                    if (fault_counts.vendorBinarySize > 0) {
                        os << "    Vendor Binary Data: " << std::to_string(fault_counts.vendorBinarySize) << "\n";
                        for (uint32_t byte = 0; byte < fault_counts.vendorBinarySize; ++byte) {
                            os << "      0x" << std::hex << binary_data[byte] << "\n";
                        }
                    }
                }
            }
        }
    }
}

}  // namespace crash_diagnostic_layer
