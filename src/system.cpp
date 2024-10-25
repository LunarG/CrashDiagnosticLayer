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

#include <algorithm>
#include <cassert>
#include <cstring>
#include <stdint.h>
#include <sstream>
#include <stdlib.h>

#if defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) || defined(SYSTEM_TARGET_BSD)
#include <sys/types.h>
#include <sys/statvfs.h>
#ifdef SYSTEM_TARGET_BSD
#include <sys/sysctl.h>
#endif
#include <sys/utsname.h>
#include <dirent.h>
#include <unistd.h>
#include <dlfcn.h>
#elif defined(SYSTEM_TARGET_WINDOWS)
#include <windows.h>
#include <stdio.h>

#elif defined(SYSTEM_TARGET_ANDROID)
#else
#error "Unsupported operating system"
#endif

#include "cdl.h"
#include "system.h"

namespace crash_diagnostic_layer {

System::System(Context& context) {
    [[maybe_unused]] bool success;
#ifdef SYSTEM_TARGET_ANDROID
    success = QueryInfoAndroid();
#elif defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) || defined(SYSTEM_TARGET_BSD)
    success = QueryInfoPosix();
#elif defined(SYSTEM_TARGET_WINDOWS)
    success = QueryInfoWindows();
#endif
    assert(success);
}

#ifdef SYSTEM_TARGET_LINUX
const char* white_space_items = " \t\n\r\f\v";
static void TrimSurroundingWhitespace(std::string& input) {
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
}

const char* quote_items = "'\"";
static void TrimSurroundingQuotes(std::string& input) {
    input.erase(input.find_last_not_of(quote_items) + 1);
    input.erase(0, input.find_first_not_of(quote_items));
}

static void TrimWhitespaceAndQuotes(std::string& input) {
    TrimSurroundingWhitespace(input);
    TrimSurroundingQuotes(input);
}
#endif

bool System::QueryInfoAndroid() {
#ifdef SYSTEM_TARGET_ANDROID
    // TODO:
#endif  // SYSTEM_TARGET_ANDROID
    return false;
}  // QueryInfoAndroid

bool System::QueryInfoPosix() {
#if defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) || defined(SYSTEM_TARGET_BSD)
    FILE* fp = nullptr;
    const uint32_t max_len = 2048;
    char* temp_string = new char[max_len];
    if (temp_string == nullptr) {
        return false;
    }

#ifdef SYSTEM_TARGET_LINUX
    // Get distro
    fp = popen("cat /etc/os-release", "r");
    if (nullptr != fp) {
        // Read the output a line at a time - output it.
        while (nullptr != fgets(temp_string, max_len - 1, fp)) {
            if (nullptr != strstr(temp_string, "PRETTY_NAME")) {
                char* equal_loc = strstr(temp_string, "=");
                os_name_ = equal_loc + 1;
                TrimWhitespaceAndQuotes(os_name_);
            }
        }
        pclose(fp);
    }
#elif defined(SYSTEM_TARGET_BSD)
    os_name_ = "BSD";
#elif defined(SYSTEM_TARGET_APPLE)
    // Get Version
    fp = popen("sw_vers", "r");
    if (nullptr != fp) {
        // Read the output a line at a time - output it.
        while (nullptr != fgets(temp_string, max_len - 1, fp)) {
            if (nullptr != strstr(temp_string, "ProductName")) {
                char* colon_loc = strstr(temp_string, ":");
                os_name_ = colon_loc + 1;
                TrimWhitespaceAndQuotes(os_name_);
            } else if (NULL != strstr(temp_string, "ProductVersion")) {
                char* colon_loc = strstr(temp_string, ":");
                os_version_ = colon_loc + 1;
                TrimWhitespaceAndQuotes(os_version_);
            } else if (NULL != strstr(temp_string, "BuildVersion")) {
                char* colon_loc = strstr(temp_string, ":");
                std::string build_version = colon_loc + 1;
                TrimWhitespaceAndQuotes(build_version);
                os_additional_info_ = "Build Version [";
                os_additional_info_ += build_version;
                os_additional_info_ += "]";
            }
        }
        pclose(fp);
    }
#endif

#if defined(SYSTEM_TARGET_LINUX) || defined(SYSTEM_TARGET_BSD)
    // Get kernel and os info
    errno = 0;
    utsname uts_buffer;
    if (uname(&uts_buffer) == 0) {
        os_additional_info_ = "Kernel [";
        os_additional_info_ += uts_buffer.release;
        os_additional_info_ += "]";
        os_bitdepth_ = uts_buffer.machine;
        os_version_ = uts_buffer.version;
    }

    // Which desktop the user is utilizing (Gnome, etc..)
    char* env_value = getenv("DESKTOP_SESSION");
    if (env_value != nullptr) {
        if (os_additional_info_.size() > 0) {
            os_additional_info_ += ", Desktop [";
        } else {
            os_additional_info_ = "Desktop [";
        }
        os_additional_info_ += env_value;
        os_additional_info_ += "]";
    }

#ifdef SYSTEM_TARGET_LINUX
    // Get CPU name
    fp = popen("cat /proc/cpuinfo", "r");
    if (nullptr != fp) {
        // Read the output a line at a time - output it.
        while (nullptr != fgets(temp_string, max_len - 1, fp)) {
            if (nullptr != strstr(temp_string, "model name")) {
                char* colon_loc = strstr(temp_string, ":");
                if (nullptr != colon_loc) {
                    cpu_name_ = colon_loc + 1;
                    TrimWhitespaceAndQuotes(cpu_name_);
                    break;
                }
            }
        }
        pclose(fp);
    }
#endif
#ifdef SYSTEM_TARGET_BSD
    // Get CPU name
    fp = popen("cat /var/run/dmesg.boot", "r");
    if (nullptr != fp) {
        // Read the output a line at a time - output it.
        while (nullptr != fgets(temp_string, max_len - 1, fp)) {
            if (nullptr != strstr(temp_string, "CPU")) {
                char* colon_loc = strstr(temp_string, ":");
                if (nullptr != colon_loc) {
                    cpu_name_ = colon_loc + 1;
                    TrimWhitespaceAndQuotes(cpu_name_);
                    break;
                }
            }
        }
        pclose(fp);
    }
#endif
#elif defined(SYSTEM_TARGET_APPLE)

    // Get CPU name
#if 0  // TODO : Get this working for Mac
    fp = popen("cat /proc/cpuinfo", "r");
    if (nullptr != fp) {
        // Read the output a line at a time - output it.
        while (nullptr != fgets(temp_string, max_len - 1, fp)) {
            if (nullptr != strstr(temp_string, "model name")) {
                char* colon_loc = strstr(temp_string, ":");
                if (nullptr != colon_loc) {
                    cpu_name_ = colon_loc + 1;
                    TrimWhitespaceAndQuotes(cpu_name_);
                    break;
                }
            }
        }
        pclose(fp);
    }
#endif
#endif

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

    // Get disk space
    std::string cur_path;
    if (getcwd(temp_string, max_len - 1) != NULL) {
        cur_path = temp_string;
    } else {
        cur_path = "";
    }

    struct statvfs fs_stats;
    if (0 == statvfs(cur_path.c_str(), &fs_stats)) {
        uint64_t bytes_total = ((uint64_t)fs_stats.f_bsize * (uint64_t)fs_stats.f_blocks) >> 10;
        if ((bytes_total >> 30) > 0) {
            total_disk_space_ = std::to_string((uint32_t)(bytes_total >> 30)) + " TB";
        } else if ((bytes_total >> 20) > 0) {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 20) + " GB";
        } else if ((bytes_total >> 10) > 0) {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 10) + " MB";
        } else {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total)) + " KB";
        }

        bytes_total = ((uint64_t)fs_stats.f_bsize * (uint64_t)fs_stats.f_bavail) >> 10;
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

    delete[] temp_string;

    if (os_name_.size() > 0 && os_version_.size() > 0 && number_cpus_.size() > 0 && total_ram_.size() > 0) {
        return true;
    }
