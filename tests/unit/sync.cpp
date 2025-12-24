/*
 * Copyright (c) 2025 The Khronos Group Inc.
 * Copyright (c) 2025 Valve Corporation
 * Copyright (c) 2025 LunarG, Inc.
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

#include <vulkan/vulkan_raii.hpp>

#include <thread>

class Sync : public CDLTestBase {};

static constexpr uint64_t kWaitTimeout{10000000000};  // 10 seconds in ns
static constexpr uint64_t kWatchdogTimeout{7000};

TEST_F(Sync, HostWaitWrongSem) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kReadWriteComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore host_signalled(device_, sem_ci);
    SetObjectName(device_, host_signalled, "host_signalled");
    vk::raii::Semaphore never_signalled(device_, sem_ci);
    SetObjectName(device_, never_signalled, "never_signalled");

    uint64_t gpu_wait_value = 123;
    vk::PipelineStageFlags wait_mask = vk::PipelineStageFlagBits::eBottomOfPipe;
    vk::TimelineSemaphoreSubmitInfo timeline_info(1, &gpu_wait_value);
    vk::SubmitInfo submit_info(*host_signalled, wait_mask, *cmd_buff_, {}, &timeline_info);

    queue_.submit(submit_info);

    vk::SemaphoreSignalInfo signal_info(*host_signalled, gpu_wait_value);
    device_.signalSemaphore(signal_info);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        // wait on the wrong semaphore
        vk::SemaphoreWaitInfo wait_info({}, *never_signalled, gpu_wait_value);
        // could be success or timeout
        (void)device_.waitSemaphores(wait_info, kWaitTimeout);
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(Sync, GpuWaitWrongSem) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kReadWriteComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore gpu_signalled(device_, sem_ci);
    SetObjectName(device_, gpu_signalled, "gpu_signalled");
    vk::raii::Semaphore never_signalled(device_, sem_ci);
    SetObjectName(device_, never_signalled, "never_signalled");

    uint64_t gpu_wait_value = 123;
    vk::PipelineStageFlags wait_mask = vk::PipelineStageFlagBits::eBottomOfPipe;
    vk::TimelineSemaphoreSubmitInfo signal_timeline_info(0, nullptr, 1, &gpu_wait_value);
    vk::SubmitInfo signal_submit({}, {}, {}, *gpu_signalled, &signal_timeline_info);

    queue_.submit(signal_submit);

    vk::TimelineSemaphoreSubmitInfo wait_timeline_info(1, &gpu_wait_value);
    vk::SubmitInfo wait_submit(*never_signalled, wait_mask, {}, {}, &wait_timeline_info);

    queue_.submit(wait_submit);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        queue_.waitIdle();
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(Sync, GpuWaitBinaryPositive) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kReadWriteComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    vk::SemaphoreCreateInfo sem_ci;

    vk::raii::Semaphore binary_sem(device_, sem_ci);
    SetObjectName(device_, binary_sem, "binary_semaphore");

    vk::PipelineStageFlags wait_mask = vk::PipelineStageFlagBits::eBottomOfPipe;
    vk::Semaphore sem_handle;
    // NOTE: MSVC win32 doesn't won't compile this with the 'advanced' constructor
    vk::SubmitInfo signal_submit(0, nullptr, nullptr, 0, nullptr, 1, &(*binary_sem), nullptr);
    queue_.submit(signal_submit);

    vk::SubmitInfo wait_submit(*binary_sem, wait_mask, *cmd_buff_, {}, nullptr);

    queue_.submit(wait_submit);

    queue_.waitIdle();
}

TEST_F(Sync, GpuWaitTimelinePositive) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kReadWriteComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    std::array<vk::CommandBuffer, 2> cbs = {*cmd_buff_, *cmd_buff_};

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore tl_sem(device_, sem_ci);
    SetObjectName(device_, tl_sem, "tl_sem");

    uint64_t sem_value = 123;
    vk::TimelineSemaphoreSubmitInfo signal_tl_info(0, nullptr, 1, &sem_value);
    vk::PipelineStageFlags wait_mask = vk::PipelineStageFlagBits::eBottomOfPipe;
    vk::SubmitInfo signal_submit({}, {}, {}, *tl_sem, &signal_tl_info);

    queue_.submit(signal_submit);

    vk::TimelineSemaphoreSubmitInfo wait_tl_info(1, &sem_value);
    vk::SubmitInfo wait_submit(*tl_sem, wait_mask, cbs, {}, &wait_tl_info);

    queue_.submit(wait_submit);

    queue_.waitIdle();
}

TEST_F(Sync, TimelineCounterPositive) {
    // test for https://github.com/LunarG/CrashDiagnosticLayer/issues/173
    using namespace std::chrono_literals;

    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    ComputeIOTest state(physical_device_, device_, kReadWriteComp);
    state.input.Set(uint32_t(65535), ComputeIOTest::kNumElems);
    state.output.Set(0.0f, ComputeIOTest::kNumElems);

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.bindPipeline(vk::PipelineBindPoint::eCompute, state.pipeline.Pipeline());
    cmd_buff_.bindDescriptorSets(vk::PipelineBindPoint::eCompute, state.pipeline.PipelineLayout(), 0,
                                 state.pipeline.DescriptorSet().Set(), {});
    cmd_buff_.dispatch(1, 1, 1);
    cmd_buff_.end();

    std::array<vk::CommandBuffer, 2> cbs = {*cmd_buff_, *cmd_buff_};

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore tl_sem(device_, sem_ci);
    SetObjectName(device_, tl_sem, "tl_sem");

    uint64_t sem_value = 123;
    vk::TimelineSemaphoreSubmitInfo signal_tl_info(0, nullptr, 1, &sem_value);
    vk::SubmitInfo signal_submit({}, {}, cbs, *tl_sem, &signal_tl_info);

    queue_.submit(signal_submit);

    while (tl_sem.getCounterValue() < sem_value) {
        std::this_thread::sleep_for(1ms);
    }
    cmd_buff_.reset();

    queue_.waitIdle();
}

TEST_F(Sync, HostWaitHang) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
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

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore host_signalled(device_, sem_ci);
    SetObjectName(device_, host_signalled, "host_signalled");
    vk::raii::Semaphore gpu_signalled(device_, sem_ci);
    SetObjectName(device_, gpu_signalled, "gpu_signalled");

    uint64_t gpu_wait_value = 123;
    uint64_t gpu_signal_value = 456;
    vk::PipelineStageFlags wait_mask = vk::PipelineStageFlagBits::eBottomOfPipe;
    vk::TimelineSemaphoreSubmitInfo timeline_info(1, &gpu_wait_value, 1, &gpu_signal_value);
    vk::SubmitInfo submit_info(*host_signalled, wait_mask, *cmd_buff_, *gpu_signalled, &timeline_info);

    queue_.submit(submit_info);

    vk::SemaphoreSignalInfo signal_info(*host_signalled, gpu_wait_value);
    device_.signalSemaphore(signal_info);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        // wait on the wrong semaphore
        vk::SemaphoreWaitInfo wait_info({}, *gpu_signalled, gpu_signal_value);
        (void)device_.waitSemaphores(wait_info, kWaitTimeout);
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(Sync, HostWaitHangSubmit2) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
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

    vk::SemaphoreTypeCreateInfo sem_type_ci(vk::SemaphoreType::eTimeline, 100);
    vk::SemaphoreCreateInfo sem_ci({}, &sem_type_ci);

    vk::raii::Semaphore host_signalled(device_, sem_ci);
    SetObjectName(device_, host_signalled, "host_signalled");
    vk::raii::Semaphore gpu_signalled(device_, sem_ci);
    SetObjectName(device_, gpu_signalled, "gpu_signalled");

    uint64_t gpu_wait_value = 123;
    uint64_t gpu_signal_value = 456;
    vk::SemaphoreSubmitInfo wait_sem(*host_signalled, gpu_wait_value, vk::PipelineStageFlagBits2::eBottomOfPipe);
    vk::SemaphoreSubmitInfo signal_sem(*gpu_signalled, gpu_signal_value, vk::PipelineStageFlagBits2::eBottomOfPipe);
    vk::CommandBufferSubmitInfo cb_info(*cmd_buff_);
    vk::SubmitInfo2 submit_info({}, wait_sem, cb_info, signal_sem);

    queue_.submit2(submit_info);

    vk::SemaphoreSignalInfo signal_info(*host_signalled, gpu_wait_value);
    device_.signalSemaphore(signal_info);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        // wait on the wrong semaphore
        vk::SemaphoreWaitInfo wait_info({}, *gpu_signalled, gpu_signal_value);
        // could be success or timeout
        (void)device_.waitSemaphores(wait_info, kWaitTimeout);
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

// TODO: Never finishes in Internal CI on 64,Debug,Windows11-rolling
TEST_F(Sync, DISABLED_FenceWaitHang) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
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

    vk::raii::Fence fence(device_, vk::FenceCreateInfo());

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_);

    queue_.submit(submit_info, *fence);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        // could be success or timeout
        (void)device_.waitForFences(*fence, vk::True, kWaitTimeout);
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}

TEST_F(Sync, DeviceWaitHang) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
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

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_);

    queue_.submit(submit_info);

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    try {
        // could be success or timeout
        (void)device_.waitIdle();
    } catch (vk::SystemError &) {
    }
    monitor_.VerifyFound();

    dump::File dump_file;
    dump::Parse(dump_file, output_path_);
}
