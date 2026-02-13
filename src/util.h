/*
 Copyright 2018 Google Inc.
 Copyright 2023-2026 LunarG, Inc.

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

#include <chrono>
#include <cstdint>
#include <string>
#include <vector>

namespace crash_diagnostic_layer {

void ToUpper(std::string& s);

std::string Uint8ToStr(uint8_t value);
std::string Uint32ToStr(uint32_t value);
std::string Uint64ToStr(uint64_t value);

template <typename T>
std::string PtrToStr(const T* ptr) {
    uintptr_t value = (uintptr_t)ptr;
    return Uint64ToStr(value);
}

// specialization for non-dispatchable handles in 32 bit builds
std::string PtrToStr(uint64_t value);

std::string DurationToStr(std::chrono::system_clock::duration elapsed);

std::string Merge(const std::vector<std::string>& value, const std::string& delimiter);

using Timepoint = std::chrono::time_point<std::chrono::system_clock>;

std::string ToString(const Timepoint& timespoint);

}  // namespace crash_diagnostic_layer
