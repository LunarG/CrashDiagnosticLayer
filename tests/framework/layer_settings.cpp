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
#include "config.h"
#include <cstring>
/*
const vk::LayerSettingsCreateInfoEXT* LayerSettings::BuildCreateInfo() {
    this->output_path_info = this->output_path.c_str();

    this->dump_semaphores_info = this->dump_semaphores.c_str();
    this->dump_queue_submits_info = this->dump_queue_submits.c_str();
    this->dump_command_buffers_info = this->dump_command_buffers.c_str();
    this->dump_commands_info = this->dump_commands.c_str();
    this->dump_shaders_info = this->dump_shaders.c_str();

    this->debug_action_info.resize(this->debug_action.size());
    for (std::size_t i = 0, n = debug_action.size(); i < n; ++i) {
        this->debug_action_info[i] = this->debug_action[i].c_str();
    }

    this->message_severity_info.resize(this->message_severity.size());
    for (std::size_t i = 0, n = message_severity.size(); i < n; ++i) {
        this->message_severity_info[i] = this->message_severity[i].c_str();
    }

    this->log_file_info = this->log_file.c_str();

    this->message_api_trace_info.resize(this->message_api_trace.size());
    for (std::size_t i = 0, n = message_api_trace.size(); i < n; ++i) {
        this->message_api_trace_info[i] = this->message_api_trace[i].c_str();
    }

    std::vector<vk::LayerSettingEXT> init{
        {kLayerSettingsName, "instrument_all_commands", vk::LayerSettingTypeEXT::eBool32, 1, &this->instrument_all_commands},
        {kLayerSettingsName, "sync_after_commands", vk::LayerSettingTypeEXT::eBool32, 1, &this->sync_after_commands},
        {kLayerSettingsName, "trigger_watchdog_timer", vk::LayerSettingTypeEXT::eBool32, 1, &this->trigger_watchdog_timer},
        {kLayerSettingsName, "watchdog_timeout_ms", vk::LayerSettingTypeEXT::eUint64, 1, &this->watchdog_timeout_ms},
        {kLayerSettingsName, "output_path", vk::LayerSettingTypeEXT::eString, 1, &this->output_path_info},
        {kLayerSettingsName, "dump_semaphores", vk::LayerSettingTypeEXT::eString, 1, &this->dump_semaphores_info},
        {kLayerSettingsName, "dump_queue_submits", vk::LayerSettingTypeEXT::eString, 1, &this->dump_queue_submits_info},
        {kLayerSettingsName, "dump_command_buffers", vk::LayerSettingTypeEXT::eString, 1, &this->dump_command_buffers_info},
        {kLayerSettingsName, "dump_commands", vk::LayerSettingTypeEXT::eString, 1, &this->dump_commands_info},
        {kLayerSettingsName, "dump_shaders", vk::LayerSettingTypeEXT::eString, 1, &this->dump_shaders_info},
        {kLayerSettingsName, "debug_action", vk::LayerSettingTypeEXT::eString, static_cast<uint32_t>(this->debug_action_info.size()), this->debug_action_info.empty() ? nullptr : &this->debug_action_info[0]},
        {kLayerSettingsName, "message_severity", vk::LayerSettingTypeEXT::eString, static_cast<uint32_t>(this->message_severity_info.size()), this->message_severity_info.empty() ? nullptr : &this->message_severity_info[0]},
        {kLayerSettingsName, "log_file", vk::LayerSettingTypeEXT::eString, 1, &this->log_file_info},
        {kLayerSettingsName, "message_api_trace", vk::LayerSettingTypeEXT::eString, static_cast<uint32_t>(this->message_api_trace_info.size()), this->message_api_trace_info.empty() ? nullptr : &this->message_api_trace_info[0]},
    };

    this->settings_ = init;

    this->create_info_ = vk::LayerSettingsCreateInfoEXT(this->settings_, this->pnext);
    return &this->create_info_;
}
*/
