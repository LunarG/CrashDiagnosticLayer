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

#include "cdl.h"
#include "util.h"

#if defined(WIN32)
// For OutputDebugString
#include <process.h>
#include <windows.h>
#else
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/un.h>
#endif

#include <algorithm>
#include <chrono>
#include <fstream>
#include <inttypes.h>
#include <iostream>
#include <memory>
#include <sstream>

#include <vulkan/utility/vk_struct_helper.hpp>
#include <vulkan/vk_enum_string_helper.h>

#include <yaml-cpp/emitter.h>

#if defined(WIN32)
#include <direct.h>
#endif

namespace crash_diagnostic_layer {

const char* kCdlVersion = "1.2.0";

namespace settings {
const char* kOutputPath = "output_path";
const char* kOutputName = "output_name";
const char* kLogfilePrefix = "logfile_prefix";
const char* kLogConfigs = "log_configs";
const char* kTraceOn = "trace_on";
const char* kShadersDump = "shaders_dump";
const char* kShadersDumpOnCrash = "shaders_dump_on_crash";
const char* kShadersDumpOnBind = "shaders_dump_on_bind";
const char* kWatchdogTimeout = "watchdog_timeout_ms";
const char* kAutodump = "autodump";
const char* kDumpAllCommandBuffers = "dump_all_command_buffers";
// TODO: buffers_dump_indirect???
const char* kTrackSemaphores = "track_semaphores";
const char* kTraceAllSemaphores = "trace_all_semaphores";
const char* kInstrumentAllCommands = "instrument_all_commands";
}  // namespace settings

const char* kLogTimeTag = "%Y-%m-%d-%H%M%S";
// =============================================================================
// Context
// =============================================================================
Context::Context(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator) {
    system_.SetContext(this);
    Log().Info("Version %s enabled.", kCdlVersion);

    const auto* create_info = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pCreateInfo);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result =
        vkuCreateLayerSettingSet("lunarg_crash_diagnostic", create_info, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        Log().Error("vkuCreateLayerSettingSet failed with error %d", result);
        return;
    }

    // output path
    {
        std::string path_string;
        vkuGetLayerSettingValue(layer_setting_set, settings::kOutputPath, path_string);
        if (!path_string.empty()) {
            output_path_ = path_string;
        } else {
#if defined(WIN32)
            output_path_ = getenv("USERPROFILE");
#else
            output_path_ = getenv("HOME");
#endif
            output_path_ /= "cdl";
        }

        // ensure base path is created
        MakeDir(output_path_);
        base_output_path_ = output_path_;

        // Calculate a unique sub directory based on time
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);

        // if output_name_ is given, don't create a subdirectory
        vkuGetLayerSettingValue(layer_setting_set, settings::kOutputName, output_name_);
        if (output_name_.empty()) {
            std::stringstream ss;
            ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%H%M%S");
            output_path_ /= ss.str();
        }

        // If logfile prefix is given, create it with the date_time suffix
        std::string logfile_prefix;
        vkuGetLayerSettingValue(layer_setting_set, settings::kLogfilePrefix, logfile_prefix);
        if (!logfile_prefix.empty()) {
            MakeOutputPath();
            std::filesystem::path log_file(output_path_);
            std::stringstream ss;
            ss << logfile_prefix << std::put_time(std::localtime(&in_time_t), kLogTimeTag) << ".log";
            log_file /= ss.str();
            logger_.OpenLogFile(log_file);
        }
    }

    // report cdl configs
    {
        if (vkuHasLayerSetting(layer_setting_set, settings::kLogConfigs)) {
            vkuGetLayerSettingValue(layer_setting_set, settings::kLogConfigs, log_configs_);
        }
        if (log_configs_) {
            configs_.push_back(std::string(settings::kLogConfigs) + "=1");
        }
    }

    // trace mode
    GetEnvVal<bool>(layer_setting_set, settings::kTraceOn, &trace_all_);

    // setup shader loading modes
    shader_module_load_options_ = ShaderModule::LoadOptions::kNone;

    {
        bool dump_shaders = false;
        GetEnvVal<bool>(layer_setting_set, settings::kShadersDump, &dump_shaders);
        if (dump_shaders) {
            shader_module_load_options_ |= ShaderModule::LoadOptions::kDumpOnCreate;
        } else {
            // if we're not dumping all shaders then check if we dump in other cases
            {
                GetEnvVal<bool>(layer_setting_set, settings::kShadersDumpOnCrash, &debug_dump_shaders_on_crash_);
                if (debug_dump_shaders_on_crash_) {
                    shader_module_load_options_ |= ShaderModule::LoadOptions::kKeepInMemory;
                }
            }

            {
                GetEnvVal<bool>(layer_setting_set, settings::kShadersDumpOnBind, &debug_dump_shaders_on_bind_);
                if (debug_dump_shaders_on_bind_) {
                    shader_module_load_options_ |= ShaderModule::LoadOptions::kKeepInMemory;
                }
            }
        }
    }

    // manage the watchdog thread
    {
        GetEnvVal<uint64_t>(layer_setting_set, settings::kWatchdogTimeout, &watchdog_timer_ms_);

        last_submit_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
                                std::chrono::high_resolution_clock::now().time_since_epoch())
                                .count();

        if (watchdog_timer_ms_ > 0) {
            StartWatchdogTimer();
            Log().Info("Begin Watchdog: %" PRId64 "ms", watchdog_timer_ms_);
        }
    }

    // Setup debug flags
    GetEnvVal<int>(layer_setting_set, settings::kAutodump, &debug_autodump_rate_);
    GetEnvVal<bool>(layer_setting_set, settings::kDumpAllCommandBuffers, &debug_dump_all_command_buffers_);
    GetEnvVal<bool>(layer_setting_set, settings::kTrackSemaphores, &track_semaphores_);
    GetEnvVal<bool>(layer_setting_set, settings::kTraceAllSemaphores, &trace_all_semaphores_);
    GetEnvVal<bool>(layer_setting_set, settings::kInstrumentAllCommands, &instrument_all_commands_);

    vkuDestroyLayerSettingSet(layer_setting_set, nullptr);
}

