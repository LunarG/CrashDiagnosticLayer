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

#include <condition_variable>
#include <mutex>

namespace icd {
class Fence {
   public:
    Fence(const VkFenceCreateInfo& create_info);
    void Reset();
    void Signal();
    void DeviceLost();

    VkResult GetStatus() const;
    VkResult WaitFor(uint64_t ms);

   private:
    std::lock_guard<std::mutex> Lock() const { return std::lock_guard<std::mutex>(lock_); }

    mutable std::mutex lock_;
    std::condition_variable cond_;

    enum State {
        kWaiting,
        kSignalled,
        kDeviceLost,
    };

    State state_;
};

}  // namespace icd
