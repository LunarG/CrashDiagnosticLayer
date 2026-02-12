/*
 Copyright 2018 Google Inc.
 Copyright (c) 2023-2026 LunarG, Inc.

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

#include "cdl.h"
#include "util.h"

#if defined(VK_USE_PLATFORM_WIN32_KHR)
// For OutputDebugString
#include <process.h>
#include <windows.h>
#include <direct.h>
#endif

#include <algorithm>
#include <fstream>
#include <inttypes.h>
#include <iostream>
#include <memory>
#include <sstream>

#include <vulkan/vk_enum_string_helper.h>

#include <yaml-cpp/emitter.h>

namespace crash_diagnostic_layer {

// =============================================================================
// Context
// =============================================================================
Context::Context(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator)
    : logger_(std::chrono::system_clock::now()), system_(*this) {
    settings_.emplace(pCreateInfo, pAllocator, logger_);

    // trace mode
    {
        // setup shader loading modes
        shader_module_load_options_ = ShaderModule::LoadOptions::kNone;
        switch (settings_->dump_shaders) {
            case DumpShaders::kAll:
                shader_module_load_options_ |= ShaderModule::LoadOptions::kDumpOnCreate;
                break;
            case DumpShaders::kOnCrash:
            case DumpShaders::kOnBind:
                shader_module_load_options_ |= ShaderModule::LoadOptions::kKeepInMemory;
                break;
            default:
                break;
        }
    }
}

Context::~Context() { logger_.CloseLogFile(); }

Context::DevicePtr Context::GetDevice(VkDevice device) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

Context::ConstDevicePtr Context::GetDevice(VkDevice device) const {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

std::vector<Context::DevicePtr> Context::GetAllDevices() {
    std::vector<DevicePtr> devs;
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devs.reserve(devices_.size());
    for (auto& entry : devices_) {
        devs.push_back(entry.second);
    }
    return devs;
}

std::vector<Context::ConstDevicePtr> Context::GetAllDevices() const {
    std::vector<ConstDevicePtr> devs;
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devs.resize(devices_.size());
    for (auto& entry : devices_) {
        devs.push_back(entry.second);
    }
    return devs;
}

Context::DevicePtr Context::GetQueueDevice(VkQueue queue) {
    VkDevice device;
    {
        std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
        auto iter = queue_device_tracker_.find(queue);
        if (iter == queue_device_tracker_.end()) {
            return nullptr;
        }
        device = iter->second;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

Context::ConstDevicePtr Context::GetQueueDevice(VkQueue queue) const {
    VkDevice device;
    {
        std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
        auto iter = queue_device_tracker_.find(queue);
        if (iter == queue_device_tracker_.end()) {
            return nullptr;
        }
        device = iter->second;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto iter = devices_.find(device);
    return iter != devices_.end() ? iter->second : nullptr;
}

void Context::PreApiFunction(const char* api_name) {
    if (settings_->log_message_areas & MESSAGE_AREA_COMMON_BIT) {
        Log().Info("{ %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name) {
    if (settings_->log_message_areas & MESSAGE_AREA_COMMON_BIT) {
        Log().Info("} %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name, VkResult result) {
    if (settings_->log_message_areas & MESSAGE_AREA_COMMON_BIT) {
        Log().Info("} %s (%s)", api_name, string_VkResult(result));
    }
}

struct RequiredExtension {
    char name[VK_MAX_EXTENSION_NAME_SIZE];
    bool enabled;
    bool* enabled_member;
};

const VkInstanceCreateInfo* Context::GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo* pCreateInfo) {
    const uint32_t required_extension_count = 2;
    RequiredExtension required_extensions[] = {
        {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, false, nullptr},
        {VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME, false, nullptr},
    };

    original_create_info_.initialize(pCreateInfo);
    modified_create_info_ = original_create_info_;

    for (uint32_t j = 0; j < required_extension_count; ++j) {
        vku::AddExtension(modified_create_info_, required_extensions[j].name);
    }
    return modified_create_info_.ptr();
}

static void DecodeExtensionString(DeviceExtensionsPresent& extensions, const char* name) {
    if (!strcmp(name, VK_AMD_BUFFER_MARKER_EXTENSION_NAME)) {
        extensions.amd_buffer_marker = true;
    } else if (!strcmp(name, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME)) {
        extensions.amd_coherent_memory = true;
    } else if (!strcmp(name, VK_EXT_DEVICE_FAULT_EXTENSION_NAME)) {
        extensions.ext_device_fault = true;
    } else if (!strcmp(name, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME)) {
        extensions.ext_device_address_binding_report = true;
    } else if (!strcmp(name, VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME)) {
        extensions.nv_device_diagnostic_checkpoints = true;
    } else if (!strcmp(name, VK_KHR_DYNAMIC_RENDERING_EXTENSION_NAME)) {
        extensions.khr_dynamic_rendering = true;
    } else if (!strcmp(name, VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME)) {
        extensions.khr_timeline_semaphore = true;
    }
}

static DeviceExtensionsPresent DecodeExtensionStrings(uint32_t count, const char* const* names) {
    DeviceExtensionsPresent extensions{};

    for (uint32_t i = 0; i < count; ++i) {
        DecodeExtensionString(extensions, names[i]);
    }
    return extensions;
}
template <typename T>
void Context::QueryFeature(VkPhysicalDevice physicalDevice, T *feature) {
    auto features2 = vku::InitStruct<VkPhysicalDeviceFeatures2>(feature);
    if (modified_create_info_.pApplicationInfo &&
        modified_create_info_.pApplicationInfo->apiVersion >= VK_API_VERSION_1_1) {
        Dispatch().GetPhysicalDeviceFeatures2(physicalDevice, &features2);
    } else {
        Dispatch().GetPhysicalDeviceFeatures2KHR(physicalDevice, &features2);
    }
}

const VkDeviceCreateInfo* Context::GetModifiedDeviceCreateInfo(VkPhysicalDevice physicalDevice,
                                                               const VkDeviceCreateInfo* pCreateInfo) {
    DeviceExtensionsPresent extensions_present{};
    {
        // Get the list of device extensions.
        uint32_t extension_count = 0;
        std::vector<VkExtensionProperties> properties;
        Dispatch().EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extension_count, nullptr);
        properties.resize(extension_count);
        Dispatch().EnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extension_count, properties.data());

        for (const auto& prop : properties) {
            DecodeExtensionString(extensions_present, prop.extensionName);
        }
    }
    auto extensions_enabled =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    auto device_ci = std::make_unique<DeviceCreateInfo>();
    device_ci->original.initialize(pCreateInfo);
    device_ci->modified = device_ci->original;

    const uint32_t api_version = modified_create_info_.pApplicationInfo
                                     ? modified_create_info_.pApplicationInfo->apiVersion
                                     : VK_API_VERSION_1_0;

    Log().Verbose("The Vulkan application is using Vulkan %d.%d", VK_API_VERSION_MAJOR(api_version), VK_API_VERSION_MINOR(api_version));

    // If an important extension is not enabled by default, try to enable it if it is present
    if (extensions_present.nv_device_diagnostic_checkpoints) {
        if (!extensions_enabled.nv_device_diagnostic_checkpoints) {
            // NOTE: this extension does not have a feature struct
            extensions_enabled.nv_device_diagnostic_checkpoints = true;
            vku::AddExtension(device_ci->modified, VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS_EXTENSION_NAME);
        }
    }
    if (extensions_present.amd_buffer_marker) {
        if (!extensions_enabled.amd_buffer_marker) {
            // NOTE: this extension does not have a feature struct
            extensions_enabled.amd_buffer_marker = true;
            vku::AddExtension(device_ci->modified, VK_AMD_BUFFER_MARKER_EXTENSION_NAME);
        }
        if (extensions_present.amd_coherent_memory) {
            auto amd_device_coherent = vku::InitStruct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(nullptr);
            QueryFeature(physicalDevice, &amd_device_coherent);
            if (amd_device_coherent.deviceCoherentMemory) {
                auto *existing = vku::FindStructInPNextChain<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(&device_ci->modified);
                if (existing) {
                    existing->deviceCoherentMemory = amd_device_coherent.deviceCoherentMemory;
                } else {
                    vku::AddToPnext(device_ci->modified, amd_device_coherent);
                    if (!extensions_enabled.amd_coherent_memory) {
                        vku::AddExtension(device_ci->modified, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME);
                    }
                }
            }
        } else {
            Log().Warning("No device support for VK_AMD_device_coherent_memory extension, results may not be as accurate as possible.");
        }
    } else {
        Log().Warning("No device support for VK_AMD_buffer_marker extension, semaphore tracking will be disabled.");
    }
    if (!extensions_present.nv_device_diagnostic_checkpoints && !extensions_present.amd_buffer_marker) {
        Log().Warning(
            "No device support for VK_NV_device_diagnostic_checkpoints or VK_AMD_buffer_marker extension, progression tracking will be "
            "disabled.");
    }
    if (extensions_present.ext_device_fault) {
        if (!extensions_enabled.ext_device_fault) {
            auto ext_device_fault = vku::InitStruct<VkPhysicalDeviceFaultFeaturesEXT>(nullptr);
            QueryFeature(physicalDevice, &ext_device_fault);
            if (ext_device_fault.deviceFault) {
                auto *existing = vku::FindStructInPNextChain<VkPhysicalDeviceFaultFeaturesEXT>(&device_ci->modified);
                if (existing) {
                    existing->deviceFault = ext_device_fault.deviceFault;
                    existing->deviceFaultVendorBinary = ext_device_fault.deviceFaultVendorBinary;
                } else {
                    vku::AddToPnext(device_ci->modified, ext_device_fault);
                    if (!extensions_enabled.ext_device_fault) {
                        vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_FAULT_EXTENSION_NAME);
                    }
                }
            }
        }
    } else {
        Log().Warning("No device support for VK_EXT_device_fault extension, vendor-specific crash dumps will not be available.");
    }
    if (extensions_present.ext_device_address_binding_report) {
        auto ext_dbar = vku::InitStruct<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(nullptr);
        QueryFeature(physicalDevice, &ext_dbar);
        if (ext_dbar.reportAddressBinding) {
            auto *existing = vku::FindStructInPNextChain<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(&device_ci->modified);
            if (existing) {
                existing->reportAddressBinding = ext_dbar.reportAddressBinding;
            } else {
                vku::AddToPnext(device_ci->modified, ext_dbar);
                if (!extensions_enabled.ext_device_address_binding_report) {
                    vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME);
                }
            }
        }
    } else {
        Log().Warning(
            "No device support for VK_EXT_device_address_binding_report extension, DeviceAddress information will not be available.");
    }

    bool device_has_dynamic_rendering = true;

    if (extensions_present.khr_dynamic_rendering) {
        auto khr_dynamic_rendering = vku::InitStruct<VkPhysicalDeviceDynamicRenderingFeaturesKHR>(nullptr);
        QueryFeature(physicalDevice, &khr_dynamic_rendering);

        if (!khr_dynamic_rendering.dynamicRendering) {
            device_has_dynamic_rendering = false;
        }
    } else {
        device_has_dynamic_rendering = false;
    }

    if (!device_has_dynamic_rendering) {
        Log().Error(
            "No device support for VK_KHR_dynamic_rendering extension, Vulkan 1.3 or VK_KHR_dynamic_rendering are required by the Crash Diagnostic layer.");
    }

    if (!extensions_enabled.khr_dynamic_rendering && api_version < VK_API_VERSION_1_3) {
        Log().Error(
            "The Vulkan application did not enabled the VK_KHR_dynamic_rendering extension or Vulkan 1.3. To use the Crash Diagnostics layer, the application must use Dynamic Rendering only instead of RenderPass which is a Vulkan Legacy feature not supported by the Crash Diagnostic layer.");
    }

    if (extensions_present.khr_timeline_semaphore) {
        auto khr_timeline_semaphore = vku::InitStruct<VkPhysicalDeviceTimelineSemaphoreFeaturesKHR>(nullptr);
        QueryFeature(physicalDevice, &khr_timeline_semaphore);

        if (khr_timeline_semaphore.timelineSemaphore) {
            auto* vulkan12_features = vku::FindStructInPNextChain<VkPhysicalDeviceVulkan12Features>(&device_ci->modified);
            auto* existing = vku::FindStructInPNextChain<VkPhysicalDeviceTimelineSemaphoreFeaturesKHR>(&device_ci->modified);
            if (vulkan12_features) {
                vulkan12_features->timelineSemaphore = VK_TRUE;
            } else if (existing) {
                existing->timelineSemaphore = VK_TRUE;
            } else {
                vku::AddToPnext(device_ci->modified, khr_timeline_semaphore);
                if (api_version < VK_API_VERSION_1_2 && !extensions_enabled.khr_timeline_semaphore) {
                    vku::AddExtension(device_ci->modified, VK_KHR_TIMELINE_SEMAPHORE_EXTENSION_NAME);
                }
            }
        }
    } else {
        Log().Error(
            "No device support for VK_KHR_timeline_semaphore extension, Vulkan 1.2 or VK_KHR_timeline_semaphore are required to track queue "
            "progress, enabling early device lost detection.");
    }

    // save the raw ptr before std::move of the std::unique_ptr
    const auto* ci_ptr = device_ci->modified.ptr();
    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device_create_infos_[ci_ptr] = std::move(device_ci);
    }

    return ci_ptr;
}

void Context::DumpDeviceExecutionState(Device& device, CrashSource cs) {
    auto file = OpenDumpFile();
    YAML::Emitter os(file.is_open() ? file : std::cerr);
    DumpDeviceExecutionState(device, {}, true, cs, os);
}

void Context::DumpDeviceExecutionState(Device& device, const std::string& error_report, bool dump_prologue,
                                       CrashSource crash_source, YAML::Emitter& os) {
    if (dump_prologue) {
        DumpReportPrologue(os);
    }

    device.Print(os, error_report);
}

void Context::DumpDeviceExecutionStateValidationFailed(Device& device, YAML::Emitter& os) {
    if (device.HangDetected()) {
        return;
    }
#if 0
    // We force all command buffers to dump here because validation can be
    // from a race condition and the GPU can complete work by the time we've
    // started writing the log. (Seen in practice, not theoretical!)
    auto dump_all = debug_dump_all_command_buffers_;
    debug_dump_all_command_buffers_ = true;
    std::stringstream error_report;
    error_report << os.c_str();  // TODO does this do what we want?
    DumpDeviceExecutionState(device, error_report.str(), true /* dump_prologue */, CrashSource::kDeviceLostError, os);
    debug_dump_all_command_buffers_ = dump_all;