Context::~Context() {
    StopWatchdogTimer();
    logger_.CloseLogFile();
}

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

void Context::MakeDir(const std::filesystem::path& path) {
#if defined(WIN32)
    int mkdir_result = _mkdir(path.string().c_str());
#else
    int mkdir_result = mkdir(path.string().c_str(), ACCESSPERMS);
#endif

    if (mkdir_result && EEXIST != errno) {
        Log().Error("Error creating output directory \'%s\': %s", path.string().c_str(), strerror(errno));
    }
}

template <class T>
void Context::GetEnvVal(VkuLayerSettingSet settings, const char* name, T* value) {
    if (vkuHasLayerSetting(settings, name)) {
        vkuGetLayerSettingValue(settings, name, *value);
        if (log_configs_) {
            std::stringstream ss;
            ss << name << "=" << *value;
            auto config = ss.str();
            if (std::find(configs_.begin(), configs_.end(), config) == configs_.end()) {
                configs_.push_back(config);
            }
        }
    }
}

void Context::StartWatchdogTimer() {
    // Start up the watchdog timer thread.
    watchdog_running_ = true;
    watchdog_thread_ = std::make_unique<std::thread>([&]() { this->WatchdogTimer(); });
}

void Context::StopWatchdogTimer() {
    if (watchdog_running_ && watchdog_thread_->joinable()) {
        Log().Info("Stopping Watchdog");
        watchdog_running_ = false;  // TODO: condition variable that waits
        watchdog_thread_->join();
        Log().Info("Watchdog Stopped");
    }
}

void Context::WatchdogTimer() {
    uint64_t test_interval_us = std::min((uint64_t)(1000 * 1000), watchdog_timer_ms_ * 500);
    while (watchdog_running_) {
        // TODO: condition variable that waits
        std::this_thread::sleep_for(std::chrono::microseconds(test_interval_us));

        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                       std::chrono::high_resolution_clock::now().time_since_epoch())
                       .count();
        auto ms = (int64_t)(now - last_submit_time_);

        if (ms > (int64_t)watchdog_timer_ms_) {
            Log().Info("CDL: Watchdog check failed, no submit in %" PRId64 "ms", ms);

            DumpAllDevicesExecutionState(CrashSource::kWatchdogTimer);

            // Reset the timer to prevent constantly dumping the log.
            last_submit_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
                                    std::chrono::high_resolution_clock::now().time_since_epoch())
                                    .count();
        }
    }
}

