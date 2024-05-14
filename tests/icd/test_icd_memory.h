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
#include <cassert>
#include <cstring>
#include <vector>

namespace icd {
struct DeviceMemory {
    DeviceMemory(const VkMemoryAllocateInfo& alloc_info)
        : memory(new uint8_t[alloc_info.allocationSize]), size(alloc_info.allocationSize) {}
    ~DeviceMemory() { delete[] memory; }

    VkResult Map(VkDeviceSize offset, VkDeviceSize size, VkMemoryMapFlags flags, void** ptr) {
        *ptr = memory + offset;
        return VK_SUCCESS;
    }

    uint8_t* memory;
    VkDeviceSize size;
};

struct Buffer {
    Buffer(const VkBufferCreateInfo& create_info) : size(create_info.size) {}
    VkResult Bind(DeviceMemory* mem, VkDeviceSize off) {
        assert((off + size) <= mem->size);
        bound_memory = mem;
        offset = off;
        address = uintptr_t(bound_memory->memory) + offset;
        return VK_SUCCESS;
    }
    void Write(VkDeviceSize write_offset, uint32_t value) {
        assert((write_offset + sizeof(value)) <= size);
        uint8_t* dst = bound_memory->memory + offset + write_offset;
        memcpy(dst, &value, sizeof(value));
    }

    VkDeviceSize size{0};
    VkDeviceAddress address{0};
    DeviceMemory* bound_memory{nullptr};
    VkDeviceSize offset{0};
};
};  // namespace icd
