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
#include "test_fixtures.h"
#include "shaders.h"

class GpuCrash : public CDLTestBase {};

TEST_F(GpuCrash, NoCrash) {
    InitInstance();
    InitDevice();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    compute_queue_.submit(submit_info);
    compute_queue_.waitIdle();
}

TEST_F(GpuCrash, CopyCrash) {
    InitInstance();
    InitDevice();

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    BoundBuffer in = AllocateMemory(kBuffSize, "in", vk::BufferUsageFlagBits::eTransferSrc);
    in.set(1.0f, kNumElems);

    BoundBuffer out = AllocateMemory(kBuffSize, "out", vk::BufferUsageFlagBits::eTransferDst);
    out.set(0.0f, kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    vk::BufferCopy regions(0, 0, sizeof(float));
    cmd_buff_.copyBuffer(in.buffer, out.buffer, regions);
    cmd_buff_.end();

    // this is invalid and will likely cause a VK_DEVICE_LOST
    in.memory.clear();
    out.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::DeviceLostError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
}

TEST_F(GpuCrash, ShaderCrash) {
    InitInstance();
    InitDevice();

    vk::raii::ShaderModule shader_module = CreateShaderModuleGLSL(kCrashComputeComp, vk::ShaderStageFlagBits::eCompute);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    BoundBuffer in = AllocateMemory(kBuffSize, "in", vk::BufferUsageFlagBits::eTransferSrc);
    in.set(uint32_t(65535), kNumElems);

    BoundBuffer out = AllocateMemory(kBuffSize, "out", vk::BufferUsageFlagBits::eTransferDst);
    out.set(0.0f, kNumElems);

    vk::DescriptorPoolSize pool_size(vk::DescriptorType::eStorageBuffer, 2);
    vk::DescriptorPoolCreateInfo pool_ci(vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, 2, pool_size);

    vk::raii::DescriptorPool pool = device_.createDescriptorPool(pool_ci);

    std::array<vk::DescriptorSetLayoutBinding, 2> bindings = {
        vk::DescriptorSetLayoutBinding(0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
        vk::DescriptorSetLayoutBinding(1, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
    };

    vk::DescriptorSetLayoutCreateInfo ds_layout_ci({}, bindings);
    vk::raii::DescriptorSetLayout ds_layout = device_.createDescriptorSetLayout(ds_layout_ci);

    vk::DescriptorSetAllocateInfo set_alloc_info(pool, *ds_layout);
    vk::raii::DescriptorSet descriptor_set = std::move(device_.allocateDescriptorSets(set_alloc_info).front());

    std::array<vk::DescriptorBufferInfo, 2> buffer_infos;
    buffer_infos[0].buffer = in.buffer;
    buffer_infos[0].offset = 0;
    buffer_infos[0].range = vk::WholeSize;
    buffer_infos[1].buffer = out.buffer;
    buffer_infos[1].offset = 0;
    buffer_infos[1].range = vk::WholeSize;

    std::array<vk::WriteDescriptorSet, 2> writes;
    writes[0].dstSet = descriptor_set;
    writes[0].dstBinding = 0;
    writes[0].descriptorCount = 1;
    writes[0].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[0].pBufferInfo = &buffer_infos[0];
    writes[1].dstSet = descriptor_set;
    writes[1].dstBinding = 1;
    writes[1].descriptorCount = 1;
    writes[1].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[1].pBufferInfo = &buffer_infos[1];

    device_.updateDescriptorSets(writes, {});
    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, *ds_layout);
    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(pipeline_layout_ci);

    vk::PipelineShaderStageCreateInfo stage_ci({}, vk::ShaderStageFlagBits::eCompute, shader_module, "main");
    vk::ComputePipelineCreateInfo pipeline_ci({}, stage_ci, pipeline_layout);
    vk::raii::Pipeline pipeline = device_.createComputePipeline(nullptr, pipeline_ci);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, pipeline);
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, pipeline_layout, 0, *descriptor_set, {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    // this is invalid and will likely cause a VK_DEVICE_LOST
    in.buffer.clear();
    in.memory.clear();
    out.buffer.clear();
    out.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::DeviceLostError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
}

TEST_F(GpuCrash, InfiniteLoop) {
    InitInstance();
    InitDevice();

    vk::raii::ShaderModule shader_module = CreateShaderModuleGLSL(kInfiniteLoopComp, vk::ShaderStageFlagBits::eCompute);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    BoundBuffer in = AllocateMemory(kBuffSize, "in",
                                    vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eTransferSrc);
    in.set(uint32_t(65535), kNumElems);

    BoundBuffer out = AllocateMemory(kBuffSize, "out",
                                     vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eTransferDst);
    out.set(0.0f, kNumElems);

    vk::DescriptorPoolSize pool_size(vk::DescriptorType::eStorageBuffer, 2);
    vk::DescriptorPoolCreateInfo pool_ci(vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, 2, pool_size);

    vk::raii::DescriptorPool pool = device_.createDescriptorPool(pool_ci);

    std::array<vk::DescriptorSetLayoutBinding, 2> bindings = {
        vk::DescriptorSetLayoutBinding(0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
        vk::DescriptorSetLayoutBinding(1, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
    };

    vk::DescriptorSetLayoutCreateInfo ds_layout_ci({}, bindings);
    vk::raii::DescriptorSetLayout ds_layout = device_.createDescriptorSetLayout(ds_layout_ci);

    vk::DescriptorSetAllocateInfo set_alloc_info(pool, *ds_layout);
    vk::raii::DescriptorSet descriptor_set = std::move(device_.allocateDescriptorSets(set_alloc_info).front());

    std::array<vk::DescriptorBufferInfo, 2> buffer_infos;
    buffer_infos[0].buffer = in.buffer;
    buffer_infos[0].offset = 0;
    buffer_infos[0].range = vk::WholeSize;
    buffer_infos[1].buffer = out.buffer;
    buffer_infos[1].offset = 0;
    buffer_infos[1].range = vk::WholeSize;

    std::array<vk::WriteDescriptorSet, 2> writes;
    writes[0].dstSet = descriptor_set;
    writes[0].dstBinding = 0;
    writes[0].descriptorCount = 1;
    writes[0].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[0].pBufferInfo = &buffer_infos[0];
    writes[1].dstSet = descriptor_set;
    writes[1].dstBinding = 1;
    writes[1].descriptorCount = 1;
    writes[1].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[1].pBufferInfo = &buffer_infos[1];

    device_.updateDescriptorSets(writes, {});

    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, *ds_layout);
    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(pipeline_layout_ci);

    vk::PipelineShaderStageCreateInfo stage_ci({}, vk::ShaderStageFlagBits::eCompute, shader_module, "main");
    vk::ComputePipelineCreateInfo pipeline_ci({}, stage_ci, pipeline_layout);
    vk::raii::Pipeline pipeline = device_.createComputePipeline(nullptr, pipeline_ci);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, pipeline);
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, pipeline_layout, 0, *descriptor_set, {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::DeviceLostError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
}

TEST_F(GpuCrash, HangHostEvent) {
    InitInstance();
    InitDevice();

    vk::raii::ShaderModule shader_module = CreateShaderModuleGLSL(kReadWriteComp, vk::ShaderStageFlagBits::eCompute);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    BoundBuffer in = AllocateMemory(kBuffSize, "in",
                                    vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eTransferSrc);
    in.set(uint32_t(65535), kNumElems);

    BoundBuffer out = AllocateMemory(kBuffSize, "out",
                                     vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eTransferDst);
    out.set(0.0f, kNumElems);

    vk::DescriptorPoolSize pool_size(vk::DescriptorType::eStorageBuffer, 2);
    vk::DescriptorPoolCreateInfo pool_ci(vk::DescriptorPoolCreateFlagBits::eFreeDescriptorSet, 2, pool_size);

    vk::raii::DescriptorPool pool = device_.createDescriptorPool(pool_ci);

    std::array<vk::DescriptorSetLayoutBinding, 2> bindings = {
        vk::DescriptorSetLayoutBinding(0, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
        vk::DescriptorSetLayoutBinding(1, vk::DescriptorType::eStorageBuffer, 1, vk::ShaderStageFlagBits::eCompute,
                                       nullptr),
    };

    vk::DescriptorSetLayoutCreateInfo ds_layout_ci({}, bindings);
    vk::raii::DescriptorSetLayout ds_layout = device_.createDescriptorSetLayout(ds_layout_ci);

    vk::DescriptorSetAllocateInfo set_alloc_info(pool, *ds_layout);
    vk::raii::DescriptorSet descriptor_set = std::move(device_.allocateDescriptorSets(set_alloc_info).front());

    std::array<vk::DescriptorBufferInfo, 2> buffer_infos;
    buffer_infos[0].buffer = in.buffer;
    buffer_infos[0].offset = 0;
    buffer_infos[0].range = vk::WholeSize;
    buffer_infos[1].buffer = out.buffer;
    buffer_infos[1].offset = 0;
    buffer_infos[1].range = vk::WholeSize;

    std::array<vk::WriteDescriptorSet, 2> writes;
    writes[0].dstSet = descriptor_set;
    writes[0].dstBinding = 0;
    writes[0].descriptorCount = 1;
    writes[0].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[0].pBufferInfo = &buffer_infos[0];
    writes[1].dstSet = descriptor_set;
    writes[1].dstBinding = 1;
    writes[1].descriptorCount = 1;
    writes[1].descriptorType = vk::DescriptorType::eStorageBuffer;
    writes[1].pBufferInfo = &buffer_infos[1];

    device_.updateDescriptorSets(writes, {});

    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, *ds_layout);
    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(pipeline_layout_ci);

    vk::PipelineShaderStageCreateInfo stage_ci({}, vk::ShaderStageFlagBits::eCompute, shader_module, "main");
    vk::ComputePipelineCreateInfo pipeline_ci({}, stage_ci, pipeline_layout);
    vk::raii::Pipeline pipeline = device_.createComputePipeline(nullptr, pipeline_ci);

    vk::raii::Event event = device_.createEvent(vk::EventCreateInfo());
    SetObjectName(event, "never-signalled-event");

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, pipeline);
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, pipeline_layout, 0, *descriptor_set, {});

    cmd_buff_.waitEvents(*event, vk::PipelineStageFlagBits::eHost, vk::PipelineStageFlagBits::eBottomOfPipe, {}, {},
                         {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});
    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::DeviceLostError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
}

TEST_F(GpuCrash, ReadBeforePointerPushConstant) {
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceVulkan12Features> chain;

    auto &vk12_features = chain.get<vk::PhysicalDeviceVulkan12Features>();
    vk12_features.bufferDeviceAddress = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    InitDevice({}, &features2);

    vk::raii::ShaderModule shader_module =
        CreateShaderModuleGLSL(kReadBeforePointerPushConstant, vk::ShaderStageFlagBits::eCompute);

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);

    BoundBuffer bda = AllocateMemory(
        kBuffSize, "bda", vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eShaderDeviceAddress,
        vk::MemoryAllocateFlagBits::eDeviceAddress);
    bda.set(1.0f, kNumElems);

    vk::DeviceAddress addr = device_.getBufferAddress(vk::BufferDeviceAddressInfo(*bda.buffer));

    std::array<const vk::DeviceAddress, 2> push_constants{addr, 2};

    vk::PushConstantRange push_range(vk::ShaderStageFlagBits::eCompute, 0, sizeof(push_constants));
    vk::PipelineLayoutCreateInfo pipeline_layout_ci({}, {}, push_range);
    vk::raii::PipelineLayout pipeline_layout = device_.createPipelineLayout(pipeline_layout_ci);

    vk::PipelineShaderStageCreateInfo stage_ci({}, vk::ShaderStageFlagBits::eCompute, shader_module, "main");
    vk::ComputePipelineCreateInfo pipeline_ci({}, stage_ci, pipeline_layout);
    vk::raii::Pipeline pipeline = device_.createComputePipeline(nullptr, pipeline_ci);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, pipeline);
    cmd_buff_.pushConstants<vk::DeviceAddress>(pipeline_layout, vk::ShaderStageFlagBits::eCompute, 0u, push_constants);
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    bda.buffer.clear();
    bda.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::DeviceLostError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);
}
