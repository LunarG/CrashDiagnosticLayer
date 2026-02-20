/*
 * Copyright (c) 2024, 2026 The Khronos Group Inc.
 * Copyright (c) 2024, 2026 Valve Corporation
 * Copyright (c) 2024, 2026 LunarG, Inc.
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
#include "test_fixtures.h"
#include "bound_image.h"
#include "compute_pipeline.h"
#include "graphics_pipeline.h"
#include "dump_file.h"
#include "shaders.h"
#include <filesystem>
#include <fstream>
#include <vulkan/utility/vk_struct_helper.hpp>

class Graphics : public CDLTestBase {};

TEST_F(Graphics, InfiniteLoop) {
    InitInstance();
    auto chain = vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceDynamicRenderingFeatures>();
    auto &dynamic_rendering = chain.get<vk::PhysicalDeviceDynamicRenderingFeatures>();
    dynamic_rendering.dynamicRendering = vk::True;

    auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();
    features2.features.vertexPipelineStoresAndAtomics = VK_TRUE;

    InitDevice({}, &features2);

    BoundBuffer offset_buffer(physical_device_, device_, 4, "offset", vk::BufferUsageFlagBits::eUniformBuffer, {});
    offset_buffer.Set(0xffffffffu, 1);
    BoundBuffer write_buffer(physical_device_, device_, 16, "write", vk::BufferUsageFlagBits::eStorageBuffer, {});

    const char vs_source[] = R"glsl(
    #version 450
    layout(set = 0, binding = 0) uniform ufoo { uint index[]; } u_index;      // index[1]
    layout(set = 0, binding = 1) buffer StorageBuffer { float data[]; } Data;  // data[4]
    void main() {
        uint idx = gl_VertexIndex;
        uint cnt = u_index.index[0];

        float sum = 0;
        for (uint i = 0; i < cnt; ++i) {
            for (uint j = 0; j < cnt; ++j) {
                for (uint k = 0; k < cnt; ++k) {
                    sum += i + j + k;
                }
            }
        }
        Data.data[idx] = sum;
    }
    )glsl";
    const char fs_source[] = R"glsl(
    #version 460
    layout(location = 0) out vec4 uFragColor;
    void main(){
       uFragColor = vec4(0,1,0,1);
    }
    )glsl";

    const std::vector<vk::DescriptorSetLayoutBinding> bindings{
        {0, vk::DescriptorType::eUniformBuffer, 1, vk::ShaderStageFlagBits::eVertex},
        {1, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eVertex},
    };
    vk::ImageCreateInfo create_info;
    create_info.imageType = vk::ImageType::e2D;
    create_info.format = vk::Format::eR8G8B8A8Unorm;
    create_info.extent = vk::Extent3D(256, 256, 1);
    create_info.mipLevels = 1;
    create_info.arrayLayers = 1;
    create_info.usage = vk::ImageUsageFlagBits::eColorAttachment;

    BoundImage image(physical_device_, device_, create_info, "render_target");

    vk::ImageViewCreateInfo view_create_info;
    view_create_info.viewType = vk::ImageViewType::e2D;
    view_create_info.format = create_info.format;
    view_create_info.image = image.image;
    view_create_info.subresourceRange = vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1);

    vk::raii::ImageView view(device_, view_create_info);
    GraphicsPipelineHelper pipeline(device_, vs_source, fs_source, bindings, {});

    pipeline.DescriptorSet().WriteDescriptorBufferInfo(0, *offset_buffer.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eUniformBuffer);
    pipeline.DescriptorSet().WriteDescriptorBufferInfo(1, *write_buffer.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eStorageBuffer);
    pipeline.DescriptorSet().UpdateDescriptorSets();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eGraphics, pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, pipeline.PipelineLayout(), 0,
                                 pipeline.DescriptorSet().Set(), {});

    vk::ImageMemoryBarrier img_barrier(vk::AccessFlagBits::eMemoryWrite, vk::AccessFlagBits::eMemoryRead,
                                       vk::ImageLayout::eUndefined, vk::ImageLayout::eColorAttachmentOptimal, {}, {},
                                       image.image,  view_create_info.subresourceRange);
    cmd_buff_.pipelineBarrier(vk::PipelineStageFlagBits::eTopOfPipe, vk::PipelineStageFlagBits::eAllGraphics, {}, {},
                              {}, img_barrier);

    vk::RenderingAttachmentInfo attachment(*view, vk::ImageLayout::eColorAttachmentOptimal);
    vk::RenderingInfo rendering_info({}, {{0, 0}, {256, 256}}, 1, {}, attachment);

    cmd_buff_.beginRendering(rendering_info);

    // using non-hpp types because those try to do memory management on pointers in the fault info struct.
    auto counts = vku::InitStruct<VkDeviceFaultCountsEXT>(nullptr, 0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.draw(3, 1, 0, 0);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.endRendering();

    cmd_buff_.end();

    offset_buffer.Set(uint32_t(655356), 1);

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        queue_.submit(submit_info);
        queue_.waitIdle();
    } catch (vk::SystemError &) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, this->layer_settings.crash_diagnostic.output_path);
}

TEST_F(Graphics, MultiDrawNoCrash) {
    InitInstance();
    auto chain = vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceDynamicRenderingFeatures>();
    auto &dynamic_rendering = chain.get<vk::PhysicalDeviceDynamicRenderingFeatures>();
    dynamic_rendering.dynamicRendering = vk::True;

    auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();
    features2.features.vertexPipelineStoresAndAtomics = VK_TRUE;

    InitDevice({}, &features2);

    BoundBuffer write_buffer(physical_device_, device_, 16, "write", vk::BufferUsageFlagBits::eStorageBuffer, {});

    std::array<uint32_t, 1> push_constants{1};

    std::vector<vk::PushConstantRange> push_ranges;
    push_ranges.emplace_back(vk::ShaderStageFlagBits::eVertex, 0, uint32_t(sizeof(push_constants)));

    const char vs_source[] = R"glsl(
    #version 450
    layout(push_constant) uniform ufoo { uint index; } u_index;
    layout(set = 0, binding = 0) buffer StorageBuffer { float data[]; } Data;  // data[4]
    void main() {
        uint idx = gl_VertexIndex;
        uint cnt = u_index.index;

        float sum = 0;
        for (uint i = 0; i < cnt; ++i) {
            for (uint j = 0; j < cnt; ++j) {
                for (uint k = 0; k < cnt; ++k) {
                    sum += i + j + k;
                }
            }
        }
        Data.data[idx] = sum;
    }
    )glsl";
    const char fs_source[] = R"glsl(
    #version 460
    layout(location = 0) out vec4 uFragColor;
    void main(){
       uFragColor = vec4(0,1,0,1);
    }
    )glsl";

    const std::vector<vk::DescriptorSetLayoutBinding> bindings{
        {0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eVertex},
    };
    vk::ImageCreateInfo create_info;
    create_info.imageType = vk::ImageType::e2D;
    create_info.format = vk::Format::eR8G8B8A8Unorm;
    create_info.extent = vk::Extent3D(256, 256, 1);
    create_info.mipLevels = 1;
    create_info.arrayLayers = 1;
    create_info.usage = vk::ImageUsageFlagBits::eColorAttachment;

    BoundImage image(physical_device_, device_, create_info, "render_target");

    vk::ImageViewCreateInfo view_create_info;
    view_create_info.viewType = vk::ImageViewType::e2D;
    view_create_info.format = create_info.format;
    view_create_info.image = image.image;
    view_create_info.subresourceRange = vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1);

    vk::raii::ImageView view(device_, view_create_info);
    GraphicsPipelineHelper pipeline(device_, vs_source, fs_source, bindings, push_ranges);

    pipeline.DescriptorSet().WriteDescriptorBufferInfo(0, *write_buffer.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eStorageBuffer);
    pipeline.DescriptorSet().UpdateDescriptorSets();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    vk::ImageMemoryBarrier img_barrier(vk::AccessFlagBits::eMemoryWrite, vk::AccessFlagBits::eMemoryRead,
                                       vk::ImageLayout::eUndefined, vk::ImageLayout::eColorAttachmentOptimal, {}, {},
                                       image.image,  view_create_info.subresourceRange);
    cmd_buff_.pipelineBarrier(vk::PipelineStageFlagBits::eTopOfPipe, vk::PipelineStageFlagBits::eAllGraphics, {}, {},
                              {}, img_barrier);

    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eGraphics, pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, pipeline.PipelineLayout(), 0,
                                 pipeline.DescriptorSet().Set(), {});

    vk::RenderingAttachmentInfo attachment(*view, vk::ImageLayout::eColorAttachmentOptimal);
    vk::RenderingInfo rendering_info({}, {{0, 0}, {256, 256}}, 1, {}, attachment);

    cmd_buff_.beginRendering(rendering_info);

    push_constants[0] = 200;
    for (uint32_t i = 0; i < 7; i++) {
        cmd_buff_.pushConstants<uint32_t>(pipeline.PipelineLayout(), vk::ShaderStageFlagBits::eVertex, 0u,
                                          push_constants);
        cmd_buff_.draw(3, 1, 0, 0);
        push_constants[0] += 10;
    }

    cmd_buff_.endRendering();

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    queue_.submit(submit_info);
    queue_.waitIdle();
}


TEST_F(Graphics, MultiDrawInfiniteLoop) {
    InitInstance();
    auto chain = vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceDynamicRenderingFeatures>();
    auto &dynamic_rendering = chain.get<vk::PhysicalDeviceDynamicRenderingFeatures>();
    dynamic_rendering.dynamicRendering = vk::True;

    auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();
    features2.features.vertexPipelineStoresAndAtomics = VK_TRUE;

    InitDevice({}, &features2);

    BoundBuffer write_buffer(physical_device_, device_, 16, "write", vk::BufferUsageFlagBits::eStorageBuffer, {});

    std::array<uint32_t, 1> push_constants{1};

    std::vector<vk::PushConstantRange> push_ranges;
    push_ranges.emplace_back(vk::ShaderStageFlagBits::eVertex, 0, uint32_t(sizeof(push_constants)));

    const char vs_source[] = R"glsl(
    #version 450
    layout(push_constant) uniform ufoo { uint index; } u_index;
    layout(set = 0, binding = 0) buffer StorageBuffer { float data[]; } Data;  // data[4]
    void main() {
        uint idx = gl_VertexIndex;
        uint cnt = u_index.index;

        float sum = 0;
        for (uint i = 0; i < cnt; ++i) {
            for (uint j = 0; j < cnt; ++j) {
                for (uint k = 0; k < cnt; ++k) {
                    sum += i + j + k;
                }
            }
        }
        Data.data[idx] = sum;
    }
    )glsl";
    const char fs_source[] = R"glsl(
    #version 460
    layout(location = 0) out vec4 uFragColor;
    void main(){
       uFragColor = vec4(0,1,0,1);
    }
    )glsl";

    const std::vector<vk::DescriptorSetLayoutBinding> bindings{
        {0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eVertex},
    };
    vk::ImageCreateInfo create_info;
    create_info.imageType = vk::ImageType::e2D;
    create_info.format = vk::Format::eR8G8B8A8Unorm;
    create_info.extent = vk::Extent3D(256, 256, 1);
    create_info.mipLevels = 1;
    create_info.arrayLayers = 1;
    create_info.usage = vk::ImageUsageFlagBits::eColorAttachment;

    BoundImage image(physical_device_, device_, create_info, "render_target");

    vk::ImageViewCreateInfo view_create_info;
    view_create_info.viewType = vk::ImageViewType::e2D;
    view_create_info.format = create_info.format;
    view_create_info.image = image.image;
    view_create_info.subresourceRange = vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1);

    vk::raii::ImageView view(device_, view_create_info);
    GraphicsPipelineHelper pipeline(device_, vs_source, fs_source, bindings, push_ranges);

    pipeline.DescriptorSet().WriteDescriptorBufferInfo(0, *write_buffer.buffer, 0, vk::WholeSize,
                                                       vk::DescriptorType::eStorageBuffer);
    pipeline.DescriptorSet().UpdateDescriptorSets();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eGraphics, pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, pipeline.PipelineLayout(), 0,
                                 pipeline.DescriptorSet().Set(), {});

    vk::ImageMemoryBarrier img_barrier(vk::AccessFlagBits::eMemoryWrite, vk::AccessFlagBits::eMemoryRead,
                                       vk::ImageLayout::eUndefined, vk::ImageLayout::eColorAttachmentOptimal, {}, {},
                                       image.image,  view_create_info.subresourceRange);
    cmd_buff_.pipelineBarrier(vk::PipelineStageFlagBits::eTopOfPipe, vk::PipelineStageFlagBits::eAllGraphics, {}, {},
                              {}, img_barrier);


    vk::RenderingAttachmentInfo attachment(*view, vk::ImageLayout::eColorAttachmentOptimal);
    vk::RenderingInfo rendering_info({}, {{0, 0}, {256, 256}}, 1, {}, attachment);

    cmd_buff_.beginRendering(rendering_info);


    push_constants[0] = 200;
    for (uint32_t i = 0; i < 4; i++) {
        cmd_buff_.pushConstants<uint32_t>(pipeline.PipelineLayout(), vk::ShaderStageFlagBits::eVertex, 0u,
                                          push_constants);
        cmd_buff_.draw(3, 1, 0, 0);
        push_constants[0] += 10;
    }

    // using non-hpp types because those try to do memory management on pointers in the fault info struct.
    auto counts = vku::InitStruct<VkDeviceFaultCountsEXT>(nullptr, 0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    push_constants[0] = 0xffffffff;
    cmd_buff_.pushConstants<uint32_t>(pipeline.PipelineLayout(), vk::ShaderStageFlagBits::eVertex, 0u,
                                      push_constants);
    cmd_buff_.draw(3, 1, 0, 0);
    cmd_buff_.endDebugUtilsLabelEXT();

    push_constants[0] = 200;
    for (uint32_t i = 0; i < 4; i++) {
        cmd_buff_.pushConstants<uint32_t>(pipeline.PipelineLayout(), vk::ShaderStageFlagBits::eVertex, 0u,
                                          push_constants);
        cmd_buff_.draw(3, 1, 0, 0);
        push_constants[0] += 10;
    }

    cmd_buff_.endRendering();

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        queue_.submit(submit_info);
        queue_.waitIdle();
    } catch (vk::SystemError &) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, this->layer_settings.crash_diagnostic.output_path);
}
