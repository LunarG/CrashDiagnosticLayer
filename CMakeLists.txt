# Copyright (C) 2020 Google Inc.
# Copyright (c) 2023-2024 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.17.2)

project(crash_diagnostic LANGUAGES CXX)

# This variable enables downstream users to customize the target API
# variant (e.g. Vulkan SC)
set(API_TYPE "vulkan")

add_subdirectory(scripts)

set(VVL_CPP_STANDARD 17 CACHE STRING "Set the C++ standard to build against.")
set(CMAKE_CXX_STANDARD ${VVL_CPP_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN "YES")

include(GNUInstallDirs)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) # Remove when min is 3.26, see CMP0143

find_package(VulkanHeaders REQUIRED CONFIG QUIET)
find_package(VulkanUtilityLibraries REQUIRED CONFIG QUIET)
find_package(yaml-cpp REQUIRED CONFIG QUIET)

if(WIN32)
    target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_WIN32_KHR)
elseif(ANDROID)
    target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_ANDROID_KHR)
elseif(APPLE)
    target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_MACOS_MVK VK_USE_PLATFORM_METAL_EXT)
else()
    option(BUILD_WSI_XCB_SUPPORT "Build XCB WSI support" ON)
    option(BUILD_WSI_XLIB_SUPPORT "Build Xlib WSI support" ON)
    option(BUILD_WSI_WAYLAND_SUPPORT "Build Wayland WSI support" ON)

    find_package(PkgConfig REQUIRED QUIET) # Use PkgConfig to find Linux system libraries

    if(BUILD_WSI_XCB_SUPPORT)
        pkg_check_modules(XCB REQUIRED QUIET IMPORTED_TARGET xcb)
        target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_XCB_KHR)
    endif()

    if(BUILD_WSI_XLIB_SUPPORT)
        pkg_check_modules(X11 REQUIRED QUIET IMPORTED_TARGET x11)
        target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_XLIB_KHR VK_USE_PLATFORM_XLIB_XRANDR_EXT)
    endif()

    if(BUILD_WSI_WAYLAND_SUPPORT)
        pkg_check_modules(WAYlAND_CLIENT QUIET REQUIRED IMPORTED_TARGET wayland-client)
        target_compile_definitions(Vulkan::Headers INTERFACE VK_USE_PLATFORM_WAYLAND_KHR)
    endif()
endif()

# Taking the sanitizer enablement solution from the `cpp-best-practices`
# "cmake_template" Github Repo (which is unencombered open source).
option(CDL_ENABLE_SANITIZER_ADDRESS   "Enable address sanitization"   OFF)
option(CDL_ENABLE_SANITIZER_LEAK      "Enable leak sanitization"      OFF)
option(CDL_ENABLE_SANITIZER_MEMORY    "Enable memory sanitization"    OFF)
option(CDL_ENABLE_SANITIZER_THREAD    "Enable thread sanitization"    OFF)
option(CDL_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitization" OFF)

# Now check support for each sanitizer option
set(SUPPORTS_SANITIZE_ADDRESS FALSE)
set(SUPPORTS_SANITIZE_LEAK FALSE)
set(SUPPORTS_SANITIZE_MEMORY FALSE)
set(SUPPORTS_SANITIZE_THREAD FALSE)
set(SUPPORTS_SANITIZE_UNDEFINED FALSE)
if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)
    set(SUPPORTS_SANITIZE_ADDRESS TRUE)
    set(SUPPORTS_SANITIZE_LEAK TRUE)
    set(SUPPORTS_SANITIZE_MEMORY TRUE)
    set(SUPPORTS_SANITIZE_THREAD TRUE)
    set(SUPPORTS_SANITIZE_UNDEFINED TRUE)
elseif(MSVC)
    set(SUPPORTS_SANITIZE_ADDRESS TRUE)
endif()

# Set up a list of enabled sanitizers
# Warn when one or more are not compatible with other sanitizers.
set(SANITIZER_LIST "")
if (CDL_ENABLE_SANITIZER_ADDRESS AND SUPPORTS_SANITIZE_ADDRESS)
    list(APPEND SANITIZER_LIST "address")
endif()
if (CDL_ENABLE_SANITIZER_LEAK)
    list(APPEND SANITIZER_LIST "leak")
endif()
if (CDL_ENABLE_SANITIZER_MEMORY)
    if (CDL_ENABLE_SANITIZER_ADDRESS OR CDL_ENABLE_SANITIZER_LEAK OR CDL_ENABLE_SANITIZER_THREAD)
        MESSAGE(WARNING "Memory sanitizer does not work with address, thread, or leak sanitizers enabled")
    else()
        list(APPEND SANITIZER_LIST "memory")
    endif()
endif()
if (CDL_ENABLE_SANITIZER_THREAD)
    if (CDL_ENABLE_SANITIZER_ADDRESS OR CDL_ENABLE_SANITIZER_LEAK)
        MESSAGE(WARNING "Thread sanitizer does not work with address or leak sanitizers enabled")
    else()
        list(APPEND SANITIZER_LIST "thread")
    endif()
endif()
if (CDL_ENABLE_SANITIZER_UNDEFINED AND SUPPORTS_SANITIZE_UNDEFINED)
    list(APPEND SANITIZER_LIST "undefined")
endif()

list(
    JOIN
    SANITIZER_LIST
    ","
    SANITIZER_COMMA_LIST)

# Enable them appropriately per platform
if (SANITIZER_COMMA_LIST)
    if (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        MESSAGE(WARNING "Sanitizers on Clang require all the code to be compiled with the corresponding sanitizer enabled or false positives may occur")
    endif()
    if (NOT MSVC)
        add_compile_options(-fsanitize=${SANITIZER_COMMA_LIST} -fno-omit-frame-pointer)
        add_link_options(-fsanitize=${SANITIZER_COMMA_LIST})
    else()
        if (CDL_ENABLE_SANITIZER_LEAK OR CDL_ENABLE_SANITIZER_MEMORY OR CDL_ENABLE_SANITIZER_THREAD OR CDL_ENABLE_SANITIZER_UNDEFINED)
            message(WARNING "MSVC only supports address sanitizer")
        endif()
        add_compile_options(/fsanitize=${SANITIZER_COMMA_LIST} /Oy- /INCREMENTAL:NO)
        add_link_options(/INCREMENTAL:NO)
    endif()
endif()

set(GENERATED_DIR "${CMAKE_SOURCE_DIR}/src/generated")

if(MSVC)
    # Enforce stricter ISO C++
    add_compile_options(/permissive-)

    # PDBs aren't generated on Release builds by default.
    add_compile_options("$<$<CONFIG:Release>:/Zi>")
    add_link_options("$<$<CONFIG:Release>:/DEBUG:FULL>")

    # Enable /LTCG (Link-time code generation)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)
    # Remove unreferenced code/data.
    add_link_options("$<$<CONFIG:Release>:/OPT:REF>")
    # Merge duplicate data/functions
    add_link_options("$<$<CONFIG:Release>:/OPT:ICF>")

    # Allow usage of unsafe CRT functions and minimize what Windows.h leaks
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS NOMINMAX WIN32_LEAN_AND_MEAN)

    add_compile_options($<$<BOOL:${MSVC_IDE}>:/MP>) # Speed up Visual Studio builds
endif()

add_subdirectory(src)
