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

#include "util.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

namespace crash_diagnostic_layer {

void ToUpper(std::string& s) {
	std::transform(std::begin(s), std::end(s), std::begin(s), ::toupper);
}

std::string Uint8ToStr(uint8_t value) {
    std::stringstream ss;
    // cast to uint32_t to avoid 'char' output
    ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<uint32_t>(value);
    std::string s = ss.str();
    ToUpper(s);
    s = "0x" + s;
    return s;
}

std::string Uint32ToStr(uint32_t value) {
    std::stringstream ss;
    ss << std::setw(8) << std::setfill('0') << std::hex << value;
    std::string s = ss.str();
    ToUpper(s);
    s = "0x" + s;
    return s;
}

std::string Uint64ToStr(uint64_t value) {
    std::stringstream ss;
    ss << std::setw(16) << std::setfill('0') << std::hex << value;
    std::string s = ss.str();
    ToUpper(s);
    s = "0x" + s;
    return s;
}

// specialization for non-dispatchable handles in 32 bit builds
std::string PtrToStr(uint64_t value) { return Uint64ToStr(value); }

std::string DurationToStr(std::chrono::system_clock::duration elapsed) {
    using namespace std::chrono;
    using namespace std::literals::chrono_literals;

    auto h = duration_cast<hours>(elapsed);
    elapsed -= h;
    auto m = duration_cast<minutes>(elapsed);
    elapsed -= m;
    auto s = duration_cast<seconds>(elapsed);
    elapsed -= s;
    auto ms = duration_cast<milliseconds>(elapsed);

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << (h / 1h) << ":" << std::setw(2) << (m / 1min) << ":" << std::setw(2)
       << (s / 1s) << "." << std::setw(3) << (ms / 1ms);
    return ss.str();
}

std::string Merge(const std::vector<std::string>& value, const std::string& delimiter) {
    std::string result;

    for (std::size_t i = 0, n = value.size(); i < n; ++i) {
        result += value[i];
        if (i < n - 1) {
            result += delimiter;
        }
    }

    return result;
}

std::string ToString(const Timepoint& timespoint) {
    static const char* kLogTimeTag = "%Y-%m-%d-%H%M%S";

    const std::time_t in_time_t = std::chrono::system_clock::to_time_t(timespoint);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), kLogTimeTag);
    std::string start_time_str(ss.str());

    return start_time_str;
}

}  // namespace crash_diagnostic_layer

