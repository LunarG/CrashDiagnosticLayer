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

const uint32_t kInvalidSubmitInfoId = 0xFFFFFFFF;

// Unique id counter for submit infos
static uint32_t submit_info_counter = 0;

typedef uint32_t SubmitInfoId;
typedef uint32_t QueueSubmitId;
typedef uint32_t QueueBindSparseId;

enum QueueOperationType {
    kQueueSubmit,
    kQueueBindSparse,
    kQueueSubmit2,
};

// Original bind sparse info with the submit tracker that tracks semaphores for
// the respective device.
struct PackedBindSparseInfo {
    const VkQueue queue;
    const uint32_t bind_info_count;
    const VkBindSparseInfo* bind_infos;
    SemaphoreTracker* semaphore_tracker;

    PackedBindSparseInfo(VkQueue queue_, uint32_t bind_info_count_, const VkBindSparseInfo* bind_infos_)
        : queue(queue_), bind_info_count(bind_info_count_), bind_infos(bind_infos_){};
};

// Expanded bind sparse info, including all the information needed to correctly
// insert semaphore tracking VkSubmitInfos between vkQueueBindSparse calls.
struct ExpandedBindSparseInfo {
    // Input: original bind sparse info.
    const PackedBindSparseInfo* packed_bind_sparse_info;
    // Vector of queue operation types, used to control interleaving order.
    std::vector<QueueOperationType> queue_operation_types;
    // Vector of submit info structs to be submitted to the queue.
    std::vector<VkSubmitInfo> submit_infos;
    // Vector of bool, specifying if a submit info includes a signal operation on
    // a timeline semaphore.
    std::vector<bool> has_timeline_semaphore_info;
    // Place holder for timeline semaphore infos used in queue submit infos.
    std::vector<VkTimelineSemaphoreSubmitInfoKHR> timeline_semaphore_infos;
    // Place holder for vectors of binary semaphores used in a wait semaphore
    // operation in a bind sparse info. This is needed since we need to signal
    // these semaphores in the same vkQueueSubmit that we consume them for
    // tracking (so the bind sparse info which is the real consumer of the
    // semaphore can proceed).
    std::vector<std::vector<VkSemaphore>> wait_binary_semaphores;

    ExpandedBindSparseInfo(PackedBindSparseInfo* packed_bind_sparse_info_)
        : packed_bind_sparse_info(packed_bind_sparse_info_){};
};

class Logger;

class Queue {
   public:
    Queue(Device& device, VkQueue queue, uint32_t family_index, uint32_t index, const VkQueueFamilyProperties& props);
    const Logger& Log() const;
    void Destroy();
    ~Queue();

    void Print(YAML::Emitter& os) const;

