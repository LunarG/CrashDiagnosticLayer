/*
 Copyright 2018 Google Inc.
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
#include "watchdog.h"

#include "cdl.h"
#include "device.h"

#include <algorithm>
#include <cinttypes>

namespace crash_diagnostic_layer {

Watchdog::Watchdog(Device& dev, const Settings& settings) : device_(dev), timer_ms_(settings.watchdog_timer_ms) {}

void Watchdog::Start() {
    device_.Log().Info("Begin Watchdog: %" PRId64 "ms", timer_ms_);
    // Start up the watchdog timer thread.
    running_ = true;
    Update();
    thread_ = std::thread([&]() { this->ThreadFunc(); });
}
void Watchdog::Update() {
    using namespace std::chrono;
    last_submit_time_ = duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
}

void Watchdog::Stop() {
    {
        std::lock_guard<std::mutex> guard(lock_);
        if (running_) {
            device_.Log().Info("Stopping Watchdog");
            running_ = false;
            running_cv_.notify_all();
        }
    }
    // make sure the watchdog thread is joined even if it quit on its own.
    if (thread_.joinable()) {
        thread_.join();
        device_.Log().Info("Watchdog Stopped");
    }
}

void Watchdog::ThreadFunc() {
    uint64_t test_interval_us = std::min((uint64_t)(1000 * 1000), timer_ms_ * 500);
    std::unique_lock<std::mutex> guard(lock_);
    do {
        auto status = running_cv_.wait_for(guard, std::chrono::microseconds(test_interval_us));
        if (status == std::cv_status::timeout) {
            auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
                           std::chrono::high_resolution_clock::now().time_since_epoch())
                           .count();
            auto ms = (int64_t)(now - last_submit_time_);

            if (ms > (int64_t)timer_ms_) {
                device_.Log().Info("CDL: Watchdog check failed, no submit in %" PRId64 "ms", ms);

                // Quit the thread after a hang is detected, it is unlikely that further dumps will
                // show anything more useful than the first one.
                running_ = false;
                guard.unlock();
                device_.WatchdogTimeout();
                break;
            }
        }
    } while (running_);
}

}  // namespace crash_diagnostic_layer