#endif
}

void Context::DumpReportPrologue(YAML::Emitter& os) {
    auto elapsed = std::chrono::system_clock::now() - this->settings_->start_time;
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;
    os << YAML::Comment("-                    CRASH DIAGNOSTIC LAYER                    -") << YAML::Newline;
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;
    os << YAML::BeginMap;
    os << YAML::Key << "version" << YAML::Value << kCdlVersion;
    std::stringstream timestr;
    auto in_time_t = std::chrono::system_clock::to_time_t(this->settings_->start_time);
    timestr << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    os << YAML::Key << "startTime" << YAML::Value << timestr.str();
    os << YAML::Key << "timeSinceStart" << YAML::Value << DurationToStr(elapsed);

    os << YAML::Key << "Settings" << YAML::Value;
    settings_->Print(os);

    os << YAML::Key << "SystemInfo" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "osName" << YAML::Value << system_.GetOsName();
    os << YAML::Key << "osVersion" << YAML::Value << system_.GetOsVersion();
    os << YAML::Key << "osBitdepth" << YAML::Value << system_.GetOsBitdepth();
    os << YAML::Key << "osAdditional" << YAML::Value << YAML::BeginMap;
    for (const auto& item : system_.GetOsAdditionalInfo()) {
        os << YAML::Key << item.first << YAML::Value << item.second;
    }
    os << YAML::EndMap;
    os << YAML::Key << "cpuName" << YAML::Value << system_.GetHwCpuName();
    os << YAML::Key << "numCpus" << YAML::Value << system_.GetHwNumCpus();
    os << YAML::Key << "totalRam" << YAML::Value << system_.GetHwTotalRam();
    os << YAML::Key << "totalDiskSpace" << YAML::Value << system_.GetHwTotalDiskSpace();
    os << YAML::Key << "availDiskSpace" << YAML::Value << system_.GetHwAvailDiskSpace();
    os << YAML::EndMap;  // SystemInfo

    os << YAML::Key << "Instance" << YAML::Value << YAML::BeginMap;
    // TODO handle debug utils names for VkInstance
    os << YAML::Key << "handle" << YAML::Value << (PtrToStr(vk_instance_) + " []");
    if (application_info_) {
        os << YAML::Key << "applicationInfo" << YAML::Value << YAML::BeginMap;
        os << YAML::Key << "application" << YAML::Value << application_info_->applicationName;
        os << YAML::Key << "applicationVersion" << YAML::Value << application_info_->applicationVersion;
        os << YAML::Key << "engine" << YAML::Value << application_info_->engineName;
        os << YAML::Key << "engineVersion" << YAML::Value << application_info_->engineVersion;

        auto majorVersion = VK_VERSION_MAJOR(application_info_->apiVersion);
        auto minorVersion = VK_VERSION_MINOR(application_info_->apiVersion);
        auto patchVersion = VK_VERSION_PATCH(application_info_->apiVersion);

        std::stringstream api;
        api << majorVersion << "." << minorVersion << "." << patchVersion << " ("
            << Uint32ToStr(application_info_->apiVersion) << ")";
        os << YAML::Key << "apiVersion" << YAML::Value << api.str();
        os << YAML::EndMap;  // ApplicationInfo
    }

    os << YAML::Key << "extensions" << YAML::Value << YAML::BeginSeq;
    for (uint32_t i = 0; i < original_create_info_.enabledExtensionCount; i++) {
        os << original_create_info_.ppEnabledExtensionNames[i];
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;  // Instance
    assert(os.good());
}

std::ofstream Context::OpenDumpFile() {
    // Make sure our output directory exists.
    std::filesystem::create_directories(settings_->output_path);

    // now write our log.
    std::filesystem::path dump_file_path(settings_->output_path);

    // Keep the first log as cdl_dump.yaml then add a number if more than one log is
    // generated. Multiple logs are a new feature and we want to keep backward
    // compatiblity for now.
    std::stringstream ss_name;
    if (total_logs_ > 0) {
        ss_name << "cdl_dump_" << total_logs_ << ".yaml";
    } else {
        ss_name << "cdl_dump.yaml";
    }
    dump_file_path /= ss_name.str();
    total_logs_++;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
    bool use_platform_win32 = true;
#else
    bool use_platform_win32 = false;
#endif

    // Create a symlink from the generated log file.
    std::filesystem::path symlink_path(settings_->base_output_path);
    if (!use_platform_win32) {
        symlink_path /= "cdl_dump.yaml.symlink";
        try {
            std::filesystem::remove(symlink_path);
            std::filesystem::create_symlink(dump_file_path, symlink_path);
        } catch (std::filesystem::filesystem_error& err) {
            Log().Warning("symlink %s -> %s failed: %s", dump_file_path.string().c_str(), symlink_path.string().c_str(),
                          err.what());
        }
    }

    std::stringstream ss;
    ss << "Device error encountered and log being recorded" << std::endl;
    ;
    ss << "\tOutput written to: " << dump_file_path << std::endl;
    if (!use_platform_win32) {
        ss << "\tSymlink to output: " << symlink_path << std::endl;
    }

    ss << "----------------------------------------------------------------" << std::endl;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    OutputDebugString(ss.str().c_str());
#endif
    Log().Error(ss.str());

    std::ofstream fs(dump_file_path);
    if (!fs.is_open()) {
        Log().Error("UNABLE TO OPEN LOG FILE");
    }
    fs << std::unitbuf;
    return fs;
}

// =============================================================================
// Define pre / post intercepted commands
// =============================================================================

VkResult Context::PostCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                                     VkInstance* pInstance, VkResult result) {
    vk_instance_ = *pInstance;
    auto instance_layer_data = GetInstanceLayerData(crash_diagnostic_layer::DataKey(vk_instance_));
    instance_dispatch_table_ = instance_layer_data->dispatch_table;

    if (pCreateInfo->pApplicationInfo) {
        application_info_ = std::make_unique<ApplicationInfo>();

        application_info_->applicationName =
            pCreateInfo->pApplicationInfo->pApplicationName ? pCreateInfo->pApplicationInfo->pApplicationName : "";
        application_info_->applicationVersion = pCreateInfo->pApplicationInfo->applicationVersion;

        application_info_->engineName =
            pCreateInfo->pApplicationInfo->pEngineName ? pCreateInfo->pApplicationInfo->pEngineName : "";
        application_info_->engineVersion = pCreateInfo->pApplicationInfo->engineVersion;
        application_info_->apiVersion = pCreateInfo->pApplicationInfo->apiVersion;
    }
    return result;
}

