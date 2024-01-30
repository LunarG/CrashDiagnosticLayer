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
    logger_.LogInfo("Version %s enabled.", kCdlVersion);

    const auto* create_info = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pCreateInfo);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result =
        vkuCreateLayerSettingSet("lunarg_crash_diagnostic", create_info, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        logger_.LogError("vkuCreateLayerSettingSet failed with error %d", result);
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
            logger_.LogInfo("Begin Watchdog: %" PRId64 "ms", watchdog_timer_ms_);
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

void Context::MakeDir(const std::filesystem::path& path) {
#if defined(WIN32)
    int mkdir_result = _mkdir(path.string().c_str());
#else
    int mkdir_result = mkdir(path.string().c_str(), ACCESSPERMS);
#endif

    if (mkdir_result && EEXIST != errno) {
        logger_.LogError("Error creating output directory \'%s\': %s", path.string().c_str(), strerror(errno));
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
        logger_.LogInfo("Stopping Watchdog");
        watchdog_running_ = false;  // TODO: condition variable that waits
        watchdog_thread_->join();
        logger_.LogInfo("Watchdog Stopped");
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
            logger_.LogInfo("CDL: Watchdog check failed, no submit in %" PRId64 "ms", ms);

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
        logger_.LogInfo("{ %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name) {
    if (trace_all_) {
        logger_.LogInfo("} %s", api_name);
    }
}

void Context::PostApiFunction(const char* api_name, VkResult result) {
    if (trace_all_) {
        logger_.LogInfo("} %s (%s)", api_name, string_VkResult(result));
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
        logger_.LogError("No VK_AMD_buffer_marker extension, progression tracking will be disabled. ");
    }
    if (extensions_present.amd_coherent_memory) {
        if (!extensions_enabled.amd_coherent_memory) {
            extensions_enabled.amd_coherent_memory = true;
            auto amd_device_coherent = vku::InitStruct<VkPhysicalDeviceCoherentMemoryFeaturesAMD>(nullptr, VK_TRUE);
            vku::AddToPnext(device_ci->modified, amd_device_coherent);
            vku::AddExtension(device_ci->modified, VK_AMD_DEVICE_COHERENT_MEMORY_EXTENSION_NAME);
        }
    } else {
        logger_.LogError("No VK_AMD_device_coherent_memory extension, results may not be as accurate as possible.");
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
        logger_.LogWarning("No VK_EXT_device_fault extension, vendor-specific crash dumps will not be available.");
    }
    if (extensions_present.ext_device_address_binding_report) {
        if (!extensions_enabled.ext_device_address_binding_report) {
            auto ext_device_address_binding_report =
                vku::InitStruct<VkPhysicalDeviceAddressBindingReportFeaturesEXT>(nullptr, VK_TRUE);
            vku::AddToPnext(device_ci->modified, ext_device_address_binding_report);
            vku::AddExtension(device_ci->modified, VK_EXT_DEVICE_ADDRESS_BINDING_REPORT_EXTENSION_NAME);
        }
    } else {
        logger_.LogWarning(
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

void Context::AddObjectInfo(VkDevice device, uint64_t handle, ObjectInfoPtr info) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    if (devices_.find(device) != devices_.end()) {
        devices_[device]->AddObjectInfo(handle, std::move(info));
    }
}

std::string Context::GetObjectName(VkDevice vk_device, uint64_t handle) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    if (devices_.find(vk_device) != devices_.end()) {
        return devices_[vk_device]->GetObjectName(handle);
    }
    return Uint64ToStr(handle);
}

std::string Context::GetObjectInfo(VkDevice vk_device, uint64_t handle) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    if (devices_.find(vk_device) != devices_.end()) {
        return devices_[vk_device]->GetObjectInfo(handle);
    }
    return Uint64ToStr(handle);
}

void Context::DumpAllDevicesExecutionState(CrashSource crash_source) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    bool dump_prologue = true;
    auto file = OpenDumpFile();
    YAML::Emitter os(file.is_open() ? file : std::cerr);

    for (auto& it : devices_) {
        auto device = it.second.get();
        DumpDeviceExecutionState(device, dump_prologue, crash_source, os);
        dump_prologue = false;
    }
}

void Context::DumpDeviceExecutionState(VkDevice vk_device) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    if (devices_.find(vk_device) != devices_.end()) {
        auto file = OpenDumpFile();
        YAML::Emitter os(file.is_open() ? file : std::cerr);
        DumpDeviceExecutionState(devices_[vk_device].get(), {}, true, kDeviceLostError, os);
    }
}

void Context::DumpDeviceExecutionState(const Device* device, bool dump_prologue, CrashSource crash_source,
                                       YAML::Emitter& os) {
    DumpDeviceExecutionState(device, {}, dump_prologue, crash_source, os);
}

void Context::DumpDeviceExecutionState(const Device* device, std::string error_report, bool dump_prologue,
                                       CrashSource crash_source, YAML::Emitter& os) {
    if (!device) {
        return;
    }

    if (dump_prologue) {
        DumpReportPrologue(os, device);
    }

    device->Print(os);

    if (track_semaphores_) {
        device->GetSubmitTracker()->DumpWaitingSubmits(os);
        device->GetSemaphoreTracker()->DumpWaitingThreads(os);
    }
    if (!error_report.empty()) {
        os << error_report;
    }
    auto options = CommandBufferDumpOption::kDefault;
    if (debug_dump_all_command_buffers_) options |= CommandBufferDumpOption::kDumpAllCommands;

    if (debug_autodump_rate_ > 0 || debug_dump_all_command_buffers_) {
        device->DumpAllCommandBuffers(os, options);
    } else {
        device->DumpIncompleteCommandBuffers(os, options);
    }
    os << YAML::EndMap;
}

void Context::DumpDeviceExecutionStateValidationFailed(const Device* device, YAML::Emitter& os) {
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

void Context::DumpReportPrologue(YAML::Emitter& os, const Device* device) {
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
    os << YAML::Key << "vkHandle" << YAML::Value << device->GetObjectInfo((uint64_t)vk_instance_);
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
    logger_.LogError(ss.str());

    std::ofstream fs(dump_file_path);
    if (!fs.is_open()) {
        logger_.LogError("UNABLE TO OPEN LOG FILE");
    }
    fs << std::unitbuf;
    return fs;
}

VkCommandPool Context::GetHelperCommandPool(VkDevice vk_device, VkQueue vk_queue) {
    assert(track_semaphores_ == true);
    if (vk_device == VK_NULL_HANDLE || vk_queue == VK_NULL_HANDLE) {
        return VK_NULL_HANDLE;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    uint32_t queue_family_index = devices_[vk_device]->GetQueueFamilyIndex(vk_queue);
    return devices_[vk_device]->GetHelperCommandPool(queue_family_index);
}

SubmitInfoId Context::RegisterSubmitInfo(VkDevice vk_device, QueueSubmitId queue_submit_id,
                                         const VkSubmitInfo* vk_submit_info) {
    assert(track_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto submit_info_id = devices_[vk_device]->GetSubmitTracker()->RegisterSubmitInfo(queue_submit_id, vk_submit_info);
    return submit_info_id;
}

void Context::StoreSubmitHelperCommandBuffersInfo(VkDevice vk_device, SubmitInfoId submit_info_id,
                                                  VkCommandPool vk_pool, VkCommandBuffer start_marker_cb,
                                                  VkCommandBuffer end_marker_cb) {
    assert(track_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devices_[vk_device]->GetSubmitTracker()->StoreSubmitHelperCommandBuffersInfo(submit_info_id, vk_pool,
                                                                                 start_marker_cb, end_marker_cb);
}

void Context::RecordSubmitStart(VkDevice vk_device, QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id,
                                VkCommandBuffer vk_command_buffer) {
    assert(track_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devices_[vk_device]->GetSubmitTracker()->RecordSubmitStart(qsubmit_id, submit_info_id, vk_command_buffer);
}

void Context::RecordSubmitFinish(VkDevice vk_device, QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id,
                                 VkCommandBuffer vk_command_buffer) {
    assert(track_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto submit_tracker = devices_[vk_device]->GetSubmitTracker();
    submit_tracker->RecordSubmitFinish(qsubmit_id, submit_info_id, vk_command_buffer);
    submit_tracker->CleanupSubmitInfos();
}

void Context::LogSubmitInfoSemaphores(VkDevice vk_device, VkQueue vk_queue, SubmitInfoId submit_info_id) {
    assert(track_semaphores_ == true);
    assert(trace_all_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto submit_tracker = devices_[vk_device]->GetSubmitTracker();
    if (submit_tracker->SubmitInfoHasSemaphores(submit_info_id)) {
        std::string semaphore_log = submit_tracker->GetSubmitInfoSemaphoresLog(vk_device, vk_queue, submit_info_id);
        logger_.LogInfo(semaphore_log);
    }
}

void Context::RecordBindSparseHelperSubmit(VkDevice vk_device, QueueBindSparseId qbind_sparse_id,
                                           const VkSubmitInfo* vk_submit_info, VkCommandPool vk_pool) {
    assert(track_semaphores_ == true);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto submit_tracker = devices_[vk_device]->GetSubmitTracker();
    submit_tracker->CleanupBindSparseHelperSubmits();
    submit_tracker->RecordBindSparseHelperSubmit(qbind_sparse_id, vk_submit_info, vk_pool);
}

VkDevice Context::GetQueueDevice(VkQueue queue) {
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    auto it = queue_device_tracker_.find(queue);
    if (it == queue_device_tracker_.end()) {
        logger_.LogWarning("queue 0x" PRIx64 " cannot be linked to any device.", (uint64_t)(queue));
        return VK_NULL_HANDLE;
    }
    return it->second;
}

bool Context::ShouldExpandQueueBindSparseToTrackSemaphores(PackedBindSparseInfo* packed_bind_sparse_info) {
    assert(track_semaphores_ == true);
    VkDevice vk_device = GetQueueDevice(packed_bind_sparse_info->queue);
    assert(vk_device != VK_NULL_HANDLE);
    std::lock_guard<std::mutex> lock(devices_mutex_);
    packed_bind_sparse_info->semaphore_tracker = devices_[vk_device]->GetSemaphoreTracker();
    return BindSparseUtils::ShouldExpandQueueBindSparseToTrackSemaphores(packed_bind_sparse_info);
}

void Context::ExpandBindSparseInfo(ExpandedBindSparseInfo* bind_sparse_expand_info) {
    return BindSparseUtils::ExpandBindSparseInfo(bind_sparse_expand_info);
}

void Context::LogBindSparseInfosSemaphores(VkQueue vk_queue, uint32_t bind_info_count,
                                           const VkBindSparseInfo* bind_infos) {
    assert(track_semaphores_ == true);
    assert(trace_all_semaphores_ == true);
    VkDevice vk_device = GetQueueDevice(vk_queue);
    if (vk_device == VK_NULL_HANDLE) {
        return;
    }
    std::lock_guard<std::mutex> lock(devices_mutex_);
    auto log = BindSparseUtils::LogBindSparseInfosSemaphores(devices_[vk_device].get(), vk_device, vk_queue,
                                                             bind_info_count, bind_infos);
    logger_.LogInfo(log);
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
    Logger* logger = context->GetLogger();
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
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        bool multi_device = devices_.size() > 1;
        for (auto& dev : devices_) {
            dev.second->MemoryBindEvent(rec, multi_device);
        }
    }
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

// TODO(b/141996712): extensions should be down at the intercept level, not
// pre/post OR intercept should always extend/copy list
VkResult Context::PostCreateDevice(VkPhysicalDevice physicalDevice, const VkDeviceCreateInfo* pCreateInfo,
                                   const VkAllocationCallbacks* pAllocator, VkDevice* pDevice, VkResult callResult) {
    if (callResult != VK_SUCCESS) return callResult;

    auto extensions_present =
        DecodeExtensionStrings(pCreateInfo->enabledExtensionCount, pCreateInfo->ppEnabledExtensionNames);

    VkDevice vk_device = *pDevice;
    DevicePtr device = std::make_unique<Device>(this, physicalDevice, *pDevice, extensions_present);

    {
        std::lock_guard<std::mutex> lock(device_create_infos_mutex_);
        device->SetDeviceCreateInfo(std::move(device_create_infos_[pCreateInfo]));
        device_create_infos_.erase(pCreateInfo);
    }
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        devices_[vk_device] = std::move(device);
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
                logger_.LogWarning("failed to create command pools for helper command  buffers. VkDevice: 0x" PRIx64
                                   ", queueFamilyIndex: %d",
                                   (uint64_t)(vk_device), queue_family_index);
            } else {
                std::lock_guard<std::mutex> lock(devices_mutex_);
                devices_[vk_device]->RegisterHelperCommandPool(queue_family_index, command_pool);
            }
        }
    }

    return VK_SUCCESS;
}

void Context::PreDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_) {
        auto dispatch_table =
            crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(device))->dispatch_table;
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto command_pools = devices_[device]->ReturnAndEraseCommandPools();
        for (auto& command_pool : command_pools) {
            dispatch_table.DestroyCommandPool(device, command_pool, nullptr);
        }
    }
}

void Context::PostDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lock(devices_mutex_);

    auto it = devices_.find(device);
    if (it != devices_.end()) {
        devices_.erase(it);
    }
}

void Context::PostGetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue) {
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        devices_[device]->RegisterQueueFamilyIndex(*pQueue, queueFamilyIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

void Context::PreGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {}
void Context::PostGetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue) {
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        devices_[device]->RegisterQueueFamilyIndex(*pQueue, pQueueInfo->queueFamilyIndex);
    }
    std::lock_guard<std::mutex> lock(queue_device_tracker_mutex_);
    queue_device_tracker_[*pQueue] = device;
}

