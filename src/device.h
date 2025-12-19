/*
 Copyright 2018 Google Inc.
 Copyright 2023-2025 LunarG, Inc.

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
#include "queue.h"
#include "semaphore_tracker.h"
#include "shader_module.h"
#include "watchdog.h"

#include <vulkan/utility/vk_sparse_range_map.hpp>

namespace crash_diagnostic_layer {

class CheckpointMgr;
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
    bool nv_device_diagnostic_checkpoints{false};
    bool khr_timeline_semaphore{false};
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

class Device {
   public:
    using QueuePtr = std::shared_ptr<Queue>;
    using ConstQueuePtr = std::shared_ptr<const Queue>;

    Device(Context& cdl, VkPhysicalDevice vk_gpu, VkDevice vk_device, DeviceExtensionsPresent& extensions_present,
           std::unique_ptr<DeviceCreateInfo> dci);
    Device(Device&) = delete;
    Device& operator=(Device&) = delete;
    void Destroy();
    ~Device();

    bool HangDetected() const { return hang_detected_; }
    void DeviceFault();
    void WatchdogTimeout();

    const Logger& Log() const;
    const DeviceDispatchTable& Dispatch() const { return device_dispatch_table_; }

    Context& GetContext() const;
    VkPhysicalDevice GetVkGpu() const;
    VkDevice GetVkDevice() const;

    SemaphoreTracker* GetSemaphoreTracker() const { return semaphore_tracker_.get(); }

    void AddObjectInfo(uint64_t handle, VkObjectType type, const char* name);
    void AddExtraInfo(uint64_t handle, ExtraObjectInfo info);
    const ObjectInfoDB& GetObjectInfoDB() const { return object_info_db_; }
    std::string GetObjectName(uint64_t handle,
                              HandleDebugNamePreference handle_debug_name_preference = kReportBoth) const;
    std::string GetObjectInfo(uint64_t handle) const;

    bool HasCheckpoints() const;
    std::unique_ptr<Checkpoint> AllocateCheckpoint(uint32_t initial_value);

    VkResult CreateBuffer(VkDeviceSize size, VkBuffer* p_buffer, void** cpu_mapped_address);

    void FreeCommandBuffers(VkCommandPool command_pool, uint32_t command_buffer_count,
                            const VkCommandBuffer* command_buffers);

    void AddCommandBuffer(VkCommandBuffer vk_command_buffer);

    bool ValidateCommandBufferNotInUse(CommandBuffer* p_cmd, YAML::Emitter& os);
    bool ValidateCommandBufferNotInUse(VkCommandBuffer vk_command_buffer, YAML::Emitter& os);
    void DeleteCommandBuffers(VkCommandPool vk_pool, const VkCommandBuffer* vk_cmds, uint32_t cb_count);

    void DumpCommandBuffers(YAML::Emitter& os) const;
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

    void RegisterQueue(VkQueue queue, uint32_t queueFamilyIndex, uint32_t queueIndex);
    QueuePtr GetQueue(VkQueue queue);
    ConstQueuePtr GetQueue(VkQueue queue) const;

    std::vector<QueuePtr> GetAllQueues();
    std::vector<ConstQueuePtr> GetAllQueues() const;

    void EraseCommandPools();

    void DumpDeviceFaultInfo(YAML::Emitter& os) const;

    YAML::Emitter& Print(YAML::Emitter& os, const std::string& error_report);

    void MemoryBindEvent(const DeviceAddressRecord& record, bool multi_device);

    VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

    VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

    VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

    bool UpdateIdleState();

    void UpdateWatchdog() { watchdog_.Update(); }

   private:
    Context& context_;
    DeviceDispatchTable device_dispatch_table_;
    VkPhysicalDevice vk_physical_device_{VK_NULL_HANDLE};
    VkDevice vk_device_{VK_NULL_HANDLE};
    VkPhysicalDeviceProperties physical_device_properties_{};
    DeviceExtensionsPresent extensions_present_{};

    Watchdog watchdog_;
    std::atomic<bool> hang_detected_{false};

    std::vector<VkQueueFamilyProperties> queue_family_properties_;

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

    mutable std::mutex queues_mutex_;
    std::unordered_map<VkQueue, QueuePtr> queues_;

    vku::sparse::range_map<VkDeviceAddress, DeviceAddressRecord> address_map_;

    std::unique_ptr<CheckpointMgr> checkpoints_;

    VkDebugUtilsMessengerEXT utils_messenger_ = VK_NULL_HANDLE;
};

}  // namespace crash_diagnostic_layer
