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
#include "test_icd_device.h"
#include "test_icd_queue.h"

namespace icd {

Device::Device(VkPhysicalDevice phys, const VkDeviceCreateInfo& create_info) : physical_device_(phys) {
    set_loader_magic_value(&loader_data_);

    for (uint32_t i = 0; i < create_info.queueCreateInfoCount; i++) {
        const auto& qci = create_info.pQueueCreateInfos[i];
        queue_families_[qci.queueFamilyIndex].queues.resize(qci.queueCount);
        for (auto& q : queue_families_[qci.queueFamilyIndex].queues) {
            q = std::make_unique<Queue>(*this);
        }
    }
}

VkResult Device::GetQueue(uint32_t qfi, uint32_t index, VkQueue* pQueue) {
    *pQueue = reinterpret_cast<VkQueue>(queue_families_[qfi].queues[index].get());
    return VK_SUCCESS;
}

VkResult Device::WaitIdle() {
    for (auto& family : queue_families_) {
        for (auto& queue : family.second.queues) {
            if (queue) {
                auto result = queue->WaitIdle();
                if (result != VK_SUCCESS) {
                    return result;
                }
            }
        }
    }
    return VK_SUCCESS;
}

VkResult Device::GetFaultInfo(VkDeviceFaultCountsEXT* pFaultCounts, VkDeviceFaultInfoEXT* pFaultInfo) {
    if (!fault_info_.has_value()) {
        pFaultCounts->addressInfoCount = 0;
        pFaultCounts->vendorInfoCount = 0;
        pFaultCounts->vendorBinarySize = 0;
        return VK_SUCCESS;
    }

    if (pFaultInfo != nullptr) {
        if (pFaultCounts->addressInfoCount > uint32_t(fault_info_->address_infos.size())) {
            pFaultCounts->addressInfoCount = uint32_t(fault_info_->address_infos.size());
        }
        for (uint32_t i = 0; i < pFaultCounts->addressInfoCount; i++) {
            pFaultInfo->pAddressInfos[i] = fault_info_->address_infos[i];
        }
        if (pFaultCounts->vendorInfoCount > uint32_t(fault_info_->vendor_infos.size())) {
            pFaultCounts->vendorInfoCount = uint32_t(fault_info_->vendor_infos.size());
        }
        for (uint32_t i = 0; i < pFaultCounts->vendorInfoCount; i++) {
            pFaultInfo->pVendorInfos[i] = fault_info_->vendor_infos[i];
        }
        if (pFaultCounts->vendorBinarySize > uint32_t(fault_info_->vendory_binary.size())) {
            pFaultCounts->vendorBinarySize = uint32_t(fault_info_->vendory_binary.size());
        }
        memcpy(pFaultInfo->pVendorBinaryData, fault_info_->vendory_binary.data(), pFaultCounts->vendorBinarySize);
    }
    return VK_SUCCESS;
}

}  // namespace icd