VkResult Context::PreQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit");
    last_submit_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch())
                            .count();

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferCount;
             ++command_buffer_index) {
            auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(submit_info.pCommandBuffers[command_buffer_index]);
            if (p_cmd != nullptr) {
                p_cmd->QueueSubmit(queue, fence);
            }
        }
    }

    return VK_SUCCESS;
}

VkResult Context::PreQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence) {
    PreApiFunction("vkQueueSubmit2");

    last_submit_time_ = std::chrono::duration_cast<std::chrono::milliseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch())
                            .count();

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        const auto& submit_info = pSubmits[submit_index];
        for (uint32_t command_buffer_index = 0; command_buffer_index < submit_info.commandBufferInfoCount;
             ++command_buffer_index) {
            auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(
                submit_info.pCommandBufferInfos[command_buffer_index].commandBuffer);
            if (p_cmd != nullptr) {
                p_cmd->QueueSubmit(queue, fence);
            }
        }
    }

    return VK_SUCCESS;
}

VkResult Context::PreQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                     VkFence fence) {
    PreApiFunction("vkQueueSubmit2KHR");
    return PreQueueSubmit2(queue, submitCount, pSubmits, fence);
}

// Return true if this is a VkResult that CDL considers an error.
bool IsVkError(VkResult result) { return result == VK_ERROR_DEVICE_LOST || result == VK_ERROR_INITIALIZATION_FAILED; }

