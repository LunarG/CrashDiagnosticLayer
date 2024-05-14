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

#include "test_icd_semaphore.h"
#include <cassert>

namespace icd {

void BinarySemaphore::QueueSignal(uint64_t value) {
    auto guard = Lock();
    // Don't clear device lost.
    if (state_ == kWaiting) {
        state_ = kSignalled;
    }
    cond_.notify_one();
}

VkResult BinarySemaphore::QueueWait([[maybe_unused]] uint64_t value) {
    auto guard = Lock();
    cond_.wait(guard, [this] { return state_ != kWaiting; });
    if (state_ == kDeviceLost) {
        return VK_ERROR_DEVICE_LOST;
    }
    // reset the semaphore after the wait is complete so it is ready for the next signal
    state_ = kWaiting;
    return VK_SUCCESS;
}

void BinarySemaphore::DeviceLost() {
    auto guard = Lock();
    state_ = kDeviceLost;
    cond_.notify_one();
}

TimelineSemaphore::TimelineSemaphore(uint64_t initial_value) : current_value_(initial_value) {}

VkResult TimelineSemaphore::Signal(uint64_t value) {
    auto guard = Lock();
    assert(current_value_ < value);
    current_value_ = value;
    cond_.notify_all();
    return VK_SUCCESS;
}

VkResult TimelineSemaphore::Wait(uint64_t timeout, uint64_t value) {
    auto guard = std::unique_lock<std::mutex>(lock_);
    if (!cond_.wait_for(guard, std::chrono::milliseconds{timeout}, [this, value] { return current_value_ >= value; })) {
        return VK_TIMEOUT;
    }
    return (current_value_ != kDeviceLostValue) ? VK_SUCCESS : VK_ERROR_DEVICE_LOST;
}

VkResult TimelineSemaphore::GetCounterValue(uint64_t *value) {
    auto guard = Lock();
    *value = current_value_;
    return (current_value_ != kDeviceLostValue) ? VK_SUCCESS : VK_ERROR_DEVICE_LOST;
}

void TimelineSemaphore::QueueSignal(uint64_t value) {
    auto guard = Lock();
    assert(current_value_ < value);
    current_value_ = value;
    cond_.notify_all();
}

VkResult TimelineSemaphore::QueueWait(uint64_t value) {
    auto guard = Lock();
    cond_.wait(guard, [this, value] { return current_value_ >= value; });
    return (current_value_ != kDeviceLostValue) ? VK_SUCCESS : VK_ERROR_DEVICE_LOST;
}

void TimelineSemaphore::DeviceLost() {
    auto guard = Lock();
    current_value_ = kDeviceLostValue;
}
}  // namespace icd
