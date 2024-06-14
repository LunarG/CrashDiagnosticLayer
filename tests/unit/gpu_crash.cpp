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
#include "compute_pipeline.h"
#include "dump_file.h"
#include "shaders.h"
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <vulkan/utility/vk_struct_helper.hpp>

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

    BoundBuffer in(physical_device_, device_, kBuffSize, "in", vk::BufferUsageFlagBits::eTransferSrc);
    in.Set(1.0f, kNumElems);

    BoundBuffer out(physical_device_, device_, kBuffSize, "out", vk::BufferUsageFlagBits::eTransferDst);
    out.Set(0.0f, kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    vk::BufferCopy regions(0, 0, sizeof(float));
    cmd_buff_.copyBuffer(in.buffer, out.buffer, regions);
    cmd_buff_.endDebugUtilsLabelEXT();

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
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(GpuCrash, ShaderCrash) {
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kCrashComputeComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);

    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    // this is invalid and will likely cause a VK_DEVICE_LOST
    state.input.buffer.clear();
    state.input.memory.clear();
    state.output.buffer.clear();
    state.output.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(GpuCrash, InfiniteLoop) {
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kInfiniteLoopComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.dispatch(1, 1, 1);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(GpuCrash, InfiniteLoopSubmit2) {
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kInfiniteLoopComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.dispatch(1, 1, 1);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    vk::CommandBufferSubmitInfo cb_info(*cmd_buff_);
    vk::SubmitInfo2 submit_info({}, {}, cb_info, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit2(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(GpuCrash, HangHostEvent) {
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kInfiniteLoopComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::raii::Event event = device_.createEvent(vk::EventCreateInfo());
    SetObjectName(device_, event, "never-signalled-event");

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});

    vk::DeviceFaultCountsEXT counts(0, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.waitEvents(*event, vk::PipelineStageFlagBits::eHost, vk::PipelineStageFlagBits::eBottomOfPipe, {}, {},
                         {});

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});
    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(GpuCrash, ReadBeforePointerPushConstant) {
    InitInstance();

    vk::StructureChain<vk::PhysicalDeviceFeatures2, vk::PhysicalDeviceVulkan12Features> chain;

    auto &vk12_features = chain.get<vk::PhysicalDeviceVulkan12Features>();
    vk12_features.bufferDeviceAddress = VK_TRUE;

    const auto &features2 = chain.get<vk::PhysicalDeviceFeatures2>();

    InitDevice({}, &features2);

    bool fault_ext_supported = false;
    auto extensions = physical_device_.enumerateDeviceExtensionProperties();
    for (const auto &ext : extensions) {
        if (std::string_view(ext.extensionName) == VK_EXT_DEVICE_FAULT_EXTENSION_NAME) {
            fault_ext_supported = true;
            break;
        }
    }

    constexpr size_t kNumElems = 256;
    constexpr VkDeviceSize kBuffSize = kNumElems * sizeof(float);
    BoundBuffer bda(physical_device_, device_, kBuffSize, "bda",
                    vk::BufferUsageFlagBits::eStorageBuffer | vk::BufferUsageFlagBits::eShaderDeviceAddress,
                    vk::MemoryAllocateFlagBits::eDeviceAddress);
    bda.Set(1.0f, kNumElems);

    vk::DeviceAddress addr = device_.getBufferAddress(vk::BufferDeviceAddressInfo(*bda.buffer));
    ASSERT_NE(addr, 0);

    std::array<const vk::DeviceAddress, 2> push_constants{addr, 2};

    std::vector<vk::PushConstantRange> push_ranges;
    push_ranges.emplace_back(vk::ShaderStageFlagBits::eCompute, 0, uint32_t(sizeof(push_constants)));

    ComputePipelineHelper pipeline(device_, kReadBeforePointerPushConstant, {}, push_ranges);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, pipeline.Pipeline());
    cmd_buff_.pushConstants<vk::DeviceAddress>(pipeline.PipelineLayout(), vk::ShaderStageFlagBits::eCompute, 0u,
                                               push_constants);

    // using non-hpp types because those try to do memory management on pointers in the fault info struct.
    VkDeviceFaultAddressInfoEXT address_info{VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT, addr, 0x1000};
    auto fault_info = vku::InitStruct<VkDeviceFaultInfoEXT>();
    strncpy(fault_info.description, "fault-description", sizeof(fault_info.description));
    fault_info.pAddressInfos = &address_info;

    auto counts = vku::InitStruct<VkDeviceFaultCountsEXT>(&fault_info, 1, 0, 0);
    vk::DebugUtilsLabelEXT label("hang-expected", {}, &counts);
    cmd_buff_.beginDebugUtilsLabelEXT(label);

    cmd_buff_.dispatch(1, 1, 1);

    cmd_buff_.endDebugUtilsLabelEXT();

    cmd_buff_.end();

    bda.buffer.clear();
    bda.memory.clear();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    bool hang_detected = false;
    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        compute_queue_.submit(submit_info);
        compute_queue_.waitIdle();
    } catch (vk::SystemError &err) {
        hang_detected = true;
    }
    monitor_.VerifyFound();
    ASSERT_TRUE(hang_detected);

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);

    ASSERT_EQ(dump_file.devices.size(), 1);
    if (fault_ext_supported) {
        ASSERT_TRUE(dump_file.devices[0].fault_info.has_value());
        auto &dump_info = *dump_file.devices[0].fault_info;
        ASSERT_TRUE(dump_info.description == fault_info.description);
        ASSERT_EQ(dump_info.fault_address_ranges.size(), 1);
        auto &fault_range = dump_info.fault_address_ranges[0];
        // TODO ASSERT_EQ(fault_range.type, )
        ASSERT_GE(addr, fault_range.begin);
        ASSERT_LT(addr, fault_range.end);
    }
}
