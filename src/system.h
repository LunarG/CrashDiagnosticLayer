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

#pragma once

#include <string>
#include <map>

namespace crash_diagnostic_layer {

class Context;

class System {
   public:
    static int GetTid();
    static int GetPid();
    static std::string GetOutputBasePath();

    System(Context& context);

    const std::string& GetOsName() { return os_name_; }
    const std::string& GetOsVersion() { return os_version_; }
    const std::string& GetOsBitdepth() { return os_bitdepth_; }
    const std::map<std::string, std::string>& GetOsAdditionalInfo() { return os_additional_info_; }
    const std::string& GetHwCpuName() { return cpu_name_; }
    const std::string& GetHwNumCpus() { return number_cpus_; }
    const std::string& GetHwTotalRam() { return total_ram_; }
    const std::string& GetHwTotalDiskSpace() { return total_disk_space_; }
    const std::string& GetHwAvailDiskSpace() { return avail_disk_space_; }

   private:
    bool QueryInfoPosix();
    bool QueryInfoWindows();
    void QueryFilesystem();

    std::string os_name_;
    std::string os_version_;
    std::string os_bitdepth_;
    std::map<std::string, std::string> os_additional_info_;
    std::string cpu_name_;
    std::string number_cpus_;
    std::string total_ram_;
    std::string total_disk_space_;
    std::string avail_disk_space_;
};

}  // namespace crash_diagnostic_layer
