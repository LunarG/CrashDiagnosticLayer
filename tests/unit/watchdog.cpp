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

class GpuCrash : public CDLTestBase {};

TEST_F(Watchdog, NoTimeout) {
    InitInstance();
    InitDevice();

    vk::CommandBufferBeginInfo begin_info;
    cmd_buff_.begin(begin_info);
    cmd_buff_.end();

    vk::SubmitInfo submit_info({}, {}, *cmd_buff_, {});

    compute_queue_.submit(submit_info);
    compute_queue_.waitIdle();
}

