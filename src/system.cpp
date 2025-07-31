/*
 Copyright (c) 2023-2025 LunarG, Inc.

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

#include <algorithm>
#include <cassert>
#include <cstring>
#include <stdint.h>
#include <sstream>
#include <stdlib.h>

#if defined(VK_USE_PLATFORM_WIN32_KHR)
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/statvfs.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <dlfcn.h>
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <sys/system_properties.h>
#endif

#include "cdl.h"
#include "system.h"

namespace crash_diagnostic_layer {

int System::GetTid() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    return static_cast<int>(GetCurrentThreadId());
#else
    return static_cast<int>(gettid());
#endif
}

int System::GetPid() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    return static_cast<int>(_getpid());
#else
    return static_cast<int>(getpid());
#endif
}

std::string System::GetOutputBasePath() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    return getenv("USERPROFILE");
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
    std::ifstream cmdline("/proc/self/cmdline");
    std::string app_name;
    cmdline >> app_name;
    app_name.erase(std::find(app_name.begin(), app_name.end(), '\0'), app_name.end());
    std::string result = "/sdcard/data/Android/";
    result += app_name;
    return result;
#else
    return getenv("HOME");
#endif
}

System::System(Context& context) {
    [[maybe_unused]] bool success;
    QueryFilesystem();
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    success = QueryInfoWindows();
#else
    success = QueryInfoPosix();
#endif
    assert(success);
}

#if !defined(VK_USE_PLATFORM_WIN32_KHR) && !defined(VK_USE_PLATFORM_ANDROID_KHR)
static void TrimWhitespaceAndQuotes(std::string& input) {
    const char* items = "'\" \t\n\r\f\v";
    input.erase(input.find_last_not_of(items) + 1);
    input.erase(0, input.find_first_not_of(items));
}
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
std::string GetProperty(const char* prop) {
    std::string result;
    const prop_info* info = __system_property_find(prop);
    if (info) {
        auto callback = [](void* cookie, const char* name, const char* value, uint32_t serial) {
            std::string* r = reinterpret_cast<std::string*>(cookie);
            *r = value;
        };
        __system_property_read_callback(info, callback, &result);
    }
    return result;
}
#endif

bool System::QueryInfoPosix() {
#if !defined(VK_USE_PLATFORM_WIN32_KHR)
    // Get kernel and os info
    errno = 0;
    utsname uts_buffer;
    if (uname(&uts_buffer) == 0) {
        os_name_ = uts_buffer.sysname;
        os_version_ = uts_buffer.version;
        os_bitdepth_ = uts_buffer.machine;
        os_additional_info_["kernel"] = uts_buffer.release;
    }
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    {
        os_name_ = "Android";
        os_version_ = GetProperty("ro.product.build.version.release");
        if (os_version_.empty()) {
            os_version_ = GetProperty("ro.build.version.release");
            if (os_version_.empty()) {
                os_version_ = GetProperty("ro.vendor.build.version.release");
            }
        }

        std::string sdk_version = GetProperty("ro.product.build.version.sdk");
        if (!sdk_version.empty()) {
            os_additional_info_["sdk"] = sdk_version;
        }

        std::string manufacturer = GetProperty("ro.product.manufacturer");
        if (!manufacturer.empty()) {
            os_additional_info_["manufacturer"] = manufacturer;
        }
        std::string model = GetProperty("ro.product.model");
        if (!model.empty()) {
            os_additional_info_["model"] = model;
        }
        std::string build_id = GetProperty("ro.product.build.id");
        if (!build_id.empty()) {
            os_additional_info_["buildId"] = build_id;
        }
    }
#else
    {
        std::ifstream os_release("/etc/os-release");
        std::string line;
        while (std::getline(os_release, line)) {
            if (line.find("NAME=") == 0) {
                size_t equal_loc = line.find("=");
                line.erase(0, equal_loc + 1);
                TrimWhitespaceAndQuotes(line);
                os_name_ = line;
            }
            if (line.find("VERSION_ID=") == 0) {
                size_t equal_loc = line.find("=");
                line.erase(0, equal_loc + 1);
                TrimWhitespaceAndQuotes(line);
                os_version_ = line;
            }
        }
    }
    char* env_value = getenv("XDG_CURRENT_DESKTOP");
    if (env_value != nullptr) {
        os_additional_info_["currentDesktop"] = env_value;
    }
    env_value = getenv("XDG_SESSION_TYPE");
    if (env_value != nullptr) {
        os_additional_info_["sessionType"] = env_value;
    }
    {
        std::ifstream cpu_info("/proc/cpuinfo");
        std::string line;
        while (std::getline(cpu_info, line)) {
            if (line.find("model name") == 0) {
                size_t colon_loc = line.find(":");
                line.erase(0, colon_loc + 1);
                TrimWhitespaceAndQuotes(line);
                cpu_name_ = line;
                break;
            }
        }
    }
#endif  // !defined(VK_USE_PLATFORM_ANDROID_KHR)
    // Number of CPUs
    auto num_cpus = sysconf(_SC_NPROCESSORS_ONLN);
    if (num_cpus > 0) {
        number_cpus_ = std::to_string(num_cpus);
    }

    // Get amount of RAM in the system
    auto memory =
        (static_cast<uint64_t>(sysconf(_SC_PHYS_PAGES)) * static_cast<uint64_t>(sysconf(_SC_PAGE_SIZE))) >> 10u;
    if ((memory >> 30) > 0) {
        total_ram_ = std::to_string(memory >> 30u) + " TB";
    } else if ((memory >> 20) > 0) {
        total_ram_ = std::to_string(memory >> 20u) + " GB";
    } else if ((memory >> 10) > 0) {
        total_ram_ = std::to_string(memory >> 10u) + " MB";
    } else {
        total_ram_ = std::to_string(memory) + " KB";
    }

    if (os_name_.size() > 0 && os_version_.size() > 0 && number_cpus_.size() > 0 && total_ram_.size() > 0) {
        return true;
    }
#endif  // !defined(VK_USE_PLATFORM_WIN32_KHR)
    return false;
}

#if defined(VK_USE_PLATFORM_WIN32_KHR)
static bool CheckIfGreaterThanEqualVersion(uint32_t major, uint32_t minor) {
    OSVERSIONINFOEX ms_version_info{};
    DWORDLONG condition_mask = 0;
    BYTE compare_op = VER_GREATER_EQUAL;

    // We only care about the major/minor version
    VER_SET_CONDITION(condition_mask, VER_MAJORVERSION, compare_op);
    VER_SET_CONDITION(condition_mask, VER_MINORVERSION, compare_op);

    ms_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    ms_version_info.dwMajorVersion = major;
    ms_version_info.dwMinorVersion = minor;

    if (TRUE == VerifyVersionInfo(&ms_version_info, VER_MAJORVERSION | VER_MINORVERSION, condition_mask)) {
        return true;
    }
    return false;
}

static bool CheckIsServer(const uint32_t major, const uint32_t minor) {
    OSVERSIONINFOEX ms_version_info{};
    DWORDLONG condition_mask = 0;
    BYTE compare_op = VER_EQUAL;

    // We only care about the major/minor version
    VER_SET_CONDITION(condition_mask, VER_MAJORVERSION, compare_op);
    VER_SET_CONDITION(condition_mask, VER_MINORVERSION, compare_op);
    VER_SET_CONDITION(condition_mask, VER_PRODUCT_TYPE, compare_op);

    // First check to see if this is XP or later
    ms_version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    ms_version_info.dwMajorVersion = major;
    ms_version_info.dwMinorVersion = minor;
    ms_version_info.wProductType = VER_NT_SERVER;

    if (TRUE ==
        VerifyVersionInfo(&ms_version_info, VER_MAJORVERSION | VER_MINORVERSION | VER_PRODUCT_TYPE, condition_mask)) {
        return true;
    }
    return false;
}

static bool GetWindowsVersion(uint32_t& major, uint32_t& minor, bool& is_server) {
    uint32_t check_major = major;
    uint32_t check_minor = minor;
    while (CheckIfGreaterThanEqualVersion(check_major, check_minor)) {
        check_major++;
    }
    check_major--;
    while (CheckIfGreaterThanEqualVersion(check_major, check_minor)) {
        check_minor++;
    }
    major = check_major;
    minor = check_minor--;
    is_server = CheckIsServer(check_major, check_minor);
    return true;
}

static bool ReadRegKeyString(bool is_wow64, HKEY regFolder, const char* keyPath, const char* valueName,
                             const int maxLength, char* retString) {
    bool retVal = false;
    DWORD bufLen = maxLength;
    DWORD keyFlags = KEY_READ;
    HKEY hKey;
    LONG lret;

    if (is_wow64) {
        keyFlags |= KEY_WOW64_64KEY;
    }

    *retString = '\0';
    lret = RegOpenKeyExA(regFolder, keyPath, 0, keyFlags, &hKey);
    if (lret == ERROR_SUCCESS) {
        lret = RegQueryValueExA(hKey, valueName, NULL, NULL, (BYTE*)retString, &bufLen);
        if (lret == ERROR_SUCCESS) {
            retVal = true;
        }
        RegCloseKey(hKey);
    }

    return retVal;
}
#endif

bool System::QueryInfoWindows() {
#if defined(VK_USE_PLATFORM_WIN32_KHR)

    // Determine if this is a 32-bit executable running on 64-bit Windows
    bool is_wow64 = false;
    // IsWow64Process is not available on all supported versions of Windows.
    // Use GetModuleHandle to get a handle to the DLL that contains the function
    // and GetProcAddress to get a pointer to the function if available.
    typedef BOOL(WINAPI * LPFN_ISWOW64PROCESS)(HANDLE, PBOOL);
    LPFN_ISWOW64PROCESS fpIsWow64Process =
        (LPFN_ISWOW64PROCESS)GetProcAddress(GetModuleHandle(TEXT("kernel32")), "IsWow64Process");
    if (nullptr != fpIsWow64Process) {
        BOOL is_wow_64_process = FALSE;
        if (fpIsWow64Process(GetCurrentProcess(), &is_wow_64_process)) {
            is_wow64 = (is_wow_64_process == TRUE);
        }
    }

    const uint32_t max_len = 2048;
    char* temp_string = new char[max_len];
    if (temp_string == nullptr) {
        return false;
    }

#if _WIN64
    os_bitdepth_ = "64-bit";
#else
    // If WOW64 support is present, then it's a 64-bit Windows
    if (is_wow64) {
        os_bitdepth_ = "64-bit";
    } else {
        os_bitdepth_ = "32-bit";
    }
#endif

    uint32_t major = 5;
    uint32_t minor = 0;
    bool is_server = false;
    GetWindowsVersion(major, minor, is_server);
    if (major >= 10) {
        if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows NT\\CurrentVersion",
                             "ProductName", max_len - 1, temp_string)) {
            os_name_ = temp_string;
            if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows NT\\CurrentVersion",
                                 "CurrentBuild", max_len - 1, temp_string)) {
                os_version_ = temp_string;
            }
            if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows NT\\CurrentVersion",
                                 "BuildBranch", max_len - 1, temp_string)) {
                os_additional_info_["build"] = temp_string;
            }
        } else {
            if (is_server) {
                os_name_ = "Windows Server 2016 (or newer)";
            } else {
                os_name_ = "Windows 10 (or newer)";
            }
        }
    } else if (major >= 6) {
        bool found = false;
        switch (minor) {
            case 3:
            case 2:
                if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows NT\\CurrentVersion",
                                     "ProductName", max_len - 1, temp_string)) {
                    os_name_ = temp_string;
                    if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE,
                                         "Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuild", max_len - 1,
                                         temp_string)) {
                        os_version_ = temp_string;
                    }
                    if (ReadRegKeyString(is_wow64, HKEY_LOCAL_MACHINE,
                                         "Software\\Microsoft\\Windows NT\\CurrentVersion", "BuildBranch", max_len - 1,
                                         temp_string)) {
                        os_additional_info_["build"] = temp_string;
                    }
                    found = true;
                }
                break;
            default:
                break;
        }
        if (!found) {
            if (is_server) {
                os_name_ = "Windows Server 2008 (or newer)";
            } else {
                os_name_ = "Windows 7 (or newer)";
            }
        }
    } else {
        if (is_server) {
            os_name_ = "Windows Server 2003 (or newer)";
        } else {
            os_name_ = "Windows XP (or newer)";
        }
    }

    SYSTEM_INFO system_info;
    ZeroMemory(&system_info, sizeof(SYSTEM_INFO));
    GetSystemInfo(&system_info);
    number_cpus_ = std::to_string(system_info.dwNumberOfProcessors);

    switch (system_info.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:  // x64 (AMD or Intel)
            cpu_name_ = "x64";
            break;
        case PROCESSOR_ARCHITECTURE_ARM:  // ARM
            cpu_name_ = "ARM";
            break;
        case PROCESSOR_ARCHITECTURE_ARM64:  // ARM64
            cpu_name_ = "ARM64";
            break;
        case PROCESSOR_ARCHITECTURE_IA64:  // Intel Itanium-based
            cpu_name_ = "Intel Itanium";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:  // x86
            cpu_name_ = "x86";
            break;
        case PROCESSOR_ARCHITECTURE_UNKNOWN:
        default:
            cpu_name_ = "Unknown Architecture";
            break;
    }

    MEMORYSTATUSEX mem_stat;
    ZeroMemory(&mem_stat, sizeof(MEMORYSTATUSEX));
    mem_stat.dwLength = sizeof(MEMORYSTATUSEX);
    if (TRUE == GlobalMemoryStatusEx(&mem_stat)) {
        uint64_t bytes_total = (mem_stat.ullTotalPhys) >> 10;
        if ((bytes_total >> 30) > 0) {
            total_ram_ = std::to_string((uint32_t)(bytes_total >> 30)) + " TB";
        } else if ((bytes_total >> 20) > 0) {
            total_ram_ = std::to_string((uint32_t)((bytes_total) >> 20)) + " GB";
        } else if ((bytes_total >> 10) > 0) {
            total_ram_ = std::to_string((uint32_t)((bytes_total) >> 10)) + " GB";
        } else {
            total_ram_ = std::to_string((uint32_t)(bytes_total)) + " KB";
        }
    }

    delete[] temp_string;

    if (os_name_.size() > 0 && os_version_.size() > 0 && number_cpus_.size() > 0 && total_ram_.size() > 0) {
        return true;
    }
#endif  // defined(VK_USE_PLATFORM_WIN32_KHR)
    return false;
}

void System::QueryFilesystem() {
    std::filesystem::space_info space = std::filesystem::space(std::filesystem::current_path());
    uint64_t bytes_total = space.capacity >> 10;
    if ((bytes_total >> 30) > 0) {
        total_disk_space_ = std::to_string((uint32_t)(bytes_total >> 30)) + " TB";
    } else if ((bytes_total >> 20) > 0) {
        total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 20) + " GB";
    } else if ((bytes_total >> 10) > 0) {
        total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 10) + " MB";
    } else {
        total_disk_space_ = std::to_string(((uint32_t)bytes_total)) + " KB";
    }

    bytes_total = space.available >> 10;
    if ((bytes_total >> 30) > 0) {
        avail_disk_space_ = std::to_string((uint32_t)(bytes_total >> 30)) + " TB";
    } else if ((bytes_total >> 20) > 0) {
        avail_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 20) + " GB";
    } else if ((bytes_total >> 10) > 0) {
        avail_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 10) + " MB";
    } else {
        avail_disk_space_ = std::to_string(((uint32_t)bytes_total)) + " KB";
    }
}

}  // namespace crash_diagnostic_layer
