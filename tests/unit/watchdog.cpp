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
#include <thread>

class Watchdog : public CDLTestBase {};

constexpr uint64_t kWatchdogTimeout = 3000;
TEST_F(Watchdog, NoTimeout) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    for (uint32_t i = 0; i < 10; i++) {
        vk::CommandBufferBeginInfo begin_info;
        cmd_buff_.begin(begin_info);
        cmd_buff_.end();

        vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

        queue_.submit(submit_info);
        queue_.waitIdle();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

TEST_F(Watchdog, Timeout) {
    layer_settings_.watchdog_timeout_ms = kWatchdogTimeout;
    InitInstance();
    InitDevice();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    monitor_.SetDesiredError("Device error encountered and log being recorded");
    queue_.submit(submit_info);
    std::this_thread::sleep_for(std::chrono::milliseconds(kWatchdogTimeout * 2));
    monitor_.VerifyFound();

    queue_.waitIdle();
}