VkResult Context::PostQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence,
                                  VkResult result) {
    PostApiFunction("vkQueueSubmit", result);
    total_submits_++;

    bool dump = IsVkError(result) || (debug_autodump_rate_ > 0 && (total_submits_ % debug_autodump_rate_) == 0);

    if (dump) {
        DumpDeviceExecutionState(GetQueueDevice(queue));
    }
    return result;
}

VkResult Context::PostQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence,
                                   VkResult result) {
    PostApiFunction("vkQueueSubmit2", result);
    total_submits_++;

    bool dump = IsVkError(result) || (debug_autodump_rate_ > 0 && (total_submits_ % debug_autodump_rate_) == 0);

    if (dump) {
        DumpDeviceExecutionState(GetQueueDevice(queue));
    }
    return result;
}

VkResult Context::PostQueueSubmit2KHR(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence,
                                      VkResult result) {
    PostApiFunction("vkQueueSubmit2KHR", result);
    return PostQueueSubmit2(queue, submitCount, pSubmits, fence, result);
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
        DumpDeviceExecutionState(GetQueueDevice(queue));
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
        DumpDeviceExecutionState(GetQueueDevice(queue));
    }

    return result;
}

VkResult Context::PreQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, VkBindSparseInfo const* pBindInfo,
                                     VkFence fence) {
    PreApiFunction("vkQueueBindSparse");
    return VK_SUCCESS;
}
VkResult Context::PostQueueBindSparse(VkQueue queue, uint32_t bindInfoCount, VkBindSparseInfo const* pBindInfo,
                                      VkFence fence, VkResult result) {
    PostApiFunction("vkQueueBindSparse", result);

    if (IsVkError(result)) {
        DumpDeviceExecutionState(GetQueueDevice(queue));
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
        std::lock_guard<std::mutex> lock(devices_mutex_);
        Device* p_device = devices_[device].get();
        p_device->CreateShaderModule(pCreateInfo, pShaderModule, shader_module_load_options_);
    }
    return callResult;
}

