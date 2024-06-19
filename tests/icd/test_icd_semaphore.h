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

#include <atomic>
#include <cassert>
#include <condition_variable>
#include <mutex>

namespace icd {
class Semaphore {
   public:
    // Host Functions
    virtual VkResult Signal(uint64_t value) = 0;
    virtual VkResult Wait(uint64_t timeout, uint64_t value) = 0;
    virtual VkResult GetCounterValue(uint64_t *value) = 0;

    virtual void QueueSignal(uint64_t value) = 0;
    virtual VkResult QueueWait(uint64_t value) = 0;
    virtual void DeviceLost() = 0;

   protected:
    std::unique_lock<std::mutex> Lock() const { return std::unique_lock<std::mutex>(lock_); }
    mutable std::mutex lock_;
    std::condition_variable cond_;
};

class BinarySemaphore : public Semaphore {
   public:
    BinarySemaphore() {}
    VkResult Signal(uint64_t value) override {
        assert(false);
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }
    VkResult Wait(uint64_t timeout, uint64_t value) override {
        assert(false);
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }
    VkResult GetCounterValue(uint64_t *value) override {
        assert(false);
        return VK_ERROR_FEATURE_NOT_PRESENT;
    }

    void QueueSignal(uint64_t value) override;
    VkResult QueueWait(uint64_t value) override;
    void DeviceLost() override;

   private:
    enum State {
        kWaiting,
        kSignalled,
        kDeviceLost,
    };
    State state_;
};

class TimelineSemaphore : public Semaphore {
   public:
    static constexpr uint64_t kDeviceLostValue = uint64_t(-1);
    TimelineSemaphore(uint64_t initial_value);

    VkResult Signal(uint64_t value) override;
    VkResult Wait(uint64_t timeout, uint64_t value) override;
    VkResult GetCounterValue(uint64_t *value) override;

    void QueueSignal(uint64_t value) override;
    VkResult QueueWait(uint64_t value) override;
    void DeviceLost() override;

   private:
    uint64_t current_value_;
};

}  // namespace icd