void Context::PreApiFunction(const char* api_name) {
    if (trace_all_) {
        Log().Info("{ %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name) {
    if (trace_all_) {
        Log().Info("} %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name, VkResult result) {
    if (trace_all_) {
        Log().Info("} %s (%s)", api_name, string_VkResult(result));
    }
}

struct RequiredExtension {
    char name[VK_MAX_EXTENSION_NAME_SIZE];
    bool enabled;
    bool* enabled_member;
};

const VkInstanceCreateInfo* Context::GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo* pCreateInfo) {
    const uint32_t required_extension_count = 1;
    RequiredExtension required_extensions[] = {{VK_EXT_DEBUG_UTILS_EXTENSION_NAME, false, nullptr}};

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
    }
}

static DeviceExtensionsPresent DecodeExtensionStrings(uint32_t count, const char* const* names) {
    DeviceExtensionsPresent extensions{};

    for (uint32_t i = 0; i < count; ++i) {
        DecodeExtensionString(extensions, names[i]);
    }
    return extensions;
}

const VkDeviceCreateInfo* Context::GetModifiedDeviceCreateInfo(VkPhysicalDevice physicalDevice,
                                                               const VkDeviceCreateInfo* pCreateInfo) {
    auto extensions_enabled =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    const auto& extensions_present = extensions_of_interest_present_[physicalDevice];
    auto device_ci = std::make_unique<DeviceCreateInfo>();
    device_ci->original.initialize(pCreateInfo);
    device_ci->modified = device_ci->original;

    // If an important extension is not enabled by default, try to enable it if it is present
    if (extensions_present.amd_buffer_marker) {
        if (!extensions_enabled.amd_buffer_marker) {
            // NOTE: this extension does not have a feature struct
            extensions_enabled.amd_buffer_marker = true;
            vku::AddExtension(device_ci->modified, VK_AMD_BUFFER_MARKER_EXTENSION_NAME);
        }
    } else {
        Log().Error("No VK_AMD_buffer_marker extension, progression tracking will be disabled. ");
    }
    if (extensions_present.amd_coherent_memory) {
        if (!extensions_enabled.amd_coherent_memory) {
            extensions_enabled.amd_coherent_memory = true;
            auto amd_device_coherent = vku::InitStruct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(nullptr, VK_TRUE);
            vku::AddToPnext(device_ci->modified, amd_device_coherent);
            vku::AddExtension(device_ci->modified, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME);
        }
    } else {
        Log().Error("No VK_AMD_device_coherent_memory extension, results may not be as accurate as possible.");
    }
    if (extensions_present.ext_device_fault) {
        if (!extensions_enabled.ext_device_fault) {
            extensions_enabled.ext_device_fault = true;
            // TODO: query for deviceFaultVendorBinary support
            auto ext_device_fault = vku::InitStruct<VkPhysicalDeviceFaultFeaturesEXT>(nullptr, VK_TRUE, VK_FALSE);
            vku::AddToPnext(device_ci->modified, ext_device_fault);
            vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_FAULT_EXTENSION_NAME);
        }
    } else {
        Log().Warning("No VK_EXT_device_fault extension, vendor-specific crash dumps will not be available.");
    }
    if (extensions_present.ext_device_address_binding_report) {
        if (!extensions_enabled.ext_device_address_binding_report) {
            auto ext_device_address_binding_report =
                vku::InitStruct<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(nullptr, VK_TRUE);
            vku::AddToPnext(device_ci->modified, ext_device_address_binding_report);
            vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME);
        }
    } else {
        Log().Warning(
            "No VK_EXT_device_address_binding_report extension, DeviceAddress information will not be available.");
    }

    extensions_of_interest_enabled_[physicalDevice] = std::move(extensions_enabled);

    // save the raw ptr before std::move of the std::unique_ptr
    const auto* ci_ptr = device_ci->modified.ptr();
    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device_create_infos_[ci_ptr] = std::move(device_ci);
    }

    return ci_ptr;
}

bool Context::DumpShadersOnCrash() const { return debug_dump_shaders_on_crash_; }

bool Context::DumpShadersOnBind() const { return debug_dump_shaders_on_bind_; }

void Context::DumpAllDevicesExecutionState(CrashSource crash_source) {
    auto devs = GetAllDevices();
    bool dump_prologue = true;
    auto file = OpenDumpFile();
    YAML::Emitter os(file.is_open() ? file : std::cerr);

    for (auto& device : devs) {
        DumpDeviceExecutionState(*device, dump_prologue, crash_source, os);
        dump_prologue = false;
    }
}

void Context::DumpDeviceExecutionState(VkDevice vk_device) {
    auto device_state = GetDevice(vk_device);
    if (device_state) {
        auto file = OpenDumpFile();
        YAML::Emitter os(file.is_open() ? file : std::cerr);
        DumpDeviceExecutionState(*device_state, {}, true, kDeviceLostError, os);
    }
}

void Context::DumpDeviceExecutionState(const Device& device, bool dump_prologue, CrashSource crash_source,
                                       YAML::Emitter& os) {
    DumpDeviceExecutionState(device, {}, dump_prologue, crash_source, os);
}

