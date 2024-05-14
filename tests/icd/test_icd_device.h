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
#include <vector>

#include "test_icd_queue.h"

namespace icd {
struct Queue;
struct QueueFamily {
    std::vector<std::unique_ptr<Queue>> queues;
};

struct Device {
    Device(VkPhysicalDevice phys, const VkDeviceCreateInfo& create_info) : physical_device(phys) {
        set_loader_magic_value(&loader_data);

        for (uint32_t i = 0; i < create_info.queueCreateInfoCount; i++) {
            const auto& qci = create_info.pQueueCreateInfos[i];
            queue_families[qci.queueFamilyIndex].queues.resize(qci.queueCount);
            for (auto& q : queue_families[qci.queueFamilyIndex].queues) {
                q = std::make_unique<Queue>();
            }
        }
    }

    VkResult GetQueue(uint32_t qfi, uint32_t index, VkQueue* pQueue) {
        *pQueue = reinterpret_cast<VkQueue>(queue_families[qfi].queues[index].get());
        return VK_SUCCESS;
    }

    VkResult WaitIdle() { return VK_SUCCESS; }
    VkResult GetFaultInfo(VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) { return VK_SUCCESS; }

    VK_LOADER_DATA loader_data;  // MUST be first data member
    VkPhysicalDevice physical_device;
    std::map<uint32_t, QueueFamily> queue_families;
};

}  // namespace icd
