/*
 Copyright (c) 2023-2024 LunarG, Inc.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#pragma once

#include <filesystem>
#include <mutex>
#include <stdio.h>
#include <string>

namespace crash_diagnostic_layer {

class Logger {
   public:
    Logger();
    Logger(Logger&) = delete;
    Logger& operator=(Logger&) = delete;
    ~Logger();

    enum LogLevel { LOG_LEVEL_ERROR = 0, LOG_LEVEL_WARNING, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG };

    void SetLogLevel(const LogLevel& level) { log_level_ = level; }

    bool OpenLogFile(const std::filesystem::path& filename);
    void CloseLogFile();

    void Error(const char* format, ...) const;
    void Error(const std::string& message) const;
    void Warning(const char* format, ...) const;
    void Warning(const std::string& message) const;
    void Info(const char* format, ...) const;
    void Info(const std::string& message) const;
    void Debug(const char* format, ...) const;
    void Debug(const std::string& message) const;

   private:
    LogLevel log_level_{LOG_LEVEL_ERROR};
    std::string log_file_name_;
    mutable FILE* log_file_{nullptr};
    mutable std::mutex file_access_mutex_;
};

}  // namespace crash_diagnostic_layer