void Context::DumpDeviceExecutionState(const Device& device, std::string error_report, bool dump_prologue,
                                       CrashSource crash_source, YAML::Emitter& os) {
    if (dump_prologue) {
        DumpReportPrologue(os);
    }

    device.Print(os);

    if (track_semaphores_) {
        device.GetSubmitTracker()->DumpWaitingSubmits(os);
        device.GetSemaphoreTracker()->DumpWaitingThreads(os);
    }
    if (!error_report.empty()) {
        os << error_report;
    }
    auto options = CommandBufferDumpOption::kDefault;
    if (debug_dump_all_command_buffers_) options |= CommandBufferDumpOption::kDumpAllCommands;

    if (debug_autodump_rate_ > 0 || debug_dump_all_command_buffers_) {
        device.DumpAllCommandBuffers(os, options);
    } else {
        device.DumpIncompleteCommandBuffers(os, options);
    }
}

void Context::DumpDeviceExecutionStateValidationFailed(const Device& device, YAML::Emitter& os) {
    // We force all command buffers to dump here because validation can be
    // from a race condition and the GPU can complete work by the time we've
    // started writing the log. (Seen in practice, not theoretical!)
    auto dump_all = debug_dump_all_command_buffers_;
    debug_dump_all_command_buffers_ = true;
    std::stringstream error_report;
    error_report << os.c_str();  // TODO does this do what we want?
    DumpDeviceExecutionState(device, error_report.str(), true /* dump_prologue */, CrashSource::kDeviceLostError, os);
    debug_dump_all_command_buffers_ = dump_all;
}

void Context::DumpReportPrologue(YAML::Emitter& os) {
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;
    os << YAML::Comment("-                    CRASH DIAGNOSTIC LAYER                    -") << YAML::Newline;
    os << YAML::Comment("----------------------------------------------------------------") << YAML::Newline;

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    os << YAML::Key << "CDLInfo" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "version" << YAML::Value << kCdlVersion;
    std::stringstream timestr;
    timestr << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    os << YAML::Key << "date" << YAML::Value << timestr.str();
    if (log_configs_) {
        // TODO this should be a map
        os << YAML::Key << "settings" << YAML::Value << YAML::BeginSeq;
        std::string configstr;
        for (auto& cstr : configs_) {
            os << cstr;
        }
        os << YAML::EndSeq;
    }
    os << YAML::EndMap;  // CDLInfo

    os << YAML::Key << "SystemInfo" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "osName" << YAML::Value << system_.GetOsName();
    os << YAML::Key << "osVersion" << YAML::Value << system_.GetOsVersion();
    os << YAML::Key << "osBitdepth" << YAML::Value << system_.GetOsBitdepth();
    os << YAML::Key << "osAdditional" << YAML::Value << system_.GetOsAdditionalInfo();
    os << YAML::Key << "cpuName" << YAML::Value << system_.GetHwCpuName();
    os << YAML::Key << "numCpus" << YAML::Value << system_.GetHwNumCpus();
    os << YAML::Key << "totalRam" << YAML::Value << system_.GetHwTotalRam();
    os << YAML::Key << "totalDiskSpace" << YAML::Value << system_.GetHwTotalDiskSpace();
    os << YAML::Key << "availDiskSpace" << YAML::Value << system_.GetHwAvailDiskSpace();
    os << YAML::EndMap;  // SystemInfo

    os << YAML::Key << "Instance" << YAML::Value << YAML::BeginMap;
    os << YAML::Key << "vkHandle" << YAML::Value << PtrToStr(vk_instance_);
    if (application_info_) {
        os << YAML::Key << "ApplicationInfo" << YAML::Value << YAML::BeginMap;
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
        YAML::EndMap;  // ApplicationInfo
    }

    os << YAML::Key << "instanceExtensions" << YAML::Value << YAML::BeginSeq;
    for (uint32_t i = 0; i < original_create_info_.enabledExtensionCount; i++) {
        os << original_create_info_.ppEnabledExtensionNames[i];
    }
    os << YAML::EndSeq;
    os << YAML::EndMap;  // Instance
    os << YAML::EndMap;  //??? TODO why do we need this extra EndMap?
}

