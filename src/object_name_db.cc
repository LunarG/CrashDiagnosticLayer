/*
 Copyright 2019 Google Inc.
 Copyright 2023-2024 LunarG, Inc.

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

#include "object_name_db.h"

#include <algorithm>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include "util.h"

ObjectInfoDB::ObjectInfoDB() {
    // default name for unknown objects
    unknown_object_.object = 0;
    unknown_object_.type = VK_OBJECT_TYPE_UNKNOWN;
    unknown_object_.name = "";
}

void ObjectInfoDB::AddObjectInfo(uint64_t handle, ObjectInfoPtr info) {
    std::lock_guard<std::mutex> lock(lock_);
    object_info_[handle] = std::move(info);
}

void ObjectInfoDB::AddExtraInfo(uint64_t handle, ExtraObjectInfo info) {
    std::lock_guard<std::mutex> lock(lock_);
    object_extra_info_[handle].push_back(info);
}

ObjectInfo ObjectInfoDB::FindObjectInfo(uint64_t handle) const {
    std::lock_guard<std::mutex> lock(lock_);

    auto handle_info = object_info_.find(handle);
    if (end(object_info_) != handle_info) {
        return *handle_info->second.get();
    }
    auto result = unknown_object_;
    result.object = handle;
    return result;
}

std::string ObjectInfoDB::GetObjectDebugName(uint64_t handle) const { return FindObjectInfo(handle).name; }

std::string ObjectInfoDB::GetObjectName(uint64_t handle, HandleDebugNamePreference handle_debug_name_preference) const {
    auto info = FindObjectInfo(handle);
    if (handle_debug_name_preference == kPreferDebugName) {
        if (!info.name.empty()) {
            return info.name;
        }
        return crash_diagnostic_layer::Uint64ToStr(handle);
    }
    std::stringstream object_name;
    if (!info.name.empty()) {
        object_name << info.name << " ";
    }
    object_name << "(" << crash_diagnostic_layer::Uint64ToStr(handle) << ")";
    return object_name.str();
}

std::string ObjectInfoDB::GetObjectInfoInternal(uint64_t handle,
                                                VkHandleTagRequirement vkhandle_tag_requirement) const {
    // TODO cleanup so all object are tracked and debug object names only
    // enhance object names
    std::stringstream info_ss;
#if 0
    if (vkhandle_tag_requirement == kPrintVkHandleTag) {
        info_ss << "vkHandle: ";
    }
    info_ss << crash_diagnostic_layer::Uint64ToStr(handle);
    auto info = FindObjectInfo(handle);
    if (!info.name.empty()) {
        info_ss << "debugName: \"" << info.name << "\"";
    }
    std::lock_guard<std::mutex> lock(lock_);
    auto extra_infos = object_extra_info_.find(handle);
    if (end(object_extra_info_) != extra_infos) {
        for (auto& extra_info : extra_infos->second) {
            info_ss << extra_info.first << ": " << extra_info.second;
        }
    }
#else
    auto info = FindObjectInfo(handle);
    info_ss << crash_diagnostic_layer::Uint64ToStr(handle) << "[" << info.name << "]";
    // TODO: extra infos???
#endif

    return info_ss.str();
}

std::string ObjectInfoDB::GetObjectInfo(uint64_t handle) const {
    return GetObjectInfoInternal(handle, kPrintVkHandleTag);
}

std::string ObjectInfoDB::GetObjectInfoNoHandleTag(uint64_t handle) const {
    return GetObjectInfoInternal(handle, kIgnoreVkHandleTag);
}

YAML::Emitter& ObjectInfoDB::PrintDebugInfo(YAML::Emitter& os, uint64_t handle) const {
    auto info = FindObjectInfo(handle);
    os << YAML::BeginMap;
    os << YAML::Key << "VkHandle" << YAML::Value << YAML::Hex << handle << YAML::Dec;
    if (!info.name.empty()) {
        os << YAML::Key << "name" << YAML::Value << info.name;
    }
    os << YAML::EndMap;
    return os;
}
