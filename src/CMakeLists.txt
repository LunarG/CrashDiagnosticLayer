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

set(LAYER_NAME "VkLayer_gfr")

# NOTE: Our custom code generation target isn't desirable for system package managers or add_subdirectory users.
# So this target needs to be off by default to avoid obtuse build errors or patches.
option(GFR_CODEGEN "Enable graphics flight recorder code generation")
if (GFR_CODEGEN)
    find_package(Python3 REQUIRED)
    add_custom_target(gfr_codegen
        COMMAND Python3::Interpreter
          "${CMAKE_SOURCE_DIR}/scripts/generate_source.py"
          "${VULKAN_HEADERS_INSTALL_DIR}/share/vulkan/registry"
          "${SPIRV_HEADERS_INSTALL_DIR}/include/spirv/unified1"
          --incremental --generated-version ${VulkanHeaders_VERSION} --api vulkan
        WORKING_DIRECTORY ${GENERATED_DIR}
    )
endif()

add_library(gfr MODULE)

target_sources(gfr PRIVATE
    ${GENERATED_DIR}/command_common.h
    ${GENERATED_DIR}/command_common.cc
    ${GENERATED_DIR}/command_printer.h
    ${GENERATED_DIR}/command_printer.cc
    ${GENERATED_DIR}/command_recorder.h
    ${GENERATED_DIR}/command_recorder.cc
    ${GENERATED_DIR}/command_tracker.h
    ${GENERATED_DIR}/command_tracker.cc
    ${GENERATED_DIR}/dispatch.h
    ${GENERATED_DIR}/dispatch.cc
    ${GENERATED_DIR}/layer_base.h
    ${GENERATED_DIR}/layer_base.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/bind_sparse_utils.h
    ${CMAKE_CURRENT_SOURCE_DIR}/bind_sparse_utils.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/command.h
    ${CMAKE_CURRENT_SOURCE_DIR}/command.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/command_buffer_tracker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/command_buffer_tracker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/command_pool.h
    ${CMAKE_CURRENT_SOURCE_DIR}/command_pool.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/descriptor_set.h
    ${CMAKE_CURRENT_SOURCE_DIR}/descriptor_set.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/device.h
    ${CMAKE_CURRENT_SOURCE_DIR}/device.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/gfr.h
    ${CMAKE_CURRENT_SOURCE_DIR}/gfr.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/linear_allocator.h
    ${CMAKE_CURRENT_SOURCE_DIR}/marker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/object_name_db.h
    ${CMAKE_CURRENT_SOURCE_DIR}/object_name_db.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/pipeline.h
    ${CMAKE_CURRENT_SOURCE_DIR}/pipeline.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/semaphore_tracker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/semaphore_tracker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/shader_module.h
    ${CMAKE_CURRENT_SOURCE_DIR}/shader_module.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/spirv_parse.h
    ${CMAKE_CURRENT_SOURCE_DIR}/submit_tracker.h
    ${CMAKE_CURRENT_SOURCE_DIR}/submit_tracker.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/util.h
    ${CMAKE_CURRENT_SOURCE_DIR}/util.cc
)

get_target_property(LAYER_SOURCES gfr SOURCES)
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${LAYER_SOURCES})

set_target_properties(gfr PROPERTIES OUTPUT_NAME ${LAYER_NAME})

target_link_libraries(gfr PUBLIC
    Vulkan::Headers
    ${CMAKE_DL_LIBS}
    $<TARGET_NAME_IF_EXISTS:PkgConfig::XCB>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::X11>
    $<TARGET_NAME_IF_EXISTS:PkgConfig::WAYlAND_CLIENT>
)

if(MSVC)
    target_link_options(gfr PRIVATE /DEF:${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
    target_compile_options(gfr PRIVATE /bigobj)
elseif(MINGW)
    target_sources(gfr PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.def)
    target_compile_options(gfr PRIVATE -Wa,-mbig-obj)
elseif(APPLE)
    message(STATUS "Functions are exported via VVL_EXPORT")
    set_target_properties(gfr PROPERTIES SUFFIX ".dylib")
elseif(ANDROID)
    message(STATUS "Functions are exported via VVL_EXPORT")
else()
    target_link_options(gfr PRIVATE LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/${LAYER_NAME}.map,-Bsymbolic,--exclude-libs,ALL)
endif()

target_compile_options(gfr PRIVATE "$<IF:$<CXX_COMPILER_ID:MSVC>,/wd4100,-Wno-unused-parameter>")

target_include_directories(gfr SYSTEM PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${GENERATED_DIR})

if (ANDROID)
    add_subdirectory(android)
    return()
endif()

# There are 2 primary deliverables
# - The actual library
# - The respective json file
# This code generates the appropriate json for both local testing and the installation.
# NOTE: For WIN32 the JSON and dll MUST be placed in the same location, due to Win32 using a relative path for installation.
set(INPUT_FILE "${GENERATED_DIR}/graphics_flight_recorder.json.in")
set(INTERMEDIATE_FILE "${CMAKE_CURRENT_BINARY_DIR}/json/graphics_flight_recorder.json")
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
add_custom_command(TARGET gfr POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${INTERMEDIATE_FILE} $<TARGET_FILE_DIR:gfr>/${OUTPUT_FILE_FINAL_NAME}
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
    install(FILES $<TARGET_PDB_FILE:gfr> DESTINATION ${LAYER_INSTALL_DIR})
endif()

install(TARGETS gfr DESTINATION ${LAYER_INSTALL_DIR})