std::ofstream Context::OpenDumpFile() {
    // Make sure our output directory exists.
    MakeOutputPath();

    // now write our log.
    std::filesystem::path dump_file_path(output_path_);

    // Keep the first log as cdl.log then add a number if more than one log is
    // generated. Multiple logs are a new feature and we want to keep backward
    // compatiblity for now.
    std::string output_name = "cdl";
    if (output_name_.size() > 0) {
        output_name = output_name_;
    }
    std::stringstream ss_name;
    if (total_logs_ > 0) {
        ss_name << output_name << "_" << total_submits_ << "_" << total_logs_ << ".log";
    } else {
        ss_name << output_name << ".log";
    }
    dump_file_path /= ss_name.str();
    total_logs_++;

#if !defined(WIN32)
    // Create a symlink from the generated log file.
    std::filesystem::path symlink_path(base_output_path_);
    symlink_path /= "cdl.log.symlink";
    remove(symlink_path.string().c_str());
    symlink(dump_file_path.string().c_str(), symlink_path.string().c_str());
#endif

    std::stringstream ss;
    ss << "Device error encountered and log being recorded" << std::endl;
    ;
    ss << "\tOutput written to: " << dump_file_path << std::endl;
#if !defined(WIN32)
    ss << "\tSymlink to output: " << symlink_path << std::endl;
#endif
    ss << "----------------------------------------------------------------" << std::endl;
#if defined(WIN32)
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

static VKAPI_ATTR VkBool32 VKAPI_CALL MessengerCallback(VkDebugUtilsMessageSeverityFlagBitsEXT severity,
                                                        VkDebugUtilsMessageTypeFlagsEXT types,
                                                        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                                                        void* pUserData) {
    if (nullptr == pCallbackData || nullptr == pUserData) {
        return VK_FALSE;
    }
    Context* context = reinterpret_cast<Context*>(pUserData);
    const auto* mem_info = vku::FindStructInPNextChain<VkDeviceAddressBindingCallbackDataEXT>(pCallbackData->pNext);
    if (!mem_info) {
        return VK_FALSE;
    }
    context->MemoryBindEvent(*mem_info, *pCallbackData->pObjects);
    return VK_FALSE;
}

void Context::MemoryBindEvent(const VkDeviceAddressBindingCallbackDataEXT& mem_info,
                              const VkDebugUtilsObjectNameInfoEXT& object) {
    DeviceAddressRecord rec{mem_info.baseAddress,
                            mem_info.size,
                            mem_info.flags,
                            mem_info.bindingType,
                            object.objectType,
                            object.objectHandle,
                            object.pObjectName ? object.pObjectName : "",
                            std::chrono::high_resolution_clock::now()};
    auto devs = GetAllDevices();

    bool multi_device = devs.size() > 1;
    for (auto& dev : devs) {
        dev->MemoryBindEvent(rec, multi_device);
    }
}

bool Context::CountSubmit() {
    auto total = ++total_submits_;
    return (debug_autodump_rate_ > 0 && (total % debug_autodump_rate_) == 0);
}

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
    if (VK_NULL_HANDLE == utils_messenger_) {
        VkDebugUtilsMessengerCreateInfoEXT messenger_create_info = {
            VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
            nullptr,
            0,
            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT,
            VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT,
            &MessengerCallback,
            this,
        };
        instance_dispatch_table_.CreateDebugUtilsMessengerEXT(vk_instance_, &messenger_create_info, nullptr,
                                                              &utils_messenger_);
    }

    return result;
}

void Context::PreDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    if (VK_NULL_HANDLE != utils_messenger_) {
        instance_dispatch_table_.DestroyDebugUtilsMessengerEXT(vk_instance_, utils_messenger_, nullptr);
        utils_messenger_ = VK_NULL_HANDLE;
    }
}

VkResult Context::PostEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice, const char* pLayerName,
                                                         uint32_t* pPropertyCount, VkExtensionProperties* pProperties,
                                                         VkResult result) {
    if (result == VK_SUCCESS && pPropertyCount != nullptr && pProperties != nullptr && *pPropertyCount > 0) {
        DeviceExtensionsPresent extensions_present{};

        // Get the list of device extensions.
        uint32_t extension_count = *pPropertyCount;
        for (uint32_t i = 0; i < extension_count; ++i) {
            DecodeExtensionString(extensions_present, pProperties[i].extensionName);
        }
        extensions_of_interest_present_[physicalDevice] = std::move(extensions_present);
    }
    return VK_SUCCESS;
}

