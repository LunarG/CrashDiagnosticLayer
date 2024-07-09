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
#include <map>
#include <memory>
#include <optional>
#include <vector>

#include "test_icd_fault_info.h"
#include "test_icd_queue.h"

namespace icd {
class Queue;

struct QueueFamily {
    std::vector<std::unique_ptr<Queue>> queues;
};

class Device {
   public:
    Device(VkPhysicalDevice phys, const VkDeviceCreateInfo& create_info);

    VkResult GetQueue(uint32_t qfi, uint32_t index, VkQueue* pQueue);
    VkResult WaitIdle();
    VkResult GetFaultInfo(VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo);

    void SetFaultInfo(FaultInfo&& info);

   private:
    VK_LOADER_DATA loader_data_;  // MUST be first data member
    std::map<uint32_t, QueueFamily> queue_families_;
    std::optional<FaultInfo> fault_info_;
};

}  // namespace icd
