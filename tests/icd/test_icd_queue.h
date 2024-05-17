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
#pragma once

#include <vulkan/vulkan_core.h>
#include <vulkan/vk_icd.h>

#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

namespace icd {

class CommandBuffer;
class Device;
class Fence;
class FaultInfo;
class Semaphore;

class Queue {
   public:
    struct SemInfo {
        Semaphore* semaphore;
        uint64_t value;
    };

    struct SubmitInfo {
        std::vector<SemInfo> wait_semaphores;
        std::vector<SemInfo> signal_semaphores;
        std::vector<CommandBuffer*> cmd_buffers;
    };

    struct Submission {
        std::list<SubmitInfo> submit_infos;
        Fence* fence{nullptr};
    };

    Queue(Device &device);
    ~Queue();

    VkResult Submit(uint32_t count, const VkSubmitInfo* submits, VkFence fence);
    VkResult Submit2(uint32_t count, const VkSubmitInfo2* submits, VkFence fence);
    VkResult BindSparse(uint32_t count, const VkBindSparseInfo* binds, VkFence fence);

    VkResult WaitIdle();

    void GetCheckpointData(uint32_t* count, VkCheckpointDataNV* checkpoints);
    void GetCheckpointData2(uint32_t* count, VkCheckpointData2NV* checkpoints);
    void TrackCheckpoint(uintptr_t checkpoint, VkPipelineStageFlagBits stage);

    void SetFaultInfo(FaultInfo &&);
   private:
    std::unique_lock<std::mutex> Lock() const { return std::unique_lock<std::mutex>(lock_); }
    void ThreadFunc();
    Submission* NextSubmission();
    VkResult Execute(Submission& submission);
    void StartThread();

    VK_LOADER_DATA loader_data;  // MUST be first data member
    Device &device_;
    std::thread thread_;
    mutable std::mutex lock_;
    std::condition_variable cond_;
    std::condition_variable idle_cond_;
    std::list<Submission> submissions_;
    std::atomic<uint64_t> seq_;
    bool exit_thread_{false};

    std::vector<VkCheckpointDataNV> checkpoints_;
};
}  // namespace icd