VkResult Context::PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult callResult) {
    if (callResult != VK_SUCCESS) return callResult;

    auto extensions_present =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    VkDevice vk_device = *pDevice;
    auto device = std::make_shared<Device>(this, physicalDevice, *pDevice, extensions_present);

    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device->SetDeviceCreateInfo(std::move(device_create_infos_[pCreateInfo]));
        device_create_infos_.erase(pCreateInfo);
    }
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        // the device pointer is used below, so no std::move() here.
        devices_[vk_device] = device;
    }

    if (track_semaphores_) {
        // Create a helper command pool per queue family index. This command pool
        // will be used for allocating command buffers that track the state of
        // submit and semaphores.
        auto dispatch_table =
            crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(vk_device))->dispatch_table;
        VkCommandPoolCreateInfo command_pool_create_info = {};
        command_pool_create_info.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;

        for (uint32_t i = 0; i < pCreateInfo->queueCreateInfoCount; i++) {
            auto queue_family_index = pCreateInfo->pQueueCreateInfos[i].queueFamilyIndex;
            command_pool_create_info.queueFamilyIndex = queue_family_index;
            VkCommandPool command_pool;
            auto res = dispatch_table.CreateCommandPool(vk_device, &command_pool_create_info, nullptr, &command_pool);
            if (res != VK_SUCCESS) {
                Log().Warning("failed to create command pools for helper command  buffers. VkDevice: 0x" PRIx64
                              ", queueFamilyIndex: %d",
                              (uint64_t)(vk_device), queue_family_index);
            } else {
                device->RegisterHelperCommandPool(queue_family_index, command_pool);
            }
        }
    }

    return VK_SUCCESS;
}

void Context::PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_) {
        auto device_state = GetDevice(device);
        device_state->EraseCommandPools();
    }
}

void Context::PostDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devices_.erase(device);
}

void Context::PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueueFamilyIndex(*pQueue, queueFamilyIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

void Context::PreGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {}
void Context::PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    {
        auto device_state = GetDevice(device);
        device_state->RegisterQueueFamilyIndex(*pQueue, pQueueInfo->queueFamilyIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

VkResult Context::PreDeviceWaitIdle(VkDevice device) {
    (void)device;
    PreApiFunction("vkDeviceWaitIdle");
    return VK_SUCCESS;
}
VkResult Context::PostDeviceWaitIdle(VkDevice device, VkResult result) {
    PostApiFunction("vkDeviceWaitIdle", result);

    if (IsVkError(result)) {
        DumpDeviceExecutionState(device);
    }

    return result;
}

VkResult Context::PreQueueWaitIdle(VkQueue queue) {
    (void)queue;
    PreApiFunction("vkQueueWaitIdle");
    return VK_SUCCESS;
}
VkResult Context::PostQueueWaitIdle(VkQueue queue, VkResult result) {
    PostApiFunction("vkQueueWaitIdle", result);

    if (IsVkError(result)) {
        auto file = OpenDumpFile();
        YAML::Emitter os(file.is_open() ? file : std::cerr);
        DumpDeviceExecutionState(*GetQueueDevice(queue), {}, true, kDeviceLostError, os);
    }

    return result;
}

VkResult Context::PreQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo) {
    PreApiFunction("vkQueuePresentKHR");
    return VK_SUCCESS;
}
VkResult Context::PostQueuePresentKHR(VkQueue queue, VkPresentInfoKHR const* pPresentInfo, VkResult result) {
    PostApiFunction("vkQueuePresentKHR", result);

    if (IsVkError(result)) {
        auto file = OpenDumpFile();
        YAML::Emitter os(file.is_open() ? file : std::cerr);
        DumpDeviceExecutionState(*GetQueueDevice(queue), {}, true, kDeviceLostError, os);
    }

    return result;
}

VkResult Context::PreWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                   uint64_t timeout) {
    PreApiFunction("vkWaitForFences");
    return VK_SUCCESS;
}
VkResult Context::PostWaitForFences(VkDevice device, uint32_t fenceCount, VkFence const* pFences, VkBool32 waitAll,
                                    uint64_t timeout, VkResult result) {
    PostApiFunction("vkWaitForFences", result);

    if (IsVkError(result)) {
        DumpDeviceExecutionState(device);
    }

    return result;
}

VkResult Context::PreGetFenceStatus(VkDevice device, VkFence fence) {
    PreApiFunction("vkGetFenceStatus");
    return VK_SUCCESS;
}
VkResult Context::PostGetFenceStatus(VkDevice device, VkFence fence, VkResult result) {
    PostApiFunction("vkGetFenceStatus", result);

    if (IsVkError(result)) {
        DumpDeviceExecutionState(device);
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
        DumpDeviceExecutionState(device);
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
        DumpDeviceExecutionState(device);
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

void Context::PostDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
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

void Context::PreDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {}
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
        CommandPoolPtr pool = std::make_unique<CommandPool>(
            *pCommandPool, pCreateInfo, device_state->GetVkQueueFamilyProperties(), device_state->HasBufferMarker());
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
    YAML::Emitter os;
    bool all_cb_ok = true;
    for (uint32_t i = 0; i < commandBufferCount; ++i) {
        all_cb_ok = all_cb_ok && device_state->ValidateCommandBufferNotInUse(pCommandBuffers[i], os);
    }
    if (!all_cb_ok) {
        DumpDeviceExecutionStateValidationFailed(*device_state, os);
    }

    device_state->DeleteCommandBuffers(commandPool, pCommandBuffers, commandBufferCount);
}

void Context::MakeOutputPath() {
    if (!output_path_created_) {
        output_path_created_ = true;
        MakeDir(output_path_);
    }
}

VkResult Context::PreCreateSemaphore(VkDevice device, VkSemaphoreCreateInfo const* pCreateInfo,
                                     const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore) {
    return VK_SUCCESS;
}
VkResult Context::PostCreateSemaphore(VkDevice device, VkSemaphoreCreateInfo const* pCreateInfo,
                                      const VkAllocationCallbacks* pAllocator, VkSemaphore* pSemaphore,
                                      VkResult result) {
    if (track_semaphores_ && result == VK_SUCCESS) {
        uint64_t s_value = 0;
        VkSemaphoreTypeKHR s_type = VK_SEMAPHORE_TYPE_BINARY_KHR;

        const auto* semaphore_info = vku::FindStructInPNextChain<VkSemaphoreTypeCreateInfoKHR>(pCreateInfo);
        if (semaphore_info) {
            s_value = semaphore_info->initialValue;
            s_type = semaphore_info->semaphoreType;
        }
        auto device_state = GetDevice(device);
        assert(device_state);

        device_state->GetSemaphoreTracker()->RegisterSemaphore(*pSemaphore, s_type, s_value);

        if (trace_all_semaphores_) {
            std::stringstream log;
            log << "Semaphore created. VkDevice:" << device_state->GetObjectName((uint64_t)device)
                << ", VkSemaphore: " << device_state->GetObjectName((uint64_t)(*pSemaphore));
            if (s_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                log << ", Type: Binary" << std::endl;
            } else {
                log << ", Type: Timeline, Initial value: " << s_value;
            }
            Log().Info(log.str());
        }
    }
    return result;
}

void Context::PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_ && trace_all_semaphores_) {
        auto device_state = GetDevice(device);
        assert(device_state);

        auto semaphore_tracker = device_state->GetSemaphoreTracker();

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
            log << "Latest value: Unknown" << std::endl;
        }
        Log().Info(log.str());
    }
}

