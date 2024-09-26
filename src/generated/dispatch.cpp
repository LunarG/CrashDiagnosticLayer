
/***************************************************************************
 *
 * Copyright (C) 2021 Google Inc.
 * Copyright (c) 2023-2024 LunarG, Inc.
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
 * ***   Update source file dispatch_generator.py for modifications
 * *** ---- WARNING! ----
 *
 ****************************************************************************/

// NOLINTBEGIN

#include "dispatch.h"

namespace crash_diagnostic_layer {

void InitInstanceDispatchTable(VkInstance instance, PFN_vkGetInstanceProcAddr pa, InstanceDispatchTable *dt) {
    dt->CreateInstance = (PFN_vkCreateInstance)pa(instance, "vkCreateInstance");
    dt->DestroyInstance = (PFN_vkDestroyInstance)pa(instance, "vkDestroyInstance");
    dt->EnumeratePhysicalDevices = (PFN_vkEnumeratePhysicalDevices)pa(instance, "vkEnumeratePhysicalDevices");
    dt->GetPhysicalDeviceFeatures = (PFN_vkGetPhysicalDeviceFeatures)pa(instance, "vkGetPhysicalDeviceFeatures");
    dt->GetPhysicalDeviceFormatProperties =
        (PFN_vkGetPhysicalDeviceFormatProperties)pa(instance, "vkGetPhysicalDeviceFormatProperties");
    dt->GetPhysicalDeviceImageFormatProperties =
        (PFN_vkGetPhysicalDeviceImageFormatProperties)pa(instance, "vkGetPhysicalDeviceImageFormatProperties");
    dt->GetPhysicalDeviceProperties = (PFN_vkGetPhysicalDeviceProperties)pa(instance, "vkGetPhysicalDeviceProperties");
    dt->GetPhysicalDeviceQueueFamilyProperties =
        (PFN_vkGetPhysicalDeviceQueueFamilyProperties)pa(instance, "vkGetPhysicalDeviceQueueFamilyProperties");
    dt->GetPhysicalDeviceMemoryProperties =
        (PFN_vkGetPhysicalDeviceMemoryProperties)pa(instance, "vkGetPhysicalDeviceMemoryProperties");
    dt->GetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)pa(instance, "vkGetInstanceProcAddr");
    dt->CreateDevice = (PFN_vkCreateDevice)pa(instance, "vkCreateDevice");
    dt->EnumerateInstanceExtensionProperties =
        (PFN_vkEnumerateInstanceExtensionProperties)pa(instance, "vkEnumerateInstanceExtensionProperties");
    dt->EnumerateDeviceExtensionProperties =
        (PFN_vkEnumerateDeviceExtensionProperties)pa(instance, "vkEnumerateDeviceExtensionProperties");
    dt->EnumerateInstanceLayerProperties =
        (PFN_vkEnumerateInstanceLayerProperties)pa(instance, "vkEnumerateInstanceLayerProperties");
    dt->EnumerateDeviceLayerProperties =
        (PFN_vkEnumerateDeviceLayerProperties)pa(instance, "vkEnumerateDeviceLayerProperties");
    dt->GetPhysicalDeviceSparseImageFormatProperties = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties)pa(
        instance, "vkGetPhysicalDeviceSparseImageFormatProperties");
    dt->EnumerateInstanceVersion = (PFN_vkEnumerateInstanceVersion)pa(instance, "vkEnumerateInstanceVersion");
    dt->EnumeratePhysicalDeviceGroups =
        (PFN_vkEnumeratePhysicalDeviceGroups)pa(instance, "vkEnumeratePhysicalDeviceGroups");
    dt->GetPhysicalDeviceFeatures2 = (PFN_vkGetPhysicalDeviceFeatures2)pa(instance, "vkGetPhysicalDeviceFeatures2");
    dt->GetPhysicalDeviceProperties2 =
        (PFN_vkGetPhysicalDeviceProperties2)pa(instance, "vkGetPhysicalDeviceProperties2");
    dt->GetPhysicalDeviceFormatProperties2 =
        (PFN_vkGetPhysicalDeviceFormatProperties2)pa(instance, "vkGetPhysicalDeviceFormatProperties2");
    dt->GetPhysicalDeviceImageFormatProperties2 =
        (PFN_vkGetPhysicalDeviceImageFormatProperties2)pa(instance, "vkGetPhysicalDeviceImageFormatProperties2");
    dt->GetPhysicalDeviceQueueFamilyProperties2 =
        (PFN_vkGetPhysicalDeviceQueueFamilyProperties2)pa(instance, "vkGetPhysicalDeviceQueueFamilyProperties2");
    dt->GetPhysicalDeviceMemoryProperties2 =
        (PFN_vkGetPhysicalDeviceMemoryProperties2)pa(instance, "vkGetPhysicalDeviceMemoryProperties2");
    dt->GetPhysicalDeviceSparseImageFormatProperties2 = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2)pa(
        instance, "vkGetPhysicalDeviceSparseImageFormatProperties2");
    dt->GetPhysicalDeviceExternalBufferProperties =
        (PFN_vkGetPhysicalDeviceExternalBufferProperties)pa(instance, "vkGetPhysicalDeviceExternalBufferProperties");
    dt->GetPhysicalDeviceExternalFenceProperties =
        (PFN_vkGetPhysicalDeviceExternalFenceProperties)pa(instance, "vkGetPhysicalDeviceExternalFenceProperties");
    dt->GetPhysicalDeviceExternalSemaphoreProperties = (PFN_vkGetPhysicalDeviceExternalSemaphoreProperties)pa(
        instance, "vkGetPhysicalDeviceExternalSemaphoreProperties");
    dt->GetPhysicalDeviceToolProperties =
        (PFN_vkGetPhysicalDeviceToolProperties)pa(instance, "vkGetPhysicalDeviceToolProperties");
    dt->DestroySurfaceKHR = (PFN_vkDestroySurfaceKHR)pa(instance, "vkDestroySurfaceKHR");
    dt->GetPhysicalDeviceSurfaceSupportKHR =
        (PFN_vkGetPhysicalDeviceSurfaceSupportKHR)pa(instance, "vkGetPhysicalDeviceSurfaceSupportKHR");
    dt->GetPhysicalDeviceSurfaceCapabilitiesKHR =
        (PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR)pa(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
    dt->GetPhysicalDeviceSurfaceFormatsKHR =
        (PFN_vkGetPhysicalDeviceSurfaceFormatsKHR)pa(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR");
    dt->GetPhysicalDeviceSurfacePresentModesKHR =
        (PFN_vkGetPhysicalDeviceSurfacePresentModesKHR)pa(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR");
    dt->GetPhysicalDevicePresentRectanglesKHR =
        (PFN_vkGetPhysicalDevicePresentRectanglesKHR)pa(instance, "vkGetPhysicalDevicePresentRectanglesKHR");
    dt->GetPhysicalDeviceDisplayPropertiesKHR =
        (PFN_vkGetPhysicalDeviceDisplayPropertiesKHR)pa(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR");
    dt->GetPhysicalDeviceDisplayPlanePropertiesKHR =
        (PFN_vkGetPhysicalDeviceDisplayPlanePropertiesKHR)pa(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR");
    dt->GetDisplayPlaneSupportedDisplaysKHR =
        (PFN_vkGetDisplayPlaneSupportedDisplaysKHR)pa(instance, "vkGetDisplayPlaneSupportedDisplaysKHR");
    dt->GetDisplayModePropertiesKHR = (PFN_vkGetDisplayModePropertiesKHR)pa(instance, "vkGetDisplayModePropertiesKHR");
    dt->CreateDisplayModeKHR = (PFN_vkCreateDisplayModeKHR)pa(instance, "vkCreateDisplayModeKHR");
    dt->GetDisplayPlaneCapabilitiesKHR =
        (PFN_vkGetDisplayPlaneCapabilitiesKHR)pa(instance, "vkGetDisplayPlaneCapabilitiesKHR");
    dt->CreateDisplayPlaneSurfaceKHR =
        (PFN_vkCreateDisplayPlaneSurfaceKHR)pa(instance, "vkCreateDisplayPlaneSurfaceKHR");
#ifdef VK_USE_PLATFORM_XLIB_KHR
    dt->CreateXlibSurfaceKHR = (PFN_vkCreateXlibSurfaceKHR)pa(instance, "vkCreateXlibSurfaceKHR");
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
    dt->GetPhysicalDeviceXlibPresentationSupportKHR = (PFN_vkGetPhysicalDeviceXlibPresentationSupportKHR)pa(
        instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    dt->CreateXcbSurfaceKHR = (PFN_vkCreateXcbSurfaceKHR)pa(instance, "vkCreateXcbSurfaceKHR");
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    dt->GetPhysicalDeviceXcbPresentationSupportKHR =
        (PFN_vkGetPhysicalDeviceXcbPresentationSupportKHR)pa(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    dt->CreateWaylandSurfaceKHR = (PFN_vkCreateWaylandSurfaceKHR)pa(instance, "vkCreateWaylandSurfaceKHR");
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    dt->GetPhysicalDeviceWaylandPresentationSupportKHR = (PFN_vkGetPhysicalDeviceWaylandPresentationSupportKHR)pa(
        instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR");
#endif  // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    dt->CreateAndroidSurfaceKHR = (PFN_vkCreateAndroidSurfaceKHR)pa(instance, "vkCreateAndroidSurfaceKHR");
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->CreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR)pa(instance, "vkCreateWin32SurfaceKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetPhysicalDeviceWin32PresentationSupportKHR = (PFN_vkGetPhysicalDeviceWin32PresentationSupportKHR)pa(
        instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->GetPhysicalDeviceVideoCapabilitiesKHR =
        (PFN_vkGetPhysicalDeviceVideoCapabilitiesKHR)pa(instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR");
    dt->GetPhysicalDeviceVideoFormatPropertiesKHR =
        (PFN_vkGetPhysicalDeviceVideoFormatPropertiesKHR)pa(instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR");
    dt->GetPhysicalDeviceFeatures2KHR =
        (PFN_vkGetPhysicalDeviceFeatures2KHR)pa(instance, "vkGetPhysicalDeviceFeatures2KHR");
    dt->GetPhysicalDeviceProperties2KHR =
        (PFN_vkGetPhysicalDeviceProperties2KHR)pa(instance, "vkGetPhysicalDeviceProperties2KHR");
    dt->GetPhysicalDeviceFormatProperties2KHR =
        (PFN_vkGetPhysicalDeviceFormatProperties2KHR)pa(instance, "vkGetPhysicalDeviceFormatProperties2KHR");
    dt->GetPhysicalDeviceImageFormatProperties2KHR =
        (PFN_vkGetPhysicalDeviceImageFormatProperties2KHR)pa(instance, "vkGetPhysicalDeviceImageFormatProperties2KHR");
    dt->GetPhysicalDeviceQueueFamilyProperties2KHR =
        (PFN_vkGetPhysicalDeviceQueueFamilyProperties2KHR)pa(instance, "vkGetPhysicalDeviceQueueFamilyProperties2KHR");
    dt->GetPhysicalDeviceMemoryProperties2KHR =
        (PFN_vkGetPhysicalDeviceMemoryProperties2KHR)pa(instance, "vkGetPhysicalDeviceMemoryProperties2KHR");
    dt->GetPhysicalDeviceSparseImageFormatProperties2KHR = (PFN_vkGetPhysicalDeviceSparseImageFormatProperties2KHR)pa(
        instance, "vkGetPhysicalDeviceSparseImageFormatProperties2KHR");
    dt->EnumeratePhysicalDeviceGroupsKHR =
        (PFN_vkEnumeratePhysicalDeviceGroupsKHR)pa(instance, "vkEnumeratePhysicalDeviceGroupsKHR");
    dt->GetPhysicalDeviceExternalBufferPropertiesKHR = (PFN_vkGetPhysicalDeviceExternalBufferPropertiesKHR)pa(
        instance, "vkGetPhysicalDeviceExternalBufferPropertiesKHR");
    dt->GetPhysicalDeviceExternalSemaphorePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR)pa(
        instance, "vkGetPhysicalDeviceExternalSemaphorePropertiesKHR");
    dt->GetPhysicalDeviceExternalFencePropertiesKHR = (PFN_vkGetPhysicalDeviceExternalFencePropertiesKHR)pa(
        instance, "vkGetPhysicalDeviceExternalFencePropertiesKHR");
    dt->EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR =
        (PFN_vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR)pa(
            instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR");
    dt->GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR =
        (PFN_vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR)pa(
            instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR");
    dt->GetPhysicalDeviceSurfaceCapabilities2KHR =
        (PFN_vkGetPhysicalDeviceSurfaceCapabilities2KHR)pa(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR");
    dt->GetPhysicalDeviceSurfaceFormats2KHR =
        (PFN_vkGetPhysicalDeviceSurfaceFormats2KHR)pa(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR");
    dt->GetPhysicalDeviceDisplayProperties2KHR =
        (PFN_vkGetPhysicalDeviceDisplayProperties2KHR)pa(instance, "vkGetPhysicalDeviceDisplayProperties2KHR");
    dt->GetPhysicalDeviceDisplayPlaneProperties2KHR = (PFN_vkGetPhysicalDeviceDisplayPlaneProperties2KHR)pa(
        instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR");
    dt->GetDisplayModeProperties2KHR =
        (PFN_vkGetDisplayModeProperties2KHR)pa(instance, "vkGetDisplayModeProperties2KHR");
    dt->GetDisplayPlaneCapabilities2KHR =
        (PFN_vkGetDisplayPlaneCapabilities2KHR)pa(instance, "vkGetDisplayPlaneCapabilities2KHR");
    dt->GetPhysicalDeviceFragmentShadingRatesKHR =
        (PFN_vkGetPhysicalDeviceFragmentShadingRatesKHR)pa(instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR");
    dt->GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR =
        (PFN_vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR)pa(
            instance, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR");
    dt->GetPhysicalDeviceCooperativeMatrixPropertiesKHR = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR)pa(
        instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR");
    dt->GetPhysicalDeviceCalibrateableTimeDomainsKHR = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsKHR)pa(
        instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR");
    dt->CreateDebugReportCallbackEXT =
        (PFN_vkCreateDebugReportCallbackEXT)pa(instance, "vkCreateDebugReportCallbackEXT");
    dt->DestroyDebugReportCallbackEXT =
        (PFN_vkDestroyDebugReportCallbackEXT)pa(instance, "vkDestroyDebugReportCallbackEXT");
    dt->DebugReportMessageEXT = (PFN_vkDebugReportMessageEXT)pa(instance, "vkDebugReportMessageEXT");
#ifdef VK_USE_PLATFORM_GGP
    dt->CreateStreamDescriptorSurfaceGGP =
        (PFN_vkCreateStreamDescriptorSurfaceGGP)pa(instance, "vkCreateStreamDescriptorSurfaceGGP");
#endif  // VK_USE_PLATFORM_GGP
    dt->GetPhysicalDeviceExternalImageFormatPropertiesNV = (PFN_vkGetPhysicalDeviceExternalImageFormatPropertiesNV)pa(
        instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV");
#ifdef VK_USE_PLATFORM_VI_NN
    dt->CreateViSurfaceNN = (PFN_vkCreateViSurfaceNN)pa(instance, "vkCreateViSurfaceNN");
#endif  // VK_USE_PLATFORM_VI_NN
    dt->ReleaseDisplayEXT = (PFN_vkReleaseDisplayEXT)pa(instance, "vkReleaseDisplayEXT");
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    dt->AcquireXlibDisplayEXT = (PFN_vkAcquireXlibDisplayEXT)pa(instance, "vkAcquireXlibDisplayEXT");
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
    dt->GetRandROutputDisplayEXT = (PFN_vkGetRandROutputDisplayEXT)pa(instance, "vkGetRandROutputDisplayEXT");
#endif  // VK_USE_PLATFORM_XLIB_XRANDR_EXT
    dt->GetPhysicalDeviceSurfaceCapabilities2EXT =
        (PFN_vkGetPhysicalDeviceSurfaceCapabilities2EXT)pa(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT");
#ifdef VK_USE_PLATFORM_IOS_MVK
    dt->CreateIOSSurfaceMVK = (PFN_vkCreateIOSSurfaceMVK)pa(instance, "vkCreateIOSSurfaceMVK");
#endif  // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    dt->CreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)pa(instance, "vkCreateMacOSSurfaceMVK");
#endif  // VK_USE_PLATFORM_MACOS_MVK
    dt->CreateDebugUtilsMessengerEXT =
        (PFN_vkCreateDebugUtilsMessengerEXT)pa(instance, "vkCreateDebugUtilsMessengerEXT");
    dt->DestroyDebugUtilsMessengerEXT =
        (PFN_vkDestroyDebugUtilsMessengerEXT)pa(instance, "vkDestroyDebugUtilsMessengerEXT");
    dt->SubmitDebugUtilsMessageEXT = (PFN_vkSubmitDebugUtilsMessageEXT)pa(instance, "vkSubmitDebugUtilsMessageEXT");
    dt->GetPhysicalDeviceMultisamplePropertiesEXT =
        (PFN_vkGetPhysicalDeviceMultisamplePropertiesEXT)pa(instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT");
    dt->GetPhysicalDeviceCalibrateableTimeDomainsEXT = (PFN_vkGetPhysicalDeviceCalibrateableTimeDomainsEXT)pa(
        instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsEXT");
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->CreateImagePipeSurfaceFUCHSIA =
        (PFN_vkCreateImagePipeSurfaceFUCHSIA)pa(instance, "vkCreateImagePipeSurfaceFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
    dt->CreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)pa(instance, "vkCreateMetalSurfaceEXT");
#endif  // VK_USE_PLATFORM_METAL_EXT
    dt->GetPhysicalDeviceToolPropertiesEXT =
        (PFN_vkGetPhysicalDeviceToolPropertiesEXT)pa(instance, "vkGetPhysicalDeviceToolPropertiesEXT");
    dt->GetPhysicalDeviceCooperativeMatrixPropertiesNV = (PFN_vkGetPhysicalDeviceCooperativeMatrixPropertiesNV)pa(
        instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV");
    dt->GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV =
        (PFN_vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV)pa(
            instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetPhysicalDeviceSurfacePresentModes2EXT =
        (PFN_vkGetPhysicalDeviceSurfacePresentModes2EXT)pa(instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->CreateHeadlessSurfaceEXT = (PFN_vkCreateHeadlessSurfaceEXT)pa(instance, "vkCreateHeadlessSurfaceEXT");
    dt->AcquireDrmDisplayEXT = (PFN_vkAcquireDrmDisplayEXT)pa(instance, "vkAcquireDrmDisplayEXT");
    dt->GetDrmDisplayEXT = (PFN_vkGetDrmDisplayEXT)pa(instance, "vkGetDrmDisplayEXT");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->AcquireWinrtDisplayNV = (PFN_vkAcquireWinrtDisplayNV)pa(instance, "vkAcquireWinrtDisplayNV");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetWinrtDisplayNV = (PFN_vkGetWinrtDisplayNV)pa(instance, "vkGetWinrtDisplayNV");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    dt->CreateDirectFBSurfaceEXT = (PFN_vkCreateDirectFBSurfaceEXT)pa(instance, "vkCreateDirectFBSurfaceEXT");
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    dt->GetPhysicalDeviceDirectFBPresentationSupportEXT = (PFN_vkGetPhysicalDeviceDirectFBPresentationSupportEXT)pa(
        instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT");
#endif  // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    dt->CreateScreenSurfaceQNX = (PFN_vkCreateScreenSurfaceQNX)pa(instance, "vkCreateScreenSurfaceQNX");
#endif  // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    dt->GetPhysicalDeviceScreenPresentationSupportQNX = (PFN_vkGetPhysicalDeviceScreenPresentationSupportQNX)pa(
        instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX");
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    dt->GetPhysicalDeviceOpticalFlowImageFormatsNV =
        (PFN_vkGetPhysicalDeviceOpticalFlowImageFormatsNV)pa(instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV");
};

void InitDeviceDispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr pa, DeviceDispatchTable *dt) {
    dt->GetDeviceProcAddr = (PFN_vkGetDeviceProcAddr)pa(device, "vkGetDeviceProcAddr");
    dt->DestroyDevice = (PFN_vkDestroyDevice)pa(device, "vkDestroyDevice");
    dt->GetDeviceQueue = (PFN_vkGetDeviceQueue)pa(device, "vkGetDeviceQueue");
    dt->QueueSubmit = (PFN_vkQueueSubmit)pa(device, "vkQueueSubmit");
    dt->QueueWaitIdle = (PFN_vkQueueWaitIdle)pa(device, "vkQueueWaitIdle");
    dt->DeviceWaitIdle = (PFN_vkDeviceWaitIdle)pa(device, "vkDeviceWaitIdle");
    dt->AllocateMemory = (PFN_vkAllocateMemory)pa(device, "vkAllocateMemory");
    dt->FreeMemory = (PFN_vkFreeMemory)pa(device, "vkFreeMemory");
    dt->MapMemory = (PFN_vkMapMemory)pa(device, "vkMapMemory");
    dt->UnmapMemory = (PFN_vkUnmapMemory)pa(device, "vkUnmapMemory");
    dt->FlushMappedMemoryRanges = (PFN_vkFlushMappedMemoryRanges)pa(device, "vkFlushMappedMemoryRanges");
    dt->InvalidateMappedMemoryRanges = (PFN_vkInvalidateMappedMemoryRanges)pa(device, "vkInvalidateMappedMemoryRanges");
    dt->GetDeviceMemoryCommitment = (PFN_vkGetDeviceMemoryCommitment)pa(device, "vkGetDeviceMemoryCommitment");
    dt->BindBufferMemory = (PFN_vkBindBufferMemory)pa(device, "vkBindBufferMemory");
    dt->BindImageMemory = (PFN_vkBindImageMemory)pa(device, "vkBindImageMemory");
    dt->GetBufferMemoryRequirements = (PFN_vkGetBufferMemoryRequirements)pa(device, "vkGetBufferMemoryRequirements");
    dt->GetImageMemoryRequirements = (PFN_vkGetImageMemoryRequirements)pa(device, "vkGetImageMemoryRequirements");
    dt->GetImageSparseMemoryRequirements =
        (PFN_vkGetImageSparseMemoryRequirements)pa(device, "vkGetImageSparseMemoryRequirements");
    dt->QueueBindSparse = (PFN_vkQueueBindSparse)pa(device, "vkQueueBindSparse");
    dt->CreateFence = (PFN_vkCreateFence)pa(device, "vkCreateFence");
    dt->DestroyFence = (PFN_vkDestroyFence)pa(device, "vkDestroyFence");
    dt->ResetFences = (PFN_vkResetFences)pa(device, "vkResetFences");
    dt->GetFenceStatus = (PFN_vkGetFenceStatus)pa(device, "vkGetFenceStatus");
    dt->WaitForFences = (PFN_vkWaitForFences)pa(device, "vkWaitForFences");
    dt->CreateSemaphore = (PFN_vkCreateSemaphore)pa(device, "vkCreateSemaphore");
    dt->DestroySemaphore = (PFN_vkDestroySemaphore)pa(device, "vkDestroySemaphore");
    dt->CreateEvent = (PFN_vkCreateEvent)pa(device, "vkCreateEvent");
    dt->DestroyEvent = (PFN_vkDestroyEvent)pa(device, "vkDestroyEvent");
    dt->GetEventStatus = (PFN_vkGetEventStatus)pa(device, "vkGetEventStatus");
    dt->SetEvent = (PFN_vkSetEvent)pa(device, "vkSetEvent");
    dt->ResetEvent = (PFN_vkResetEvent)pa(device, "vkResetEvent");
    dt->CreateQueryPool = (PFN_vkCreateQueryPool)pa(device, "vkCreateQueryPool");
    dt->DestroyQueryPool = (PFN_vkDestroyQueryPool)pa(device, "vkDestroyQueryPool");
    dt->GetQueryPoolResults = (PFN_vkGetQueryPoolResults)pa(device, "vkGetQueryPoolResults");
    dt->CreateBuffer = (PFN_vkCreateBuffer)pa(device, "vkCreateBuffer");
    dt->DestroyBuffer = (PFN_vkDestroyBuffer)pa(device, "vkDestroyBuffer");
    dt->CreateBufferView = (PFN_vkCreateBufferView)pa(device, "vkCreateBufferView");
    dt->DestroyBufferView = (PFN_vkDestroyBufferView)pa(device, "vkDestroyBufferView");
    dt->CreateImage = (PFN_vkCreateImage)pa(device, "vkCreateImage");
    dt->DestroyImage = (PFN_vkDestroyImage)pa(device, "vkDestroyImage");
    dt->GetImageSubresourceLayout = (PFN_vkGetImageSubresourceLayout)pa(device, "vkGetImageSubresourceLayout");
    dt->CreateImageView = (PFN_vkCreateImageView)pa(device, "vkCreateImageView");
    dt->DestroyImageView = (PFN_vkDestroyImageView)pa(device, "vkDestroyImageView");
    dt->CreateShaderModule = (PFN_vkCreateShaderModule)pa(device, "vkCreateShaderModule");
    dt->DestroyShaderModule = (PFN_vkDestroyShaderModule)pa(device, "vkDestroyShaderModule");
    dt->CreatePipelineCache = (PFN_vkCreatePipelineCache)pa(device, "vkCreatePipelineCache");
    dt->DestroyPipelineCache = (PFN_vkDestroyPipelineCache)pa(device, "vkDestroyPipelineCache");
    dt->GetPipelineCacheData = (PFN_vkGetPipelineCacheData)pa(device, "vkGetPipelineCacheData");
    dt->MergePipelineCaches = (PFN_vkMergePipelineCaches)pa(device, "vkMergePipelineCaches");
    dt->CreateGraphicsPipelines = (PFN_vkCreateGraphicsPipelines)pa(device, "vkCreateGraphicsPipelines");
    dt->CreateComputePipelines = (PFN_vkCreateComputePipelines)pa(device, "vkCreateComputePipelines");
    dt->DestroyPipeline = (PFN_vkDestroyPipeline)pa(device, "vkDestroyPipeline");
    dt->CreatePipelineLayout = (PFN_vkCreatePipelineLayout)pa(device, "vkCreatePipelineLayout");
    dt->DestroyPipelineLayout = (PFN_vkDestroyPipelineLayout)pa(device, "vkDestroyPipelineLayout");
    dt->CreateSampler = (PFN_vkCreateSampler)pa(device, "vkCreateSampler");
    dt->DestroySampler = (PFN_vkDestroySampler)pa(device, "vkDestroySampler");
    dt->CreateDescriptorSetLayout = (PFN_vkCreateDescriptorSetLayout)pa(device, "vkCreateDescriptorSetLayout");
    dt->DestroyDescriptorSetLayout = (PFN_vkDestroyDescriptorSetLayout)pa(device, "vkDestroyDescriptorSetLayout");
    dt->CreateDescriptorPool = (PFN_vkCreateDescriptorPool)pa(device, "vkCreateDescriptorPool");
    dt->DestroyDescriptorPool = (PFN_vkDestroyDescriptorPool)pa(device, "vkDestroyDescriptorPool");
    dt->ResetDescriptorPool = (PFN_vkResetDescriptorPool)pa(device, "vkResetDescriptorPool");
    dt->AllocateDescriptorSets = (PFN_vkAllocateDescriptorSets)pa(device, "vkAllocateDescriptorSets");
    dt->FreeDescriptorSets = (PFN_vkFreeDescriptorSets)pa(device, "vkFreeDescriptorSets");
    dt->UpdateDescriptorSets = (PFN_vkUpdateDescriptorSets)pa(device, "vkUpdateDescriptorSets");
    dt->CreateFramebuffer = (PFN_vkCreateFramebuffer)pa(device, "vkCreateFramebuffer");
    dt->DestroyFramebuffer = (PFN_vkDestroyFramebuffer)pa(device, "vkDestroyFramebuffer");
    dt->CreateRenderPass = (PFN_vkCreateRenderPass)pa(device, "vkCreateRenderPass");
    dt->DestroyRenderPass = (PFN_vkDestroyRenderPass)pa(device, "vkDestroyRenderPass");
    dt->GetRenderAreaGranularity = (PFN_vkGetRenderAreaGranularity)pa(device, "vkGetRenderAreaGranularity");
    dt->CreateCommandPool = (PFN_vkCreateCommandPool)pa(device, "vkCreateCommandPool");
    dt->DestroyCommandPool = (PFN_vkDestroyCommandPool)pa(device, "vkDestroyCommandPool");
    dt->ResetCommandPool = (PFN_vkResetCommandPool)pa(device, "vkResetCommandPool");
    dt->AllocateCommandBuffers = (PFN_vkAllocateCommandBuffers)pa(device, "vkAllocateCommandBuffers");
    dt->FreeCommandBuffers = (PFN_vkFreeCommandBuffers)pa(device, "vkFreeCommandBuffers");
    dt->BeginCommandBuffer = (PFN_vkBeginCommandBuffer)pa(device, "vkBeginCommandBuffer");
    dt->EndCommandBuffer = (PFN_vkEndCommandBuffer)pa(device, "vkEndCommandBuffer");
    dt->ResetCommandBuffer = (PFN_vkResetCommandBuffer)pa(device, "vkResetCommandBuffer");
    dt->CmdBindPipeline = (PFN_vkCmdBindPipeline)pa(device, "vkCmdBindPipeline");
    dt->CmdSetViewport = (PFN_vkCmdSetViewport)pa(device, "vkCmdSetViewport");
    dt->CmdSetScissor = (PFN_vkCmdSetScissor)pa(device, "vkCmdSetScissor");
    dt->CmdSetLineWidth = (PFN_vkCmdSetLineWidth)pa(device, "vkCmdSetLineWidth");
    dt->CmdSetDepthBias = (PFN_vkCmdSetDepthBias)pa(device, "vkCmdSetDepthBias");
    dt->CmdSetBlendConstants = (PFN_vkCmdSetBlendConstants)pa(device, "vkCmdSetBlendConstants");
    dt->CmdSetDepthBounds = (PFN_vkCmdSetDepthBounds)pa(device, "vkCmdSetDepthBounds");
    dt->CmdSetStencilCompareMask = (PFN_vkCmdSetStencilCompareMask)pa(device, "vkCmdSetStencilCompareMask");
    dt->CmdSetStencilWriteMask = (PFN_vkCmdSetStencilWriteMask)pa(device, "vkCmdSetStencilWriteMask");
    dt->CmdSetStencilReference = (PFN_vkCmdSetStencilReference)pa(device, "vkCmdSetStencilReference");
    dt->CmdBindDescriptorSets = (PFN_vkCmdBindDescriptorSets)pa(device, "vkCmdBindDescriptorSets");
    dt->CmdBindIndexBuffer = (PFN_vkCmdBindIndexBuffer)pa(device, "vkCmdBindIndexBuffer");
    dt->CmdBindVertexBuffers = (PFN_vkCmdBindVertexBuffers)pa(device, "vkCmdBindVertexBuffers");
    dt->CmdDraw = (PFN_vkCmdDraw)pa(device, "vkCmdDraw");
    dt->CmdDrawIndexed = (PFN_vkCmdDrawIndexed)pa(device, "vkCmdDrawIndexed");
    dt->CmdDrawIndirect = (PFN_vkCmdDrawIndirect)pa(device, "vkCmdDrawIndirect");
    dt->CmdDrawIndexedIndirect = (PFN_vkCmdDrawIndexedIndirect)pa(device, "vkCmdDrawIndexedIndirect");
    dt->CmdDispatch = (PFN_vkCmdDispatch)pa(device, "vkCmdDispatch");
    dt->CmdDispatchIndirect = (PFN_vkCmdDispatchIndirect)pa(device, "vkCmdDispatchIndirect");
    dt->CmdCopyBuffer = (PFN_vkCmdCopyBuffer)pa(device, "vkCmdCopyBuffer");
    dt->CmdCopyImage = (PFN_vkCmdCopyImage)pa(device, "vkCmdCopyImage");
    dt->CmdBlitImage = (PFN_vkCmdBlitImage)pa(device, "vkCmdBlitImage");
    dt->CmdCopyBufferToImage = (PFN_vkCmdCopyBufferToImage)pa(device, "vkCmdCopyBufferToImage");
    dt->CmdCopyImageToBuffer = (PFN_vkCmdCopyImageToBuffer)pa(device, "vkCmdCopyImageToBuffer");
    dt->CmdUpdateBuffer = (PFN_vkCmdUpdateBuffer)pa(device, "vkCmdUpdateBuffer");
    dt->CmdFillBuffer = (PFN_vkCmdFillBuffer)pa(device, "vkCmdFillBuffer");
    dt->CmdClearColorImage = (PFN_vkCmdClearColorImage)pa(device, "vkCmdClearColorImage");
    dt->CmdClearDepthStencilImage = (PFN_vkCmdClearDepthStencilImage)pa(device, "vkCmdClearDepthStencilImage");
    dt->CmdClearAttachments = (PFN_vkCmdClearAttachments)pa(device, "vkCmdClearAttachments");
    dt->CmdResolveImage = (PFN_vkCmdResolveImage)pa(device, "vkCmdResolveImage");
    dt->CmdSetEvent = (PFN_vkCmdSetEvent)pa(device, "vkCmdSetEvent");
    dt->CmdResetEvent = (PFN_vkCmdResetEvent)pa(device, "vkCmdResetEvent");
    dt->CmdWaitEvents = (PFN_vkCmdWaitEvents)pa(device, "vkCmdWaitEvents");
    dt->CmdPipelineBarrier = (PFN_vkCmdPipelineBarrier)pa(device, "vkCmdPipelineBarrier");
    dt->CmdBeginQuery = (PFN_vkCmdBeginQuery)pa(device, "vkCmdBeginQuery");
    dt->CmdEndQuery = (PFN_vkCmdEndQuery)pa(device, "vkCmdEndQuery");
    dt->CmdResetQueryPool = (PFN_vkCmdResetQueryPool)pa(device, "vkCmdResetQueryPool");
    dt->CmdWriteTimestamp = (PFN_vkCmdWriteTimestamp)pa(device, "vkCmdWriteTimestamp");
    dt->CmdCopyQueryPoolResults = (PFN_vkCmdCopyQueryPoolResults)pa(device, "vkCmdCopyQueryPoolResults");
    dt->CmdPushConstants = (PFN_vkCmdPushConstants)pa(device, "vkCmdPushConstants");
    dt->CmdBeginRenderPass = (PFN_vkCmdBeginRenderPass)pa(device, "vkCmdBeginRenderPass");
    dt->CmdNextSubpass = (PFN_vkCmdNextSubpass)pa(device, "vkCmdNextSubpass");
    dt->CmdEndRenderPass = (PFN_vkCmdEndRenderPass)pa(device, "vkCmdEndRenderPass");
    dt->CmdExecuteCommands = (PFN_vkCmdExecuteCommands)pa(device, "vkCmdExecuteCommands");
    dt->BindBufferMemory2 = (PFN_vkBindBufferMemory2)pa(device, "vkBindBufferMemory2");
    dt->BindImageMemory2 = (PFN_vkBindImageMemory2)pa(device, "vkBindImageMemory2");
    dt->GetDeviceGroupPeerMemoryFeatures =
        (PFN_vkGetDeviceGroupPeerMemoryFeatures)pa(device, "vkGetDeviceGroupPeerMemoryFeatures");
    dt->CmdSetDeviceMask = (PFN_vkCmdSetDeviceMask)pa(device, "vkCmdSetDeviceMask");
    dt->CmdDispatchBase = (PFN_vkCmdDispatchBase)pa(device, "vkCmdDispatchBase");
    dt->GetImageMemoryRequirements2 = (PFN_vkGetImageMemoryRequirements2)pa(device, "vkGetImageMemoryRequirements2");
    dt->GetBufferMemoryRequirements2 = (PFN_vkGetBufferMemoryRequirements2)pa(device, "vkGetBufferMemoryRequirements2");
    dt->GetImageSparseMemoryRequirements2 =
        (PFN_vkGetImageSparseMemoryRequirements2)pa(device, "vkGetImageSparseMemoryRequirements2");
    dt->TrimCommandPool = (PFN_vkTrimCommandPool)pa(device, "vkTrimCommandPool");
    dt->GetDeviceQueue2 = (PFN_vkGetDeviceQueue2)pa(device, "vkGetDeviceQueue2");
    dt->CreateSamplerYcbcrConversion = (PFN_vkCreateSamplerYcbcrConversion)pa(device, "vkCreateSamplerYcbcrConversion");
    dt->DestroySamplerYcbcrConversion =
        (PFN_vkDestroySamplerYcbcrConversion)pa(device, "vkDestroySamplerYcbcrConversion");
    dt->CreateDescriptorUpdateTemplate =
        (PFN_vkCreateDescriptorUpdateTemplate)pa(device, "vkCreateDescriptorUpdateTemplate");
    dt->DestroyDescriptorUpdateTemplate =
        (PFN_vkDestroyDescriptorUpdateTemplate)pa(device, "vkDestroyDescriptorUpdateTemplate");
    dt->UpdateDescriptorSetWithTemplate =
        (PFN_vkUpdateDescriptorSetWithTemplate)pa(device, "vkUpdateDescriptorSetWithTemplate");
    dt->GetDescriptorSetLayoutSupport =
        (PFN_vkGetDescriptorSetLayoutSupport)pa(device, "vkGetDescriptorSetLayoutSupport");
    dt->CmdDrawIndirectCount = (PFN_vkCmdDrawIndirectCount)pa(device, "vkCmdDrawIndirectCount");
    dt->CmdDrawIndexedIndirectCount = (PFN_vkCmdDrawIndexedIndirectCount)pa(device, "vkCmdDrawIndexedIndirectCount");
    dt->CreateRenderPass2 = (PFN_vkCreateRenderPass2)pa(device, "vkCreateRenderPass2");
    dt->CmdBeginRenderPass2 = (PFN_vkCmdBeginRenderPass2)pa(device, "vkCmdBeginRenderPass2");
    dt->CmdNextSubpass2 = (PFN_vkCmdNextSubpass2)pa(device, "vkCmdNextSubpass2");
    dt->CmdEndRenderPass2 = (PFN_vkCmdEndRenderPass2)pa(device, "vkCmdEndRenderPass2");
    dt->ResetQueryPool = (PFN_vkResetQueryPool)pa(device, "vkResetQueryPool");
    dt->GetSemaphoreCounterValue = (PFN_vkGetSemaphoreCounterValue)pa(device, "vkGetSemaphoreCounterValue");
    dt->WaitSemaphores = (PFN_vkWaitSemaphores)pa(device, "vkWaitSemaphores");
    dt->SignalSemaphore = (PFN_vkSignalSemaphore)pa(device, "vkSignalSemaphore");
    dt->GetBufferDeviceAddress = (PFN_vkGetBufferDeviceAddress)pa(device, "vkGetBufferDeviceAddress");
    dt->GetBufferOpaqueCaptureAddress =
        (PFN_vkGetBufferOpaqueCaptureAddress)pa(device, "vkGetBufferOpaqueCaptureAddress");
    dt->GetDeviceMemoryOpaqueCaptureAddress =
        (PFN_vkGetDeviceMemoryOpaqueCaptureAddress)pa(device, "vkGetDeviceMemoryOpaqueCaptureAddress");
    dt->CreatePrivateDataSlot = (PFN_vkCreatePrivateDataSlot)pa(device, "vkCreatePrivateDataSlot");
    dt->DestroyPrivateDataSlot = (PFN_vkDestroyPrivateDataSlot)pa(device, "vkDestroyPrivateDataSlot");
    dt->SetPrivateData = (PFN_vkSetPrivateData)pa(device, "vkSetPrivateData");
    dt->GetPrivateData = (PFN_vkGetPrivateData)pa(device, "vkGetPrivateData");
    dt->CmdSetEvent2 = (PFN_vkCmdSetEvent2)pa(device, "vkCmdSetEvent2");
    dt->CmdResetEvent2 = (PFN_vkCmdResetEvent2)pa(device, "vkCmdResetEvent2");
    dt->CmdWaitEvents2 = (PFN_vkCmdWaitEvents2)pa(device, "vkCmdWaitEvents2");
    dt->CmdPipelineBarrier2 = (PFN_vkCmdPipelineBarrier2)pa(device, "vkCmdPipelineBarrier2");
    dt->CmdWriteTimestamp2 = (PFN_vkCmdWriteTimestamp2)pa(device, "vkCmdWriteTimestamp2");
    dt->QueueSubmit2 = (PFN_vkQueueSubmit2)pa(device, "vkQueueSubmit2");
    dt->CmdCopyBuffer2 = (PFN_vkCmdCopyBuffer2)pa(device, "vkCmdCopyBuffer2");
    dt->CmdCopyImage2 = (PFN_vkCmdCopyImage2)pa(device, "vkCmdCopyImage2");
    dt->CmdCopyBufferToImage2 = (PFN_vkCmdCopyBufferToImage2)pa(device, "vkCmdCopyBufferToImage2");
    dt->CmdCopyImageToBuffer2 = (PFN_vkCmdCopyImageToBuffer2)pa(device, "vkCmdCopyImageToBuffer2");
    dt->CmdBlitImage2 = (PFN_vkCmdBlitImage2)pa(device, "vkCmdBlitImage2");
    dt->CmdResolveImage2 = (PFN_vkCmdResolveImage2)pa(device, "vkCmdResolveImage2");
    dt->CmdBeginRendering = (PFN_vkCmdBeginRendering)pa(device, "vkCmdBeginRendering");
    dt->CmdEndRendering = (PFN_vkCmdEndRendering)pa(device, "vkCmdEndRendering");
    dt->CmdSetCullMode = (PFN_vkCmdSetCullMode)pa(device, "vkCmdSetCullMode");
    dt->CmdSetFrontFace = (PFN_vkCmdSetFrontFace)pa(device, "vkCmdSetFrontFace");
    dt->CmdSetPrimitiveTopology = (PFN_vkCmdSetPrimitiveTopology)pa(device, "vkCmdSetPrimitiveTopology");
    dt->CmdSetViewportWithCount = (PFN_vkCmdSetViewportWithCount)pa(device, "vkCmdSetViewportWithCount");
    dt->CmdSetScissorWithCount = (PFN_vkCmdSetScissorWithCount)pa(device, "vkCmdSetScissorWithCount");
    dt->CmdBindVertexBuffers2 = (PFN_vkCmdBindVertexBuffers2)pa(device, "vkCmdBindVertexBuffers2");
    dt->CmdSetDepthTestEnable = (PFN_vkCmdSetDepthTestEnable)pa(device, "vkCmdSetDepthTestEnable");
    dt->CmdSetDepthWriteEnable = (PFN_vkCmdSetDepthWriteEnable)pa(device, "vkCmdSetDepthWriteEnable");
    dt->CmdSetDepthCompareOp = (PFN_vkCmdSetDepthCompareOp)pa(device, "vkCmdSetDepthCompareOp");
    dt->CmdSetDepthBoundsTestEnable = (PFN_vkCmdSetDepthBoundsTestEnable)pa(device, "vkCmdSetDepthBoundsTestEnable");
    dt->CmdSetStencilTestEnable = (PFN_vkCmdSetStencilTestEnable)pa(device, "vkCmdSetStencilTestEnable");
    dt->CmdSetStencilOp = (PFN_vkCmdSetStencilOp)pa(device, "vkCmdSetStencilOp");
    dt->CmdSetRasterizerDiscardEnable =
        (PFN_vkCmdSetRasterizerDiscardEnable)pa(device, "vkCmdSetRasterizerDiscardEnable");
    dt->CmdSetDepthBiasEnable = (PFN_vkCmdSetDepthBiasEnable)pa(device, "vkCmdSetDepthBiasEnable");
    dt->CmdSetPrimitiveRestartEnable = (PFN_vkCmdSetPrimitiveRestartEnable)pa(device, "vkCmdSetPrimitiveRestartEnable");
    dt->GetDeviceBufferMemoryRequirements =
        (PFN_vkGetDeviceBufferMemoryRequirements)pa(device, "vkGetDeviceBufferMemoryRequirements");
    dt->GetDeviceImageMemoryRequirements =
        (PFN_vkGetDeviceImageMemoryRequirements)pa(device, "vkGetDeviceImageMemoryRequirements");
    dt->GetDeviceImageSparseMemoryRequirements =
        (PFN_vkGetDeviceImageSparseMemoryRequirements)pa(device, "vkGetDeviceImageSparseMemoryRequirements");
    dt->CreateSwapchainKHR = (PFN_vkCreateSwapchainKHR)pa(device, "vkCreateSwapchainKHR");
    dt->DestroySwapchainKHR = (PFN_vkDestroySwapchainKHR)pa(device, "vkDestroySwapchainKHR");
    dt->GetSwapchainImagesKHR = (PFN_vkGetSwapchainImagesKHR)pa(device, "vkGetSwapchainImagesKHR");
    dt->AcquireNextImageKHR = (PFN_vkAcquireNextImageKHR)pa(device, "vkAcquireNextImageKHR");
    dt->QueuePresentKHR = (PFN_vkQueuePresentKHR)pa(device, "vkQueuePresentKHR");
    dt->GetDeviceGroupPresentCapabilitiesKHR =
        (PFN_vkGetDeviceGroupPresentCapabilitiesKHR)pa(device, "vkGetDeviceGroupPresentCapabilitiesKHR");
    dt->GetDeviceGroupSurfacePresentModesKHR =
        (PFN_vkGetDeviceGroupSurfacePresentModesKHR)pa(device, "vkGetDeviceGroupSurfacePresentModesKHR");
    dt->AcquireNextImage2KHR = (PFN_vkAcquireNextImage2KHR)pa(device, "vkAcquireNextImage2KHR");
    dt->CreateSharedSwapchainsKHR = (PFN_vkCreateSharedSwapchainsKHR)pa(device, "vkCreateSharedSwapchainsKHR");
    dt->CreateVideoSessionKHR = (PFN_vkCreateVideoSessionKHR)pa(device, "vkCreateVideoSessionKHR");
    dt->DestroyVideoSessionKHR = (PFN_vkDestroyVideoSessionKHR)pa(device, "vkDestroyVideoSessionKHR");
    dt->GetVideoSessionMemoryRequirementsKHR =
        (PFN_vkGetVideoSessionMemoryRequirementsKHR)pa(device, "vkGetVideoSessionMemoryRequirementsKHR");
    dt->BindVideoSessionMemoryKHR = (PFN_vkBindVideoSessionMemoryKHR)pa(device, "vkBindVideoSessionMemoryKHR");
    dt->CreateVideoSessionParametersKHR =
        (PFN_vkCreateVideoSessionParametersKHR)pa(device, "vkCreateVideoSessionParametersKHR");
    dt->UpdateVideoSessionParametersKHR =
        (PFN_vkUpdateVideoSessionParametersKHR)pa(device, "vkUpdateVideoSessionParametersKHR");
    dt->DestroyVideoSessionParametersKHR =
        (PFN_vkDestroyVideoSessionParametersKHR)pa(device, "vkDestroyVideoSessionParametersKHR");
    dt->CmdBeginVideoCodingKHR = (PFN_vkCmdBeginVideoCodingKHR)pa(device, "vkCmdBeginVideoCodingKHR");
    dt->CmdEndVideoCodingKHR = (PFN_vkCmdEndVideoCodingKHR)pa(device, "vkCmdEndVideoCodingKHR");
    dt->CmdControlVideoCodingKHR = (PFN_vkCmdControlVideoCodingKHR)pa(device, "vkCmdControlVideoCodingKHR");
    dt->CmdDecodeVideoKHR = (PFN_vkCmdDecodeVideoKHR)pa(device, "vkCmdDecodeVideoKHR");
    dt->CmdBeginRenderingKHR = (PFN_vkCmdBeginRenderingKHR)pa(device, "vkCmdBeginRenderingKHR");
    dt->CmdEndRenderingKHR = (PFN_vkCmdEndRenderingKHR)pa(device, "vkCmdEndRenderingKHR");
    dt->GetDeviceGroupPeerMemoryFeaturesKHR =
        (PFN_vkGetDeviceGroupPeerMemoryFeaturesKHR)pa(device, "vkGetDeviceGroupPeerMemoryFeaturesKHR");
    dt->CmdSetDeviceMaskKHR = (PFN_vkCmdSetDeviceMaskKHR)pa(device, "vkCmdSetDeviceMaskKHR");
    dt->CmdDispatchBaseKHR = (PFN_vkCmdDispatchBaseKHR)pa(device, "vkCmdDispatchBaseKHR");
    dt->TrimCommandPoolKHR = (PFN_vkTrimCommandPoolKHR)pa(device, "vkTrimCommandPoolKHR");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetMemoryWin32HandleKHR = (PFN_vkGetMemoryWin32HandleKHR)pa(device, "vkGetMemoryWin32HandleKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetMemoryWin32HandlePropertiesKHR =
        (PFN_vkGetMemoryWin32HandlePropertiesKHR)pa(device, "vkGetMemoryWin32HandlePropertiesKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->GetMemoryFdKHR = (PFN_vkGetMemoryFdKHR)pa(device, "vkGetMemoryFdKHR");
    dt->GetMemoryFdPropertiesKHR = (PFN_vkGetMemoryFdPropertiesKHR)pa(device, "vkGetMemoryFdPropertiesKHR");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->ImportSemaphoreWin32HandleKHR =
        (PFN_vkImportSemaphoreWin32HandleKHR)pa(device, "vkImportSemaphoreWin32HandleKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetSemaphoreWin32HandleKHR = (PFN_vkGetSemaphoreWin32HandleKHR)pa(device, "vkGetSemaphoreWin32HandleKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->ImportSemaphoreFdKHR = (PFN_vkImportSemaphoreFdKHR)pa(device, "vkImportSemaphoreFdKHR");
    dt->GetSemaphoreFdKHR = (PFN_vkGetSemaphoreFdKHR)pa(device, "vkGetSemaphoreFdKHR");
    dt->CmdPushDescriptorSetKHR = (PFN_vkCmdPushDescriptorSetKHR)pa(device, "vkCmdPushDescriptorSetKHR");
    dt->CmdPushDescriptorSetWithTemplateKHR =
        (PFN_vkCmdPushDescriptorSetWithTemplateKHR)pa(device, "vkCmdPushDescriptorSetWithTemplateKHR");
    dt->CreateDescriptorUpdateTemplateKHR =
        (PFN_vkCreateDescriptorUpdateTemplateKHR)pa(device, "vkCreateDescriptorUpdateTemplateKHR");
    dt->DestroyDescriptorUpdateTemplateKHR =
        (PFN_vkDestroyDescriptorUpdateTemplateKHR)pa(device, "vkDestroyDescriptorUpdateTemplateKHR");
    dt->UpdateDescriptorSetWithTemplateKHR =
        (PFN_vkUpdateDescriptorSetWithTemplateKHR)pa(device, "vkUpdateDescriptorSetWithTemplateKHR");
    dt->CreateRenderPass2KHR = (PFN_vkCreateRenderPass2KHR)pa(device, "vkCreateRenderPass2KHR");
    dt->CmdBeginRenderPass2KHR = (PFN_vkCmdBeginRenderPass2KHR)pa(device, "vkCmdBeginRenderPass2KHR");
    dt->CmdNextSubpass2KHR = (PFN_vkCmdNextSubpass2KHR)pa(device, "vkCmdNextSubpass2KHR");
    dt->CmdEndRenderPass2KHR = (PFN_vkCmdEndRenderPass2KHR)pa(device, "vkCmdEndRenderPass2KHR");
    dt->GetSwapchainStatusKHR = (PFN_vkGetSwapchainStatusKHR)pa(device, "vkGetSwapchainStatusKHR");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->ImportFenceWin32HandleKHR = (PFN_vkImportFenceWin32HandleKHR)pa(device, "vkImportFenceWin32HandleKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetFenceWin32HandleKHR = (PFN_vkGetFenceWin32HandleKHR)pa(device, "vkGetFenceWin32HandleKHR");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->ImportFenceFdKHR = (PFN_vkImportFenceFdKHR)pa(device, "vkImportFenceFdKHR");
    dt->GetFenceFdKHR = (PFN_vkGetFenceFdKHR)pa(device, "vkGetFenceFdKHR");
    dt->AcquireProfilingLockKHR = (PFN_vkAcquireProfilingLockKHR)pa(device, "vkAcquireProfilingLockKHR");
    dt->ReleaseProfilingLockKHR = (PFN_vkReleaseProfilingLockKHR)pa(device, "vkReleaseProfilingLockKHR");
    dt->GetImageMemoryRequirements2KHR =
        (PFN_vkGetImageMemoryRequirements2KHR)pa(device, "vkGetImageMemoryRequirements2KHR");
    dt->GetBufferMemoryRequirements2KHR =
        (PFN_vkGetBufferMemoryRequirements2KHR)pa(device, "vkGetBufferMemoryRequirements2KHR");
    dt->GetImageSparseMemoryRequirements2KHR =
        (PFN_vkGetImageSparseMemoryRequirements2KHR)pa(device, "vkGetImageSparseMemoryRequirements2KHR");
    dt->CreateSamplerYcbcrConversionKHR =
        (PFN_vkCreateSamplerYcbcrConversionKHR)pa(device, "vkCreateSamplerYcbcrConversionKHR");
    dt->DestroySamplerYcbcrConversionKHR =
        (PFN_vkDestroySamplerYcbcrConversionKHR)pa(device, "vkDestroySamplerYcbcrConversionKHR");
    dt->BindBufferMemory2KHR = (PFN_vkBindBufferMemory2KHR)pa(device, "vkBindBufferMemory2KHR");
    dt->BindImageMemory2KHR = (PFN_vkBindImageMemory2KHR)pa(device, "vkBindImageMemory2KHR");
    dt->GetDescriptorSetLayoutSupportKHR =
        (PFN_vkGetDescriptorSetLayoutSupportKHR)pa(device, "vkGetDescriptorSetLayoutSupportKHR");
    dt->CmdDrawIndirectCountKHR = (PFN_vkCmdDrawIndirectCountKHR)pa(device, "vkCmdDrawIndirectCountKHR");
    dt->CmdDrawIndexedIndirectCountKHR =
        (PFN_vkCmdDrawIndexedIndirectCountKHR)pa(device, "vkCmdDrawIndexedIndirectCountKHR");
    dt->GetSemaphoreCounterValueKHR = (PFN_vkGetSemaphoreCounterValueKHR)pa(device, "vkGetSemaphoreCounterValueKHR");
    dt->WaitSemaphoresKHR = (PFN_vkWaitSemaphoresKHR)pa(device, "vkWaitSemaphoresKHR");
    dt->SignalSemaphoreKHR = (PFN_vkSignalSemaphoreKHR)pa(device, "vkSignalSemaphoreKHR");
    dt->CmdSetFragmentShadingRateKHR = (PFN_vkCmdSetFragmentShadingRateKHR)pa(device, "vkCmdSetFragmentShadingRateKHR");
    dt->CmdSetRenderingAttachmentLocationsKHR =
        (PFN_vkCmdSetRenderingAttachmentLocationsKHR)pa(device, "vkCmdSetRenderingAttachmentLocationsKHR");
    dt->CmdSetRenderingInputAttachmentIndicesKHR =
        (PFN_vkCmdSetRenderingInputAttachmentIndicesKHR)pa(device, "vkCmdSetRenderingInputAttachmentIndicesKHR");
    dt->WaitForPresentKHR = (PFN_vkWaitForPresentKHR)pa(device, "vkWaitForPresentKHR");
    dt->GetBufferDeviceAddressKHR = (PFN_vkGetBufferDeviceAddressKHR)pa(device, "vkGetBufferDeviceAddressKHR");
    dt->GetBufferOpaqueCaptureAddressKHR =
        (PFN_vkGetBufferOpaqueCaptureAddressKHR)pa(device, "vkGetBufferOpaqueCaptureAddressKHR");
    dt->GetDeviceMemoryOpaqueCaptureAddressKHR =
        (PFN_vkGetDeviceMemoryOpaqueCaptureAddressKHR)pa(device, "vkGetDeviceMemoryOpaqueCaptureAddressKHR");
    dt->CreateDeferredOperationKHR = (PFN_vkCreateDeferredOperationKHR)pa(device, "vkCreateDeferredOperationKHR");
    dt->DestroyDeferredOperationKHR = (PFN_vkDestroyDeferredOperationKHR)pa(device, "vkDestroyDeferredOperationKHR");
    dt->GetDeferredOperationMaxConcurrencyKHR =
        (PFN_vkGetDeferredOperationMaxConcurrencyKHR)pa(device, "vkGetDeferredOperationMaxConcurrencyKHR");
    dt->GetDeferredOperationResultKHR =
        (PFN_vkGetDeferredOperationResultKHR)pa(device, "vkGetDeferredOperationResultKHR");
    dt->DeferredOperationJoinKHR = (PFN_vkDeferredOperationJoinKHR)pa(device, "vkDeferredOperationJoinKHR");
    dt->GetPipelineExecutablePropertiesKHR =
        (PFN_vkGetPipelineExecutablePropertiesKHR)pa(device, "vkGetPipelineExecutablePropertiesKHR");
    dt->GetPipelineExecutableStatisticsKHR =
        (PFN_vkGetPipelineExecutableStatisticsKHR)pa(device, "vkGetPipelineExecutableStatisticsKHR");
    dt->GetPipelineExecutableInternalRepresentationsKHR = (PFN_vkGetPipelineExecutableInternalRepresentationsKHR)pa(
        device, "vkGetPipelineExecutableInternalRepresentationsKHR");
    dt->MapMemory2KHR = (PFN_vkMapMemory2KHR)pa(device, "vkMapMemory2KHR");
    dt->UnmapMemory2KHR = (PFN_vkUnmapMemory2KHR)pa(device, "vkUnmapMemory2KHR");
    dt->GetEncodedVideoSessionParametersKHR =
        (PFN_vkGetEncodedVideoSessionParametersKHR)pa(device, "vkGetEncodedVideoSessionParametersKHR");
    dt->CmdEncodeVideoKHR = (PFN_vkCmdEncodeVideoKHR)pa(device, "vkCmdEncodeVideoKHR");
    dt->CmdSetEvent2KHR = (PFN_vkCmdSetEvent2KHR)pa(device, "vkCmdSetEvent2KHR");
    dt->CmdResetEvent2KHR = (PFN_vkCmdResetEvent2KHR)pa(device, "vkCmdResetEvent2KHR");
    dt->CmdWaitEvents2KHR = (PFN_vkCmdWaitEvents2KHR)pa(device, "vkCmdWaitEvents2KHR");
    dt->CmdPipelineBarrier2KHR = (PFN_vkCmdPipelineBarrier2KHR)pa(device, "vkCmdPipelineBarrier2KHR");
    dt->CmdWriteTimestamp2KHR = (PFN_vkCmdWriteTimestamp2KHR)pa(device, "vkCmdWriteTimestamp2KHR");
    dt->QueueSubmit2KHR = (PFN_vkQueueSubmit2KHR)pa(device, "vkQueueSubmit2KHR");
    dt->CmdWriteBufferMarker2AMD = (PFN_vkCmdWriteBufferMarker2AMD)pa(device, "vkCmdWriteBufferMarker2AMD");
    dt->GetQueueCheckpointData2NV = (PFN_vkGetQueueCheckpointData2NV)pa(device, "vkGetQueueCheckpointData2NV");
    dt->CmdCopyBuffer2KHR = (PFN_vkCmdCopyBuffer2KHR)pa(device, "vkCmdCopyBuffer2KHR");
    dt->CmdCopyImage2KHR = (PFN_vkCmdCopyImage2KHR)pa(device, "vkCmdCopyImage2KHR");
    dt->CmdCopyBufferToImage2KHR = (PFN_vkCmdCopyBufferToImage2KHR)pa(device, "vkCmdCopyBufferToImage2KHR");
    dt->CmdCopyImageToBuffer2KHR = (PFN_vkCmdCopyImageToBuffer2KHR)pa(device, "vkCmdCopyImageToBuffer2KHR");
    dt->CmdBlitImage2KHR = (PFN_vkCmdBlitImage2KHR)pa(device, "vkCmdBlitImage2KHR");
    dt->CmdResolveImage2KHR = (PFN_vkCmdResolveImage2KHR)pa(device, "vkCmdResolveImage2KHR");
    dt->CmdTraceRaysIndirect2KHR = (PFN_vkCmdTraceRaysIndirect2KHR)pa(device, "vkCmdTraceRaysIndirect2KHR");
    dt->GetDeviceBufferMemoryRequirementsKHR =
        (PFN_vkGetDeviceBufferMemoryRequirementsKHR)pa(device, "vkGetDeviceBufferMemoryRequirementsKHR");
    dt->GetDeviceImageMemoryRequirementsKHR =
        (PFN_vkGetDeviceImageMemoryRequirementsKHR)pa(device, "vkGetDeviceImageMemoryRequirementsKHR");
    dt->GetDeviceImageSparseMemoryRequirementsKHR =
        (PFN_vkGetDeviceImageSparseMemoryRequirementsKHR)pa(device, "vkGetDeviceImageSparseMemoryRequirementsKHR");
    dt->CmdBindIndexBuffer2KHR = (PFN_vkCmdBindIndexBuffer2KHR)pa(device, "vkCmdBindIndexBuffer2KHR");
    dt->GetRenderingAreaGranularityKHR =
        (PFN_vkGetRenderingAreaGranularityKHR)pa(device, "vkGetRenderingAreaGranularityKHR");
    dt->GetDeviceImageSubresourceLayoutKHR =
        (PFN_vkGetDeviceImageSubresourceLayoutKHR)pa(device, "vkGetDeviceImageSubresourceLayoutKHR");
    dt->GetImageSubresourceLayout2KHR =
        (PFN_vkGetImageSubresourceLayout2KHR)pa(device, "vkGetImageSubresourceLayout2KHR");
    dt->CreatePipelineBinariesKHR = (PFN_vkCreatePipelineBinariesKHR)pa(device, "vkCreatePipelineBinariesKHR");
    dt->DestroyPipelineBinaryKHR = (PFN_vkDestroyPipelineBinaryKHR)pa(device, "vkDestroyPipelineBinaryKHR");
    dt->GetPipelineKeyKHR = (PFN_vkGetPipelineKeyKHR)pa(device, "vkGetPipelineKeyKHR");
    dt->GetPipelineBinaryDataKHR = (PFN_vkGetPipelineBinaryDataKHR)pa(device, "vkGetPipelineBinaryDataKHR");
    dt->ReleaseCapturedPipelineDataKHR =
        (PFN_vkReleaseCapturedPipelineDataKHR)pa(device, "vkReleaseCapturedPipelineDataKHR");
    dt->CmdSetLineStippleKHR = (PFN_vkCmdSetLineStippleKHR)pa(device, "vkCmdSetLineStippleKHR");
    dt->GetCalibratedTimestampsKHR = (PFN_vkGetCalibratedTimestampsKHR)pa(device, "vkGetCalibratedTimestampsKHR");
    dt->CmdBindDescriptorSets2KHR = (PFN_vkCmdBindDescriptorSets2KHR)pa(device, "vkCmdBindDescriptorSets2KHR");
    dt->CmdPushConstants2KHR = (PFN_vkCmdPushConstants2KHR)pa(device, "vkCmdPushConstants2KHR");
    dt->CmdPushDescriptorSet2KHR = (PFN_vkCmdPushDescriptorSet2KHR)pa(device, "vkCmdPushDescriptorSet2KHR");
    dt->CmdPushDescriptorSetWithTemplate2KHR =
        (PFN_vkCmdPushDescriptorSetWithTemplate2KHR)pa(device, "vkCmdPushDescriptorSetWithTemplate2KHR");
    dt->CmdSetDescriptorBufferOffsets2EXT =
        (PFN_vkCmdSetDescriptorBufferOffsets2EXT)pa(device, "vkCmdSetDescriptorBufferOffsets2EXT");
    dt->CmdBindDescriptorBufferEmbeddedSamplers2EXT =
        (PFN_vkCmdBindDescriptorBufferEmbeddedSamplers2EXT)pa(device, "vkCmdBindDescriptorBufferEmbeddedSamplers2EXT");
    dt->DebugMarkerSetObjectTagEXT = (PFN_vkDebugMarkerSetObjectTagEXT)pa(device, "vkDebugMarkerSetObjectTagEXT");
    dt->DebugMarkerSetObjectNameEXT = (PFN_vkDebugMarkerSetObjectNameEXT)pa(device, "vkDebugMarkerSetObjectNameEXT");
    dt->CmdDebugMarkerBeginEXT = (PFN_vkCmdDebugMarkerBeginEXT)pa(device, "vkCmdDebugMarkerBeginEXT");
    dt->CmdDebugMarkerEndEXT = (PFN_vkCmdDebugMarkerEndEXT)pa(device, "vkCmdDebugMarkerEndEXT");
    dt->CmdDebugMarkerInsertEXT = (PFN_vkCmdDebugMarkerInsertEXT)pa(device, "vkCmdDebugMarkerInsertEXT");
    dt->CmdBindTransformFeedbackBuffersEXT =
        (PFN_vkCmdBindTransformFeedbackBuffersEXT)pa(device, "vkCmdBindTransformFeedbackBuffersEXT");
    dt->CmdBeginTransformFeedbackEXT = (PFN_vkCmdBeginTransformFeedbackEXT)pa(device, "vkCmdBeginTransformFeedbackEXT");
    dt->CmdEndTransformFeedbackEXT = (PFN_vkCmdEndTransformFeedbackEXT)pa(device, "vkCmdEndTransformFeedbackEXT");
    dt->CmdBeginQueryIndexedEXT = (PFN_vkCmdBeginQueryIndexedEXT)pa(device, "vkCmdBeginQueryIndexedEXT");
    dt->CmdEndQueryIndexedEXT = (PFN_vkCmdEndQueryIndexedEXT)pa(device, "vkCmdEndQueryIndexedEXT");
    dt->CmdDrawIndirectByteCountEXT = (PFN_vkCmdDrawIndirectByteCountEXT)pa(device, "vkCmdDrawIndirectByteCountEXT");
    dt->CreateCuModuleNVX = (PFN_vkCreateCuModuleNVX)pa(device, "vkCreateCuModuleNVX");
    dt->CreateCuFunctionNVX = (PFN_vkCreateCuFunctionNVX)pa(device, "vkCreateCuFunctionNVX");
    dt->DestroyCuModuleNVX = (PFN_vkDestroyCuModuleNVX)pa(device, "vkDestroyCuModuleNVX");
    dt->DestroyCuFunctionNVX = (PFN_vkDestroyCuFunctionNVX)pa(device, "vkDestroyCuFunctionNVX");
    dt->CmdCuLaunchKernelNVX = (PFN_vkCmdCuLaunchKernelNVX)pa(device, "vkCmdCuLaunchKernelNVX");
    dt->GetImageViewHandleNVX = (PFN_vkGetImageViewHandleNVX)pa(device, "vkGetImageViewHandleNVX");
    dt->GetImageViewAddressNVX = (PFN_vkGetImageViewAddressNVX)pa(device, "vkGetImageViewAddressNVX");
    dt->CmdDrawIndirectCountAMD = (PFN_vkCmdDrawIndirectCountAMD)pa(device, "vkCmdDrawIndirectCountAMD");
    dt->CmdDrawIndexedIndirectCountAMD =
        (PFN_vkCmdDrawIndexedIndirectCountAMD)pa(device, "vkCmdDrawIndexedIndirectCountAMD");
    dt->GetShaderInfoAMD = (PFN_vkGetShaderInfoAMD)pa(device, "vkGetShaderInfoAMD");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetMemoryWin32HandleNV = (PFN_vkGetMemoryWin32HandleNV)pa(device, "vkGetMemoryWin32HandleNV");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->CmdBeginConditionalRenderingEXT =
        (PFN_vkCmdBeginConditionalRenderingEXT)pa(device, "vkCmdBeginConditionalRenderingEXT");
    dt->CmdEndConditionalRenderingEXT =
        (PFN_vkCmdEndConditionalRenderingEXT)pa(device, "vkCmdEndConditionalRenderingEXT");
    dt->CmdSetViewportWScalingNV = (PFN_vkCmdSetViewportWScalingNV)pa(device, "vkCmdSetViewportWScalingNV");
    dt->DisplayPowerControlEXT = (PFN_vkDisplayPowerControlEXT)pa(device, "vkDisplayPowerControlEXT");
    dt->RegisterDeviceEventEXT = (PFN_vkRegisterDeviceEventEXT)pa(device, "vkRegisterDeviceEventEXT");
    dt->RegisterDisplayEventEXT = (PFN_vkRegisterDisplayEventEXT)pa(device, "vkRegisterDisplayEventEXT");
    dt->GetSwapchainCounterEXT = (PFN_vkGetSwapchainCounterEXT)pa(device, "vkGetSwapchainCounterEXT");
    dt->GetRefreshCycleDurationGOOGLE =
        (PFN_vkGetRefreshCycleDurationGOOGLE)pa(device, "vkGetRefreshCycleDurationGOOGLE");
    dt->GetPastPresentationTimingGOOGLE =
        (PFN_vkGetPastPresentationTimingGOOGLE)pa(device, "vkGetPastPresentationTimingGOOGLE");
    dt->CmdSetDiscardRectangleEXT = (PFN_vkCmdSetDiscardRectangleEXT)pa(device, "vkCmdSetDiscardRectangleEXT");
    dt->CmdSetDiscardRectangleEnableEXT =
        (PFN_vkCmdSetDiscardRectangleEnableEXT)pa(device, "vkCmdSetDiscardRectangleEnableEXT");
    dt->CmdSetDiscardRectangleModeEXT =
        (PFN_vkCmdSetDiscardRectangleModeEXT)pa(device, "vkCmdSetDiscardRectangleModeEXT");
    dt->SetHdrMetadataEXT = (PFN_vkSetHdrMetadataEXT)pa(device, "vkSetHdrMetadataEXT");
    dt->SetDebugUtilsObjectNameEXT = (PFN_vkSetDebugUtilsObjectNameEXT)pa(device, "vkSetDebugUtilsObjectNameEXT");
    dt->SetDebugUtilsObjectTagEXT = (PFN_vkSetDebugUtilsObjectTagEXT)pa(device, "vkSetDebugUtilsObjectTagEXT");
    dt->QueueBeginDebugUtilsLabelEXT = (PFN_vkQueueBeginDebugUtilsLabelEXT)pa(device, "vkQueueBeginDebugUtilsLabelEXT");
    dt->QueueEndDebugUtilsLabelEXT = (PFN_vkQueueEndDebugUtilsLabelEXT)pa(device, "vkQueueEndDebugUtilsLabelEXT");
    dt->QueueInsertDebugUtilsLabelEXT =
        (PFN_vkQueueInsertDebugUtilsLabelEXT)pa(device, "vkQueueInsertDebugUtilsLabelEXT");
    dt->CmdBeginDebugUtilsLabelEXT = (PFN_vkCmdBeginDebugUtilsLabelEXT)pa(device, "vkCmdBeginDebugUtilsLabelEXT");
    dt->CmdEndDebugUtilsLabelEXT = (PFN_vkCmdEndDebugUtilsLabelEXT)pa(device, "vkCmdEndDebugUtilsLabelEXT");
    dt->CmdInsertDebugUtilsLabelEXT = (PFN_vkCmdInsertDebugUtilsLabelEXT)pa(device, "vkCmdInsertDebugUtilsLabelEXT");
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    dt->GetAndroidHardwareBufferPropertiesANDROID =
        (PFN_vkGetAndroidHardwareBufferPropertiesANDROID)pa(device, "vkGetAndroidHardwareBufferPropertiesANDROID");
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    dt->GetMemoryAndroidHardwareBufferANDROID =
        (PFN_vkGetMemoryAndroidHardwareBufferANDROID)pa(device, "vkGetMemoryAndroidHardwareBufferANDROID");
#endif  // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->CreateExecutionGraphPipelinesAMDX =
        (PFN_vkCreateExecutionGraphPipelinesAMDX)pa(device, "vkCreateExecutionGraphPipelinesAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->GetExecutionGraphPipelineScratchSizeAMDX =
        (PFN_vkGetExecutionGraphPipelineScratchSizeAMDX)pa(device, "vkGetExecutionGraphPipelineScratchSizeAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->GetExecutionGraphPipelineNodeIndexAMDX =
        (PFN_vkGetExecutionGraphPipelineNodeIndexAMDX)pa(device, "vkGetExecutionGraphPipelineNodeIndexAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->CmdInitializeGraphScratchMemoryAMDX =
        (PFN_vkCmdInitializeGraphScratchMemoryAMDX)pa(device, "vkCmdInitializeGraphScratchMemoryAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->CmdDispatchGraphAMDX = (PFN_vkCmdDispatchGraphAMDX)pa(device, "vkCmdDispatchGraphAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->CmdDispatchGraphIndirectAMDX = (PFN_vkCmdDispatchGraphIndirectAMDX)pa(device, "vkCmdDispatchGraphIndirectAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_ENABLE_BETA_EXTENSIONS
    dt->CmdDispatchGraphIndirectCountAMDX =
        (PFN_vkCmdDispatchGraphIndirectCountAMDX)pa(device, "vkCmdDispatchGraphIndirectCountAMDX");
#endif  // VK_ENABLE_BETA_EXTENSIONS
    dt->CmdSetSampleLocationsEXT = (PFN_vkCmdSetSampleLocationsEXT)pa(device, "vkCmdSetSampleLocationsEXT");
    dt->GetImageDrmFormatModifierPropertiesEXT =
        (PFN_vkGetImageDrmFormatModifierPropertiesEXT)pa(device, "vkGetImageDrmFormatModifierPropertiesEXT");
    dt->CreateValidationCacheEXT = (PFN_vkCreateValidationCacheEXT)pa(device, "vkCreateValidationCacheEXT");
    dt->DestroyValidationCacheEXT = (PFN_vkDestroyValidationCacheEXT)pa(device, "vkDestroyValidationCacheEXT");
    dt->MergeValidationCachesEXT = (PFN_vkMergeValidationCachesEXT)pa(device, "vkMergeValidationCachesEXT");
    dt->GetValidationCacheDataEXT = (PFN_vkGetValidationCacheDataEXT)pa(device, "vkGetValidationCacheDataEXT");
    dt->CmdBindShadingRateImageNV = (PFN_vkCmdBindShadingRateImageNV)pa(device, "vkCmdBindShadingRateImageNV");
    dt->CmdSetViewportShadingRatePaletteNV =
        (PFN_vkCmdSetViewportShadingRatePaletteNV)pa(device, "vkCmdSetViewportShadingRatePaletteNV");
    dt->CmdSetCoarseSampleOrderNV = (PFN_vkCmdSetCoarseSampleOrderNV)pa(device, "vkCmdSetCoarseSampleOrderNV");
    dt->CreateAccelerationStructureNV =
        (PFN_vkCreateAccelerationStructureNV)pa(device, "vkCreateAccelerationStructureNV");
    dt->DestroyAccelerationStructureNV =
        (PFN_vkDestroyAccelerationStructureNV)pa(device, "vkDestroyAccelerationStructureNV");
    dt->GetAccelerationStructureMemoryRequirementsNV = (PFN_vkGetAccelerationStructureMemoryRequirementsNV)pa(
        device, "vkGetAccelerationStructureMemoryRequirementsNV");
    dt->BindAccelerationStructureMemoryNV =
        (PFN_vkBindAccelerationStructureMemoryNV)pa(device, "vkBindAccelerationStructureMemoryNV");
    dt->CmdBuildAccelerationStructureNV =
        (PFN_vkCmdBuildAccelerationStructureNV)pa(device, "vkCmdBuildAccelerationStructureNV");
    dt->CmdCopyAccelerationStructureNV =
        (PFN_vkCmdCopyAccelerationStructureNV)pa(device, "vkCmdCopyAccelerationStructureNV");
    dt->CmdTraceRaysNV = (PFN_vkCmdTraceRaysNV)pa(device, "vkCmdTraceRaysNV");
    dt->CreateRayTracingPipelinesNV = (PFN_vkCreateRayTracingPipelinesNV)pa(device, "vkCreateRayTracingPipelinesNV");
    dt->GetRayTracingShaderGroupHandlesKHR =
        (PFN_vkGetRayTracingShaderGroupHandlesKHR)pa(device, "vkGetRayTracingShaderGroupHandlesKHR");
    dt->GetRayTracingShaderGroupHandlesNV =
        (PFN_vkGetRayTracingShaderGroupHandlesNV)pa(device, "vkGetRayTracingShaderGroupHandlesNV");
    dt->GetAccelerationStructureHandleNV =
        (PFN_vkGetAccelerationStructureHandleNV)pa(device, "vkGetAccelerationStructureHandleNV");
    dt->CmdWriteAccelerationStructuresPropertiesNV =
        (PFN_vkCmdWriteAccelerationStructuresPropertiesNV)pa(device, "vkCmdWriteAccelerationStructuresPropertiesNV");
    dt->CompileDeferredNV = (PFN_vkCompileDeferredNV)pa(device, "vkCompileDeferredNV");
    dt->GetMemoryHostPointerPropertiesEXT =
        (PFN_vkGetMemoryHostPointerPropertiesEXT)pa(device, "vkGetMemoryHostPointerPropertiesEXT");
    dt->CmdWriteBufferMarkerAMD = (PFN_vkCmdWriteBufferMarkerAMD)pa(device, "vkCmdWriteBufferMarkerAMD");
    dt->GetCalibratedTimestampsEXT = (PFN_vkGetCalibratedTimestampsEXT)pa(device, "vkGetCalibratedTimestampsEXT");
    dt->CmdDrawMeshTasksNV = (PFN_vkCmdDrawMeshTasksNV)pa(device, "vkCmdDrawMeshTasksNV");
    dt->CmdDrawMeshTasksIndirectNV = (PFN_vkCmdDrawMeshTasksIndirectNV)pa(device, "vkCmdDrawMeshTasksIndirectNV");
    dt->CmdDrawMeshTasksIndirectCountNV =
        (PFN_vkCmdDrawMeshTasksIndirectCountNV)pa(device, "vkCmdDrawMeshTasksIndirectCountNV");
    dt->CmdSetExclusiveScissorEnableNV =
        (PFN_vkCmdSetExclusiveScissorEnableNV)pa(device, "vkCmdSetExclusiveScissorEnableNV");
    dt->CmdSetExclusiveScissorNV = (PFN_vkCmdSetExclusiveScissorNV)pa(device, "vkCmdSetExclusiveScissorNV");
    dt->CmdSetCheckpointNV = (PFN_vkCmdSetCheckpointNV)pa(device, "vkCmdSetCheckpointNV");
    dt->GetQueueCheckpointDataNV = (PFN_vkGetQueueCheckpointDataNV)pa(device, "vkGetQueueCheckpointDataNV");
    dt->InitializePerformanceApiINTEL =
        (PFN_vkInitializePerformanceApiINTEL)pa(device, "vkInitializePerformanceApiINTEL");
    dt->UninitializePerformanceApiINTEL =
        (PFN_vkUninitializePerformanceApiINTEL)pa(device, "vkUninitializePerformanceApiINTEL");
    dt->CmdSetPerformanceMarkerINTEL = (PFN_vkCmdSetPerformanceMarkerINTEL)pa(device, "vkCmdSetPerformanceMarkerINTEL");
    dt->CmdSetPerformanceStreamMarkerINTEL =
        (PFN_vkCmdSetPerformanceStreamMarkerINTEL)pa(device, "vkCmdSetPerformanceStreamMarkerINTEL");
    dt->CmdSetPerformanceOverrideINTEL =
        (PFN_vkCmdSetPerformanceOverrideINTEL)pa(device, "vkCmdSetPerformanceOverrideINTEL");
    dt->AcquirePerformanceConfigurationINTEL =
        (PFN_vkAcquirePerformanceConfigurationINTEL)pa(device, "vkAcquirePerformanceConfigurationINTEL");
    dt->ReleasePerformanceConfigurationINTEL =
        (PFN_vkReleasePerformanceConfigurationINTEL)pa(device, "vkReleasePerformanceConfigurationINTEL");
    dt->QueueSetPerformanceConfigurationINTEL =
        (PFN_vkQueueSetPerformanceConfigurationINTEL)pa(device, "vkQueueSetPerformanceConfigurationINTEL");
    dt->GetPerformanceParameterINTEL = (PFN_vkGetPerformanceParameterINTEL)pa(device, "vkGetPerformanceParameterINTEL");
    dt->SetLocalDimmingAMD = (PFN_vkSetLocalDimmingAMD)pa(device, "vkSetLocalDimmingAMD");
    dt->GetBufferDeviceAddressEXT = (PFN_vkGetBufferDeviceAddressEXT)pa(device, "vkGetBufferDeviceAddressEXT");
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->AcquireFullScreenExclusiveModeEXT =
        (PFN_vkAcquireFullScreenExclusiveModeEXT)pa(device, "vkAcquireFullScreenExclusiveModeEXT");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->ReleaseFullScreenExclusiveModeEXT =
        (PFN_vkReleaseFullScreenExclusiveModeEXT)pa(device, "vkReleaseFullScreenExclusiveModeEXT");
#endif  // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    dt->GetDeviceGroupSurfacePresentModes2EXT =
        (PFN_vkGetDeviceGroupSurfacePresentModes2EXT)pa(device, "vkGetDeviceGroupSurfacePresentModes2EXT");
#endif  // VK_USE_PLATFORM_WIN32_KHR
    dt->CmdSetLineStippleEXT = (PFN_vkCmdSetLineStippleEXT)pa(device, "vkCmdSetLineStippleEXT");
    dt->ResetQueryPoolEXT = (PFN_vkResetQueryPoolEXT)pa(device, "vkResetQueryPoolEXT");
    dt->CmdSetCullModeEXT = (PFN_vkCmdSetCullModeEXT)pa(device, "vkCmdSetCullModeEXT");
    dt->CmdSetFrontFaceEXT = (PFN_vkCmdSetFrontFaceEXT)pa(device, "vkCmdSetFrontFaceEXT");
    dt->CmdSetPrimitiveTopologyEXT = (PFN_vkCmdSetPrimitiveTopologyEXT)pa(device, "vkCmdSetPrimitiveTopologyEXT");
    dt->CmdSetViewportWithCountEXT = (PFN_vkCmdSetViewportWithCountEXT)pa(device, "vkCmdSetViewportWithCountEXT");
    dt->CmdSetScissorWithCountEXT = (PFN_vkCmdSetScissorWithCountEXT)pa(device, "vkCmdSetScissorWithCountEXT");
    dt->CmdBindVertexBuffers2EXT = (PFN_vkCmdBindVertexBuffers2EXT)pa(device, "vkCmdBindVertexBuffers2EXT");
    dt->CmdSetDepthTestEnableEXT = (PFN_vkCmdSetDepthTestEnableEXT)pa(device, "vkCmdSetDepthTestEnableEXT");
    dt->CmdSetDepthWriteEnableEXT = (PFN_vkCmdSetDepthWriteEnableEXT)pa(device, "vkCmdSetDepthWriteEnableEXT");
    dt->CmdSetDepthCompareOpEXT = (PFN_vkCmdSetDepthCompareOpEXT)pa(device, "vkCmdSetDepthCompareOpEXT");
    dt->CmdSetDepthBoundsTestEnableEXT =
        (PFN_vkCmdSetDepthBoundsTestEnableEXT)pa(device, "vkCmdSetDepthBoundsTestEnableEXT");
    dt->CmdSetStencilTestEnableEXT = (PFN_vkCmdSetStencilTestEnableEXT)pa(device, "vkCmdSetStencilTestEnableEXT");
    dt->CmdSetStencilOpEXT = (PFN_vkCmdSetStencilOpEXT)pa(device, "vkCmdSetStencilOpEXT");
    dt->CopyMemoryToImageEXT = (PFN_vkCopyMemoryToImageEXT)pa(device, "vkCopyMemoryToImageEXT");
    dt->CopyImageToMemoryEXT = (PFN_vkCopyImageToMemoryEXT)pa(device, "vkCopyImageToMemoryEXT");
    dt->CopyImageToImageEXT = (PFN_vkCopyImageToImageEXT)pa(device, "vkCopyImageToImageEXT");
    dt->TransitionImageLayoutEXT = (PFN_vkTransitionImageLayoutEXT)pa(device, "vkTransitionImageLayoutEXT");
    dt->GetImageSubresourceLayout2EXT =
        (PFN_vkGetImageSubresourceLayout2EXT)pa(device, "vkGetImageSubresourceLayout2EXT");
    dt->ReleaseSwapchainImagesEXT = (PFN_vkReleaseSwapchainImagesEXT)pa(device, "vkReleaseSwapchainImagesEXT");
    dt->GetGeneratedCommandsMemoryRequirementsNV =
        (PFN_vkGetGeneratedCommandsMemoryRequirementsNV)pa(device, "vkGetGeneratedCommandsMemoryRequirementsNV");
    dt->CmdPreprocessGeneratedCommandsNV =
        (PFN_vkCmdPreprocessGeneratedCommandsNV)pa(device, "vkCmdPreprocessGeneratedCommandsNV");
    dt->CmdExecuteGeneratedCommandsNV =
        (PFN_vkCmdExecuteGeneratedCommandsNV)pa(device, "vkCmdExecuteGeneratedCommandsNV");
    dt->CmdBindPipelineShaderGroupNV = (PFN_vkCmdBindPipelineShaderGroupNV)pa(device, "vkCmdBindPipelineShaderGroupNV");
    dt->CreateIndirectCommandsLayoutNV =
        (PFN_vkCreateIndirectCommandsLayoutNV)pa(device, "vkCreateIndirectCommandsLayoutNV");
    dt->DestroyIndirectCommandsLayoutNV =
        (PFN_vkDestroyIndirectCommandsLayoutNV)pa(device, "vkDestroyIndirectCommandsLayoutNV");
    dt->CmdSetDepthBias2EXT = (PFN_vkCmdSetDepthBias2EXT)pa(device, "vkCmdSetDepthBias2EXT");
    dt->CreatePrivateDataSlotEXT = (PFN_vkCreatePrivateDataSlotEXT)pa(device, "vkCreatePrivateDataSlotEXT");
    dt->DestroyPrivateDataSlotEXT = (PFN_vkDestroyPrivateDataSlotEXT)pa(device, "vkDestroyPrivateDataSlotEXT");
    dt->SetPrivateDataEXT = (PFN_vkSetPrivateDataEXT)pa(device, "vkSetPrivateDataEXT");
    dt->GetPrivateDataEXT = (PFN_vkGetPrivateDataEXT)pa(device, "vkGetPrivateDataEXT");
    dt->CreateCudaModuleNV = (PFN_vkCreateCudaModuleNV)pa(device, "vkCreateCudaModuleNV");
    dt->GetCudaModuleCacheNV = (PFN_vkGetCudaModuleCacheNV)pa(device, "vkGetCudaModuleCacheNV");
    dt->CreateCudaFunctionNV = (PFN_vkCreateCudaFunctionNV)pa(device, "vkCreateCudaFunctionNV");
    dt->DestroyCudaModuleNV = (PFN_vkDestroyCudaModuleNV)pa(device, "vkDestroyCudaModuleNV");
    dt->DestroyCudaFunctionNV = (PFN_vkDestroyCudaFunctionNV)pa(device, "vkDestroyCudaFunctionNV");
    dt->CmdCudaLaunchKernelNV = (PFN_vkCmdCudaLaunchKernelNV)pa(device, "vkCmdCudaLaunchKernelNV");
#ifdef VK_USE_PLATFORM_METAL_EXT
    dt->ExportMetalObjectsEXT = (PFN_vkExportMetalObjectsEXT)pa(device, "vkExportMetalObjectsEXT");
#endif  // VK_USE_PLATFORM_METAL_EXT
    dt->GetDescriptorSetLayoutSizeEXT =
        (PFN_vkGetDescriptorSetLayoutSizeEXT)pa(device, "vkGetDescriptorSetLayoutSizeEXT");
    dt->GetDescriptorSetLayoutBindingOffsetEXT =
        (PFN_vkGetDescriptorSetLayoutBindingOffsetEXT)pa(device, "vkGetDescriptorSetLayoutBindingOffsetEXT");
    dt->GetDescriptorEXT = (PFN_vkGetDescriptorEXT)pa(device, "vkGetDescriptorEXT");
    dt->CmdBindDescriptorBuffersEXT = (PFN_vkCmdBindDescriptorBuffersEXT)pa(device, "vkCmdBindDescriptorBuffersEXT");
    dt->CmdSetDescriptorBufferOffsetsEXT =
        (PFN_vkCmdSetDescriptorBufferOffsetsEXT)pa(device, "vkCmdSetDescriptorBufferOffsetsEXT");
    dt->CmdBindDescriptorBufferEmbeddedSamplersEXT =
        (PFN_vkCmdBindDescriptorBufferEmbeddedSamplersEXT)pa(device, "vkCmdBindDescriptorBufferEmbeddedSamplersEXT");
    dt->GetBufferOpaqueCaptureDescriptorDataEXT =
        (PFN_vkGetBufferOpaqueCaptureDescriptorDataEXT)pa(device, "vkGetBufferOpaqueCaptureDescriptorDataEXT");
    dt->GetImageOpaqueCaptureDescriptorDataEXT =
        (PFN_vkGetImageOpaqueCaptureDescriptorDataEXT)pa(device, "vkGetImageOpaqueCaptureDescriptorDataEXT");
    dt->GetImageViewOpaqueCaptureDescriptorDataEXT =
        (PFN_vkGetImageViewOpaqueCaptureDescriptorDataEXT)pa(device, "vkGetImageViewOpaqueCaptureDescriptorDataEXT");
    dt->GetSamplerOpaqueCaptureDescriptorDataEXT =
        (PFN_vkGetSamplerOpaqueCaptureDescriptorDataEXT)pa(device, "vkGetSamplerOpaqueCaptureDescriptorDataEXT");
    dt->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT =
        (PFN_vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT)pa(
            device, "vkGetAccelerationStructureOpaqueCaptureDescriptorDataEXT");
    dt->CmdSetFragmentShadingRateEnumNV =
        (PFN_vkCmdSetFragmentShadingRateEnumNV)pa(device, "vkCmdSetFragmentShadingRateEnumNV");
    dt->GetDeviceFaultInfoEXT = (PFN_vkGetDeviceFaultInfoEXT)pa(device, "vkGetDeviceFaultInfoEXT");
    dt->CmdSetVertexInputEXT = (PFN_vkCmdSetVertexInputEXT)pa(device, "vkCmdSetVertexInputEXT");
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->GetMemoryZirconHandleFUCHSIA = (PFN_vkGetMemoryZirconHandleFUCHSIA)pa(device, "vkGetMemoryZirconHandleFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->GetMemoryZirconHandlePropertiesFUCHSIA =
        (PFN_vkGetMemoryZirconHandlePropertiesFUCHSIA)pa(device, "vkGetMemoryZirconHandlePropertiesFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->ImportSemaphoreZirconHandleFUCHSIA =
        (PFN_vkImportSemaphoreZirconHandleFUCHSIA)pa(device, "vkImportSemaphoreZirconHandleFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->GetSemaphoreZirconHandleFUCHSIA =
        (PFN_vkGetSemaphoreZirconHandleFUCHSIA)pa(device, "vkGetSemaphoreZirconHandleFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->CreateBufferCollectionFUCHSIA =
        (PFN_vkCreateBufferCollectionFUCHSIA)pa(device, "vkCreateBufferCollectionFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->SetBufferCollectionImageConstraintsFUCHSIA =
        (PFN_vkSetBufferCollectionImageConstraintsFUCHSIA)pa(device, "vkSetBufferCollectionImageConstraintsFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->SetBufferCollectionBufferConstraintsFUCHSIA =
        (PFN_vkSetBufferCollectionBufferConstraintsFUCHSIA)pa(device, "vkSetBufferCollectionBufferConstraintsFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->DestroyBufferCollectionFUCHSIA =
        (PFN_vkDestroyBufferCollectionFUCHSIA)pa(device, "vkDestroyBufferCollectionFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_FUCHSIA
    dt->GetBufferCollectionPropertiesFUCHSIA =
        (PFN_vkGetBufferCollectionPropertiesFUCHSIA)pa(device, "vkGetBufferCollectionPropertiesFUCHSIA");
#endif  // VK_USE_PLATFORM_FUCHSIA
    dt->GetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI = (PFN_vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI)pa(
        device, "vkGetDeviceSubpassShadingMaxWorkgroupSizeHUAWEI");
    dt->CmdSubpassShadingHUAWEI = (PFN_vkCmdSubpassShadingHUAWEI)pa(device, "vkCmdSubpassShadingHUAWEI");
    dt->CmdBindInvocationMaskHUAWEI = (PFN_vkCmdBindInvocationMaskHUAWEI)pa(device, "vkCmdBindInvocationMaskHUAWEI");
    dt->GetMemoryRemoteAddressNV = (PFN_vkGetMemoryRemoteAddressNV)pa(device, "vkGetMemoryRemoteAddressNV");
    dt->GetPipelinePropertiesEXT = (PFN_vkGetPipelinePropertiesEXT)pa(device, "vkGetPipelinePropertiesEXT");
    dt->CmdSetPatchControlPointsEXT = (PFN_vkCmdSetPatchControlPointsEXT)pa(device, "vkCmdSetPatchControlPointsEXT");
    dt->CmdSetRasterizerDiscardEnableEXT =
        (PFN_vkCmdSetRasterizerDiscardEnableEXT)pa(device, "vkCmdSetRasterizerDiscardEnableEXT");
    dt->CmdSetDepthBiasEnableEXT = (PFN_vkCmdSetDepthBiasEnableEXT)pa(device, "vkCmdSetDepthBiasEnableEXT");
    dt->CmdSetLogicOpEXT = (PFN_vkCmdSetLogicOpEXT)pa(device, "vkCmdSetLogicOpEXT");
    dt->CmdSetPrimitiveRestartEnableEXT =
        (PFN_vkCmdSetPrimitiveRestartEnableEXT)pa(device, "vkCmdSetPrimitiveRestartEnableEXT");
    dt->CmdSetColorWriteEnableEXT = (PFN_vkCmdSetColorWriteEnableEXT)pa(device, "vkCmdSetColorWriteEnableEXT");
    dt->CmdDrawMultiEXT = (PFN_vkCmdDrawMultiEXT)pa(device, "vkCmdDrawMultiEXT");
    dt->CmdDrawMultiIndexedEXT = (PFN_vkCmdDrawMultiIndexedEXT)pa(device, "vkCmdDrawMultiIndexedEXT");
    dt->CreateMicromapEXT = (PFN_vkCreateMicromapEXT)pa(device, "vkCreateMicromapEXT");
    dt->DestroyMicromapEXT = (PFN_vkDestroyMicromapEXT)pa(device, "vkDestroyMicromapEXT");
    dt->CmdBuildMicromapsEXT = (PFN_vkCmdBuildMicromapsEXT)pa(device, "vkCmdBuildMicromapsEXT");
    dt->BuildMicromapsEXT = (PFN_vkBuildMicromapsEXT)pa(device, "vkBuildMicromapsEXT");
    dt->CopyMicromapEXT = (PFN_vkCopyMicromapEXT)pa(device, "vkCopyMicromapEXT");
    dt->CopyMicromapToMemoryEXT = (PFN_vkCopyMicromapToMemoryEXT)pa(device, "vkCopyMicromapToMemoryEXT");
    dt->CopyMemoryToMicromapEXT = (PFN_vkCopyMemoryToMicromapEXT)pa(device, "vkCopyMemoryToMicromapEXT");
    dt->WriteMicromapsPropertiesEXT = (PFN_vkWriteMicromapsPropertiesEXT)pa(device, "vkWriteMicromapsPropertiesEXT");
    dt->CmdCopyMicromapEXT = (PFN_vkCmdCopyMicromapEXT)pa(device, "vkCmdCopyMicromapEXT");
    dt->CmdCopyMicromapToMemoryEXT = (PFN_vkCmdCopyMicromapToMemoryEXT)pa(device, "vkCmdCopyMicromapToMemoryEXT");
    dt->CmdCopyMemoryToMicromapEXT = (PFN_vkCmdCopyMemoryToMicromapEXT)pa(device, "vkCmdCopyMemoryToMicromapEXT");
    dt->CmdWriteMicromapsPropertiesEXT =
        (PFN_vkCmdWriteMicromapsPropertiesEXT)pa(device, "vkCmdWriteMicromapsPropertiesEXT");
    dt->GetDeviceMicromapCompatibilityEXT =
        (PFN_vkGetDeviceMicromapCompatibilityEXT)pa(device, "vkGetDeviceMicromapCompatibilityEXT");
    dt->GetMicromapBuildSizesEXT = (PFN_vkGetMicromapBuildSizesEXT)pa(device, "vkGetMicromapBuildSizesEXT");
    dt->CmdDrawClusterHUAWEI = (PFN_vkCmdDrawClusterHUAWEI)pa(device, "vkCmdDrawClusterHUAWEI");
    dt->CmdDrawClusterIndirectHUAWEI = (PFN_vkCmdDrawClusterIndirectHUAWEI)pa(device, "vkCmdDrawClusterIndirectHUAWEI");
    dt->SetDeviceMemoryPriorityEXT = (PFN_vkSetDeviceMemoryPriorityEXT)pa(device, "vkSetDeviceMemoryPriorityEXT");
    dt->GetDescriptorSetLayoutHostMappingInfoVALVE =
        (PFN_vkGetDescriptorSetLayoutHostMappingInfoVALVE)pa(device, "vkGetDescriptorSetLayoutHostMappingInfoVALVE");
    dt->GetDescriptorSetHostMappingVALVE =
        (PFN_vkGetDescriptorSetHostMappingVALVE)pa(device, "vkGetDescriptorSetHostMappingVALVE");
    dt->CmdCopyMemoryIndirectNV = (PFN_vkCmdCopyMemoryIndirectNV)pa(device, "vkCmdCopyMemoryIndirectNV");
    dt->CmdCopyMemoryToImageIndirectNV =
        (PFN_vkCmdCopyMemoryToImageIndirectNV)pa(device, "vkCmdCopyMemoryToImageIndirectNV");
    dt->CmdDecompressMemoryNV = (PFN_vkCmdDecompressMemoryNV)pa(device, "vkCmdDecompressMemoryNV");
    dt->CmdDecompressMemoryIndirectCountNV =
        (PFN_vkCmdDecompressMemoryIndirectCountNV)pa(device, "vkCmdDecompressMemoryIndirectCountNV");
    dt->GetPipelineIndirectMemoryRequirementsNV =
        (PFN_vkGetPipelineIndirectMemoryRequirementsNV)pa(device, "vkGetPipelineIndirectMemoryRequirementsNV");
    dt->CmdUpdatePipelineIndirectBufferNV =
        (PFN_vkCmdUpdatePipelineIndirectBufferNV)pa(device, "vkCmdUpdatePipelineIndirectBufferNV");
    dt->GetPipelineIndirectDeviceAddressNV =
        (PFN_vkGetPipelineIndirectDeviceAddressNV)pa(device, "vkGetPipelineIndirectDeviceAddressNV");
    dt->CmdSetDepthClampEnableEXT = (PFN_vkCmdSetDepthClampEnableEXT)pa(device, "vkCmdSetDepthClampEnableEXT");
    dt->CmdSetPolygonModeEXT = (PFN_vkCmdSetPolygonModeEXT)pa(device, "vkCmdSetPolygonModeEXT");
    dt->CmdSetRasterizationSamplesEXT =
        (PFN_vkCmdSetRasterizationSamplesEXT)pa(device, "vkCmdSetRasterizationSamplesEXT");
    dt->CmdSetSampleMaskEXT = (PFN_vkCmdSetSampleMaskEXT)pa(device, "vkCmdSetSampleMaskEXT");
    dt->CmdSetAlphaToCoverageEnableEXT =
        (PFN_vkCmdSetAlphaToCoverageEnableEXT)pa(device, "vkCmdSetAlphaToCoverageEnableEXT");
    dt->CmdSetAlphaToOneEnableEXT = (PFN_vkCmdSetAlphaToOneEnableEXT)pa(device, "vkCmdSetAlphaToOneEnableEXT");
    dt->CmdSetLogicOpEnableEXT = (PFN_vkCmdSetLogicOpEnableEXT)pa(device, "vkCmdSetLogicOpEnableEXT");
    dt->CmdSetColorBlendEnableEXT = (PFN_vkCmdSetColorBlendEnableEXT)pa(device, "vkCmdSetColorBlendEnableEXT");
    dt->CmdSetColorBlendEquationEXT = (PFN_vkCmdSetColorBlendEquationEXT)pa(device, "vkCmdSetColorBlendEquationEXT");
    dt->CmdSetColorWriteMaskEXT = (PFN_vkCmdSetColorWriteMaskEXT)pa(device, "vkCmdSetColorWriteMaskEXT");
    dt->CmdSetTessellationDomainOriginEXT =
        (PFN_vkCmdSetTessellationDomainOriginEXT)pa(device, "vkCmdSetTessellationDomainOriginEXT");
    dt->CmdSetRasterizationStreamEXT = (PFN_vkCmdSetRasterizationStreamEXT)pa(device, "vkCmdSetRasterizationStreamEXT");
    dt->CmdSetConservativeRasterizationModeEXT =
        (PFN_vkCmdSetConservativeRasterizationModeEXT)pa(device, "vkCmdSetConservativeRasterizationModeEXT");
    dt->CmdSetExtraPrimitiveOverestimationSizeEXT =
        (PFN_vkCmdSetExtraPrimitiveOverestimationSizeEXT)pa(device, "vkCmdSetExtraPrimitiveOverestimationSizeEXT");
    dt->CmdSetDepthClipEnableEXT = (PFN_vkCmdSetDepthClipEnableEXT)pa(device, "vkCmdSetDepthClipEnableEXT");
    dt->CmdSetSampleLocationsEnableEXT =
        (PFN_vkCmdSetSampleLocationsEnableEXT)pa(device, "vkCmdSetSampleLocationsEnableEXT");
    dt->CmdSetColorBlendAdvancedEXT = (PFN_vkCmdSetColorBlendAdvancedEXT)pa(device, "vkCmdSetColorBlendAdvancedEXT");
    dt->CmdSetProvokingVertexModeEXT = (PFN_vkCmdSetProvokingVertexModeEXT)pa(device, "vkCmdSetProvokingVertexModeEXT");
    dt->CmdSetLineRasterizationModeEXT =
        (PFN_vkCmdSetLineRasterizationModeEXT)pa(device, "vkCmdSetLineRasterizationModeEXT");
    dt->CmdSetLineStippleEnableEXT = (PFN_vkCmdSetLineStippleEnableEXT)pa(device, "vkCmdSetLineStippleEnableEXT");
    dt->CmdSetDepthClipNegativeOneToOneEXT =
        (PFN_vkCmdSetDepthClipNegativeOneToOneEXT)pa(device, "vkCmdSetDepthClipNegativeOneToOneEXT");
    dt->CmdSetViewportWScalingEnableNV =
        (PFN_vkCmdSetViewportWScalingEnableNV)pa(device, "vkCmdSetViewportWScalingEnableNV");
    dt->CmdSetViewportSwizzleNV = (PFN_vkCmdSetViewportSwizzleNV)pa(device, "vkCmdSetViewportSwizzleNV");
    dt->CmdSetCoverageToColorEnableNV =
        (PFN_vkCmdSetCoverageToColorEnableNV)pa(device, "vkCmdSetCoverageToColorEnableNV");
    dt->CmdSetCoverageToColorLocationNV =
        (PFN_vkCmdSetCoverageToColorLocationNV)pa(device, "vkCmdSetCoverageToColorLocationNV");
    dt->CmdSetCoverageModulationModeNV =
        (PFN_vkCmdSetCoverageModulationModeNV)pa(device, "vkCmdSetCoverageModulationModeNV");
    dt->CmdSetCoverageModulationTableEnableNV =
        (PFN_vkCmdSetCoverageModulationTableEnableNV)pa(device, "vkCmdSetCoverageModulationTableEnableNV");
    dt->CmdSetCoverageModulationTableNV =
        (PFN_vkCmdSetCoverageModulationTableNV)pa(device, "vkCmdSetCoverageModulationTableNV");
    dt->CmdSetShadingRateImageEnableNV =
        (PFN_vkCmdSetShadingRateImageEnableNV)pa(device, "vkCmdSetShadingRateImageEnableNV");
    dt->CmdSetRepresentativeFragmentTestEnableNV =
        (PFN_vkCmdSetRepresentativeFragmentTestEnableNV)pa(device, "vkCmdSetRepresentativeFragmentTestEnableNV");
    dt->CmdSetCoverageReductionModeNV =
        (PFN_vkCmdSetCoverageReductionModeNV)pa(device, "vkCmdSetCoverageReductionModeNV");
    dt->GetShaderModuleIdentifierEXT = (PFN_vkGetShaderModuleIdentifierEXT)pa(device, "vkGetShaderModuleIdentifierEXT");
    dt->GetShaderModuleCreateInfoIdentifierEXT =
        (PFN_vkGetShaderModuleCreateInfoIdentifierEXT)pa(device, "vkGetShaderModuleCreateInfoIdentifierEXT");
    dt->CreateOpticalFlowSessionNV = (PFN_vkCreateOpticalFlowSessionNV)pa(device, "vkCreateOpticalFlowSessionNV");
    dt->DestroyOpticalFlowSessionNV = (PFN_vkDestroyOpticalFlowSessionNV)pa(device, "vkDestroyOpticalFlowSessionNV");
    dt->BindOpticalFlowSessionImageNV =
        (PFN_vkBindOpticalFlowSessionImageNV)pa(device, "vkBindOpticalFlowSessionImageNV");
    dt->CmdOpticalFlowExecuteNV = (PFN_vkCmdOpticalFlowExecuteNV)pa(device, "vkCmdOpticalFlowExecuteNV");
    dt->AntiLagUpdateAMD = (PFN_vkAntiLagUpdateAMD)pa(device, "vkAntiLagUpdateAMD");
    dt->CreateShadersEXT = (PFN_vkCreateShadersEXT)pa(device, "vkCreateShadersEXT");
    dt->DestroyShaderEXT = (PFN_vkDestroyShaderEXT)pa(device, "vkDestroyShaderEXT");
    dt->GetShaderBinaryDataEXT = (PFN_vkGetShaderBinaryDataEXT)pa(device, "vkGetShaderBinaryDataEXT");
    dt->CmdBindShadersEXT = (PFN_vkCmdBindShadersEXT)pa(device, "vkCmdBindShadersEXT");
    dt->CmdSetDepthClampRangeEXT = (PFN_vkCmdSetDepthClampRangeEXT)pa(device, "vkCmdSetDepthClampRangeEXT");
    dt->GetFramebufferTilePropertiesQCOM =
        (PFN_vkGetFramebufferTilePropertiesQCOM)pa(device, "vkGetFramebufferTilePropertiesQCOM");
    dt->GetDynamicRenderingTilePropertiesQCOM =
        (PFN_vkGetDynamicRenderingTilePropertiesQCOM)pa(device, "vkGetDynamicRenderingTilePropertiesQCOM");
    dt->SetLatencySleepModeNV = (PFN_vkSetLatencySleepModeNV)pa(device, "vkSetLatencySleepModeNV");
    dt->LatencySleepNV = (PFN_vkLatencySleepNV)pa(device, "vkLatencySleepNV");
    dt->SetLatencyMarkerNV = (PFN_vkSetLatencyMarkerNV)pa(device, "vkSetLatencyMarkerNV");
    dt->GetLatencyTimingsNV = (PFN_vkGetLatencyTimingsNV)pa(device, "vkGetLatencyTimingsNV");
    dt->QueueNotifyOutOfBandNV = (PFN_vkQueueNotifyOutOfBandNV)pa(device, "vkQueueNotifyOutOfBandNV");
    dt->CmdSetAttachmentFeedbackLoopEnableEXT =
        (PFN_vkCmdSetAttachmentFeedbackLoopEnableEXT)pa(device, "vkCmdSetAttachmentFeedbackLoopEnableEXT");
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    dt->GetScreenBufferPropertiesQNX = (PFN_vkGetScreenBufferPropertiesQNX)pa(device, "vkGetScreenBufferPropertiesQNX");
#endif  // VK_USE_PLATFORM_SCREEN_QNX
    dt->GetGeneratedCommandsMemoryRequirementsEXT =
        (PFN_vkGetGeneratedCommandsMemoryRequirementsEXT)pa(device, "vkGetGeneratedCommandsMemoryRequirementsEXT");
    dt->CmdPreprocessGeneratedCommandsEXT =
        (PFN_vkCmdPreprocessGeneratedCommandsEXT)pa(device, "vkCmdPreprocessGeneratedCommandsEXT");
    dt->CmdExecuteGeneratedCommandsEXT =
        (PFN_vkCmdExecuteGeneratedCommandsEXT)pa(device, "vkCmdExecuteGeneratedCommandsEXT");
    dt->CreateIndirectCommandsLayoutEXT =
        (PFN_vkCreateIndirectCommandsLayoutEXT)pa(device, "vkCreateIndirectCommandsLayoutEXT");
    dt->DestroyIndirectCommandsLayoutEXT =
        (PFN_vkDestroyIndirectCommandsLayoutEXT)pa(device, "vkDestroyIndirectCommandsLayoutEXT");
    dt->CreateIndirectExecutionSetEXT =
        (PFN_vkCreateIndirectExecutionSetEXT)pa(device, "vkCreateIndirectExecutionSetEXT");
    dt->DestroyIndirectExecutionSetEXT =
        (PFN_vkDestroyIndirectExecutionSetEXT)pa(device, "vkDestroyIndirectExecutionSetEXT");
    dt->UpdateIndirectExecutionSetPipelineEXT =
        (PFN_vkUpdateIndirectExecutionSetPipelineEXT)pa(device, "vkUpdateIndirectExecutionSetPipelineEXT");
    dt->UpdateIndirectExecutionSetShaderEXT =
        (PFN_vkUpdateIndirectExecutionSetShaderEXT)pa(device, "vkUpdateIndirectExecutionSetShaderEXT");
    dt->CreateAccelerationStructureKHR =
        (PFN_vkCreateAccelerationStructureKHR)pa(device, "vkCreateAccelerationStructureKHR");
    dt->DestroyAccelerationStructureKHR =
        (PFN_vkDestroyAccelerationStructureKHR)pa(device, "vkDestroyAccelerationStructureKHR");
    dt->CmdBuildAccelerationStructuresKHR =
        (PFN_vkCmdBuildAccelerationStructuresKHR)pa(device, "vkCmdBuildAccelerationStructuresKHR");
    dt->CmdBuildAccelerationStructuresIndirectKHR =
        (PFN_vkCmdBuildAccelerationStructuresIndirectKHR)pa(device, "vkCmdBuildAccelerationStructuresIndirectKHR");
    dt->BuildAccelerationStructuresKHR =
        (PFN_vkBuildAccelerationStructuresKHR)pa(device, "vkBuildAccelerationStructuresKHR");
    dt->CopyAccelerationStructureKHR = (PFN_vkCopyAccelerationStructureKHR)pa(device, "vkCopyAccelerationStructureKHR");
    dt->CopyAccelerationStructureToMemoryKHR =
        (PFN_vkCopyAccelerationStructureToMemoryKHR)pa(device, "vkCopyAccelerationStructureToMemoryKHR");
    dt->CopyMemoryToAccelerationStructureKHR =
        (PFN_vkCopyMemoryToAccelerationStructureKHR)pa(device, "vkCopyMemoryToAccelerationStructureKHR");
    dt->WriteAccelerationStructuresPropertiesKHR =
        (PFN_vkWriteAccelerationStructuresPropertiesKHR)pa(device, "vkWriteAccelerationStructuresPropertiesKHR");
    dt->CmdCopyAccelerationStructureKHR =
        (PFN_vkCmdCopyAccelerationStructureKHR)pa(device, "vkCmdCopyAccelerationStructureKHR");
    dt->CmdCopyAccelerationStructureToMemoryKHR =
        (PFN_vkCmdCopyAccelerationStructureToMemoryKHR)pa(device, "vkCmdCopyAccelerationStructureToMemoryKHR");
    dt->CmdCopyMemoryToAccelerationStructureKHR =
        (PFN_vkCmdCopyMemoryToAccelerationStructureKHR)pa(device, "vkCmdCopyMemoryToAccelerationStructureKHR");
    dt->GetAccelerationStructureDeviceAddressKHR =
        (PFN_vkGetAccelerationStructureDeviceAddressKHR)pa(device, "vkGetAccelerationStructureDeviceAddressKHR");
    dt->CmdWriteAccelerationStructuresPropertiesKHR =
        (PFN_vkCmdWriteAccelerationStructuresPropertiesKHR)pa(device, "vkCmdWriteAccelerationStructuresPropertiesKHR");
    dt->GetDeviceAccelerationStructureCompatibilityKHR = (PFN_vkGetDeviceAccelerationStructureCompatibilityKHR)pa(
        device, "vkGetDeviceAccelerationStructureCompatibilityKHR");
    dt->GetAccelerationStructureBuildSizesKHR =
        (PFN_vkGetAccelerationStructureBuildSizesKHR)pa(device, "vkGetAccelerationStructureBuildSizesKHR");
    dt->CmdTraceRaysKHR = (PFN_vkCmdTraceRaysKHR)pa(device, "vkCmdTraceRaysKHR");
    dt->CreateRayTracingPipelinesKHR = (PFN_vkCreateRayTracingPipelinesKHR)pa(device, "vkCreateRayTracingPipelinesKHR");
    dt->GetRayTracingCaptureReplayShaderGroupHandlesKHR = (PFN_vkGetRayTracingCaptureReplayShaderGroupHandlesKHR)pa(
        device, "vkGetRayTracingCaptureReplayShaderGroupHandlesKHR");
    dt->CmdTraceRaysIndirectKHR = (PFN_vkCmdTraceRaysIndirectKHR)pa(device, "vkCmdTraceRaysIndirectKHR");
    dt->GetRayTracingShaderGroupStackSizeKHR =
        (PFN_vkGetRayTracingShaderGroupStackSizeKHR)pa(device, "vkGetRayTracingShaderGroupStackSizeKHR");
    dt->CmdSetRayTracingPipelineStackSizeKHR =
        (PFN_vkCmdSetRayTracingPipelineStackSizeKHR)pa(device, "vkCmdSetRayTracingPipelineStackSizeKHR");
    dt->CmdDrawMeshTasksEXT = (PFN_vkCmdDrawMeshTasksEXT)pa(device, "vkCmdDrawMeshTasksEXT");
    dt->CmdDrawMeshTasksIndirectEXT = (PFN_vkCmdDrawMeshTasksIndirectEXT)pa(device, "vkCmdDrawMeshTasksIndirectEXT");
    dt->CmdDrawMeshTasksIndirectCountEXT =
        (PFN_vkCmdDrawMeshTasksIndirectCountEXT)pa(device, "vkCmdDrawMeshTasksIndirectCountEXT");
};

}  // namespace crash_diagnostic_layer

// NOLINTEND