void Context::PostDestroyShaderModule(VkDevice device, VkShaderModule shaderModule,
                                      const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    devices_[device]->DeleteShaderModule(shaderModule);
}

VkResult Context::PostCreateGraphicsPipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                              const VkGraphicsPipelineCreateInfo* pCreateInfos,
                                              const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                              VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        Device* p_device = devices_[device].get();
        p_device->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

VkResult Context::PostCreateComputePipelines(VkDevice device, VkPipelineCache pipelineCache, uint32_t createInfoCount,
                                             const VkComputePipelineCreateInfo* pCreateInfos,
                                             const VkAllocationCallbacks* pAllocator, VkPipeline* pPipelines,
                                             VkResult callResult) {
    if (callResult == VK_SUCCESS) {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        Device* p_device = devices_[device].get();
        p_device->CreatePipeline(createInfoCount, pCreateInfos, pPipelines);
    }
    return callResult;
}

void Context::PreDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {}
void Context::PostDestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator) {
    std::lock_guard<std::mutex> lock(devices_mutex_);
    Device* p_device = devices_[device].get();
    p_device->DeletePipeline(pipeline);
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
        std::lock_guard<std::mutex> lock_devices(devices_mutex_);
        Device* p_device = devices_[device].get();
        CommandPoolPtr pool = std::make_unique<CommandPool>(
            *pCommandPool, pCreateInfo, p_device->GetVkQueueFamilyProperties(), p_device->HasBufferMarker());
        p_device->SetCommandPool(*pCommandPool, std::move(pool));
    }
    return callResult;
}

void Context::PreDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                    const VkAllocationCallbacks* pAllocator) {
    PreApiFunction("vkDestroyCommandPool");

    std::lock_guard<std::mutex> lock_devices(devices_mutex_);
    YAML::Emitter os;
    devices_[device]->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(devices_[device].get(), os);
    }
}

void Context::PostDestroyCommandPool(VkDevice device, VkCommandPool commandPool,
                                     const VkAllocationCallbacks* pAllocator) {
    PostApiFunction("vkDestroyCommandPool");

    std::lock_guard<std::mutex> lock_devices(devices_mutex_);
    devices_[device]->DeleteCommandPool(commandPool);
}

VkResult Context::PreResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags) {
    PreApiFunction("vkResetCommandPool");

    std::lock_guard<std::mutex> lock_devices(devices_mutex_);
    YAML::Emitter os;
    devices_[device]->ValidateCommandPoolState(commandPool, os);
    if (os.size() > 0) {
        DumpDeviceExecutionStateValidationFailed(devices_[device].get(), os);
    }
    return VK_SUCCESS;
}