void Context::PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_) {
        auto device_state = GetDevice(device);
        auto semaphore_tracker = device_state->GetSemaphoreTracker();
        semaphore_tracker->EraseSemaphore(semaphore);
    }
}

VkResult Context::PreSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo) {
    return VK_SUCCESS;
}
VkResult Context::PostSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo,
                                         VkResult result) {
    if (track_semaphores_ && result == VK_SUCCESS) {
        auto device_state = GetDevice(device);
        device_state->GetSemaphoreTracker()->SignalSemaphore(pSignalInfo->semaphore, pSignalInfo->value,
                                                             {SemaphoreModifierType::kModifierHost});
        if (trace_all_semaphores_) {
            std::string timeline_message = "Timeline semaphore signaled from host. VkDevice: ";
            timeline_message += device_state->GetObjectName((uint64_t)device) +
                                ", VkSemaphore: " + device_state->GetObjectName((uint64_t)(pSignalInfo->semaphore)) +
                                ", Signal value: " + std::to_string(pSignalInfo->value);
            Log().Info(timeline_message.c_str());
        }
    }
    return result;
}

VkResult Context::PreWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout) {
    if (track_semaphores_) {
        int tid = 0;
#ifdef __linux__
        tid = syscall(SYS_gettid);
#endif

#ifdef WIN32
        int pid = _getpid();
#else
        int pid = getpid();
#endif

        auto device_state = GetDevice(device);
        device_state->GetSemaphoreTracker()->BeginWaitOnSemaphores(pid, tid, pWaitInfo);

        if (trace_all_semaphores_) {
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
    return VK_SUCCESS;
}

VkResult Context::PostWaitSemaphoresKHR(VkDevice device, const VkSemaphoreWaitInfoKHR* pWaitInfo, uint64_t timeout,
                                        VkResult result) {
    if (IsVkError(result)) {
        DumpDeviceExecutionState(device);
        return result;
    }
    if (track_semaphores_ && (result == VK_SUCCESS || result == VK_TIMEOUT)) {
        int tid = 0;
#ifdef __linux__
        tid = syscall(SYS_gettid);
#endif

#ifdef WIN32
        int pid = _getpid();
#else
        int pid = getpid();
#endif
        auto device_state = GetDevice(device);

        {
            // Update semaphore values
            uint64_t semaphore_value;
            auto dispatch_table =
                crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(device))->dispatch_table;
            auto semaphore_tracker = device_state->GetSemaphoreTracker();
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                auto res =
                    dispatch_table.GetSemaphoreCounterValueKHR(device, pWaitInfo->pSemaphores[i], &semaphore_value);
                if (res == VK_SUCCESS) {
                    semaphore_tracker->SignalSemaphore(pWaitInfo->pSemaphores[i], semaphore_value,
                                                       {SemaphoreModifierType::kModifierHost});
                }
            }
            semaphore_tracker->EndWaitOnSemaphores(pid, tid, pWaitInfo);
        }

        if (trace_all_semaphores_) {
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

VkResult Context::PreGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue) {
    return VK_SUCCESS;
}
VkResult Context::PostGetSemaphoreCounterValueKHR(VkDevice device, VkSemaphore semaphore, uint64_t* pValue,
                                                  VkResult result) {
    if (IsVkError(result)) {
        DumpDeviceExecutionState(device);
    }
    return result;
}

const std::filesystem::path& Context::GetOutputPath() const { return output_path_; }

VkResult Context::PreDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo) {
    auto object_id = pNameInfo->object;

    auto name_info = std::make_unique<ObjectInfo>();
    name_info->object = pNameInfo->object;
    name_info->type = static_cast<VkObjectType>(pNameInfo->objectType);
    name_info->name = pNameInfo->pObjectName;

    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(object_id, std::move(name_info));

    return VK_SUCCESS;
};

VkResult Context::PostDebugMarkerSetObjectNameEXT(VkDevice device, const VkDebugMarkerObjectNameInfoEXT* pNameInfo,
                                                  VkResult result) {
    return result;
};

VkResult Context::PreSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo) {
    auto object_id = pNameInfo->objectHandle;

    auto name_info = std::make_unique<ObjectInfo>();
    name_info->object = pNameInfo->objectHandle;
    name_info->type = pNameInfo->objectType;
    name_info->name = pNameInfo->pObjectName;

    auto device_state = GetDevice(device);
    device_state->AddObjectInfo(object_id, std::move(name_info));

    return VK_SUCCESS;
}

