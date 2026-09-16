# ~~~
# Copyright (c) 2014-2026 Valve Corporation
# Copyright (c) 2014-2026 LunarG, Inc.
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
if (ANDROID)
    add_library(cdl_tests MODULE)
else()
    add_executable(cdl_tests)
endif()
target_sources(cdl_tests PRIVATE
    framework/cdl_tests.cpp
    framework/bound_buffer.h
    framework/bound_buffer.cpp
    framework/bound_image.h
    framework/bound_image.cpp
    framework/compute_pipeline.h
    framework/compute_pipeline.cpp
    framework/descriptorset_helper.h
    framework/descriptorset_helper.cpp
    framework/dump_file.h
    framework/dump_file.cpp
    framework/error_monitor.h
    framework/error_monitor.cpp
    framework/graphics_pipeline.h
    framework/graphics_pipeline.cpp
    framework/layer_settings.h
    framework/layer_settings.cpp
    framework/test_fixtures.h
    framework/test_fixtures.cpp
    unit/create_instance.cpp
    unit/gpu_crash.cpp
    unit/graphics.cpp
    unit/ray_tracing.cpp
    unit/sync.cpp
    unit/settings.cpp
    unit/watchdog.cpp
    unit/tooling.cpp
)

get_target_property(TEST_SOURCES cdl_tests SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${TEST_SOURCES})

add_dependencies(cdl_tests crash_diagnostic)

find_package(GTest CONFIG)
find_package(glslang CONFIG)

# A system installed glslang or gtest in /usr/local/include must not shadow the ones we link.
cdl_no_system_includes(GTest::gtest
                       glslang::glslang
                       glslang::SPIRV
                       glslang::glslang-default-resource-limits)

target_link_libraries(cdl_tests PRIVATE
    Vulkan::Headers
    Vulkan::UtilityHeaders
    Vulkan::SafeStruct
    GTest::gtest
    glslang::SPIRV
    glslang::glslang-default-resource-limits
    yaml-cpp::yaml-cpp
)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    #32 bit MSVC needs this option so that Vulkan-Hpp operator== statements work
    target_compile_definitions(cdl_tests PRIVATE VULKAN_HPP_TYPESAFE_CONVERSION=1)
endif()

# tests/icd skips MINGW, so the tests have to cope with there being no mock ICD to point at.
add_subdirectory(icd)
if (TARGET CDL_Test_ICD)
    set(MOCK_ICD_AVAILABLE true)
    set(MOCK_ICD_BUILD_PATH "$<TARGET_FILE_DIR:CDL_Test_ICD>")
else()
    set(MOCK_ICD_AVAILABLE false)
    set(MOCK_ICD_BUILD_PATH "")
endif()

# setup framework/config.h using framework/config.h.in as a source.
# configure_file() resolves the @VAR@ references, file(GENERATE) the generator expressions.
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/framework/config.h.in" "${CMAKE_CURRENT_BINARY_DIR}/config.h.configured" @ONLY)
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/config$<CONFIG>.h" INPUT "${CMAKE_CURRENT_BINARY_DIR}/config.h.configured")

# copy config$<CONFIG>.h to the build directory
add_custom_command(
    COMMAND ${CMAKE_COMMAND} "-E" "copy_if_different" "${CMAKE_CURRENT_BINARY_DIR}/config$<CONFIG>.h" "${CMAKE_CURRENT_BINARY_DIR}/config.h"
    VERBATIM
    DEPENDS  "${CMAKE_CURRENT_BINARY_DIR}/config$<CONFIG>.h"
    OUTPUT   "${CMAKE_CURRENT_BINARY_DIR}/config.h"
    COMMENT  "creating config.h file ({event: PRE_BUILD}, {filename: config.h })"
    )
add_custom_target (generate_framework_config DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/config.h")
add_dependencies (generate_framework_config cdl_tests)
target_sources(cdl_tests PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/config.h)
target_include_directories(cdl_tests PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(cdl_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/framework)


if (ANDROID)
    add_subdirectory(android)
else()
    install(TARGETS cdl_tests)
    include(GoogleTest)
    gtest_discover_tests(cdl_tests DISCOVERY_TIMEOUT 100)
endif()


