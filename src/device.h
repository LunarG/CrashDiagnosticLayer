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

#pragma once

#include <vulkan/vulkan.h>

#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#include <vector>
#include <yaml-cpp/emitter.h>

#include "command.h"
#include "command_pool.h"
#include "layer_base.h"
#include "marker.h"
#include "object_name_db.h"
#include "pipeline.h"
#include "semaphore_tracker.h"
#include "shader_module.h"
#include "submit_tracker.h"

#include <vulkan/utility/vk_sparse_range_map.hpp>

namespace crash_diagnostic_layer {

const VkDeviceSize kBufferMarkerEventCount = 1024;
const MarkerType kMarkerType = MarkerType::kUint32;

class Context;
struct DeviceCreateInfo;
class Logger;

// Options when dumping a command buffer to a log file.
typedef uint32_t CommandBufferDumpOptions;
struct CommandBufferDumpOption;

struct DeviceExtensionsPresent {
    bool amd_buffer_marker{false};
    bool amd_coherent_memory{false};
    bool ext_device_fault{false};
    bool ext_device_address_binding_report{false};
};

struct DeviceAddressRecord {
    VkDeviceAddress base;
    VkDeviceSize size;
    VkDeviceAddressBindingFlagsEXT flags;
    VkDeviceAddressBindingTypeEXT binding_type;
    VkObjectType object_type;
    uint64_t object_handle;
    std::string object_name;
    std::chrono::time_point<std::chrono::high_resolution_clock> when;
};

enum QueueOperationType {
    kQueueSubmit,
    kQueueBindSparse,
    kQueueSubmit2,
};

// Original bind sparse info with the submit tracker that tracks semaphores for
// the respective device.
struct PackedBindSparseInfo {
    const VkQueue queue;
    const uint32_t bind_info_count;
    const VkBindSparseInfo* bind_infos;
    SemaphoreTracker* semaphore_tracker;

    PackedBindSparseInfo(VkQueue queue_, uint32_t bind_info_count_, const VkBindSparseInfo* bind_infos_)
        : queue(queue_), bind_info_count(bind_info_count_), bind_infos(bind_infos_){};
};

// Expanded bind sparse info, including all the information needed to correctly
// insert semaphore tracking VkSubmitInfos between vkQueueBindSparse calls.
struct ExpandedBindSparseInfo {
    // Input: original bind sparse info.
    const PackedBindSparseInfo* packed_bind_sparse_info;
    // Vector of queue operation types, used to control interleaving order.
    std::vector<QueueOperationType> queue_operation_types;
    // Vector of submit info structs to be submitted to the queue.
    std::vector<VkSubmitInfo> submit_infos;
    // Vector of bool, specifying if a submit info includes a signal operation on
    // a timeline semaphore.
    std::vector<bool> has_timeline_semaphore_info;
    // Place holder for timeline semaphore infos used in queue submit infos.
    std::vector<VkTimelineSemaphoreSubmitInfoKHR> timeline_semaphore_infos;
    // Place holder for vectors of binary semaphores used in a wait semaphore
    // operation in a bind sparse info. This is needed since we need to signal
    // these semaphores in the same vkQueueSubmit that we consume them for
    // tracking (so the bind sparse info which is the real consumer of the
    // semaphore can proceed).
    std::vector<std::vector<VkSemaphore>> wait_binary_semaphores;

    ExpandedBindSparseInfo(PackedBindSparseInfo* packed_bind_sparse_info_)
        : packed_bind_sparse_info(packed_bind_sparse_info_){};
};

class Device {
   public:
    Device(Context& cdl, VkPhysicalDevice vk_gpu, VkDevice vk_device, DeviceExtensionsPresent& extensions_present);
    ~Device();
    void SetDeviceCreateInfo(std::unique_ptr<DeviceCreateInfo> device_create_info);

    Context& GetContext() const;
    VkPhysicalDevice GetVkGpu() const;
    VkDevice GetVkDevice() const;

    SubmitTracker* GetSubmitTracker() const { return submit_tracker_.get(); }
    SemaphoreTracker* GetSemaphoreTracker() const { return semaphore_tracker_.get(); }

    void AddObjectInfo(uint64_t handle, ObjectInfoPtr info);
    void AddExtraInfo(uint64_t handle, ExtraObjectInfo info);
    const ObjectInfoDB& GetObjectInfoDB() const { return object_info_db_; }
    std::string GetObjectName(uint64_t handle,
                              HandleDebugNamePreference handle_debug_name_preference = kReportBoth) const;
    std::string GetObjectInfo(uint64_t handle) const;
    std::string GetObjectInfoNoHandleTag(uint64_t handle) const;

