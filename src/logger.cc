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

#include <stdarg.h>

#include "logger.h"

namespace crash_diagnostic_layer {

Logger::Logger() {}

Logger::~Logger() { CloseLogFile(); }

bool Logger::OpenLogFile(const std::string& filename) {
    if (log_file_ != nullptr) {
        CloseLogFile();
    }
    log_file_ = fopen(filename.c_str(), "wt");
    if (log_file_ != nullptr) {
        log_file_name_ = filename;
        return true;
    }
    return false;
}

void Logger::CloseLogFile() {
    if (log_file_ != nullptr) {
        fclose(log_file_);
        log_file_ = nullptr;
    }
    log_file_name_ = "";
}

void Logger::LogError(const char* format, ...) const {
    if (log_level_ <= LOG_LEVEL_ERROR) {
        va_list argptr;
        if (log_file_ != nullptr) {
            va_start(argptr, format);
            fprintf(log_file_, "CDL_ERROR: ");
            vfprintf(log_file_, format, argptr);
            fprintf(log_file_, "\n");
            va_end(argptr);
        }
        va_start(argptr, format);
        fprintf(stderr, "CDL_ERROR: ");
        vfprintf(stderr, format, argptr);
        fprintf(stderr, "\n");
        va_end(argptr);
    }
}

void Logger::LogError(const std::string& message) const {
    if (log_level_ <= LOG_LEVEL_ERROR) {
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_ERROR: %s\n", message.c_str());
        }
        fprintf(stderr, "CDL_ERROR: %s\n", message.c_str());
    }
}

void Logger::LogWarning(const char* format, ...) const {
    if (log_level_ <= LOG_LEVEL_WARNING) {
        va_list argptr;
        if (log_file_ != nullptr) {
            va_start(argptr, format);
            fprintf(log_file_, "CDL_WARNING: ");
            vfprintf(log_file_, format, argptr);
            fprintf(log_file_, "\n");
            va_end(argptr);
        }
        va_start(argptr, format);
        fprintf(stdout, "CDL_WARNING: ");
        vfprintf(stdout, format, argptr);
        fprintf(stdout, "\n");
        va_end(argptr);
    }
}

void Logger::LogWarning(const std::string& message) const {
    if (log_level_ <= LOG_LEVEL_WARNING) {
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_WARNING: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_WARNING: %s\n", message.c_str());
    }
}

void Logger::LogInfo(const char* format, ...) const {
    if (log_level_ <= LOG_LEVEL_INFO) {
        va_list argptr;
        va_start(argptr, format);
        if (log_file_ != nullptr) {
            va_start(argptr, format);
            fprintf(log_file_, "CDL_INFO: ");
            vfprintf(log_file_, format, argptr);
            fprintf(log_file_, "\n");
            va_end(argptr);
        }
        va_start(argptr, format);
        fprintf(stdout, "CDL_INFO: ");
        vfprintf(stdout, format, argptr);
        fprintf(stdout, "\n");
        va_end(argptr);
    }
}

void Logger::LogInfo(const std::string& message) const {
    if (log_level_ <= LOG_LEVEL_INFO) {
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_INFO: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_INFO: %s\n", message.c_str());
    }
}

void Logger::LogDebug(const char* format, ...) const {
    if (log_level_ <= LOG_LEVEL_DEBUG) {
        va_list argptr;
        va_start(argptr, format);
        if (log_file_ != nullptr) {
            va_start(argptr, format);
            fprintf(log_file_, "CDL_DEBUG: ");
            vfprintf(log_file_, format, argptr);
            fprintf(log_file_, "\n");
            va_end(argptr);
        }
        va_start(argptr, format);
        fprintf(stdout, "CDL_DEBUG: ");
        vfprintf(stdout, format, argptr);
        fprintf(stdout, "\n");
        va_end(argptr);
    }
}

void Logger::LogDebug(const std::string& message) const {
    if (log_level_ <= LOG_LEVEL_DEBUG) {
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_DEBUG: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_DEBUG: %s\n", message.c_str());
    }
}

}  // namespace crash_diagnostic_layer
