/*
 * Copyright (c) 2023-2024 The Khronos Group Inc.
 * Copyright (c) 2023-2024 Valve Corporation
 * Copyright (c) 2023-2024 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 */

#pragma once

#include <vulkan/vulkan_raii.hpp>

struct BoundImage {
    static constexpr vk::MemoryPropertyFlags kMemoryFlags = {};
    static constexpr vk::MemoryPropertyFlags kMemoryForbid = vk::MemoryPropertyFlagBits::eProtected;

    BoundImage(vk::raii::PhysicalDevice& phys_dev, vk::raii::Device& device, const vk::ImageCreateInfo& ci,
               const std::string& name, vk::MemoryAllocateFlags alloc_flags = {},
               vk::MemoryPropertyFlags flags = kMemoryFlags, vk::MemoryPropertyFlags forbid = kMemoryForbid);

    static uint32_t FindMemoryType(vk::raii::PhysicalDevice& phys_dev, const vk::MemoryRequirements& reqs,
                                   vk::MemoryPropertyFlags flags, vk::MemoryPropertyFlags forbid);

    vk::raii::Image image;
    vk::raii::DeviceMemory memory;
};
