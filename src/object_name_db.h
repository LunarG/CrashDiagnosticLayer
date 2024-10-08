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

#ifndef OBJECT_NAME_DB_HEADER_
#define OBJECT_NAME_DB_HEADER_

#include <vulkan/vulkan.h>

#include <memory>
#include <mutex>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <yaml-cpp/emitter.h>

// -----------------------------------------------------------------------------
// Debug info for a Vulkan object
// -----------------------------------------------------------------------------
struct ObjectInfo {
    ObjectInfo(uint64_t o, VkObjectType t, const char* n) : object(o), type(t), name(n) {}
    ObjectInfo() : object(0), type(VK_OBJECT_TYPE_UNKNOWN), name("") {}

    uint64_t object;
    VkObjectType type;
    std::string name;
};

using ObjectInfoPtr = std::unique_ptr<ObjectInfo>;
using ExtraObjectInfo = std::pair<std::string, std::string>;

enum HandleDebugNamePreference {
    kPreferDebugName,
    kReportBoth,
};

// -----------------------------------------------------------------------------
// Database of debug info for multiple Vulkan objects
// -----------------------------------------------------------------------------
class ObjectInfoDB {
   public:
    ObjectInfoDB();
    ObjectInfoDB(ObjectInfoDB&) = delete;
    ObjectInfoDB& operator=(ObjectInfoDB&) = delete;

    void AddObjectInfo(uint64_t handle, VkObjectType type, const char* name);
    void AddExtraInfo(uint64_t handle, ExtraObjectInfo info);

    void RemoveObjectInfo(uint64_t handle) {}  // TODO remove object info..

    ObjectInfo FindObjectInfo(uint64_t handle) const;
    std::string GetObjectName(uint64_t handle,
                              HandleDebugNamePreference handle_debug_name_preference = kReportBoth) const;
    std::string GetObjectInfo(uint64_t handle) const;

   private:
    mutable std::mutex lock_;

    std::unordered_map<uint64_t, ObjectInfoPtr> object_info_;
    std::unordered_map<uint64_t, std::vector<ExtraObjectInfo>> object_extra_info_;
    ObjectInfo unknown_object_;
};

#endif  // OBJECT_NAME_DB_HEADER_
