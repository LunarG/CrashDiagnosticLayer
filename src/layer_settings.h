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
#pragma once

#include "util.h"
#include "system.h"

#include <vulkan/vulkan.hpp>
#include <yaml-cpp/emitter.h>

#include <string>
#include <vector>
#include <filesystem>
#include <chrono>

//extern const std::string kCdlVersion;

namespace crash_diagnostic_layer {

class Logger;

enum DumpSemaphores {
    SETTING_DUMP_SEMAPHORES_OFF = 0,
    SETTING_DUMP_SEMAPHORES_ON_CRASH,
};

// Used for command buffers, commands and queue submisions
enum DumpCommands {
    SETTING_DUMP_COMMANDS_RUNNING = 0,
    SETTING_DUMP_COMMANDS_PENDING,
    SETTING_DUMP_COMMANDS_ALL,
};

enum DumpShaders {
    SETTING_DUMP_OFF = 0,
    SETTING_DUMP_SHADERS_ON_CRASH,
    SETTING_DUMP_SHADERS_ON_BIND,
    SETTING_DUMP_SHADERS_ALL,
};

// Definitions for Debug Actions
enum VkLayerDbgActionBits {
    VK_DBG_LAYER_ACTION_IGNORE = 0x00000000,
    VK_DBG_LAYER_ACTION_CALLBACK = 0x00000001,
    VK_DBG_LAYER_ACTION_LOG_MSG = 0x00000002,
    VK_DBG_LAYER_ACTION_BREAK = 0x00000004,
    VK_DBG_LAYER_ACTION_DEBUG_OUTPUT = 0x00000008,
    VK_DBG_LAYER_ACTION_LOG_STDOUT = 0x00000010,
    VK_DBG_LAYER_ACTION_LOG_STDERR = 0x00000020,
    VK_DBG_LAYER_ACTION_DEFAULT = 0x40000000,
};
using VkLayerDbgActionFlags = VkFlags;

// Definitions for Message API Trace
enum MessageApiTraceBits {
    MESSAGE_API_TRACE_COMMON_BIT = 0x00000001,
    MESSAGE_API_TRACE_SEMAPHORE_BIT = 0x00000002,
};
using MessageApiTraceFlags = VkFlags;

struct Settings {
    using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

    Settings() {}
    ~Settings() {}

    void Init(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator);

    void Print(Logger& log) const;
    void Print(YAML::Emitter& os) const;

    bool sync_after_commands = false;
    bool instrument_all_commands = false;

    std::filesystem::path crash_dump_output_dir = std::filesystem::path(System::GetOutputBasePath()) / "cdl";
    bool trigger_watchdog_timer = true;
    int64_t watchdog_timer_ms = 30000;

    DumpSemaphores dump_semaphores = SETTING_DUMP_SEMAPHORES_OFF;
    DumpCommands dump_queue_submits = SETTING_DUMP_COMMANDS_RUNNING;
    DumpCommands dump_command_buffers = SETTING_DUMP_COMMANDS_RUNNING;
    DumpCommands dump_commands = SETTING_DUMP_COMMANDS_RUNNING;
    DumpShaders dump_shaders = SETTING_DUMP_OFF;

    VkLayerDbgActionFlags debug_action = VK_DBG_LAYER_ACTION_LOG_MSG | VK_DBG_LAYER_ACTION_DEBUG_OUTPUT;
    VkDebugUtilsMessageSeverityFlagsEXT log_message_severity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
    std::filesystem::path log_file = "cdl_log.txt";
    MessageApiTraceFlags log_message_api_trace = 0;

   private:
    bool init_failed = false;
    bool bad_value = false;

    std::string invalid_crash_dump_output_dir;
    std::vector<std::string> invalid_dump_semaphores_values;
    std::vector<std::string> invalid_dump_queue_submits_values;
    std::vector<std::string> invalid_dump_command_buffers_values;
    std::vector<std::string> invalid_dump_commands_values;
    std::vector<std::string> invalid_dump_shaders_values;
    std::vector<std::string> invalid_debug_action_values;
    std::vector<std::string> invalid_message_severity_values;
    std::vector<std::string> invalid_message_api_trace_values;
};

}  // namespace crash_diagnostic_layer
