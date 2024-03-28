# Copyright (C) 2020 Google Inc.
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

set(LAYER_NAME "VkLayer_crash_diagnostic")

# NOTE: Our custom code generation target isn't desirable for system package managers or add_subdirectory users.
# So this target needs to be off by default to avoid obtuse build errors or patches.
option(CDL_CODEGEN "Enable graphics flight recorder code generation")
if (CDL_CODEGEN)
    find_package(Python3 REQUIRED)
    add_custom_target(cdl_codegen
        COMMAND Python3::Interpreter
          "${CMAKE_SOURCE_DIR}/scripts/generate_source.py"
          "${VULKAN_HEADERS_INSTALL_DIR}/share/vulkan/registry"
          "${SPIRV_HEADERS_INSTALL_DIR}/include/spirv/unified1"
          --incremental --generated-version ${VulkanHeaders_VERSION} --api vulkan
        WORKING_DIRECTORY ${GENERATED_DIR}
    )
endif()

add_library(crash_diagnostic MODULE)

target_sources(crash_diagnostic PRIVATE
    generated/command_common.h
    generated/command_common.cc
    generated/command_printer.h
    generated/command_printer.cc
    generated/command_printer_structs.cc
    generated/command_printer_types.cc
    generated/command_recorder.h
    generated/command_recorder.cc
    generated/command_tracker.h
    generated/command_tracker.cc
    generated/dispatch.h
    generated/dispatch.cc
    generated/layer_base.h
    generated/layer_base.cc
    bind_sparse_utils.h
    bind_sparse_utils.cc
    command.h
    command.cc
    command_buffer_tracker.h
    command_buffer_tracker.cc
    command_pool.h
    command_pool.cc
    descriptor_set.h
    descriptor_set.cc
    device.h
    device.cc
    cdl.h
    cdl.cc
    linear_allocator.h
    logger.h
    logger.cc
    marker.h
    object_name_db.h
    object_name_db.cc
    pipeline.h
    pipeline.cc
    semaphore_tracker.h
    semaphore_tracker.cc
    shader_module.h
    shader_module.cc
    spirv_parse.h
    submit_tracker.h
    submit_tracker.cc
    system.h
    system.cc
    util.h
)

get_target_property(LAYER_SOURCES crash_diagnostic SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${LAYER_SOURCES})

set_target_properties(crash_diagnostic PROPERTIES OUTPUT_NAME ${LAYER_NAME})

target_link_libraries(crash_diagnostic PUBLIC
    Vulkan::Headers
    Vulkan::LayerSettings
    Vulkan::UtilityHeaders
    yaml-cpp::yaml-cpp
    ${CMAKE_DL_LIBS}
    $<TARGET_NAME_IF_EXISTS:PkgConfig::XCB>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::X11>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::WAYlAND_CLIENT>
)

if(ANDROID)
target_link_libraries(crash_diagnostic PUBLIC log)
endif()

if(MSVC)
    target_link_options(crash_diagnostic PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
    target_compile_options(crash_diagnostic PRIVATE /bigobj)
    target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_WINDOWS)
elseif(MINGW)
    target_sources(crash_diagnosticPRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
    target_compile_options(crash_diagnostic PRIVATE -Wa,-mbig-obj)
    target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_WINDOWS)
elseif(APPLE)
    message(STATUS "Functions are exported via VVL_EXPORT")
    set_target_properties(crash_diagnostic PROPERTIES SUFFIX ".dylib")
    target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_APPLE)
elseif(ANDROID)
    message(STATUS "Functions are exported via VVL_EXPORT")
    target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_ANDROID)
else()
    target_link_options(crash_diagnostic PRIVATE LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.map,-Bsymbolic,--exclude-libs,ALL)
    if(CMAKE_SYSTEM_NAME MATCHES "Linux")
        target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_LINUX)
    elseif(CMAKE_SYSTEM_NAME MATCHES "BSD")
        target_compile_definitions(crash_diagnostic PRIVATE -DSYSTEM_TARGET_BSD)
    endif()
endif()

target_compile_options(crash_diagnostic PRIVATE "$<IF:$<CXX_COMPILER_ID:MSVC>,/wd4100,-Wno-unused-parameter>")

target_include_directories(crash_diagnostic SYSTEM PRIVATE
                                ${CMAKE_CURRENT_SOURCE_DIR}
                                ${GENERATED_DIR}
                                ${SPIRV_HEADERS_INSTALL_DIR}/include/spirv/unified1
                                )

if (ANDROID)
    add_subdirectory(android)
    return()
endif()

# There are 2 primary deliverables
# - The actual library
# - The respective json file
# This code generates the appropriate json for both local testing and the installation.
# NOTE: For WIN32 the JSON and dll MUST be placed in the same location, due to Win32 using a relative path for installation.
set(INPUT_FILE "${CMAKE_CURRENT_SOURCE_DIR}/crash_diagnostic_layer.json.in")
set(INTERMEDIATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/json/crash_diagnostic_layer.json")
set(OUTPUT_FILE_FINAL_NAME "${LAYER_NAME}.json")
set(LAYER_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})

if (WIN32)
    set(LAYER_INSTALL_DIR ${CMAKE_INSTALL_BINDIR}) # WIN32/MINGW expect the dll in the `bin` dir, this matches our WIN32 SDK process
endif()

if (WIN32)
    set(JSON_LIBRARY_PATH ".\\\\${LAYER_NAME}.dll")
elseif(APPLE)
    set(JSON_LIBRARY_PATH "./lib${LAYER_NAME}.dylib")
else()
    set(JSON_LIBRARY_PATH "./lib${LAYER_NAME}.so")
endif()

configure_file(${INPUT_FILE} ${INTERMEDIATE_FILE} @ONLY)

# To support both multi/single configuration generators just copy the json to the correct directory
add_custom_command(TARGET crash_diagnostic POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${INTERMEDIATE_FILE} $<TARGET_FILE_DIR:crash_diagnostic>/${OUTPUT_FILE_FINAL_NAME}
)

# For UNIX-based systems, `library_path` should not contain a relative path (indicated by "./") before installing to system directories
# This json isn't used for regular local development, it's used for installation
if (UNIX)
    set(UNIX_INTERMEDIATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/json/unix_install_validation.json")

    if(APPLE)
        set(JSON_LIBRARY_PATH "lib${LAYER_NAME}.dylib")
    else()
        set(JSON_LIBRARY_PATH "lib${LAYER_NAME}.so")
    endif()

    configure_file(${INPUT_FILE} ${UNIX_INTERMEDIATE_FILE} @ONLY)

    install(FILES ${UNIX_INTERMEDIATE_FILE} DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/vulkan/implicit_layer.d RENAME ${OUTPUT_FILE_FINAL_NAME})
endif()

if (WIN32)
    install(FILES ${INTERMEDIATE_FILE} DESTINATION ${LAYER_INSTALL_DIR} RENAME ${OUTPUT_FILE_FINAL_NAME})
endif()
if (MSVC)
    install(FILES $<TARGET_PDB_FILE:crash_diagnostic> DESTINATION ${LAYER_INSTALL_DIR})
endif()

install(TARGETS crash_diagnostic DESTINATION ${LAYER_INSTALL_DIR})
