/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024-2026 Valve Corporation
 * Copyright (c) 2024-2026 LunarG, Inc.
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
#include <filesystem>
#include <regex>

class Settings : public CDLTestBase {};

TEST_F(Settings, WatchdogTimeout) {
    this->layer_settings.crash_diagnostic.watchdog_timeout_ms = 123456u;
    this->layer_settings.crash_diagnostic.message_severity = {"info"};

    monitor_.SetAllowedFailureMsg("Version");
    monitor_.SetAllowedFailureMsg("Using layer settings:");
    monitor_.SetAllowedFailureMsg(" - ");
    monitor_.SetDesiredFailureMsg(ErrorMonitor::SeverityBits::eInfo, "Begin Watchdog: 123456ms");
    InitDevice();
    monitor_.VerifyFound();
}

TEST_F(Settings, LogFilePath) {
    // The test framework writes sets the output path to ./cdl_output/<test-suite-name>/<test-name>/
    const char* kLogFileName = "cdl_log.txt";
    this->layer_settings.crash_diagnostic.log_file = kLogFileName;
    // make sure something gets logged.
    this->layer_settings.crash_diagnostic.message_severity = {"error", "warn", "info", "verbose"};
    InitInstance();
    // There should now be a log file under that directory with a timestamped directory after it.
    std::filesystem::directory_iterator output_iter(this->layer_settings.crash_diagnostic.output_path);
    std::filesystem::directory_iterator end;

    ASSERT_FALSE(output_iter == end);
    ASSERT_TRUE(output_iter->is_directory());

    auto rel = std::filesystem::relative(output_iter->path(), this->layer_settings.crash_diagnostic.output_path).string();
    // should look like yyyy-mm-dd-hhmmss
    std::regex dir_re("\\d{4}-\\d{2}-\\d{2}-\\d{6}");
    std::smatch m;
    bool result = std::regex_match(rel, m, dir_re);
    ASSERT_TRUE(result);

    // look for cdl_log.txt
    std::filesystem::directory_iterator log_iter(*output_iter);
    ASSERT_FALSE(log_iter == end);
    ASSERT_TRUE(log_iter->is_regular_file());

    ASSERT_EQ(log_iter->path().filename(), kLogFileName);

    // there should be only one file
    ++log_iter;
    ASSERT_TRUE(log_iter == end);

    // there should be only one directory at this level.
    ++output_iter;
    ASSERT_TRUE(output_iter == end);
}

TEST_F(Settings, LogFileLeadingDot) {
    // A leading '.' should create a log file relative to the current working directory
    // rather than the timestamped dump file directory
    const auto* test_info = testing::UnitTest::GetInstance()->current_test_info();
    std::filesystem::path log_file = ".";
    log_file /= kTestOutputBaseDir;
    log_file /= test_info->test_suite_name();
    log_file += '-';
    log_file += test_info->name();
    log_file += "-cdl_log.txt";

    std::string s = log_file.string();
    this->layer_settings.crash_diagnostic.log_file = s.c_str();
    // make sure something gets logged.
    this->layer_settings.crash_diagnostic.message_severity = {"error", "warn", "info", "verbose"};
    InitInstance();
    ASSERT_TRUE(std::filesystem::exists(log_file));
}
