/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024 Valve Corporation
 * Copyright (c) 2024 LunarG, Inc.
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

#define MakeStringSetting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eString, 1, &_name)

#define MakeBoolSetting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eBool32, 1, &_name)

#define MakeUint64Setting(_name) \
    vk::LayerSettingEXT(kLayerSettingsName, #_name, vk::LayerSettingTypeEXT::eUint64, 1, &_name)

LayerSettings::LayerSettings(const void* pnext)
    : settings_{
        MakeStringSetting(output_path),
        MakeBoolSetting(trace_on),
        MakeStringSetting(message_severity),
        MakeStringSetting(log_file),

        MakeBoolSetting(instrument_all_commands),
        MakeBoolSetting(sync_after_commands),

        MakeBoolSetting(track_semaphores),
        MakeBoolSetting(trace_all_semaphores),

        MakeStringSetting(dump_queue_submits),
        MakeStringSetting(dump_command_buffers),
        MakeStringSetting(dump_commands),
        MakeStringSetting(dump_shaders),

        MakeUint64Setting(watchdog_timeout_ms),
    },
    create_info_(settings_, pnext) {
    SetOutputPath("");
    SetMessageSeverity("");
    SetLogFile("");
    SetDumpQueueSubmits("");
    SetDumpCommandBuffers("");
    SetDumpCommands("");
    SetDumpShaders("");
}

LayerSettings::~LayerSettings() {
    free(output_path);
    free(message_severity);
    free(log_file);
    free(dump_shaders);
    free(dump_commands);
    free(dump_command_buffers);
    free(dump_queue_submits);
}

void LayerSettings::SetOutputPath(const char* s) {
    free(output_path);
    output_path = strdup(s);
}

void LayerSettings::SetMessageSeverity(const char* s) {
    free(message_severity);
    message_severity = strdup(s);
}

void LayerSettings::SetLogFile(const char* s) {
    free(log_file);
    log_file = strdup(s);
}

void LayerSettings::SetDumpQueueSubmits(const char* s) {
    free(dump_queue_submits);
    dump_queue_submits = strdup(s);
}

void LayerSettings::SetDumpCommandBuffers(const char* s) {
    free(dump_command_buffers);
    dump_command_buffers = strdup(s);
}

void LayerSettings::SetDumpCommands(const char* s) {
    free(dump_commands);
    dump_commands = strdup(s);
}

void LayerSettings::SetDumpShaders(const char* s) {
    free(dump_shaders);
    dump_shaders = strdup(s);
}