#endif  // defined(SYSTEM_TARGET_APPLE) || defined(SYSTEM_TARGET_LINUX) || defined(SYSTEM_TARGET_BSD)
    return false;
}  // QueryInfoPosix

#ifdef SYSTEM_TARGET_WINDOWS
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

#endif  // SYSTEM_TARGET_WINDOWS

bool System::QueryInfoWindows() {
#ifdef SYSTEM_TARGET_WINDOWS

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
                os_additional_info_ = "Build [";
                os_additional_info_ += temp_string;
                os_additional_info_ += "]";
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
                        os_additional_info_ = "Build [";
                        os_additional_info_ += temp_string;
                        os_additional_info_ += "]";
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

    DWORD sect_per_cluster = 0;
    DWORD bytes_per_sect = 0;
    DWORD num_free_cluster = 0;
    DWORD total_num_cluster = 0;
    if (TRUE == GetDiskFreeSpaceA(NULL, &sect_per_cluster, &bytes_per_sect, &num_free_cluster, &total_num_cluster)) {
        uint64_t bytes_total = (uint64_t)bytes_per_sect * (uint64_t)sect_per_cluster * (uint64_t)total_num_cluster;
        bytes_total >>= 10;
        if ((bytes_total >> 30) > 0) {
            total_disk_space_ = std::to_string((uint32_t)(bytes_total >> 30)) + " TB";
        } else if ((bytes_total >> 20) > 0) {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 20) + " GB";
        } else if ((bytes_total >> 10) > 0) {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total) >> 10) + " MB";
        } else {
            total_disk_space_ = std::to_string(((uint32_t)bytes_total)) + " KB";
        }

        uint64_t bytes_free = (uint64_t)bytes_per_sect * (uint64_t)sect_per_cluster * (uint64_t)num_free_cluster;
        bytes_free >>= 10;
        if ((bytes_free >> 30) > 0) {
            avail_disk_space_ = std::to_string((uint32_t)(bytes_free >> 30)) + " TB";
        } else if ((bytes_free >> 20) > 0) {
            avail_disk_space_ = std::to_string(((uint32_t)bytes_free) >> 20) + " GB";
        } else if ((bytes_free >> 10) > 0) {
            avail_disk_space_ = std::to_string(((uint32_t)bytes_free) >> 10) + " MB";
        } else {
            avail_disk_space_ = std::to_string(((uint32_t)bytes_free)) + " KB";
        }
    }

    delete[] temp_string;

    if (os_name_.size() > 0 && os_version_.size() > 0 && number_cpus_.size() > 0 && total_ram_.size() > 0) {
        return true;
    }
#endif  // SYSTEM_TARGET_WINDOWS
    return false;
}  // QueryInfoWindows

}  // namespace crash_diagnostic_layer