    bool HasBufferMarker() const;

    const std::vector<VkQueueFamilyProperties>& GetVkQueueFamilyProperties() const;

    VkResult CreateBuffer(VkDeviceSize size, VkBuffer* p_buffer, void** cpu_mapped_address);

    VkResult AcquireMarkerBuffer();

    void CmdWriteBufferMarkerAMD(VkCommandBuffer commandBuffer, VkPipelineStageFlagBits pipelineStage,
                                 VkBuffer dstBuffer, VkDeviceSize dstOffset, uint32_t marker);

    void FreeCommandBuffers(VkCommandPool command_pool, uint32_t command_buffer_count,
                            const VkCommandBuffer* command_buffers);

    void AddCommandBuffer(VkCommandBuffer vk_command_buffer);

    bool ValidateCommandBufferNotInUse(CommandBuffer* p_cmd, YAML::Emitter& os);
    bool ValidateCommandBufferNotInUse(VkCommandBuffer vk_command_buffer, YAML::Emitter& os);
    void DeleteCommandBuffers(VkCommandPool vk_pool, const VkCommandBuffer* vk_cmds, uint32_t cb_count);

    void DumpCommandBuffers(YAML::Emitter& os, const char* section_name, CommandBufferDumpOptions options,
                            bool dump_all_command_buffers) const;
    void DumpAllCommandBuffers(YAML::Emitter& os, CommandBufferDumpOptions options) const;
    void DumpIncompleteCommandBuffers(YAML::Emitter& os, CommandBufferDumpOptions options) const;
    void DumpCommandBufferStateOnScreen(CommandBuffer* p_cmd, YAML::Emitter& os) const;

    void SetCommandPool(VkCommandPool vk_command_pool, CommandPoolPtr command_pool);
    CommandPool* GetCommandPool(VkCommandPool vk_command_pool);
    void AllocateCommandBuffers(VkCommandPool vk_command_pool, const VkCommandBufferAllocateInfo* allocate_info,
                                VkCommandBuffer* command_buffers);
    void ValidateCommandPoolState(VkCommandPool vk_command_pool, YAML::Emitter& os);
    void ResetCommandPool(VkCommandPool vk_command_pool);
    void DeleteCommandPool(VkCommandPool vk_command_pool);

    void CreatePipeline(uint32_t createInfoCount, const VkGraphicsPipelineCreateInfo* pCreateInfos,
                        VkPipeline* pPipelines);
    void CreatePipeline(uint32_t createInfoCount, const VkComputePipelineCreateInfo* pCreateInfos,
                        VkPipeline* pPipelines);
    const Pipeline* FindPipeline(VkPipeline pipeline) const;
    void DumpShaderFromPipeline(VkPipeline pipeline) const;
    void DeletePipeline(VkPipeline pipeline);

    void CreateShaderModule(const VkShaderModuleCreateInfo* pCreateInfo, VkShaderModule* pShaderModule,
                            int shader_module_load_options);
    const ShaderModule* FindShaderModule(VkShaderModule shader_module) const;
    void DeleteShaderModule(VkShaderModule shaderModule);

    void RegisterQueueFamilyIndex(VkQueue queue, uint32_t queueFamilyIndex);
    uint32_t GetQueueFamilyIndex(VkQueue queue);

    void RegisterHelperCommandPool(uint32_t queueFamilyIndex, VkCommandPool commandPool);
    VkCommandPool GetHelperCommandPool(uint32_t queueFamilyIndex);
    VkCommandPool GetHelperCommandPool(VkQueue queue);
    void EraseCommandPools();

    bool AllocateMarker(Marker* marker);
    void FreeMarker(const Marker marker);

    void DumpDeviceFaultInfo(YAML::Emitter& os) const;

    YAML::Emitter& Print(YAML::Emitter& stream) const;

    void MemoryBindEvent(const DeviceAddressRecord& record, bool multi_device);

    VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
    VkResult QueueSubmitWithoutTrackingSemaphores(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits,
                                                  VkFence fence);

    VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

    VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
    VkResult QueueSubmit2WithoutTrackingSemaphores(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                   VkFence fence);

    void PostSubmit(VkQueue queue, VkResult result);

    QueueSubmitId GetNextQueueSubmitId() { return ++queue_submit_index_; };
    void LogSubmitInfoSemaphores(VkQueue vk_queue, SubmitInfoId submit_info_id);
    void StoreSubmitHelperCommandBuffersInfo(SubmitInfoId submit_info_id, VkCommandPool vk_pool,
                                             VkCommandBuffer start_marker_cb, VkCommandBuffer end_marker_cb);

