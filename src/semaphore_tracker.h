/*
 Copyright 2020 Google Inc.
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

#pragma once

#include <vulkan/vulkan.h>
#include <yaml-cpp/emitter.h>

#include <map>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "marker.h"

namespace crash_diagnostic_layer {

class Device;
class Logger;

struct SemInfo {
    VkSemaphore handle;
    uint64_t value{0};
    VkPipelineStageFlags2 stage{0};
};
enum SemaphoreOperation { kWaitOperation, kSignalOperation };

enum SemaphoreModifierType : uint32_t {
    kNotModified = 0,
    kModifierHost = 1,
    kModifierQueueSubmit = 2,
    kModifierQueueBindSparse = 3
};

struct SemaphoreModifierInfo {
    SemaphoreModifierType type = kNotModified;
    uint32_t id = 0;
};

struct TrackedSemaphoreInfo {
    VkSemaphore semaphore = VK_NULL_HANDLE;
    VkSemaphoreTypeKHR semaphore_type = VK_SEMAPHORE_TYPE_BINARY_KHR;
    // This can be a wait operation value or a signal operation value.
    uint64_t semaphore_operation_value = 0;
    uint64_t current_value = 0;
    bool current_value_available = false;
    SemaphoreModifierInfo last_modifier;
};

class SemaphoreTracker {
   public:
    SemaphoreTracker(Device& device);
    SemaphoreTracker(SemaphoreTracker&) = delete;
    SemaphoreTracker& operator=(SemaphoreTracker&) = delete;

    const Logger& Log() const;

    void RegisterSemaphore(VkSemaphore vk_semaphore, VkSemaphoreTypeKHR type, uint64_t value);
    void SignalSemaphore(VkSemaphore vk_semaphore, uint64_t value, SemaphoreModifierInfo modifier_info);
    void EraseSemaphore(VkSemaphore vk_semaphore);

    bool GetSemaphoreValue(VkSemaphore vk_semaphore, uint64_t& value) const;
    VkSemaphoreTypeKHR GetSemaphoreType(VkSemaphore vk_semaphore) const;

    void BeginWaitOnSemaphores(int pid, int tid, const VkSemaphoreWaitInfoKHR* pWaitInfo);
    void EndWaitOnSemaphores(int pid, int tid, const VkSemaphoreWaitInfoKHR* pWaitInfo);
    void DumpWaitingThreads(YAML::Emitter& os) const;

    void WriteMarker(VkSemaphore vk_semaphore, VkCommandBuffer vk_command_buffer,
                     VkPipelineStageFlagBits vk_pipeline_stage, uint64_t value, SemaphoreModifierInfo modifier_info);

    std::vector<TrackedSemaphoreInfo> GetTrackedSemaphoreInfos(const std::vector<SemInfo>& semaphores);

    std::string PrintTrackedSemaphoreInfos(const std::vector<TrackedSemaphoreInfo>& tracked_semaphores,
                                           const char* tab) const;

   private:
    Device& device_;
    BufferMarkerMgr markers_;
    bool track_semaphores_last_setter_ = false;

    struct SemaphoreInfo {
        // VkSemaphore used as the key in the container, so not included here.
        VkSemaphoreTypeKHR semaphore_type = VK_SEMAPHORE_TYPE_BINARY_KHR;
        std::unique_ptr<Marker64> marker;
        std::unique_ptr<Marker> last_id, last_type;
        SemaphoreInfo() {}

        void UpdateLastModifier(Device& device, SemaphoreModifierInfo modifier_info);
        SemaphoreModifierInfo GetLastModifier(Device& device);
    };

    mutable std::mutex semaphores_mutex_;
    std::unordered_map<VkSemaphore, SemaphoreInfo> semaphores_;

    enum SemaphoreWaitType {
        kAll = 0,
        kAny = 1,
    };

    struct WaitingThreadInfo {
        int pid = 0;
        int tid = 0;
        SemaphoreWaitType wait_type;
        std::vector<VkSemaphore> semaphores;
        std::vector<uint64_t> wait_values;
    };

    mutable std::mutex waiting_threads_mutex_;
    std::vector<WaitingThreadInfo> waiting_threads_;
};

using SemaphoreTrackerPtr = std::unique_ptr<SemaphoreTracker>;

}  // namespace crash_diagnostic_layer
