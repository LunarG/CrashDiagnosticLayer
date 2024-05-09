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

#include "descriptorset_helper.h"

DescriptorSetHelper::DescriptorSetHelper(vk::raii::Device &device, const Bindings &bindings,
                                         vk::DescriptorSetLayoutCreateFlags layout_flags, void *layout_pnext,
                                         vk::DescriptorPoolCreateFlags poolFlags, void *allocate_pnext,
                                         void *create_pool_pnext)
    : device_{device}, pool_(VK_NULL_HANDLE), layout_(VK_NULL_HANDLE), set_(VK_NULL_HANDLE) {
    vk::Result err;
    std::vector<vk::DescriptorPoolSize> sizes;
    for (const auto &b : bindings) sizes.push_back({b.descriptorType, std::max(1u, b.descriptorCount)});

    vk::DescriptorSetLayoutCreateInfo ds_layout_ci({}, bindings);
    layout_ = device_.createDescriptorSetLayout(ds_layout_ci);

    vk::DescriptorPoolCreateInfo dspci(poolFlags, 1, uint32_t(sizes.size()), sizes.data(), create_pool_pnext);
    pool_ = device_.createDescriptorPool(dspci);

    if (!(layout_flags & vk::DescriptorSetLayoutCreateFlagBits::ePushDescriptorKHR)) {
        vk::DescriptorSetAllocateInfo alloc_info(*pool_, *layout_, allocate_pnext);
        set_ = std::move(device_.allocateDescriptorSets(alloc_info).front());
    }
}

void DescriptorSetHelper::Clear() {
    resource_infos_.clear();
    descriptor_writes_.clear();
}

void DescriptorSetHelper::AddDescriptorWrite(uint32_t binding, uint32_t array_element,
                                             vk::DescriptorType descriptor_type, uint32_t descriptor_count /*= 1*/) {
    vk::WriteDescriptorSet descriptor_write(set_, binding, array_element, descriptor_count, descriptor_type);
    descriptor_writes_.emplace_back(descriptor_write);
}

void DescriptorSetHelper::WriteDescriptorBufferInfo(int binding, vk::Buffer buffer, vk::DeviceSize offset,
                                                    vk::DeviceSize range, vk::DescriptorType descriptorType,
                                                    uint32_t arrayElement) {
    vk::DescriptorBufferInfo buffer_info(buffer, offset, range);

    ResourceInfo resource_info;
    resource_info.buffer_info = buffer_info;
    resource_infos_.emplace_back(resource_info);
    AddDescriptorWrite(binding, arrayElement, descriptorType);
}

void DescriptorSetHelper::WriteDescriptorBufferView(int binding, vk::BufferView buffer_view,
                                                    vk::DescriptorType descriptorType, uint32_t arrayElement) {
    ResourceInfo resource_info;
    resource_info.buffer_view = buffer_view;
    resource_infos_.emplace_back(resource_info);
    AddDescriptorWrite(binding, arrayElement, descriptorType);
}

void DescriptorSetHelper::WriteDescriptorImageInfo(int binding, vk::ImageView image_view, vk::Sampler sampler,
                                                   vk::DescriptorType descriptorType, vk::ImageLayout imageLayout,
                                                   uint32_t arrayElement) {
    vk::DescriptorImageInfo image_info(sampler, image_view, imageLayout);

    ResourceInfo resource_info;
    resource_info.image_info = image_info;
    resource_infos_.emplace_back(resource_info);
    AddDescriptorWrite(binding, arrayElement, descriptorType);
}

void DescriptorSetHelper::WriteDescriptorAccelStruct(int binding, uint32_t accelerationStructureCount,
                                                     const vk::AccelerationStructureKHR *pAccelerationStructures,
                                                     uint32_t arrayElement /*= 0*/) {
    vk::WriteDescriptorSetAccelerationStructureKHR write_desc_set_accel_struct(accelerationStructureCount,
                                                                               pAccelerationStructures);

    ResourceInfo resource_info;
    resource_info.accel_struct_info = write_desc_set_accel_struct;
    resource_infos_.emplace_back(resource_info);
    AddDescriptorWrite(binding, arrayElement, vk::DescriptorType::eAccelerationStructureKHR,
                       accelerationStructureCount);
}

void DescriptorSetHelper::UpdateDescriptorSets() {
    assert(resource_infos_.size() == descriptor_writes_.size());
    for (size_t i = 0; i < resource_infos_.size(); i++) {
        const auto &info = resource_infos_[i];
        if (info.image_info.has_value()) {
            descriptor_writes_[i].pImageInfo = &info.image_info.value();
        } else if (info.buffer_info.has_value()) {
            descriptor_writes_[i].pBufferInfo = &info.buffer_info.value();
        } else if (info.buffer_view.has_value()) {
            descriptor_writes_[i].pTexelBufferView = &info.buffer_view.value();
        } else {
            assert(info.accel_struct_info.has_value());
            descriptor_writes_[i].pNext = &info.accel_struct_info.value();
        }
    }
    device_.updateDescriptorSets(descriptor_writes_, {});
}
