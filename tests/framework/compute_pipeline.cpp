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

#include "compute_pipeline.h"
#include "test_fixtures.h"

ComputePipelineHelper::ComputePipelineHelper(vk::raii::Device &device, const char *shader,
                                             const std::vector<vk::DescriptorSetLayoutBinding> &bindings,
                                             const std::vector<vk::PushConstantRange> &push_constants, void *pNext)
    : device_(device),
      pipeline_cache_(device_, vk::PipelineCacheCreateInfo()),
      cs_(CreateShaderModuleGLSL(device, shader, vk::ShaderStageFlagBits::eCompute)),
      descriptor_set_(device, bindings),
      pipeline_layout_(VK_NULL_HANDLE),
      pipeline_(VK_NULL_HANDLE) {
    auto ds_layout = descriptor_set_.Layout();
    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, ds_layout, push_constants);
    pipeline_layout_ = device_.createPipelineLayout(pipeline_layout_ci);

    vk::PipelineShaderStageCreateInfo stage_ci({}, vk::ShaderStageFlagBits::eCompute, *cs_, "main");
    vk::ComputePipelineCreateInfo cp_ci({}, stage_ci, *pipeline_layout_);
    cp_ci.pNext = pNext;
    pipeline_ = device_.createComputePipeline(pipeline_cache_, cp_ci);
}

static const std::vector<vk::DescriptorSetLayoutBinding> io_bindings{
    {0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute},
    {1, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute},
};

ComputeIOTest::ComputeIOTest(vk::raii::PhysicalDevice &phys_dev, vk::raii::Device &device, const char *shader)
    : pipeline(device, shader, io_bindings),
      input(phys_dev, device, kBuffSize, "input", vk::BufferUsageFlagBits::eStorageBuffer),
      output(phys_dev, device, kBuffSize, "output", vk::BufferUsageFlagBits::eStorageBuffer) {
    pipeline.DescriptorSet().WriteDescriptorBufferInfo(0, *input.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eStorageBuffer);
    pipeline.DescriptorSet().WriteDescriptorBufferInfo(1, *output.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eStorageBuffer);

    pipeline.DescriptorSet().UpdateDescriptorSets();
}
