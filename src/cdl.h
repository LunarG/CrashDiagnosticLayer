/*
 Copyright 2018 Google Inc.
 Copyright (c) 2023-2024 LunarG, Inc.

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
#include <vulkan/layer/vk_layer_settings.hpp>
#include <vulkan/utility/vk_struct_helper.hpp>
#include <vulkan/utility/vk_safe_struct.hpp>

#if defined(SYSTEM_TARGET_ANDROID) || defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) || \
    defined(SYSTEM_TARGET_BSD)
#include <sys/syscall.h>
#include <unistd.h>
#endif  // defined(SYSTEM_TARGET_ANDROID) || defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) ||
        // defined(SYSTEM_TARGET_BSD)

#include <atomic>
#include <cassert>
#include <chrono>
#include <filesystem>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>
#include <yaml-cpp/emitter.h>

#include "bind_sparse_utils.h"
#include "command.h"
#include "command_buffer_tracker.h"
#include "device.h"
#include "layer_base.h"
#include "logger.h"
#include "system.h"

namespace crash_diagnostic_layer {

// Return true if this is a VkResult that CDL considers an error.
constexpr bool IsVkError(VkResult result) {
    return result == VK_ERROR_DEVICE_LOST || result == VK_ERROR_INITIALIZATION_FAILED;
}

struct DeviceCreateInfo {
    vku::safe_VkDeviceCreateInfo original;
    vku::safe_VkDeviceCreateInfo modified;
};

enum CrashSource {
    kDeviceLostError,
    kWatchdogTimer,
};

enum DumpShaders {
    kOff = 0,
    kOnCrash,
    kOnBind,
    kAll,
};

static inline void NewHandler() {
    std::cout << "CDL: Memory allocation failed!" << std::endl;
    std::cerr << "CDL: Memory allocation failed!" << std::endl;
    std::set_new_handler(nullptr);
}

template <typename T, typename... Args>
T* New(Args&&... args) {
    std::set_new_handler(NewHandler);
    return new T(std::forward<Args>(args)...);
}

template <typename T, typename... Args>
T* NewArray(size_t size) {
    std::set_new_handler(NewHandler);
    return new T[size];
}

class Context : public Interceptor {
   public:
    using DevicePtr = std::shared_ptr<Device>;
    using ConstDevicePtr = std::shared_ptr<const Device>;
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    Context(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator);
    Context(Context&) = delete;
    Context& operator=(Context&) = delete;
    virtual ~Context();

    const InstanceDispatchTable& Dispatch() { return instance_dispatch_table_; }
    VkInstance GetInstance() { return vk_instance_; }

    const std::filesystem::path& GetOutputPath() const;
    std::ofstream OpenDumpFile();
    const Logger& Log() const { return logger_; }

    const ShaderModule* FindShaderModule(VkShaderModule shader) const;

    DevicePtr GetDevice(VkDevice);
    ConstDevicePtr GetDevice(VkDevice) const;

    std::vector<DevicePtr> GetAllDevices();
    std::vector<ConstDevicePtr> GetAllDevices() const;

    DevicePtr GetQueueDevice(VkQueue);
    ConstDevicePtr GetQueueDevice(VkQueue) const;

    bool DumpShadersOnCrash() const;
    bool DumpShadersOnBind() const;

    bool TrackingSemaphores() const { return track_semaphores_; };
    bool TracingAllSemaphores() const { return trace_all_semaphores_; };
    bool InstrumentAllCommands() const { return instrument_all_commands_; };

    void MemoryBindEvent(const VkDeviceAddressBindingCallbackDataEXT& mem_info,
                         const VkDebugUtilsObjectNameInfoEXT& object);

    void DumpAllDevicesExecutionState(CrashSource crash_source);
    void DumpDeviceExecutionState(const Device& device);
    void DumpDeviceExecutionState(const Device& device, bool dump_prologue, CrashSource crash_source,
                                  YAML::Emitter& os);
    void DumpDeviceExecutionState(const Device& device, const std::string& error_report, bool dump_prologue,
                                  CrashSource crash_source, YAML::Emitter& os);
    void DumpDeviceExecutionStateValidationFailed(const Device& device, YAML::Emitter& os);

    void DumpReportPrologue(YAML::Emitter& os);

   private:
    void StartWatchdogTimer();
    void StopWatchdogTimer();
    void WatchdogTimer();

    void ValidateCommandBufferNotInUse(CommandBuffer* commandBuffer);

   public:
    void PreApiFunction(const char* api_name);
    void PostApiFunction(const char* api_name);
    void PostApiFunction(const char* api_name, VkResult result);

    const VkInstanceCreateInfo* GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo* pCreateInfo) override;
    const VkDeviceCreateInfo* GetModifiedDeviceCreateInfo(VkPhysicalDevice physicalDevice,
                                                          const VkDeviceCreateInfo* pCreateInfo) override;

    const DeviceExtensionsPresent& EnabledExtensions(VkPhysicalDevice physicalDevice) {
        return extensions_of_interest_enabled_[physicalDevice];
    }

#include "cdl_commands.h.inc"

    VkResult PostCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                VkInstance* pInstance, VkResult result) override;

    void PreDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) override;

    VkResult PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                              const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult result) override;

    void PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) override;
    void PostDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) override;

    VkResult PostEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                    uint32_t* pPropertyCount, VkExtensionProperties* pProperties,
                                                    VkResult result) override;

    void PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) override;

    VkResult QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) override;

    VkResult PreQueueWaitIdle(VkQueue queue) override;
    VkResult PostQueueWaitIdle(VkQueue queue, VkResult result) override;

    VkResult PreDeviceWaitIdle(VkDevice device) override;
    VkResult PostDeviceWaitIdle(VkDevice device, VkResult result) override;

    VkResult QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                             VkFence fence) override;

    VkResult PreGetFenceStatus(VkDevice device, VkFence fence) override;
    VkResult PostGetFenceStatus(VkDevice device, VkFence fence, VkResult result) override;

    VkResult PreWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                              uint64_t timeout) override;
    VkResult PostWaitForFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll,
                               uint64_t timeout, VkResult result) override;

    VkResult PostCreateSemaphore(VkDevice device, const VkSemaphoreCreateInfo* pCreateInfo,
                                 const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                 VkResult result) override;

    void PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) override;
    void PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) override;

    VkResult PreGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                    size_t dataSize, void* pData, VkDeviceSize stride,
                                    VkQueryResultFlags flags) override;
    VkResult PostGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount,
                                     size_t dataSize, void* pData, VkDeviceSize stride, VkQueryResultFlags flags,
                                     VkResult result) override;

    VkResult PostCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                    const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                    VkResult result) override;

    void PostDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                 const VkAllocationCallbacks* pAllocator) override;

    VkResult PostCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                         const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                         const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                         VkResult result) override;

    VkResult PostCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                        const VkComputePipelineCreateInfo* pCreateInfos,
                                        const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                        VkResult result) override;

    void PostDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) override;

    VkResult PreCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                  const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) override;
    VkResult PostCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                   VkResult result) override;

    void PreDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                               const VkAllocationCallbacks* pAllocator) override;
    void PostDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                const VkAllocationCallbacks* pAllocator) override;

    VkResult PreResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) override;
    VkResult PostResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                  VkResult result) override;

    VkResult PreAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                       VkCommandBuffer* pCommandBuffers) override;
    VkResult PostAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                        VkCommandBuffer* pCommandBuffers, VkResult result) override;

    void PreFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                               const VkCommandBuffer* pCommandBuffers) override;
    void PostFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                const VkCommandBuffer* pCommandBuffers) override;

    void PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) override;

    VkResult QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) override;

    VkResult PreAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore,
                                    VkFence fence, uint32_t* pImageIndex) override;
    VkResult PostAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore,
                                     VkFence fence, uint32_t* pImageIndex, VkResult result) override;

    VkResult PreQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo) override;
    VkResult PostQueuePresentKHR(VkQueue queue, const VkPresentInfoKHR* pPresentInfo, VkResult result) override;

    VkResult PostGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                             VkResult result) override;

    VkResult PreWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout) override;
    VkResult PostWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfo* pWaitInfo, uint64_t timeout,
                                   VkResult result) override;

    VkResult PostSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfo* pSignalInfo,
                                    VkResult result) override;

    VkResult QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                             VkFence fence) override;

    VkResult PostCreateDebugReportCallbackEXT(VkInstance instance,
                                              const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkDebugReportCallbackEXT* pCallback, VkResult result) override;

    void PreDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                          const VkAllocationCallbacks* pAllocator) override;

    VkResult PreDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) override;
    VkResult PreSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) override;
    VkResult PostCreateDebugUtilsMessengerEXT(VkInstance instance,
                                              const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkDebugUtilsMessengerEXT* pMessenger, VkResult result) override;

    void PreDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                          const VkAllocationCallbacks* pAllocator) override;

   private:
    template <class T>
    void GetEnvVal(VkuLayerSettingSet settings, const char* name, T& value);

    TimePoint start_time_;
    Logger logger_;
    System system_;

    VkInstance vk_instance_ = VK_NULL_HANDLE;
    vku::safe_VkInstanceCreateInfo original_create_info_;
    vku::safe_VkInstanceCreateInfo modified_create_info_;

    InstanceDispatchTable instance_dispatch_table_;

    std::unordered_map<VkPhysicalDevice, DeviceExtensionsPresent> extensions_of_interest_present_;
    std::unordered_map<VkPhysicalDevice, DeviceExtensionsPresent> extensions_of_interest_enabled_;

    mutable std::mutex device_create_infos_mutex_;
    std::unordered_map<const VkDeviceCreateInfo* /*modified_create_info*/, std::unique_ptr<DeviceCreateInfo>>
        device_create_infos_;

    struct ApplicationInfo {
        std::string applicationName;
        uint32_t applicationVersion;

        std::string engineName;
        uint32_t engineVersion;
        uint32_t apiVersion;
    };

    std::unique_ptr<ApplicationInfo> application_info_;

    VkDebugUtilsMessengerEXT utils_messenger_ = VK_NULL_HANDLE;

    mutable std::mutex devices_mutex_;
    std::unordered_map<VkDevice, DevicePtr> devices_;

    // Tracks VkDevice that a VkQueue belongs to. This is needed when tracking
    // semaphores in vkQueueBindSparse, for which we need to allocate new command
    // buffers from the device that owns the queue. This is valid since VkQueue is
    // an opaque handle, since guaranteed to be unique.
    mutable std::mutex queue_device_tracker_mutex_;
    std::unordered_map<VkQueue, VkDevice> queue_device_tracker_;

    // Debug flags
    bool debug_dump_all_command_buffers_ = false;
    DumpShaders dump_shaders_{DumpShaders::kOff};

    int shader_module_load_options_ = ShaderModule::LoadOptions::kNone;

    bool instrument_all_commands_ = false;
    bool track_semaphores_ = false;
    bool trace_all_semaphores_ = false;

    bool trace_all_ = false;

    std::filesystem::path base_output_path_;
    std::filesystem::path output_path_;
    int total_logs_ = 0;

    bool dump_configs_ = false;
    std::vector<std::pair<std::string, std::string>> configs_;

    // Watchdog
    std::unique_ptr<std::thread> watchdog_thread_;
    std::atomic<bool> watchdog_running_;
    std::atomic<long long> last_submit_time_;
    uint64_t watchdog_timer_ms_ = 0;
};

}  // namespace crash_diagnostic_layer