VkResult Context::PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult callResult) {
    if (callResult != VK_SUCCESS) return callResult;

    auto extensions_present =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    VkDevice vk_device = *pDevice;
    std::unique_ptr<DeviceCreateInfo> device_create_info;
    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device_create_info = std::move(device_create_infos_[pCreateInfo]);
        device_create_infos_.erase(pCreateInfo);
    }
    auto device =
        std::make_shared<Device>(*this, physicalDevice, *pDevice, extensions_present, std::move(device_create_info));
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        // the device pointer is used below, so no std::move() here.
        devices_[vk_device] = device;
    }

    return VK_SUCCESS;
}

void Context::PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    // Destroy the device state without holding devices_mutex_ to avoid possible recursive locking.
    DevicePtr device_state;
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto iter = devices_.find(device);
        if (iter != devices_.end()) {
            device_state = std::move(iter->second);
            devices_.erase(iter);
        }
    }
    device_state.reset();
}

void Context::PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueue(*pQueue, queueFamilyIndex, queueIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

void Context::PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueue(*pQueue, pQueueInfo->queueFamilyIndex, pQueueInfo->queueIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

VkResult Context::PreDeviceWaitIdle(VkDevice device) {
    (void)device;
    PreApiFunction("vkDeviceWaitIdle");
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostDeviceWaitIdle(VkDevice device, VkResult result) {
    PostApiFunction("vkDeviceWaitIdle", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    // some drivers return VK_TIMEOUT on a hang
    if (IsVkError(result) || result == VK_TIMEOUT) {
        device_state->DeviceFault();
    } else {
        device_state->UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreQueueWaitIdle(VkQueue queue) {
    (void)queue;
    PreApiFunction("vkQueueWaitIdle");
    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostQueueWaitIdle(VkQueue queue, VkResult result) {
    PostApiFunction("vkQueueWaitIdle", result);

    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    // some drivers return VK_TIMEOUT on a hang
    if (IsVkError(result) || result == VK_TIMEOUT) {
        device_state->DeviceFault();
    } else {
        device_state->UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo) {
    PreApiFunction("vkQueuePresentKHR");
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateWatchdog();
    device_state->UpdateIdleState();
    return VK_SUCCESS;
}
VkResult Context::PostQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo, VkResult result) {
    PostApiFunction("vkQueuePresentKHR", result);

    auto device_state = GetQueueDevice(queue);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                   uint64_t timeout) {
    PreApiFunction("vkWaitForFences");
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        device_state->DeviceFault();
        return VK_ERROR_DEVICE_LOST;
    }
    return VK_SUCCESS;
}
VkResult Context::PostWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                    uint64_t timeout, VkResult result) {
    PostApiFunction("vkWaitForFences", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    } else if (result == VK_SUCCESS) {
        device_state->UpdateWatchdog();
    }

    return result;
}

VkResult Context::PreGetFenceStatus(VkDevice device, VkFence fence) {
    PreApiFunction("vkGetFenceStatus");
    return VK_SUCCESS;
}
VkResult Context::PostGetFenceStatus(VkDevice device, VkFence fence, VkResult result) {
    PostApiFunction("vkGetFenceStatus", result);

    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                         uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                         VkQueryResultFlags flags) {
    PostApiFunction("vkGetQueryPoolResults");
    return VK_SUCCESS;
}
VkResult Context::PostGetQueryPoolResults(VkDevice device, VkQueryPool queryPool, uint32_t firstQuery,
                                          uint32_t queryCount, size_t dataSize, void* pData, VkDeviceSize stride,
                                          VkQueryResultFlags flags, VkResult result) {
    PostApiFunction("vkGetQueryPoolResults", result);

    if (IsVkError(result)) {
        auto device_state = GetDevice(device);
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PreAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                         VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex) {
    PreApiFunction("vkAcquireNextImageKHR");
    return VK_SUCCESS;
}
VkResult Context::PostAcquireNextImageKHR(VkDevice device, VkSwapchainKHR swapchain, uint64_t timeout,
                                          VkSemaphore semaphore, VkFence fence, uint32_t* pImageIndex,
                                          VkResult result) {
    PostApiFunction("vkAcquireNextImageKHR", result);

    if (IsVkError(result)) {
        auto device_state = GetDevice(device);
        device_state->DeviceFault();
    }

    return result;
}

VkResult Context::PostCreateShaderModule(VkDevice device, const VkShaderModuleCreateInfo* pCreateInfo,
                                         const VkAllocationCallbacks* pAllocator, VkShaderModule* pShaderModule,
                                         VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreateShaderModule(pCreateInfo, pShaderModule, shader_module_load_options_);
    }
    return callResult;
}

void Context::PreDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                     const VkAllocationCallbacks* pAllocator) {
    auto device_state = GetDevice(device);
    device_state->DeleteShaderModule(shaderModule);
}

VkResult Context::PostCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                              VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

VkResult Context::PostCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                             VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

void Context::PostDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    auto device_state = GetDevice(device);
    device_state->DeletePipeline(pipeline);
}

VkResult Context::PreCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                       const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool) {
    PreApiFunction("vkCreateCommandPool");
    return VK_SUCCESS;
}
VkResult Context::PostCreateCommandPool(VkDevice device, const VkCommandPoolCreateInfo* pCreateInfo,
                                        const VkAllocationCallbacks* pAllocator, VkCommandPool* pCommandPool,
                                        VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        PostApiFunction("vkCreateCommandPool");
        auto device_state = GetDevice(device);
        CommandPoolPtr pool = std::make_unique<CommandPool>(*pCommandPool, pCreateInfo);
        device_state->SetCommandPool(*pCommandPool, std::move(pool));
    }
    return callResult;
}

void Context::PreDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                    const VkAllocationCallbacks* pAllocator) {
    PreApiFunction("vkDestroyCommandPool");

    auto device_state = GetDevice(device);
    YAML::Emitter os;
    device_state->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(*device_state, os);
    }
}