VkResult Context::PostResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags,
                                       VkResult callResult) {
    PostApiFunction("vkResetCommandPool");

    std::lock_guard<std::mutex> lock_devices(devices_mutex_);
    devices_[device]->ResetCommandPool(commandPool);

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

        std::lock_guard<std::mutex> lock_devices(devices_mutex_);

        Device* p_device = devices_[device].get();
        auto vk_pool = pAllocateInfo->commandPool;
        p_device->AllocateCommandBuffers(vk_pool, pAllocateInfo, pCommandBuffers);
        auto has_buffer_markers = p_device->GetCommandPool(vk_pool)->HasBufferMarkers();

        // create command buffers tracking data
        for (uint32_t i = 0; i < pAllocateInfo->commandBufferCount; ++i) {
            VkCommandBuffer vk_cmd = pCommandBuffers[i];

            auto cmd = std::make_unique<CommandBuffer>(p_device, vk_pool, vk_cmd, pAllocateInfo, has_buffer_markers);
            cmd->SetInstrumentAllCommands(instrument_all_commands_);

            crash_diagnostic_layer::SetCommandBuffer(vk_cmd, std::move(cmd));
            p_device->AddCommandBuffer(vk_cmd);
        }
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

    std::lock_guard<std::mutex> lock_devices(devices_mutex_);
    YAML::Emitter os;
    bool all_cb_ok = true;
    for (uint32_t i = 0; i < commandBufferCount; ++i) {
        all_cb_ok = all_cb_ok && devices_[device]->ValidateCommandBufferNotInUse(pCommandBuffers[i], os);
    }
    if (!all_cb_ok) {
        DumpDeviceExecutionStateValidationFailed(devices_[device].get(), os);
    }

    devices_[device]->GetCommandPool(commandPool)->FreeCommandBuffers(commandBufferCount, pCommandBuffers);

    // Free the command buffer objects.
    devices_[device]->DeleteCommandBuffers(pCommandBuffers, commandBufferCount);
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
        {
            std::lock_guard<std::mutex> lock(devices_mutex_);
            devices_[device]->GetSemaphoreTracker()->RegisterSemaphore(*pSemaphore, s_type, s_value);
        }
        if (trace_all_semaphores_) {
            std::stringstream log;
            log << "Semaphore created. VkDevice:" << GetObjectName(device, (uint64_t)device)
                << ", VkSemaphore: " << GetObjectName(device, (uint64_t)(*pSemaphore));
            if (s_type == VK_SEMAPHORE_TYPE_BINARY_KHR) {
                log << ", Type: Binary" << std::endl;
            } else {
                log << ", Type: Timeline, Initial value: " << s_value;
            }
            logger_.LogInfo(log.str());
        }
    }
    return result;
}

void Context::PreDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_) {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto& dev_object = *devices_[device];
        auto semaphore_tracker = dev_object.GetSemaphoreTracker();
        if (trace_all_semaphores_) {
            std::stringstream log;
            log << "Semaphore destroyed. VkDevice:" << dev_object.GetObjectName((uint64_t)device)
                << ", VkSemaphore: " << dev_object.GetObjectName((uint64_t)(semaphore));
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
            logger_.LogInfo(log.str());
        }
    }
}
void Context::PostDestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator) {
    if (track_semaphores_) {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto semaphore_tracker = devices_[device]->GetSemaphoreTracker();
        semaphore_tracker->EraseSemaphore(semaphore);
    }
}