VkResult Context::PostSetDebugUtilsObjectNameEXT(VkDevice device, const VkDebugUtilsObjectNameInfoEXT* pNameInfo,
                                                 VkResult result) {
    return VK_SUCCESS;
}

// =============================================================================
// Include the generated implementation to forward commands to command buffer
// =============================================================================
#include "cdl_commands.cc.inc"

// =============================================================================
// Define the custom pre intercepted commands
// =============================================================================
void Context::PreCmdBindPipeline(VkCommandBuffer commandBuffer, VkPipelineBindPoint pipelineBindPoint,
                                 VkPipeline pipeline) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    if (DumpShadersOnBind()) {
        p_cmd->GetDevice()->DumpShaderFromPipeline(pipeline);
    }

    p_cmd->PreCmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);
}

VkResult Context::PreBeginCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferBeginInfo const* pBeginInfo) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device->ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(*device, os);
        }
    }

    return p_cmd->PreBeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult Context::PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        auto device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device->ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(*device, os);
        }
    }

    return p_cmd->PreResetCommandBuffer(commandBuffer, flags);
}

VkResult Context::QueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit");
    auto device_state = GetQueueDevice(queue);
    auto result = device_state->QueueSubmit(queue, submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit", result);
    return result;
}

VkResult Context::QueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2");
    auto device_state = GetQueueDevice(queue);
    auto result = device_state->QueueSubmit2(queue, submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2", result);
    return result;
}

VkResult Context::QueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2KHR");
    auto device_state = GetQueueDevice(queue);
    auto result = device_state->QueueSubmit2(queue, submitCount, pSubmits, fence);
    PostApiFunction("vkQueueSubmit2KHR", result);
    return result;
}

VkResult Context::QueueBindSparse(VkQueue queue, uint32_t bindInfoCount, VkBindSparseInfo const* pBindInfo,
                                  VkFence fence) {
    PreApiFunction("vkQueueBindSparse");
    auto device_state = GetQueueDevice(queue);
    auto result = device_state->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    PostApiFunction("vkQueueBindSparse", result);
    return result;
}

VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                        VkInstance* pInstance, Interceptor** interceptor) {
    auto* context = new Context(pCreateInfo, pAllocator);
    *interceptor = context;
    return VK_SUCCESS;
}

}  // namespace crash_diagnostic_layer
