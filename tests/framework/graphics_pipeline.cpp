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

#include "graphics_pipeline.h"
#include "test_fixtures.h"

GraphicsPipelineHelper::GraphicsPipelineHelper(vk::raii::Device &device, const char *vert_shader,
                                               const char *frag_shader,
                                               const std::vector<vk::DescriptorSetLayoutBinding> &bindings,
                                               const std::vector<vk::PushConstantRange> &push_constants, void *pNext)
    : device_(device),
      pipeline_cache_(device_, vk::PipelineCacheCreateInfo()),
      vs_(CreateShaderModuleGLSL(device, vert_shader, vk::ShaderStageFlagBits::eVertex)),
      fs_(CreateShaderModuleGLSL(device, frag_shader, vk::ShaderStageFlagBits::eFragment)),
      descriptor_set_(device, bindings),
      pipeline_layout_(VK_NULL_HANDLE),
      pipeline_(VK_NULL_HANDLE),
      vi_ci_(),
      ia_ci_({}, vk::PrimitiveTopology::eTriangleStrip),
      viewport_(0.0, 0.0, 64, 64, 0, 1),
      scissor_({0, 0}, {64, 64}),
      vp_state_ci_({}, viewport_, scissor_),
      ms_ci_({}, vk::SampleCountFlagBits::e1),
      rs_state_ci_({}, vk::False, vk::False, vk::PolygonMode::eFill, vk::CullModeFlagBits::eBack,
                   vk::FrontFace::eClockwise, vk::False, 0, 0, 0, 1.0),
      cb_attachments_(),
      cb_ci_({}, vk::False, vk::LogicOp::eCopy, cb_attachments_, {1, 1, 1, 1}),
      attachment_format_(vk::Format::eR8G8B8A8Unorm),
      dynamic_rendering_ci_({}, attachment_format_) {
    auto ds_layout = descriptor_set_.Layout();
    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, ds_layout, push_constants);
    pipeline_layout_ = device_.createPipelineLayout(pipeline_layout_ci);

    std::array<vk::PipelineShaderStageCreateInfo, 2> stage_ci{
        vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eVertex, *vs_, "main"),
        vk::PipelineShaderStageCreateInfo({}, vk::ShaderStageFlagBits::eFragment, *fs_, "main"),
    };

    vk::GraphicsPipelineCreateInfo gp_ci({}, stage_ci, &vi_ci_, &ia_ci_, nullptr, &vp_state_ci_, &rs_state_ci_, &ms_ci_,
                                         nullptr, &cb_ci_, nullptr, pipeline_layout_);
    dynamic_rendering_ci_.pNext = pNext;
    gp_ci.pNext = &dynamic_rendering_ci_;
    pipeline_ = device_.createGraphicsPipeline(pipeline_cache_, gp_ci);
}