void Context::PostDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                     const VkAllocationCallbacks* pAllocator) {
    PostApiFunction("vkDestroyCommandPool");

    auto device_state = GetDevice(device);
    device_state->DeleteCommandPool(commandPool);
}

VkResult Context::PreResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    PreApiFunction("vkResetCommandPool");

    auto device_state = GetDevice(device);
    YAML::Emitter os;
    device_state->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(*device_state, os);
    }
    return VK_SUCCESS;
}

VkResult Context::PostResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                       VkResult callResult) {
    PostApiFunction("vkResetCommandPool");

    auto device_state = GetDevice(device);
    device_state->ResetCommandPool(commandPool);

    return callResult;
}

VkResult Context::PreAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                            VkCommandBuffer* pCommandBuffers) {
    PreApiFunction("vkAllocateCommandBuffers");
    return VK_SUCCESS;
}

VkResult Context::PostAllocateCommandBuffers(VkDevice device, const VkCommandBufferAllocateInfo* pAllocateInfo,
                                             VkCommandBuffer* pCommandBuffers, VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        PostApiFunction("vkAllocateCommandBuffers");

        auto device_state = GetDevice(device);

        auto vk_pool = pAllocateInfo->commandPool;
        device_state->AllocateCommandBuffers(vk_pool, pAllocateInfo, pCommandBuffers);
    }
    return callResult;
}

