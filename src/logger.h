/*
 Copyright (c) 2023 Valve Corporation
 Copyright (c) 2023 LunarG, Inc.

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

#include <mutex>
#include <stdio.h>
#include <string>

namespace crash_diagnostic_layer {

class Logger {
   public:
    Logger();
    ~Logger();

    enum LogLevel { LOG_LEVEL_ERROR = 0, LOG_LEVEL_WARNING, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG };

    void SetLogLevel(const LogLevel& level) { log_level_ = level; }

    bool OpenLogFile(const std::string& filename);
    void CloseLogFile();

    void LogError(const char* format, ...);
    void LogError(const std::string& message);
    void LogWarning(const char* format, ...);
    void LogWarning(const std::string& message);
    void LogInfo(const char* format, ...);
    void LogInfo(const std::string& message);
    void LogDebug(const char* format, ...);
    void LogDebug(const std::string& message);

   private:
    LogLevel log_level_{LOG_LEVEL_ERROR};
    std::string log_file_name_;
    FILE* log_file_{nullptr};
    std::mutex file_access_mutex_;
};

}  // namespace crash_diagnostic_layer
