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

ObjectInfoDB::ObjectInfoDB() {}

void ObjectInfoDB::AddObjectInfo(uint64_t handle, VkObjectType type, const char* name) {
    ObjectInfoPtr info = std::make_unique<ObjectInfo>(handle, type, name);
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

std::string ObjectInfoDB::GetObjectInfo(uint64_t handle) const {
    // TODO cleanup so all object are tracked and debug object names only
    // enhance object names
    std::stringstream info_ss;
    auto info = FindObjectInfo(handle);
    info_ss << crash_diagnostic_layer::Uint64ToStr(handle) << "[" << info.name << "]";
    return info_ss.str();
}
