
/***************************************************************************
*
* Copyright (C) 2021 Google Inc.
* Copyright (c) 2023 LunarG, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* *** ---- WARNING! ----
* ***   THIS FILE IS GENERATED - DO NOT EDIT
* ***   Update source file layer_utils_generator.py for modifications
* *** ---- WARNING! ----
*
****************************************************************************/


// NOLINTBEGIN


#include "layer_utils.h"

namespace crash_diagnostic_layer {

void GetResultString(VkResult result, std::string& result_string) {
    switch (result) {
        default: result_string = "Unknown Error"; break;
        case VK_SUCCESS: result_string = "VK_SUCCESS"; break;
        case VK_NOT_READY: result_string = "VK_NOT_READY"; break;
        case VK_TIMEOUT: result_string = "VK_TIMEOUT"; break;
        case VK_EVENT_SET: result_string = "VK_EVENT_SET"; break;
        case VK_EVENT_RESET: result_string = "VK_EVENT_RESET"; break;
        case VK_INCOMPLETE: result_string = "VK_INCOMPLETE"; break;
        case VK_ERROR_OUT_OF_HOST_MEMORY: result_string = "VK_ERROR_OUT_OF_HOST_MEMORY"; break;
        case VK_ERROR_OUT_OF_DEVICE_MEMORY: result_string = "VK_ERROR_OUT_OF_DEVICE_MEMORY"; break;
        case VK_ERROR_INITIALIZATION_FAILED: result_string = "VK_ERROR_INITIALIZATION_FAILED"; break;
        case VK_ERROR_DEVICE_LOST: result_string = "VK_ERROR_DEVICE_LOST"; break;
        case VK_ERROR_MEMORY_MAP_FAILED: result_string = "VK_ERROR_MEMORY_MAP_FAILED"; break;
        case VK_ERROR_LAYER_NOT_PRESENT: result_string = "VK_ERROR_LAYER_NOT_PRESENT"; break;
        case VK_ERROR_EXTENSION_NOT_PRESENT: result_string = "VK_ERROR_EXTENSION_NOT_PRESENT"; break;
        case VK_ERROR_FEATURE_NOT_PRESENT: result_string = "VK_ERROR_FEATURE_NOT_PRESENT"; break;
        case VK_ERROR_INCOMPATIBLE_DRIVER: result_string = "VK_ERROR_INCOMPATIBLE_DRIVER"; break;
        case VK_ERROR_TOO_MANY_OBJECTS: result_string = "VK_ERROR_TOO_MANY_OBJECTS"; break;
        case VK_ERROR_FORMAT_NOT_SUPPORTED: result_string = "VK_ERROR_FORMAT_NOT_SUPPORTED"; break;
        case VK_ERROR_FRAGMENTED_POOL: result_string = "VK_ERROR_FRAGMENTED_POOL"; break;
        case VK_ERROR_UNKNOWN: result_string = "VK_ERROR_UNKNOWN"; break;
        case VK_ERROR_OUT_OF_POOL_MEMORY: result_string = "VK_ERROR_OUT_OF_POOL_MEMORY"; break;
        case VK_ERROR_INVALID_EXTERNAL_HANDLE: result_string = "VK_ERROR_INVALID_EXTERNAL_HANDLE"; break;
        case VK_ERROR_FRAGMENTATION: result_string = "VK_ERROR_FRAGMENTATION"; break;
        case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: result_string = "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS"; break;
        case VK_PIPELINE_COMPILE_REQUIRED: result_string = "VK_PIPELINE_COMPILE_REQUIRED"; break;
        case VK_ERROR_SURFACE_LOST_KHR: result_string = "VK_ERROR_SURFACE_LOST_KHR"; break;
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: result_string = "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR"; break;
        case VK_SUBOPTIMAL_KHR: result_string = "VK_SUBOPTIMAL_KHR"; break;
        case VK_ERROR_OUT_OF_DATE_KHR: result_string = "VK_ERROR_OUT_OF_DATE_KHR"; break;
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: result_string = "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR"; break;
        case VK_ERROR_VALIDATION_FAILED_EXT: result_string = "VK_ERROR_VALIDATION_FAILED_EXT"; break;
        case VK_ERROR_INVALID_SHADER_NV: result_string = "VK_ERROR_INVALID_SHADER_NV"; break;
        case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR: result_string = "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR"; break;
        case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: result_string = "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT"; break;
        case VK_ERROR_NOT_PERMITTED_KHR: result_string = "VK_ERROR_NOT_PERMITTED_KHR"; break;
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: result_string = "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT"; break;
        case VK_THREAD_IDLE_KHR: result_string = "VK_THREAD_IDLE_KHR"; break;
        case VK_THREAD_DONE_KHR: result_string = "VK_THREAD_DONE_KHR"; break;
        case VK_OPERATION_DEFERRED_KHR: result_string = "VK_OPERATION_DEFERRED_KHR"; break;
        case VK_OPERATION_NOT_DEFERRED_KHR: result_string = "VK_OPERATION_NOT_DEFERRED_KHR"; break;
        case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR: result_string = "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR"; break;
        case VK_ERROR_COMPRESSION_EXHAUSTED_EXT: result_string = "VK_ERROR_COMPRESSION_EXHAUSTED_EXT"; break;
        case VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT: result_string = "VK_ERROR_INCOMPATIBLE_SHADER_BINARY_EXT"; break;
    }
}


} // namespace crash_diagnostic_layer


// NOLINTEND

