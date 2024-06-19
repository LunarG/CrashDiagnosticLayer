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
#include "test_icd_fence.h"

#include <cassert>
#include <chrono>

namespace icd {

Fence::Fence(const VkFenceCreateInfo& create_info)
    : state_((create_info.flags & VK_FENCE_CREATE_SIGNALED_BIT) ? kSignalled : kWaiting) {}

void Fence::Reset() {
    auto guard = Lock();
    state_ = kWaiting;
}

void Fence::Signal() {
    auto guard = Lock();
    state_ = kSignalled;
    cond_.notify_all();
}

void Fence::DeviceLost() {
    auto guard = Lock();
    state_ = kDeviceLost;
    cond_.notify_all();
}

VkResult Fence::GetStatus() const {
    auto guard = Lock();
    switch (state_) {
        case kWaiting:
            return VK_NOT_READY;
        case kSignalled:
            return VK_SUCCESS;
        case kDeviceLost:
        default:
            return VK_ERROR_DEVICE_LOST;
    }
}

VkResult Fence::WaitFor(uint64_t ms) {
    auto guard = std::unique_lock<std::mutex>(lock_);
    std::chrono::milliseconds ss{ms};
    if (!cond_.wait_for(guard, std::chrono::milliseconds{ms}, [this] { return state_ != kWaiting; })) {
        return VK_TIMEOUT;
    }
    assert(state_ != kWaiting);
    return (state_ == kSignalled) ? VK_SUCCESS : VK_ERROR_DEVICE_LOST;
}

}  // namespace icd