    VkResult RecordSubmitStart(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id,
                               VkCommandBuffer vk_command_buffer);

    VkResult RecordSubmitFinish(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id,
                                VkCommandBuffer vk_command_buffer);

    QueueBindSparseId GetNextQueueBindSparseId() { return ++queue_bind_sparse_index_; };

    VkResult RecordBindSparseHelperSubmit(QueueBindSparseId qbind_sparse_id, const VkSubmitInfo* vk_submit_info,
                                          VkCommandPool vk_pool);

    bool ShouldExpandQueueBindSparseToTrackSemaphores(PackedBindSparseInfo* packed_bind_sparse_info);
    void ExpandBindSparseInfo(ExpandedBindSparseInfo* bind_sparse_expand_info);
    void LogBindSparseInfosSemaphores(VkQueue vk_queue, uint32_t bind_info_count, const VkBindSparseInfo* bind_infos);

    const Logger& Log() const;

    std::vector<VkCommandBuffer> AllocHelperCBs(VkCommandPool vk_command_pool, uint32_t count);

   private:
    Context& context_;
    InstanceDispatchTable instance_dispatch_table_;
    DeviceDispatchTable device_dispatch_table_;
    VkPhysicalDevice vk_physical_device_ = VK_NULL_HANDLE;
    VkDevice vk_device_ = VK_NULL_HANDLE;
    std::vector<VkQueueFamilyProperties> queue_family_properties_;
    VkPhysicalDeviceMemoryProperties memory_properties_ = {};
    VkPhysicalDeviceProperties physical_device_properties_ = {};
    DeviceExtensionsPresent extensions_present_{};

    SubmitTrackerPtr submit_tracker_;
    SemaphoreTrackerPtr semaphore_tracker_;

    std::unique_ptr<DeviceCreateInfo> device_create_info_;

    ObjectInfoDB object_info_db_;

    mutable std::recursive_mutex command_buffers_mutex_;
    std::vector<VkCommandBuffer> command_buffers_;

    std::mutex command_pools_mutex_;
    std::unordered_map<VkCommandPool, CommandPoolPtr> command_pools_;

    mutable std::mutex pipelines_mutex_;
    std::unordered_map<VkPipeline, PipelinePtr> pipelines_;

    mutable std::mutex shader_modules_mutex_;
    std::unordered_map<VkShaderModule, ShaderModulePtr> shader_modules_;

    // Tracks the queue index family used when creating queues. We need this info
    // to use a proper command pool when we create helper command buffers to
    // track the state of submits and semaphores.
    mutable std::mutex queue_family_index_trackers_mutex_;
    std::unordered_map<VkQueue, uint32_t /* queueFamilyIndex */> queue_family_index_trackers_;

    mutable std::mutex helper_command_pools_mutex_;
    std::unordered_map<uint32_t /* queueFamilyIndex */, VkCommandPool> helper_command_pools_;

    struct MarkerBuffer {
        VkDeviceSize size = 0;
        VkBuffer buffer = VK_NULL_HANDLE;
        void* cpu_mapped_address = nullptr;
        VkDeviceSize heap_offset = 0;
    };

    VkDeviceMemory marker_buffers_heap_ = VK_NULL_HANDLE;
    void* marker_buffers_heap_mapped_base_ = nullptr;
    VkDeviceSize current_heap_offset_ = 0;

    std::mutex marker_buffers_mutex_;
    std::vector<MarkerBuffer> marker_buffers_;
    uint32_t current_marker_index_ = 0;

    std::mutex recycled_markers_u32_mutex_;
    std::vector<Marker> recycled_markers_u32_;

    std::mutex recycled_markers_u64_mutex_;
    std::vector<Marker> recycled_markers_u64_;

    PFN_vkCmdWriteBufferMarkerAMD pfn_vkCmdWriteBufferMarkerAMD_ = nullptr;
    PFN_vkFreeCommandBuffers pfn_vkFreeCommandBuffers_ = nullptr;

    PFN_vkGetDeviceFaultInfoEXT pfn_vkGetDeviceFaultInfoEXT = nullptr;

    vku::sparse::range_map<VkDeviceAddress, DeviceAddressRecord> address_map_;

    std::atomic<QueueSubmitId> queue_submit_index_{0};
    std::atomic<QueueBindSparseId> queue_bind_sparse_index_{0};
};

}  // namespace crash_diagnostic_layer