void Context::PreFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                    const VkCommandBuffer* pCommandBuffers) {
    PreApiFunction("vkFreeCommandBuffers");
}
void Context::PostFreeCommandBuffers(VkDevice device, VkCommandPool commandPool, uint32_t commandBufferCount,
                                     const VkCommandBuffer* pCommandBuffers) {
    PostApiFunction("vkFreeCommandBuffers");

    auto device_state = GetDevice(device);
    if (!device_state->HangDetected()) {
        YAML::Emitter os;
        bool all_cb_ok = true;
        for (uint32_t i = 0; i < commandBufferCount; ++i) {
            all_cb_ok = all_cb_ok && device_state->ValidateCommandBufferNotInUse(pCommandBuffers[i], os);
        }
        if (!all_cb_ok) {
            DumpDeviceExecutionStateValidationFailed(*device_state, os);
        }
    }

    device_state->DeleteCommandBuffers(commandPool, pCommandBuffers, commandBufferCount);
}

VkResult Context::PostCreateSemaphore(VkDevice device, VkSemaphoreCreateInfo const* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                      VkResult result) {
    if (result == VK_SUCCESS) {
        uint64_t s_value = 0;
        VkSemaphoreTypeKHR s_type = VK_SEMAPHORE_TYPE_BINARY_KHR;

        const auto* semaphore_info = vku::FindStructInPNextChain<VkSemaphoreTypeCreateInfoKHR>(pCreateInfo);
        if (semaphore_info) {
            s_value = semaphore_info->initialValue;
            s_type = semaphore_info->semaphoreType;
        }
        auto device_state = GetDevice(device);
        assert(device_state);

        if (device_state->GetSemaphoreTracker() != nullptr) {
            device_state->GetSemaphoreTracker()->RegisterSemaphore(*pSemaphore, s_type, s_value);

            if ((settings_->log_message_areas & MESSAGE_AREA_SEMAPHORE_BIT)) {
                std::stringstream log;
                log << "Semaphore created. VkDevice:" << device_state->GetObjectName((uint64_t)device)
                    << ", VkSemaphore: " << device_state->GetObjectName((uint64_t)(*pSemaphore));
                if (s_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                    log << ", Type: Binary";
                } else {
                    log << ", Type: Timeline, Initial value: " << s_value;
                }
                Log().Info(log.str());
            }
        }
    }
    return result;
}

