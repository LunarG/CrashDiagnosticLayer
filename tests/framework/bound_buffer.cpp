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
#include "bound_buffer.h"
#include "test_fixtures.h"

uint32_t BoundBuffer::FindMemoryType(vk::raii::PhysicalDevice& phys_dev, const vk::MemoryRequirements& reqs,
                                     vk::MemoryPropertyFlags flags, vk::MemoryPropertyFlags forbid) {
    auto props = phys_dev.getMemoryProperties();
    uint32_t type_mask = reqs.memoryTypeBits;
    for (uint32_t i = 0; i < props.memoryTypeCount; i++) {
        if (type_mask & 1) {
            const auto& type = props.memoryTypes[i];
            if (((type.propertyFlags & flags) == flags) &&
                ((type.propertyFlags & forbid) == vk::MemoryPropertyFlags()) &&
                (props.memoryHeaps[type.heapIndex].size >= reqs.size)) {
                return i;
            }
        }
    }
    assert(false);
    return ~0u;
}

BoundBuffer::BoundBuffer(vk::raii::PhysicalDevice& phys_dev, vk::raii::Device& device, vk::DeviceSize size,
                         const std::string& name, vk::BufferUsageFlags usage, vk::MemoryAllocateFlags alloc_flags,
                         vk::MemoryPropertyFlags flags, vk::MemoryPropertyFlags forbid)
    : buffer(device, vk::BufferCreateInfo({}, size, usage, vk::SharingMode::eExclusive)), memory(VK_NULL_HANDLE) {
    SetObjectName(device, buffer, name + "_buffer");

    auto reqs = buffer.getMemoryRequirements();

    vk::MemoryAllocateFlagsInfo flags_info(alloc_flags);
    vk::MemoryAllocateInfo alloc_info(reqs.size, FindMemoryType(phys_dev, reqs, flags, forbid), &flags_info);

    memory = device.allocateMemory(alloc_info);
    SetObjectName(device, memory, name + "_memory");

    buffer.bindMemory(memory, 0);
}

VkDeviceAddress BoundBuffer::GetAddress(const vk::raii::Device& dev) {
    vk::BufferDeviceAddressInfo bda_info(*buffer);
    return dev.getBufferAddress(bda_info);
}
