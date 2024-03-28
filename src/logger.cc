/*
 Copyright 2023-2024 LunarG, Inc.

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

#ifdef ANDROID
#include <android/log.h>
#endif  // ANDROID

namespace crash_diagnostic_layer {

Logger::Logger() {}

Logger::~Logger() { CloseLogFile(); }

bool Logger::OpenLogFile(const std::filesystem::path& filename) {
    if (log_file_ != nullptr) {
        CloseLogFile();
    }
    log_file_ = fopen(filename.string().c_str(), "wt");
    if (log_file_ != nullptr) {
        log_file_name_ = filename.string();
        return true;
    } else {
        perror(filename.string().c_str());
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

void Logger::LogError(const char* format, ...) {
    if (log_level_ <= LOG_LEVEL_ERROR) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
        va_list argptr;
#ifdef ANDROID
        va_start(argptr, format);
        __android_log_vprint(ANDROID_LOG_ERROR, "CDL", format, argptr);
        va_end(argptr);
#else   // !ANDROID
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
#endif  // !ANDROID
    }
}

void Logger::LogError(const std::string& message) {
    if (log_level_ <= LOG_LEVEL_ERROR) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
#ifdef ANDROID
        __android_log_print(ANDROID_LOG_ERROR, "CDL", "%s", message.c_str());
#else  // !ANDROID
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_ERROR: %s\n", message.c_str());
        }
        fprintf(stderr, "CDL_ERROR: %s\n", message.c_str());
#endif
    }
}

void Logger::LogWarning(const char* format, ...) {
    if (log_level_ <= LOG_LEVEL_WARNING) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
        va_list argptr;
#ifdef ANDROID
        va_start(argptr, format);
        __android_log_vprint(ANDROID_LOG_WARN, "CDL", format, argptr);
        va_end(argptr);
#else  // !ANDROID
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
#endif
    }
}

void Logger::LogWarning(const std::string& message) {
    if (log_level_ <= LOG_LEVEL_WARNING) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
#ifdef ANDROID
        __android_log_print(ANDROID_LOG_WARN, "CDL", "%s", message.c_str());
#else  // !ANDROID
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_WARNING: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_WARNING: %s\n", message.c_str());
#endif
    }
}

void Logger::LogInfo(const char* format, ...) {
    if (log_level_ <= LOG_LEVEL_INFO) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
        va_list argptr;
#ifdef ANDROID
        va_start(argptr, format);
        __android_log_vprint(ANDROID_LOG_INFO, "CDL", format, argptr);
        va_end(argptr);
#else  // !ANDROID
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
#endif
    }
}

void Logger::LogInfo(const std::string& message) {
    if (log_level_ <= LOG_LEVEL_INFO) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
#ifdef ANDROID
        __android_log_print(ANDROID_LOG_INFO, "CDL", "%s", message.c_str());
#else  // !ANDROID
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_INFO: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_INFO: %s\n", message.c_str());
#endif
    }
}

void Logger::LogDebug(const char* format, ...) {
    if (log_level_ <= LOG_LEVEL_DEBUG) {
        std::lock_guard<std::mutex> lock(file_access_mutex_);
        va_list argptr;
#ifdef ANDROID
        va_start(argptr, format);
        __android_log_vprint(ANDROID_LOG_DEBUG, "CDL", format, argptr);
        va_end(argptr);
#else  // !ANDROID
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
#endif
    }
}

void Logger::LogDebug(const std::string& message) {
    if (log_level_ <= LOG_LEVEL_DEBUG) {
        std::lock_guard<std::mutex> guard(file_access_mutex_);
#ifdef ANDROID
        __android_log_print(ANDROID_LOG_DEBUG, "CDL", "%s", message.c_str());
#else  // !ANDROID
        if (log_file_ != nullptr) {
            fprintf(log_file_, "CDL_DEBUG: %s\n", message.c_str());
        }
        fprintf(stdout, "CDL_DEBUG: %s\n", message.c_str());
#endif
    }
}

}  // namespace crash_diagnostic_layer
