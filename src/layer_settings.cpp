/*
 * Copyright (c) 2024-2026 The Khronos Group Inc.
 * Copyright (c) 2024-2026 Valve Corporation
 * Copyright (c) 2024-2026 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "layer_settings.h"
#include "logger.h"
#include "system.h"
#include "util.h"

#include <vulkan/utility/vk_struct_helper.hpp>
#include <vulkan/layer/vk_layer_settings.hpp>

#include <regex>
#include <cstring>
#include <string>
#include <unordered_map>
#include <iostream>

namespace crash_diagnostic_layer {

const char* SETTING_INSTRUMENT_ALL_COMMANDS = "instrument_all_commands";
const char* SETTING_SYNC_AFTER_COMMANDS = "sync_after_commands";

const char* SETTING_DUMP_OUTPUT_PATH = "output_path";
const char* SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT = "trigger_watchdog_timeout";
const char* SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT_MS = "watchdog_timeout_ms";
const char* SETTING_DUMP_SEMAPHORES = "dump_semaphores";
const char* SETTING_DUMP_QUEUE_SUBMITS = "dump_queue_submits";
const char* SETTING_DUMP_COMMAND_BUFFERS = "dump_command_buffers";
const char* SETTING_DUMP_COMMANDS = "dump_commands";
const char* SETTING_DUMP_SHADERS = "dump_shaders";

const char *SETTING_DEBUG_ACTION = "debug_action";
const char* SETTING_LOG_FILE = "log_file";
const char *SETTING_MESSAGE_SEVERITY = "message_severity";
const char *SETTING_MESSAGE_API_TRACE = "message_api_trace";

static const std::unordered_map<std::string, VkFlags> kDebugActionValues = {
    {"VK_DBG_LAYER_ACTION_IGNORE", VK_DBG_LAYER_ACTION_IGNORE},
    {"VK_DBG_LAYER_ACTION_CALLBACK", VK_DBG_LAYER_ACTION_CALLBACK},
    {"VK_DBG_LAYER_ACTION_LOG_MSG", VK_DBG_LAYER_ACTION_LOG_MSG},
    {"VK_DBG_LAYER_ACTION_BREAK", VK_DBG_LAYER_ACTION_BREAK},
    {"VK_DBG_LAYER_ACTION_DEBUG_OUTPUT", VK_DBG_LAYER_ACTION_DEBUG_OUTPUT},
    {"VK_DBG_LAYER_ACTION_LOG_STDOUT", VK_DBG_LAYER_ACTION_LOG_STDOUT},
    {"VK_DBG_LAYER_ACTION_LOG_STDERR", VK_DBG_LAYER_ACTION_LOG_STDERR},
    {"VK_DBG_LAYER_ACTION_DEFAULT", VK_DBG_LAYER_ACTION_DEFAULT}
};

static const std::unordered_map<std::string, VkDebugUtilsMessageSeverityFlagBitsEXT> kMessageSeverityValues{
    {"error", VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT},
    {"warn", VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT},
    {"info", VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT},
    {"verbose", VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT},
};

static const std::unordered_map<std::string, MessageApiTraceBits> kMessageApiTraceValues{
    {"common", MESSAGE_API_TRACE_COMMON_BIT},
    {"semaphore", MESSAGE_API_TRACE_SEMAPHORE_BIT},
};

static const std::unordered_map<std::string, DumpSemaphores> kDumpSemaphoresValues{
    {"off", SETTING_DUMP_SEMAPHORES_OFF},
    {"on_crash", SETTING_DUMP_SEMAPHORES_ON_CRASH},
};

static const std::unordered_map<std::string, DumpCommands> kDumpCommandsValues{
    {"running", SETTING_DUMP_COMMANDS_RUNNING},
    {"pending", SETTING_DUMP_COMMANDS_PENDING},
    {"all", SETTING_DUMP_COMMANDS_ALL},
};

static const std::unordered_map<std::string, DumpShaders> kDumpShadersValues{
    {"off", SETTING_DUMP_OFF},
    {"on_crash", SETTING_DUMP_SHADERS_ON_CRASH},
    {"on_bind", SETTING_DUMP_SHADERS_ON_BIND},
    {"all", SETTING_DUMP_SHADERS_ALL},
};

template <typename T>
std::string ToString(const std::unordered_map<std::string, T>& values) {
    std::vector<std::string> collected;

    for (auto i : values) {
        collected.push_back(i.first);
    }

    return Merge(collected, ",");
}

template <typename T>
std::string ToString(const std::unordered_map<std::string, T>& values, int flags) {
    std::vector<std::string> collected;

    for (auto i : values) {
        if (i.second & flags) {
            collected.push_back(i.first);
        }
    }

    return Merge(collected, ",");
}

void Settings::Init(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator) {
    auto* pnext = pCreateInfo->pNext;
    const auto* settings_ci = vku::FindStructInPNextChain<VkLayerSettingsCreateInfoEXT>(pnext);

    VkuLayerSettingSet layer_setting_set = VK_NULL_HANDLE;
    VkResult result = vkuCreateLayerSettingSet("lunarg_crash_diagnostic", settings_ci, pAllocator, nullptr, &layer_setting_set);
    if (result != VK_SUCCESS) {
        this->init_failed = true;
        return;
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_SYNC_AFTER_COMMANDS)) {
        vkuGetLayerSettingValue(layer_setting_set, SETTING_SYNC_AFTER_COMMANDS, this->sync_after_commands);
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_INSTRUMENT_ALL_COMMANDS)) {
        vkuGetLayerSettingValue(layer_setting_set, SETTING_INSTRUMENT_ALL_COMMANDS, this->instrument_all_commands);
    }

    // output path
    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_OUTPUT_PATH)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_OUTPUT_PATH, value);

        std::filesystem::path default_value = this->crash_dump_output_dir;

        try {
            // On Windows, if the path include an invalid drive, then filesystem crash...
            // We need to use an exception to capture this problem
            this->crash_dump_output_dir = value;
            std::filesystem::create_directories(this->crash_dump_output_dir);
        } catch (std::exception& e) {
            this->bad_value = true;
            this->invalid_crash_dump_output_dir = value + " - " + e.what();
            this->crash_dump_output_dir = default_value;
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT)) {
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT, this->trigger_watchdog_timer);
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT_MS)) {
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT_MS, this->watchdog_timer_ms);
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_SEMAPHORES)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_SEMAPHORES, value);

        auto iter = kDumpSemaphoresValues.find(value);
        if (iter != kDumpSemaphoresValues.end()) {
            this->dump_semaphores = iter->second;
        } else {
            this->bad_value = true;
            this->invalid_dump_semaphores_values.push_back(value);
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_QUEUE_SUBMITS)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_QUEUE_SUBMITS, value);

        auto iter = kDumpCommandsValues.find(value);
        if (iter != kDumpCommandsValues.end()) {
            this->dump_queue_submits = iter->second;
        } else {
            this->bad_value = true;
            this->invalid_dump_queue_submits_values.push_back(value);
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_COMMAND_BUFFERS)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_COMMAND_BUFFERS, value);

        auto iter = kDumpCommandsValues.find(value);
        if (iter != kDumpCommandsValues.end()) {
            this->dump_command_buffers = iter->second;
        } else {
            this->bad_value = true;
            this->invalid_dump_command_buffers_values.push_back(value);
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_COMMANDS)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_COMMANDS, value);

        auto iter = kDumpCommandsValues.find(value);
        if (iter != kDumpCommandsValues.end()) {
            this->dump_commands = iter->second;
        } else {
            this->bad_value = true;
            this->invalid_dump_commands_values.push_back(value);
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DUMP_SHADERS)) {
        std::string value;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_DUMP_SHADERS, value);

        auto iter = kDumpShadersValues.find(value);
        if (iter != kDumpShadersValues.end()) {
            this->dump_shaders = iter->second;
        } else {
            this->bad_value = true;
            this->invalid_dump_shaders_values.push_back(value);
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_DEBUG_ACTION)) {
        std::vector<std::string> values;
        vkuGetLayerSettingValues(layer_setting_set, SETTING_DEBUG_ACTION, values);

        this->debug_action = 0;
        for (std::size_t i = 0, n = values.size(); i < n; ++i) {
            if (values[i].empty()) {
                continue;
            }

            auto iter = kDebugActionValues.find(values[i]);
            if (iter != kDebugActionValues.end()) {
                this->debug_action |= iter->second;
            } else {
                this->bad_value = true;
                this->invalid_debug_action_values.push_back(values[i]);
            }
        }
    }

    // logging
    if (vkuHasLayerSetting(layer_setting_set, SETTING_LOG_FILE)) {
        std::string log_file_string;
        vkuGetLayerSettingValue(layer_setting_set, SETTING_LOG_FILE, log_file_string);
        this->log_file = log_file_string;
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_MESSAGE_SEVERITY)) {
        std::vector<std::string> values;
        vkuGetLayerSettingValues(layer_setting_set, SETTING_MESSAGE_SEVERITY, values);

        this->log_message_severity = 0;
        for (std::size_t i = 0, n = values.size(); i < n; ++i) {
            if (values[i].empty()) {
                continue;
            }

            auto iter = kMessageSeverityValues.find(values[i]);
            if (iter != kMessageSeverityValues.end()) {
                this->log_message_severity |= iter->second;
            } else {
                this->bad_value = true;
                this->invalid_message_severity_values.push_back(values[i]);
            }
        }
    }

    if (vkuHasLayerSetting(layer_setting_set, SETTING_MESSAGE_API_TRACE)) {
        std::vector<std::string> values;
        vkuGetLayerSettingValues(layer_setting_set, SETTING_MESSAGE_API_TRACE, values);

        this->log_message_api_trace = 0;
        for (std::size_t i = 0, n = values.size(); i < n; ++i) {
            if (values[i].empty()) {
                continue;
            }

            auto iter = kMessageApiTraceValues.find(values[i]);
            if (iter != kMessageApiTraceValues.end()) {
                this->log_message_api_trace |= iter->second;
            } else {
                this->bad_value = true;
                this->invalid_message_api_trace_values.push_back(values[i]);
            }
        }
    }

    vkuDestroyLayerSettingSet(layer_setting_set, nullptr);
}

void Settings::Print(Logger& log) const {
    if (this->init_failed) {
        log.Error("Could not initialize layer settings, using default setting values");
    }

    if (this->bad_value) {
        log.Error("Using layer settings:");
    }

    if (!this->invalid_crash_dump_output_dir.empty()) {
        log.Error("Invalid path for `%s` setting: \"%s\"", SETTING_DUMP_OUTPUT_PATH,
                  this->invalid_crash_dump_output_dir.c_str());
    }

    if (!this->invalid_dump_semaphores_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DUMP_SEMAPHORES,
                  Merge(this->invalid_dump_semaphores_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DUMP_SEMAPHORES, ToString(kDumpSemaphoresValues).c_str());
    }

    if (!this->invalid_dump_queue_submits_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DUMP_QUEUE_SUBMITS,
                  Merge(this->invalid_dump_queue_submits_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DUMP_QUEUE_SUBMITS, ToString(kDumpCommandsValues).c_str());
    }

    if (!this->invalid_dump_command_buffers_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DUMP_COMMAND_BUFFERS,
                  Merge(this->invalid_dump_command_buffers_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DUMP_COMMAND_BUFFERS, ToString(kDumpCommandsValues).c_str());
    }

    if (!this->invalid_dump_commands_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DUMP_COMMANDS,
                  Merge(this->invalid_dump_commands_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DUMP_COMMANDS, ToString(kDumpCommandsValues).c_str());
    }

    if (!this->invalid_dump_shaders_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DUMP_SHADERS,
                  Merge(this->invalid_dump_shaders_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DUMP_SHADERS, ToString(kDumpShadersValues).c_str());
    }

    if (!this->invalid_debug_action_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_DEBUG_ACTION,
                  Merge(this->invalid_debug_action_values, ",").c_str());
        log.Info(
            "The valid values for `%s` setting are: \"%s\"",
            SETTING_DEBUG_ACTION, ToString(kDebugActionValues).c_str());
    }

    if (!this->invalid_message_severity_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_MESSAGE_SEVERITY,
                  Merge(this->invalid_message_severity_values, ",").c_str());
        log.Info("The valid values for `%s` setting are: \"%s\"",
            SETTING_MESSAGE_SEVERITY, ToString(kMessageSeverityValues).c_str());
    }

    if (!this->invalid_message_api_trace_values.empty()) {
        log.Error("Invalid value for `%s` setting: \"%s\"", SETTING_MESSAGE_API_TRACE,
                  Merge(this->invalid_message_api_trace_values, ",").c_str());
        log.Info("The valid values for `%s` setting are: \"%s\"",
            SETTING_MESSAGE_API_TRACE, ToString(kMessageApiTraceValues).c_str());
    }

    log.Info("Using layer settings:");
    log.Info(" - %s: %s", SETTING_INSTRUMENT_ALL_COMMANDS, this->instrument_all_commands ? "true" : "false");
    log.Info(" - %s: %s", SETTING_SYNC_AFTER_COMMANDS, this->sync_after_commands ? "true" : "false");

    log.Info(" - %s: %s", SETTING_DUMP_OUTPUT_PATH, this->crash_dump_output_dir.c_str());
    log.Info(" - %s: %s", SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT, this->trigger_watchdog_timer ? "true" : "false");
    log.Info(" - %s: %dms", SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT_MS, this->watchdog_timer_ms);

    log.Info(" - %s: %s", SETTING_DUMP_SEMAPHORES, ToString(kDumpSemaphoresValues, this->dump_semaphores).c_str());
    log.Info(" - %s: %s", SETTING_DUMP_QUEUE_SUBMITS, ToString(kDumpCommandsValues, this->dump_queue_submits).c_str());
    log.Info(" - %s: %s", SETTING_DUMP_COMMAND_BUFFERS, ToString(kDumpCommandsValues, this->dump_command_buffers).c_str());
    log.Info(" - %s: %s", SETTING_DUMP_COMMANDS, ToString(kDumpCommandsValues, this->dump_commands).c_str());
    log.Info(" - %s: %s", SETTING_DUMP_SHADERS, ToString(kDumpShadersValues, this->dump_shaders).c_str());

    log.Info(" - %s: %s", SETTING_DEBUG_ACTION, ToString(kDebugActionValues, this->debug_action).c_str());
    log.Info(" - %s: %s", SETTING_LOG_FILE, this->log_file.c_str());
    log.Info(" - %s: %s", SETTING_MESSAGE_SEVERITY, ToString(kMessageSeverityValues, this->log_message_severity).c_str());
    log.Info(" - %s: %s", SETTING_MESSAGE_API_TRACE, ToString(kMessageApiTraceValues, this->log_message_api_trace).c_str());
}

void Settings::Print(YAML::Emitter& os) const {
    os << YAML::BeginMap;
    os << YAML::Key << SETTING_INSTRUMENT_ALL_COMMANDS << YAML::Value << this->instrument_all_commands;
    os << YAML::Key << SETTING_SYNC_AFTER_COMMANDS << YAML::Value << this->sync_after_commands;

    os << YAML::Key << SETTING_DUMP_OUTPUT_PATH << YAML::Value << this->crash_dump_output_dir.c_str();
    os << YAML::Key << SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT << YAML::Value << this->trigger_watchdog_timer;
    os << YAML::Key << SETTING_DUMP_TRIGGER_WATCHDOG_TIMEOUT_MS << YAML::Value << this->watchdog_timer_ms;
    os << YAML::Key << SETTING_DUMP_SEMAPHORES << YAML::Value << ToString(kDumpSemaphoresValues, this->dump_semaphores).c_str();
    os << YAML::Key << SETTING_DUMP_QUEUE_SUBMITS << YAML::Value << ToString(kDumpCommandsValues, this->dump_queue_submits).c_str();
    os << YAML::Key << SETTING_DUMP_COMMAND_BUFFERS << YAML::Value << ToString(kDumpCommandsValues, this->dump_command_buffers).c_str();
    os << YAML::Key << SETTING_DUMP_COMMANDS << YAML::Value << ToString(kDumpCommandsValues, this->dump_commands).c_str();
    os << YAML::Key << SETTING_DUMP_SHADERS << YAML::Value << ToString(kDumpShadersValues, this->dump_shaders).c_str();

    //TODO
    os << YAML::Key << SETTING_DEBUG_ACTION << YAML::Value << ToString(kDebugActionValues, this->debug_action);
    os << YAML::Key << SETTING_LOG_FILE << YAML::Value << this->log_file.c_str();
    os << YAML::Key << SETTING_MESSAGE_SEVERITY << YAML::Value << ToString(kMessageSeverityValues, this->log_message_severity);
    os << YAML::Key << SETTING_MESSAGE_API_TRACE << YAML::Value << ToString(kMessageApiTraceValues, this->log_message_api_trace);

    os << YAML::EndMap;
}

}  // namespace crash_diagnostic_layer
