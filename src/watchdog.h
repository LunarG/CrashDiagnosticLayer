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

#pragma once
#include <atomic>
#include <condition_variable>
#include <mutex>
#include <thread>

namespace crash_diagnostic_layer {

struct Settings;
class Device;

class Watchdog {
   public:
    Watchdog(Device &, const Settings &);
    ~Watchdog() { Stop(); }

    void Start();
    void Stop();
    void Update();

   private:
    void ThreadFunc();

    Device &device_;
    std::thread thread_;
    std::mutex lock_;
    std::condition_variable running_cv_;
    bool running_{false};
    std::atomic<long long> last_submit_time_{0};
    uint64_t timer_ms_{0};
};

}  // namespace crash_diagnostic_layer
