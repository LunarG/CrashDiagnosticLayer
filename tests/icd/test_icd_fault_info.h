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
#include <cassert>
#include <cstdint>
#include <cstring>
#include <optional>
#include <string>
#include <vector>

#include <vulkan/vulkan_core.h>
#include <vulkan/utility/vk_struct_helper.hpp>

namespace icd {

struct FaultInfo {
    FaultInfo(const VkDebugUtilsLabelEXT& label) {
        auto* fault_counts = vku::FindStructInPNextChain<VkDeviceFaultCountsEXT>(label.pNext);
        if (!fault_counts) {
            return;
        }
        if (fault_counts->addressInfoCount == 0 && fault_counts->vendorInfoCount == 0 &&
            fault_counts->vendorBinarySize == 0) {
            return;
        }
        auto* fault_info = vku::FindStructInPNextChain<VkDeviceFaultInfoEXT>(label.pNext);
        assert(fault_info);
        description = fault_info->description;

        address_infos.reserve(fault_counts->addressInfoCount);
        for (uint32_t i = 0; i < fault_counts->addressInfoCount; i++) {
            address_infos.push_back(fault_info->pAddressInfos[i]);
        }
        vendor_infos.reserve(fault_counts->vendorInfoCount);
        for (uint32_t i = 0; i < fault_counts->vendorInfoCount; i++) {
            vendor_infos.push_back(fault_info->pVendorInfos[i]);
        }
        vendor_binary.resize(fault_counts->vendorBinarySize);
        memcpy(vendor_binary.data(), fault_info->pVendorBinaryData, fault_counts->vendorBinarySize);
    }

    std::string description;
    std::vector<VkDeviceFaultAddressInfoEXT> address_infos;
    std::vector<VkDeviceFaultVendorInfoEXT> vendor_infos;
    std::vector<uint8_t> vendor_binary;
};
}  // namespace icd