VkResult Context::PreSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo) {
    return VK_SUCCESS;
}
VkResult Context::PostSignalSemaphoreKHR(VkDevice device, const VkSemaphoreSignalInfoKHR* pSignalInfo,
                                         VkResult result) {
    if (track_semaphores_ && result == VK_SUCCESS) {
        {
            std::lock_guard<std::mutex> lock(devices_mutex_);
            devices_[device]->GetSemaphoreTracker()->SignalSemaphore(pSignalInfo->semaphore, pSignalInfo->value,
                                                                     {SemaphoreModifierType::kModifierHost});
        }
        if (trace_all_semaphores_) {
            std::string timeline_message = "Timeline semaphore signaled from host. VkDevice: ";
            timeline_message += GetObjectName(device, (uint64_t)device) +
                                ", VkSemaphore: " + GetObjectName(device, (uint64_t)(pSignalInfo->semaphore)) +
                                ", Signal value: " + std::to_string(pSignalInfo->value);
            logger_.LogInfo(timeline_message.c_str());
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

        {
            std::lock_guard<std::mutex> lock(devices_mutex_);
            devices_[device]->GetSemaphoreTracker()->BeginWaitOnSemaphores(pid, tid, pWaitInfo);
        }
        if (trace_all_semaphores_) {
            std::stringstream log;
            log << "Waiting for timeline semaphores on host. PID: " << pid << ", TID: " << tid
                << ", VkDevice: " << GetObjectName(device, (uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << GetObjectName(device, (uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            logger_.LogInfo(log.str());
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

        {
            // Update semaphore values
            uint64_t semaphore_value;
            auto dispatch_table =
                crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(device))->dispatch_table;
            std::lock_guard<std::mutex> lock(devices_mutex_);
            auto semaphore_tracker = devices_[device]->GetSemaphoreTracker();
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
                << ", VkDevice: " << GetObjectName(device, (uint64_t)device) << std::endl;
            for (uint32_t i = 0; i < pWaitInfo->semaphoreCount; i++) {
                log << "\tVkSemaphore: " << GetObjectName(device, (uint64_t)(pWaitInfo->pSemaphores[i]))
                    << ", Wait value: " << pWaitInfo->pValues[i] << std::endl;
            }
            logger_.LogInfo(log.str());
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
    AddObjectInfo(device, object_id, std::move(name_info));

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
    AddObjectInfo(device, object_id, std::move(name_info));

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
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device->ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreBeginCommandBuffer(commandBuffer, pBeginInfo);
}

VkResult Context::PreResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags) {
    auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);
    {
        std::lock_guard<std::mutex> lock(devices_mutex_);
        auto device = p_cmd->GetDevice();
        YAML::Emitter os;
        if (!device->ValidateCommandBufferNotInUse(commandBuffer, os)) {
            DumpDeviceExecutionStateValidationFailed(device, os);
        }
    }

    return p_cmd->PreResetCommandBuffer(commandBuffer, flags);
}

// =============================================================================
// Custom Vulkan entry points
// TODO: these appear to be unused
// =============================================================================

VkResult QueueSubmitWithoutTrackingSemaphores(VkQueue queue, uint32_t submitCount, VkSubmitInfo const* pSubmits,
                                              VkFence fence, bool callPreQueueSubmit = true) {
    auto* device_data = crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(queue));
    auto* context = static_cast<Context*>(device_data->interceptor);
    if (callPreQueueSubmit) {
        context->PreQueueSubmit(queue, submitCount, pSubmits, fence);
    }

    VkResult res = VK_SUCCESS;
    auto dispatch_table =
        crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(queue))->dispatch_table;
    if (dispatch_table.QueueSubmit) {
        res = dispatch_table.QueueSubmit(queue, submitCount, pSubmits, fence);
    }

    context->PostQueueSubmit(queue, submitCount, pSubmits, fence, res);

    return res;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(PFN_vkQueueSubmit fp_queue_submit, VkQueue queue, uint32_t submitCount,
                                           VkSubmitInfo const* pSubmits, VkFence fence) {
    auto* device_data = crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(queue));
    auto* context = static_cast<Context*>(device_data->interceptor);
    bool track_semaphores = context->TrackingSemaphores();
    if (!track_semaphores) {
        return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence);
    }

    // Track semaphore values before and after each queue submit.
    context->PreQueueSubmit(queue, submitCount, pSubmits, fence);
    bool call_pre_queue_submit = false;

    // Define common variables and structs used for each extended queue submit
    VkDevice vk_device = context->GetQueueDevice(queue);
    auto dispatch_table =
        crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(vk_device))->dispatch_table;
    VkCommandPool vk_pool = context->GetHelperCommandPool(vk_device, queue);
    if (vk_pool == VK_NULL_HANDLE) {
        context->GetLogger()->LogError(
            "failed to find the helper command pool to allocate helper command buffers for tracking queue submit "
            "state. Not tracking semaphores.");
        return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence, call_pre_queue_submit);
    }

    bool trace_all_semaphores = context->TracingAllSemaphores();
    auto queue_submit_id = context->GetNextQueueSubmitId();
    auto semaphore_tracking_submits = reinterpret_cast<VkSubmitInfo*>(alloca(sizeof(VkSubmitInfo) * submitCount));

    // VkCommandBufferAllocateInfo for helper command buffers. Two extra CBs used
    // to track the state of submits and semaphores. We create the extra CBs from
    // the same pool used to create the original CBs of the submit. These extra
    // CBs are used to record vkCmdWriteBufferMarkerAMD commands into.
    VkCommandBufferAllocateInfo cb_allocate_info = {};
    cb_allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cb_allocate_info.pNext = nullptr;
    cb_allocate_info.commandPool = vk_pool;
    cb_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cb_allocate_info.commandBufferCount = 2;

    for (uint32_t submit_index = 0; submit_index < submitCount; ++submit_index) {
        // TODO b/152057973: Recycle state tracking CBs
        VkCommandBuffer* new_buffers = crash_diagnostic_layer::NewArray<VkCommandBuffer>(2);
        auto result = dispatch_table.AllocateCommandBuffers(vk_device, &cb_allocate_info, new_buffers);
        assert(result == VK_SUCCESS);
        if (result != VK_SUCCESS) {
            context->GetLogger()->LogWarning(
                "failed to allocate helper command buffers for tracking queue submit state. vkAllocateCommandBuffers() "
                "returned 0x%08x",
                result);
            return QueueSubmitWithoutTrackingSemaphores(queue, submitCount, pSubmits, fence, call_pre_queue_submit);
        }

        // Add the semaphore tracking command buffers to the beginning and the end
        // of the queue submit info.
        semaphore_tracking_submits[submit_index] = pSubmits[submit_index];
        auto cb_count = pSubmits[submit_index].commandBufferCount;
        VkCommandBuffer* extended_cbs = (VkCommandBuffer*)alloca((cb_count + 2) * sizeof(VkCommandBuffer));
        semaphore_tracking_submits[submit_index].pCommandBuffers = extended_cbs;
        semaphore_tracking_submits[submit_index].commandBufferCount = cb_count + 2;

        extended_cbs[0] = new_buffers[0];
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            extended_cbs[cb_index + 1] = pSubmits[submit_index].pCommandBuffers[cb_index];
        }
        extended_cbs[cb_count + 1] = new_buffers[1];

        SetDeviceLoaderData(vk_device, extended_cbs[0]);
        SetDeviceLoaderData(vk_device, extended_cbs[cb_count + 1]);

        auto submit_info_id =
            context->RegisterSubmitInfo(vk_device, queue_submit_id, &semaphore_tracking_submits[submit_index]);
        context->StoreSubmitHelperCommandBuffersInfo(vk_device, submit_info_id, vk_pool, extended_cbs[0],
                                                     extended_cbs[cb_count + 1]);
        for (uint32_t cb_index = 0; cb_index < cb_count; ++cb_index) {
            auto command_buffer =
                crash_diagnostic_layer::GetCommandBuffer(pSubmits[submit_index].pCommandBuffers[cb_index]);
            assert(command_buffer != nullptr);
            if (command_buffer) {
                command_buffer->SetSubmitInfoId(submit_info_id);
            }
        }

        // Record the two semaphore tracking command buffers.
        VkCommandBufferBeginInfo commandBufferBeginInfo = {};
        commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        commandBufferBeginInfo.flags = 0;
        result = dispatch_table.BeginCommandBuffer(extended_cbs[0], &commandBufferBeginInfo);
        assert(result == VK_SUCCESS);
        if (result != VK_SUCCESS) {
            context->GetLogger()->LogWarning(
                "failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        } else {
            context->RecordSubmitStart(vk_device, queue_submit_id, submit_info_id, extended_cbs[0]);
            result = dispatch_table.EndCommandBuffer(extended_cbs[0]);
            assert(result == VK_SUCCESS);
        }

        result = dispatch_table.BeginCommandBuffer(extended_cbs[cb_count + 1], &commandBufferBeginInfo);
        assert(result == VK_SUCCESS);
        if (result != VK_SUCCESS) {
            context->GetLogger()->LogWarning(
                "failed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        } else {
            context->RecordSubmitFinish(vk_device, queue_submit_id, submit_info_id, extended_cbs[cb_count + 1]);
            result = dispatch_table.EndCommandBuffer(extended_cbs[cb_count + 1]);
            assert(result == VK_SUCCESS);
        }
        if (trace_all_semaphores) {
            context->LogSubmitInfoSemaphores(vk_device, queue, submit_info_id);
        }
    }

    VkResult res = VK_SUCCESS;
    if (dispatch_table.QueueSubmit) {
        res = dispatch_table.QueueSubmit(queue, submitCount, semaphore_tracking_submits, fence);
    }

    context->PostQueueSubmit(queue, submitCount, semaphore_tracking_submits, fence, res);
    return res;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(PFN_vkQueueBindSparse fp_queue_bind_sparse, VkQueue queue,
                                               uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo,
                                               VkFence fence) {
    auto* device_data = crash_diagnostic_layer::GetDeviceLayerData(crash_diagnostic_layer::DataKey(queue));
    auto dispatch_table = device_data->dispatch_table;
    auto* context = static_cast<Context*>(device_data->interceptor);
    bool track_semaphores = context->TrackingSemaphores();
    // If semaphore tracking is not requested, pass the call to the dispatch table
    // as is.
    if (!track_semaphores) {
        return dispatch_table.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    }

    auto qbind_sparse_id = context->GetNextQueueBindSparseId();
    bool trace_all_semaphores = context->TracingAllSemaphores();
    if (track_semaphores && trace_all_semaphores) {
        context->LogBindSparseInfosSemaphores(queue, bindInfoCount, pBindInfo);
    }

    // Ensure the queue is registered before and we know which command pool use
    // for this queue. If not, pass the call to dispatch table.
    VkDevice vk_device = context->GetQueueDevice(queue);
    VkCommandPool vk_pool = context->GetHelperCommandPool(vk_device, queue);
    if (vk_device == VK_NULL_HANDLE || vk_pool == VK_NULL_HANDLE) {
        context->GetLogger()->LogWarning("device handle not found for queue 0x" PRIx64
                                         ", Ignoring semaphore signals in vkQueueBindSparse call.",
                                         (uint64_t)queue);
        return dispatch_table.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    }

    // If we don't need to expand the bind sparse info, pass the call to dispatch
    // table.
    crash_diagnostic_layer::PackedBindSparseInfo packed_bind_sparse_info(queue, bindInfoCount, pBindInfo);
    if (!context->ShouldExpandQueueBindSparseToTrackSemaphores(&packed_bind_sparse_info)) {
        return dispatch_table.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    }

    crash_diagnostic_layer::ExpandedBindSparseInfo expanded_bind_sparse_info(&packed_bind_sparse_info);
    context->ExpandBindSparseInfo(&expanded_bind_sparse_info);

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
    VkCommandBuffer* helper_cbs = (VkCommandBuffer*)alloca((num_submits) * sizeof(VkCommandBuffer));

    VkCommandBufferAllocateInfo cb_allocate_info = {};
    cb_allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    cb_allocate_info.pNext = nullptr;
    cb_allocate_info.commandPool = vk_pool;
    cb_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cb_allocate_info.commandBufferCount = num_submits;
    // TODO b/152057973: Recycle state tracking CBs
    VkCommandBuffer* new_buffers = crash_diagnostic_layer::NewArray<VkCommandBuffer>(num_submits);
    auto result = dispatch_table.AllocateCommandBuffers(vk_device, &cb_allocate_info, new_buffers);
    assert(result == VK_SUCCESS);
    if (result != VK_SUCCESS) {
        context->GetLogger()->LogWarning(
            "failed to allocate helper command buffers for tracking queue bind sparse state. "
            "vkAllocateCommandBuffers() returned 0x%08x",
            result);
        // Silently pass the call to the dispatch table.
        return dispatch_table.QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
    }
    for (uint32_t i = 0; i < num_submits; i++) {
        helper_cbs[i] = new_buffers[i];
    }

    VkCommandBufferBeginInfo commandBufferBeginInfo = {};
    commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    commandBufferBeginInfo.flags = 0;

    uint32_t next_wait_helper_submit = 0;
    for (uint32_t i = 0; i < num_submits; i++) {
        expanded_bind_sparse_info.submit_infos[i].pCommandBuffers = &helper_cbs[i];
        expanded_bind_sparse_info.submit_infos[i].commandBufferCount = 1;
        SetDeviceLoaderData(vk_device, helper_cbs[i]);

        result = dispatch_table.BeginCommandBuffer(helper_cbs[i], &commandBufferBeginInfo);
        assert(result == VK_SUCCESS);
        if (result != VK_SUCCESS) {
            context->GetLogger()->LogWarning(
                "ailed to begin helper command buffer. vkBeginCommandBuffer() returned 0x%08x", result);
        } else {
            context->RecordBindSparseHelperSubmit(vk_device, qbind_sparse_id,
                                                  &expanded_bind_sparse_info.submit_infos[i], vk_pool);
            result = dispatch_table.EndCommandBuffer(helper_cbs[i]);
            assert(result == VK_SUCCESS);
        }

        if (expanded_bind_sparse_info.submit_infos[i].signalSemaphoreCount > 0) {
            // Rip out semaphore signal operations from signal helper submit. We
            // needed this info to correctly record the signal semaphore markers, but
            // we don't need the helper submits to signal the semaphores that are
            // already signalled in a bind sparse info.
            expanded_bind_sparse_info.submit_infos[i].signalSemaphoreCount = 0;
            expanded_bind_sparse_info.submit_infos[i].pSignalSemaphores = nullptr;
            expanded_bind_sparse_info.submit_infos[i].pNext = nullptr;
        } else {
            // This is a wait helper submit. We need to signal the wait binary
            // semaphores that the helper submit is waiting on.
            expanded_bind_sparse_info.submit_infos[i].signalSemaphoreCount =
                (uint32_t)expanded_bind_sparse_info.wait_binary_semaphores[next_wait_helper_submit].size();
            expanded_bind_sparse_info.submit_infos[i].pSignalSemaphores =
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
                result = dispatch_table.QueueBindSparse(queue, available_bind_sparse_info_counter,
                                                        &pBindInfo[next_bind_sparse_info_index], bind_fence);
                if (result != VK_SUCCESS) {
                    last_bind_result = result;
                    break;
                }
                next_bind_sparse_info_index += available_bind_sparse_info_counter;
                available_bind_sparse_info_counter = 0;
            }
            // Send the submit info
            result = dispatch_table.QueueSubmit(
                queue, 1, &expanded_bind_sparse_info.submit_infos[next_submit_info_index], VK_NULL_HANDLE);
            if (result != VK_SUCCESS) {
                context->GetLogger()->LogWarning(
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
        context->GetLogger()->LogWarning(
            "QueueBindSparse: Unexpected VkResult = 0x%8x after submitting %d bind sparse infos and %d "
            " helper submit infos to the queue. Submitting the remained bind sparse infos at once.",
            last_bind_result, next_bind_sparse_info_index, next_submit_info_index);
        return dispatch_table.QueueBindSparse(queue, bindInfoCount - next_bind_sparse_info_index,
                                              &pBindInfo[next_bind_sparse_info_index], fence);
    }
    // If any remaining bind sparse infos, submit them all.
    if (bindInfoCount > next_bind_sparse_info_index + available_bind_sparse_info_counter) {
        return dispatch_table.QueueBindSparse(queue, bindInfoCount - next_submit_info_index,
                                              &pBindInfo[next_bind_sparse_info_index], fence);
    }
    return last_bind_result;
}

VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                        VkInstance* pInstance, Interceptor** interceptor) {
    auto* context = new Context(pCreateInfo, pAllocator);
    *interceptor = context;
    return VK_SUCCESS;
}

}  // namespace crash_diagnostic_layer