void Context::PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if ((settings_->log_message_areas & MESSAGE_AREA_SEMAPHORE_BIT)) {
        auto device_state = GetDevice(device);
        assert(device_state);

        auto semaphore_tracker = device_state->GetSemaphoreTracker();
        if (semaphore_tracker != nullptr) {
            std::stringstream log;
            log << "Semaphore destroyed. VkDevice:" << device_state->GetObjectName((uint64_t)device)
                << ", VkSemaphore: " << device_state->GetObjectName((uint64_t)(semaphore));
            if (semaphore_tracker->GetSemaphoreType(semaphore) == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                log << ", Type: Binary, ";
            } else {
                log << ", Type: Timeline, ";
            }
            uint64_t semaphore_value;
            if (semaphore_tracker->GetSemaphoreValue(semaphore, semaphore_value)) {
                log << "Latest value: " << semaphore_value;
            } else {
                log << "Latest value: Unknown";
            }
            Log().Info(log.str());
        }
    }
}

void Context::PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    auto device_state = GetDevice(device);
    auto semaphore_tracker = device_state->GetSemaphoreTracker();
    if (semaphore_tracker != nullptr) {
        semaphore_tracker->EraseSemaphore(semaphore);
    }
}

VkResult Context::PostSignalSemaphore(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo, VkResult result) {
    if (result == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        assert(device_state);

        auto semaphore_tracker = device_state->GetSemaphoreTracker();

        if (semaphore_tracker != nullptr) {
            semaphore_tracker->SignalSemaphore(pSignalInfo->semaphore, pSignalInfo->value,
                                                                 {SemaphoreModifierType::kModifierHost});
            if ((settings_->log_message_areas & MESSAGE_AREA_SEMAPHORE_BIT)) {
                std::string timeline_message = "Timeline semaphore signaled from host. VkDevice: ";
                timeline_message += device_state->GetObjectName((uint64_t)device) +
                                    ", VkSemaphore: " + device_state->GetObjectName((uint64_t)(pSignalInfo->semaphore)) +
                                    ", Signal value: " + std::to_string(pSignalInfo->value);
                Log().Info(timeline_message.c_str());
            }
        }
    }
    return result;
}

