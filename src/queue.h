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

#include <atomic>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

#include "command.h"
#include "command_pool.h"
#include "marker.h"
#include "semaphore_tracker.h"

namespace YAML {
class Emitter;
}  // namespace YAML

namespace crash_diagnostic_layer {

class Device;

// Unique id counter for submit infos
static uint32_t submit_info_counter = 0;

enum QueueOperationType : uint32_t {
    kQueueSubmit,
    kQueueBindSparse,
    kQueueSubmit2,
};

class Logger;

class Queue {
   public:
    Queue(Device& device, VkQueue queue, uint32_t family_index, uint32_t index, const VkQueueFamilyProperties& props);
    Queue(Queue&) = delete;
    Queue& operator=(Queue&) = delete;
    void Destroy();
    ~Queue();

    const Logger& Log() const;

    VkQueue GetVkQueue() const { return vk_queue_; }

    void Print(YAML::Emitter& os);

    VkResult Submit(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
    VkResult Submit2(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
    VkResult BindSparse(uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

    bool UpdateIdleState();

   private:
    enum SubmitState : uint32_t {
        kQueued = 1,
        kRunning = 2,
        kFinished = 3,
    };

    struct SubmitInfo {
        SubmitInfo(Device& device, const VkSubmitInfo& submit_info, uint64_t seq);
        SubmitInfo(Device& device, const VkSubmitInfo2& submit_info, uint64_t seq);
        SubmitInfo(Device& device, const VkBindSparseInfo& submit_info, uint64_t seq);

        QueueOperationType type;
        SubmitState state{kQueued};
        uint64_t start_seq{0};
        uint64_t end_seq{0};
        std::vector<SemInfo> wait_semaphores;
        std::vector<VkCommandBuffer> command_buffers;
        // TODO: sparse info
        std::vector<SemInfo> signal_semaphores;
    };

    struct Submission {
        Submission(QueueOperationType type_, uint64_t start) : type(type_), start_seq(start) {}
        QueueOperationType type;
        SubmitState state{kQueued};
        uint64_t start_seq;
        uint64_t end_seq{0};
        std::vector<SubmitInfo> submit_infos;
        VkFence fence{VK_NULL_HANDLE};
    };

    std::vector<TrackedSemaphoreInfo> GetTrackedSemaphoreInfos(const SubmitInfo& submit_info,
                                                               SemaphoreOperation operation) const;

    bool SubmitInfoHasSemaphores(const SubmitInfo& submit_info) const;
    std::string GetSubmitInfoSemaphoresLog(const SubmitInfo& submit_info) const;

    bool QueuedSubmitWaitingOnSemaphores(const SubmitInfo& submit_info) const;

    void PostSubmit(VkResult result);

    void LogSubmitInfoSemaphores(const SubmitInfo& submit_info);

    uint64_t CompletedSeq() const { return complete_seq_; }
    uint64_t SubmittedSeq() const { return submit_seq_; }

   private:
    bool UpdateSeq();

    Device& device_;
    VkQueue vk_queue_{VK_NULL_HANDLE};
    const uint32_t queue_family_index_;
    const uint32_t queue_index_;
    const VkQueueFamilyProperties queue_family_properties_;
    bool trace_all_semaphores_{false};

    mutable std::mutex queue_submits_mutex_;
    std::list<Submission> queue_submits_;

    VkSemaphore submit_sem_{VK_NULL_HANDLE};
    std::atomic<uint64_t> submit_seq_{0};
    std::atomic<uint64_t> complete_seq_{0};
};

}  // namespace crash_diagnostic_layer
