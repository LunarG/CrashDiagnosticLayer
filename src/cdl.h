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
#include "submit_tracker.h"

namespace crash_diagnostic_layer {

// Return true if this is a VkResult that CDL considers an error.
constexpr bool IsVkError(VkResult result) {
    return result == VK_ERROR_DEVICE_LOST || result == VK_ERROR_INITIALIZATION_FAILED;
}
using StringArray = std::vector<std::string>;

struct DeviceCreateInfo {
    vku::safe_VkDeviceCreateInfo original;
    vku::safe_VkDeviceCreateInfo modified;
};

enum CrashSource {
    kDeviceLostError,
    kWatchdogTimer,
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

    Context(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator);
    virtual ~Context();

    VkInstance GetInstance() { return vk_instance_; }

    void MakeOutputPath();
    const std::filesystem::path& GetOutputPath() const;
    std::ofstream OpenDumpFile();

    Logger* GetLogger() { return &logger_; }
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
    void DumpDeviceExecutionState(VkDevice vk_device);
    void DumpDeviceExecutionState(const Device& device, bool dump_prologue, CrashSource crash_source,
                                  YAML::Emitter& os);
    void DumpDeviceExecutionState(const Device& device, std::string error_report, bool dump_prologue,
                                  CrashSource crash_source, YAML::Emitter& os);
    void DumpDeviceExecutionStateValidationFailed(const Device& device, YAML::Emitter& os);

    void DumpReportPrologue(YAML::Emitter& os);

    bool CountSubmit();

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

   private:
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
    int debug_autodump_rate_ = 0;
    bool debug_dump_all_command_buffers_ = false;
    bool debug_dump_shaders_on_crash_ = false;
    bool debug_dump_shaders_on_bind_ = false;

    int shader_module_load_options_ = ShaderModule::LoadOptions::kNone;

    bool instrument_all_commands_ = false;
    bool track_semaphores_ = false;
    bool trace_all_semaphores_ = false;

    // TODO some verbosity/trace modes?
    bool trace_all_ = false;

    bool output_path_created_ = false;
    std::filesystem::path base_output_path_;
    std::filesystem::path output_path_;
    std::string output_name_;

    bool log_configs_ = false;
    StringArray configs_;
    template <class T>
    void GetEnvVal(VkuLayerSettingSet settings, const char* name, T* value);
    void MakeDir(const std::filesystem::path& path);

    std::atomic<uint32_t> total_submits_ = 0;
    int total_logs_ = 0;

    // Watchdog
    // TODO we should have a way to shut this down, but currently the
    // CDL context never gets destroyed
    std::unique_ptr<std::thread> watchdog_thread_;
    std::atomic<bool> watchdog_running_;
    std::atomic<long long> last_submit_time_;
    uint64_t watchdog_timer_ms_ = 0;
};

}  // namespace crash_diagnostic_layer