VkResult Context::PreWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout) {
    VkResult result = VK_SUCCESS;
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }

    auto semaphore_tracker = device_state->GetSemaphoreTracker();

    if (semaphore_tracker != nullptr) {
        auto tid = System::GetTid();
        auto pid = System::GetPid();

        semaphore_tracker->BeginWaitOnSemaphores(pid, tid, pWaitInfo);

        if ((settings_->log_message_areas & MESSAGE_AREA_SEMAPHORE_BIT)) {
            std::stringstream log;
            log << "Waiting for timeline semaphores on host. PID: " << pid << ", TID: " << tid
                << ", VkDevice: " << device_state->GetObjectName((uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << device_state->GetObjectName((uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

VkResult Context::PostWaitSemaphores(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout,
                                     VkResult result) {
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
        return result;
    }

    auto semaphore_tracker = device_state->GetSemaphoreTracker();
    if (semaphore_tracker != nullptr && (result == VK_SUCCESS || result == VK_TIMEOUT)) {
        auto tid = System::GetTid();
        auto pid = System::GetPid();
        {
            // Update semaphore values
            uint64_t semaphore_value;
            auto dispatch_table =
                crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(device))->dispatch_table;

            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                VkResult res;
                if (dispatch_table.GetSemaphoreCounterValue) {
                    res = dispatch_table.GetSemaphoreCounterValue(device, pWaitInfo->pSemaphores[i], &semaphore_value);
                } else {
                    res =
                        dispatch_table.GetSemaphoreCounterValueKHR(device, pWaitInfo->pSemaphores[i], &semaphore_value);
                }
                if (res == VK_SUCCESS) {
                    semaphore_tracker->SignalSemaphore(pWaitInfo->pSemaphores[i], semaphore_value,
                                                       {SemaphoreModifierType::kModifierHost});
                }
            }
            semaphore_tracker->EndWaitOnSemaphores(pid, tid, pWaitInfo);
        }

        if ((settings_->log_message_areas & MESSAGE_AREA_SEMAPHORE_BIT)) {
            std::stringstream log;
            log << "Finished waiting for timeline semaphores on host. PID: " << pid << ", TID: " << tid
                << ", VkDevice: " << device_state->GetObjectName((uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << device_state->GetObjectName((uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

VkResult Context::PostGetSemaphoreCounterValue(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                               VkResult result) {
    auto device_state = GetDevice(device);
    if (!device_state->UpdateIdleState()) {
        result = VK_ERROR_DEVICE_LOST;
    }
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

const std::filesystem::path& Context::GetOutputPath() const { return this->settings_->output_path; }

VkResult Context::PreDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(pNameInfo->object, static_cast<VkObjectType>(pNameInfo->objectType),
                                pNameInfo->pObjectName);
    return VK_SUCCESS;
};

VkResult Context::PreSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(pNameInfo->objectHandle, pNameInfo->objectType, pNameInfo->pObjectName);
    return VK_SUCCESS;
}

// =============================================================================
// Include the generated implementation to forward commands to command buffer
// =============================================================================
#include "cdl_commands.cpp.inc"

// =============================================================================
// Define the custom pre intercepted commands
// =============================================================================
void Context::PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    if (settings_->dump_shaders == DumpShaders::kOnBind) {
        p_cmd->GetDevice().DumpShaderFromPipeline(pipeline);
    }

    p_cmd->PreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

VkResult Context::PreBeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferBeginInfo const* pBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto& device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device.ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreBeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult Context::PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto& device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device.ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreResetCommandBuffer(commandBuffer, flags);
}

VkResult Context::QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit");
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateWatchdog();
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2");
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateWatchdog();
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit2(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2KHR");
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateWatchdog();
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->Submit2(submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2KHR", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, VkBindSparseInfo const* pBindInfo,
                                  VkFence fence) {
    PreApiFunction("vkQueueBindSparse");
    auto device_state = GetQueueDevice(queue);
    device_state->UpdateWatchdog();
    auto queue_state = device_state->GetQueue(queue);
    auto result = queue_state->BindSparse(bindInfoCount, pBindInfo, fence);
    PostApiFunction("vkQueueBindSparse", result);
    if (IsVkError(result)) {
        device_state->DeviceFault();
    }
    return result;
}

VkResult Context::PostCreateDebugUtilsMessengerEXT(VkInstance instance,
                                                   const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkDebugUtilsMessengerEXT* pMessenger, VkResult result) {
    if (result == VK_SUCCESS) {
        logger_.AddLogCallback(*pMessenger, *pCreateInfo);
    }
    return result;
}

void Context::PreDestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT messenger,
                                               const VkAllocationCallbacks* pAllocator) {
    logger_.RemoveLogCallback(messenger);
}

VkResult Context::PostCreateDebugReportCallbackEXT(VkInstance instance,
                                                   const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkDebugReportCallbackEXT* pCallback, VkResult result) {
    if (result == VK_SUCCESS) {
        logger_.AddLogCallback(*pCallback, *pCreateInfo);
    }
    return result;
}

void Context::PreDestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback,
                                               const VkAllocationCallbacks* pAllocator) {
    logger_.RemoveLogCallback(callback);
}

VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                        VkInstance* pInstance, Interceptor** interceptor) {
    auto* context = new Context(pCreateInfo, pAllocator);
    *interceptor = context;
    return VK_SUCCESS;
}

}  // namespace crash_diagnostic_layer
