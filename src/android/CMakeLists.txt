# ~~~
# Copyright (c) 2023 LunarG, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

# https://gitlab.kitware.com/cmake/cmake/issues/18787
# https://github.com/android-ndk/ndk/issues/463
# "Users should be able to reliably use the toolchain provided by the NDK r23 or later when using CMake 3.21 or later" - Professional CMake
if (CMAKE_VERSION VERSION_LESS "3.21")
    message(FATAL_ERROR "Android build requires at least CMake 3.21!")
endif()

# Avoid issues with older NDKs which complicate correct CMake builds:
#
# Example:
# The NDK toolchain file in r23 contains a bug which means CMAKE_ANDROID_EXCEPTIONS might not be set correctly in some circumstances, if not set directly by the developer.
if (ANDROID_NDK_REVISION VERSION_LESS "25")
    message(FATAL_ERROR "Android build requires at least NDK r25!")
endif()

message(STATUS "Targeting Android API Level ${CMAKE_SYSTEM_VERSION}")

message(STATUS "Building with Android NDK Version ${ANDROID_NDK_REVISION}")

install(TARGETS crash_diagnostic DESTINATION ${CMAKE_INSTALL_LIBDIR})