    VkResult Submit(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
    VkResult Submit2(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
    VkResult BindSparse(uint32_t bindInfoCount, const VkBindSparseInfo* pBindInfo, VkFence fence);

   private:
    std::vector<TrackedSemaphoreInfo> GetTrackedSemaphoreInfos(SubmitInfoId submit_info_id,
                                                               SemaphoreOperation operation) const;

    SubmitInfoId RegisterSubmitInfo(QueueSubmitId queue_submit_index, const VkSubmitInfo* submit_info);
    SubmitInfoId RegisterSubmitInfo(QueueSubmitId queue_submit_index, const VkSubmitInfo2* submit_info);

    void RecordSubmitStart(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer vk_command_buffer);
    void RecordSubmitFinish(QueueSubmitId qsubmit_id, SubmitInfoId submit_info_id, VkCommandBuffer vk_command_buffer);
    void CleanupSubmitInfos();
    bool SubmitInfoHasSemaphores(SubmitInfoId submit_info_id) const;
    std::string GetSubmitInfoSemaphoresLog(SubmitInfoId submit_info_id) const;

    void RecordBindSparseHelperSubmit(QueueBindSparseId qbind_sparse_id, const VkSubmitInfo* vk_submit_info);
    void CleanupBindSparseHelperSubmits();

    bool QueuedSubmitWaitingOnSemaphores(SubmitInfoId submit_info_id) const;

    VkResult SubmitWithoutTrackingSemaphores(uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);
    VkResult Submit2WithoutTrackingSemaphores(uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);
    void PostSubmit(VkResult result);

    QueueSubmitId GetNextQueueSubmitId() { return ++queue_submit_index_; };
    void LogSubmitInfoSemaphores(SubmitInfoId submit_info_id);
    void StoreSubmitHelperCommandBuffersInfo(SubmitInfoId submit_info_id, VkCommandBuffer start_marker_cb,
                                             VkCommandBuffer end_marker_cb);

    QueueBindSparseId GetNextQueueBindSparseId() { return ++queue_bind_sparse_index_; };

    bool ShouldExpandQueueBindSparseToTrackSemaphores(PackedBindSparseInfo* packed_bind_sparse_info);
    void ExpandBindSparseInfo(ExpandedBindSparseInfo* bind_sparse_expand_info);
    void LogBindSparseInfosSemaphores(uint32_t bind_info_count, const VkBindSparseInfo* bind_infos);

    std::vector<VkCommandBuffer> AllocHelperCBs(uint32_t count);

   private:
    Device& device_;
    VkQueue vk_queue_{VK_NULL_HANDLE};
    const uint32_t queue_family_index_;
    const uint32_t queue_index_;
    const VkQueueFamilyProperties queue_family_properties_;
    bool tracking_semaphores_{false};
    bool trace_all_semaphores_{false};

    enum SubmitState : uint32_t {
        kInvalid = 0,
        kQueued = 1,
        kRunning = 2,
        kFinished = 3,
    };

    struct SubmitInfo {
        SubmitInfoId submit_info_id;
        std::vector<VkSemaphore> wait_semaphores;
        std::vector<uint64_t> wait_semaphore_values;
        std::vector<VkPipelineStageFlags> wait_semaphore_pipeline_stages;
        std::vector<VkCommandBuffer> command_buffers;
        std::vector<VkSemaphore> signal_semaphores;
        std::vector<uint64_t> signal_semaphore_values;
        VkFence fence = VK_NULL_HANDLE;
        // Markers used to track the state of the submit.
        Marker top_marker;
        Marker bottom_marker;
        // Info for extra command buffers used to track semaphore values
        VkCommandBuffer start_marker_cb = VK_NULL_HANDLE;
        VkCommandBuffer end_marker_cb = VK_NULL_HANDLE;
        // vkQueueSubmit tracking index
        uint32_t queue_submit_index = 0;
    };

    mutable std::mutex queue_submits_mutex_;
    std::map<QueueSubmitId, std::vector<SubmitInfoId>> queue_submits_;

    mutable std::mutex submit_infos_mutex_;
    std::map<SubmitInfoId, SubmitInfo> submit_infos_;

    // Helper submit infos used to track signal semaphore operations in
    // vkQueueBindSparse.
    struct HelperSubmitInfo {
        QueueBindSparseId qbind_sparse_id;
        // Marker used to track the state of the helper submit and its signal
        // semaphore operations. While CDL doesn't care about the state of helper
        // submits in its log, this is necessary to free the extra command buffer
        // allocated and used in the helper submit.
        Marker marker;
        // Info for the command buffer used to track semaphore values.
        // We expect helper submit infos to have only one command buffer.
        VkCommandBuffer marker_cb = VK_NULL_HANDLE;

        HelperSubmitInfo() {}
    };

    std::mutex helper_submit_infos_mutex_;
    std::vector<HelperSubmitInfo> helper_submit_infos_;

    std::atomic<QueueSubmitId> queue_submit_index_{0};
    std::atomic<QueueBindSparseId> queue_bind_sparse_index_{0};

    VkCommandPool helper_command_pool_{VK_NULL_HANDLE};
};

}  // namespace crash_diagnostic_layer
