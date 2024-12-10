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
 *
 ****************************************************************************/

#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

#include "layer_base.h"

namespace crash_diagnostic_layer {

constexpr VkLayerProperties kLayerProperties{"VK_LAYER_LUNARG_crash_diagnostic", VK_HEADER_VERSION, 1,
                                             "Crash Diagnostic Layer is a crash/hang debugging tool that helps "
                                             "determines GPU progress in a Vulkan application."};

constexpr VkPhysicalDeviceToolPropertiesEXT kToolProperties{
    VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT,
    nullptr,
    "VK_LAYER_LUNARG_crash_diagnostic",
    "1",
    VK_TOOL_PURPOSE_TRACING_BIT_EXT | VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT | VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT,
    "Crash Diagnostic Layer is a crash/hang debugging tool that helps determines GPU progress in a Vulkan application.",
    "VK_LAYER_LUNARG_crash_diagnostic",
};

namespace {

// Generally we expect to get the same device and instance, so we keep them handy
static thread_local InstanceData* last_used_instance_data = nullptr;
static thread_local DeviceData* last_used_device_data = nullptr;

std::mutex g_instance_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<InstanceData>> g_instance_data;

std::mutex g_device_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<DeviceData>> g_device_data;

}  // namespace

uintptr_t DataKey(const void* object) { return (uintptr_t)(*(void**)object); }

InstanceData* GetInstanceLayerData(uintptr_t key) {
    if (last_used_instance_data && DataKey(last_used_instance_data->instance) == key) {
        return last_used_instance_data;
    }

    std::lock_guard<std::mutex> lock(g_instance_mutex);
    last_used_instance_data = g_instance_data[key].get();
    return last_used_instance_data;
}

void FreeInstanceLayerData(uintptr_t key) {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    g_instance_data.erase(key);
    last_used_instance_data = nullptr;
}

DeviceData* GetDeviceLayerData(uintptr_t key) {
    if (last_used_device_data && DataKey(last_used_device_data->device) == key) {
        return last_used_device_data;
    }

    std::lock_guard<std::mutex> lock(g_device_mutex);
    last_used_device_data = g_device_data[key].get();
    return last_used_device_data;
}

void FreeDeviceLayerData(uintptr_t key) {
    std::lock_guard<std::mutex> lock(g_device_mutex);
    g_device_data.erase(key);
    last_used_device_data = nullptr;
}

static VkStruct* FindOnChain(VkStruct* s, VkStructureType type) {
    VkStruct* n = (VkStruct*)s->pNext;
    while (n && n->sType != type) {
        n = (VkStruct*)n->pNext;
    }
    return n;
}

VkLayerInstanceCreateInfo* GetLoaderInstanceInfo(const VkInstanceCreateInfo* create_info, VkLayerFunction func_type) {
    VkStruct* n = (VkStruct*)create_info;
    while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO))) {
        VkLayerInstanceCreateInfo* vci = (VkLayerInstanceCreateInfo*)n;
        if (vci->function == func_type) {
            return vci;
        }
    }
    return nullptr;
}

VkLayerDeviceCreateInfo* GetLoaderDeviceInfo(const VkDeviceCreateInfo* create_info, VkLayerFunction func_type) {
    VkStruct* n = (VkStruct*)create_info;
    while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))) {
        VkLayerDeviceCreateInfo* vdi = (VkLayerDeviceCreateInfo*)n;
        if (vdi->function == func_type) {
            return vdi;
        }
    }
    return nullptr;
}

VkResult SetInstanceLoaderData(VkInstance instance, void* obj) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(instance));
    return instance_data->pfn_set_instance_loader_data(instance, obj);
}

VkResult SetDeviceLoaderData(VkDevice device, void* obj) {
    DeviceData* device_data = GetDeviceLayerData(DataKey(device));
    return device_data->pfn_set_device_loader_data(device, obj);
}

// Declare the list of implemented instance and device extensions.

static constexpr std::array<VkExtensionProperties, 3> instance_extensions{{
    {VK_EXT_DEBUG_REPORT_EXTENSION_NAME, VK_EXT_DEBUG_REPORT_SPEC_VERSION},
    {VK_EXT_DEBUG_UTILS_EXTENSION_NAME, VK_EXT_DEBUG_UTILS_SPEC_VERSION},
    {VK_EXT_LAYER_SETTINGS_EXTENSION_NAME, VK_EXT_LAYER_SETTINGS_SPEC_VERSION},
}};
static constexpr std::array<VkExtensionProperties, 1> device_extensions{{
    {VK_EXT_TOOLING_INFO_EXTENSION_NAME, VK_EXT_TOOLING_INFO_SPEC_VERSION},
}};

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassInstanceProcDownTheChain(VkInstance inst, const char* func) {
    // Get the instance data.
    auto id = GetInstanceLayerData(DataKey(inst));
    // Pass down the instance proc address call through the chain.
    return (PFN_vkVoidFunction)id->pfn_next_instance_proc_addr(inst, func);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassDeviceProcDownTheChain(VkDevice dev, const char* func) {
    // Get the device data.
    auto dd = GetDeviceLayerData(DataKey(dev));
    // Pass down the device proc address call through the chain.
    return (PFN_vkVoidFunction)dd->pfn_next_device_proc_addr(dev, func);
}

/*****************************************************************************/
/*                         Custom Intercept Functions                        */
/*****************************************************************************/

VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateInstance(const VkInstanceCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
    // Find the create info
    VkLayerInstanceCreateInfo* layer_create_info = GetLoaderInstanceInfo(pCreateInfo, VK_LAYER_LINK_INFO);
    if (layer_create_info == NULL) {
        // No loader instance create info
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    PFN_vkGetInstanceProcAddr pfn_get_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkCreateInstance pfn_create_instance =
        (PFN_vkCreateInstance)pfn_get_instance_proc_addr(NULL, "vkCreateInstance");
    if (pfn_create_instance == NULL) return VK_ERROR_INITIALIZATION_FAILED;

    // Move chain on for the next layer.
    layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

    Interceptor* interceptor = nullptr;
    auto result = CreateInstance(pCreateInfo, pAllocator, pInstance, &interceptor);
    if (result != VK_SUCCESS) {
        return result;
    }

    const VkInstanceCreateInfo* pFinalCreateInfo = interceptor->GetModifiedInstanceCreateInfo(pCreateInfo);

    result = pfn_create_instance(pFinalCreateInfo, pAllocator, pInstance);
    if (VK_SUCCESS != result) {
        return result;
    }

    auto id = std::make_unique<InstanceData>();
    id->instance = *pInstance;
    id->interceptor = interceptor;
    auto chain_info = GetLoaderInstanceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
    id->pfn_set_instance_loader_data = chain_info->u.pfnSetInstanceLoaderData;
    id->pfn_next_instance_proc_addr = pfn_get_instance_proc_addr;
    InitInstanceDispatchTable(*pInstance, pfn_get_instance_proc_addr, &id->dispatch_table);

    {
        std::lock_guard<std::mutex> lock(g_instance_mutex);
        g_instance_data[DataKey(*pInstance)] = std::move(id);
    }

    result = interceptor->PostCreateInstance(pFinalCreateInfo, pAllocator, pInstance, result);

    return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator) {
    auto instance_key = DataKey(instance);
    InstanceData* instance_data = GetInstanceLayerData(instance_key);

    instance_data->interceptor->PreDestroyInstance(instance, pAllocator);

    auto pfn_destroy_instance = instance_data->dispatch_table.DestroyInstance;
    pfn_destroy_instance(instance, pAllocator);
    delete instance_data->interceptor;
    FreeInstanceLayerData(instance_key);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateDevice(VkPhysicalDevice gpu, const VkDeviceCreateInfo* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkDevice* pDevice) {
    VkLayerDeviceCreateInfo* layer_create_info = GetLoaderDeviceInfo(pCreateInfo, VK_LAYER_LINK_INFO);

    // Get the instance data.
    auto instance_data = GetInstanceLayerData(DataKey(gpu));

    // Get the proc addr pointers for this layer and update the chain for the next
    // layer.
    PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
    PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
    PFN_vkCreateDevice pfn_create_device =
        (PFN_vkCreateDevice)pfn_next_instance_proc_addr(instance_data->instance, "vkCreateDevice");
    layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

    const VkDeviceCreateInfo* pFinalCreateInfo =
        instance_data->interceptor->GetModifiedDeviceCreateInfo(gpu, pCreateInfo);

    auto result = pfn_create_device(gpu, pFinalCreateInfo, pAllocator, pDevice);
    if (VK_SUCCESS != result) {
        return result;
    }

    auto dd = std::make_unique<DeviceData>();
    dd->device = *pDevice;
    dd->interceptor = instance_data->interceptor;
    auto chain_info = GetLoaderDeviceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
    dd->pfn_set_device_loader_data = chain_info->u.pfnSetDeviceLoaderData;
    dd->pfn_next_device_proc_addr = pfn_next_device_proc_addr;
    InitDeviceDispatchTable(*pDevice, pfn_next_device_proc_addr, &dd->dispatch_table);
    {
        std::lock_guard<std::mutex> lock(g_device_mutex);
        g_device_data[DataKey(*pDevice)] = std::move(dd);
    }

    result = instance_data->interceptor->PostCreateDevice(gpu, pFinalCreateInfo, pAllocator, pDevice, result);

    return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator) {
    auto device_key = DataKey(device);
    DeviceData* device_data = GetDeviceLayerData(device_key);
    device_data->interceptor->PreDestroyDevice(device, pAllocator);
    auto pfn_destroy_device = device_data->dispatch_table.DestroyDevice;
    pfn_destroy_device(device, pAllocator);

    FreeDeviceLayerData(device_key);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptQueueSubmit(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits,
                                                    VkFence fence) {
    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit(queue, submitCount, pSubmits, fence);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptQueueBindSparse(VkQueue queue, uint32_t bindInfoCount,
                                                        const VkBindSparseInfo* pBindInfo, VkFence fence) {
    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptQueueSubmit2(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits,
                                                     VkFence fence) {
    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit2(queue, submitCount, pSubmits, fence);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptQueueSubmit2KHR(VkQueue queue, uint32_t submitCount,
                                                        const VkSubmitInfo2* pSubmits, VkFence fence) {
    auto layer_data = GetDeviceLayerData(DataKey(queue));
    return layer_data->interceptor->QueueSubmit2(queue, submitCount, pSubmits, fence);
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptEnumerateInstanceLayerProperties(uint32_t* pPropertyCount,
                                                                         VkLayerProperties* pProperties) {
    if (pProperties != nullptr && *pPropertyCount > 0) {
        *pProperties = kLayerProperties;
    }
    *pPropertyCount = 1;
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice,
                                                                       uint32_t* pPropertyCount,
                                                                       VkLayerProperties* pProperties) {
    if (pProperties != nullptr && *pPropertyCount > 0) {
        *pProperties = kLayerProperties;
    }
    *pPropertyCount = 1;
    return VK_SUCCESS;
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptEnumerateInstanceExtensionProperties(const char* pLayerName,
                                                                             uint32_t* pPropertyCount,
                                                                             VkExtensionProperties* pProperties) {
    if (pLayerName && !strcmp(pLayerName, kLayerProperties.layerName)) {
        const uint32_t count = static_cast<uint32_t>(instance_extensions.size());
        if (pProperties == nullptr) {
            *pPropertyCount = count;
            return VK_SUCCESS;
        }
        const uint32_t copy_size = *pPropertyCount < count ? *pPropertyCount : count;
        std::memcpy(pProperties, instance_extensions.data(), copy_size * sizeof(VkExtensionProperties));
        *pPropertyCount = copy_size;
        return (copy_size < count) ? VK_INCOMPLETE : VK_SUCCESS;
    }
    return VK_ERROR_LAYER_NOT_PRESENT;
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                           const char* pLayerName,
                                                                           uint32_t* pPropertyCount,
                                                                           VkExtensionProperties* pProperties) {
    if (pLayerName && !strcmp(pLayerName, kLayerProperties.layerName)) {
        const uint32_t count = static_cast<uint32_t>(device_extensions.size());
        if (pProperties == nullptr) {
            *pPropertyCount = count;
            return VK_SUCCESS;
        }
        const uint32_t copy_size = *pPropertyCount < count ? *pPropertyCount : count;
        std::memcpy(pProperties, device_extensions.data(), copy_size * sizeof(VkExtensionProperties));
        *pPropertyCount = copy_size;
        return (copy_size < count) ? VK_INCOMPLETE : VK_SUCCESS;
    }

    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));

    VkResult result = instance_data->dispatch_table.EnumerateDeviceExtensionProperties(physicalDevice, pLayerName, pPropertyCount, pProperties);

    result = instance_data->interceptor->PostEnumerateDeviceExtensionProperties(physicalDevice, pLayerName,
                                                                                pPropertyCount, pProperties, result);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptGetPhysicalDeviceToolProperties(
    VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));
    VkResult result = VK_SUCCESS;
    if (pToolProperties != nullptr && *pToolCount > 0) {
        *pToolProperties = kToolProperties;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    if (instance_data->dispatch_table.GetPhysicalDeviceToolProperties == nullptr) {
        // This layer is the terminator.
        *pToolCount = 0;
    } else {
        result =
            instance_data->dispatch_table.GetPhysicalDeviceToolProperties(physicalDevice, pToolCount, pToolProperties);
    }
    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InterceptGetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolProperties* pToolProperties) {
    InstanceData* instance_data = GetInstanceLayerData(DataKey(physicalDevice));
    VkResult result = VK_SUCCESS;
    if (pToolProperties != nullptr && *pToolCount > 0) {
        *pToolProperties = kToolProperties;
        pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
        (*pToolCount)--;
    }
    if (instance_data->dispatch_table.GetPhysicalDeviceToolPropertiesEXT == nullptr) {
        // This layer is the terminator.
        *pToolCount = 0;
    } else {
        result = instance_data->dispatch_table.GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount,
                                                                                  pToolProperties);
    }
    return result;
}

#include "layer_base.cpp.inc"

}  // namespace crash_diagnostic_layer

extern "C" {

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetInstanceProcAddr(VkInstance inst, const char* func) {
    const auto& name_map = crash_diagnostic_layer::GetNameToFuncPtrMap();
    const auto& item = name_map.find(func);
    if (item != name_map.end()) {
        return reinterpret_cast<PFN_vkVoidFunction>(item->second.funcptr);
    }
    return (PFN_vkVoidFunction)crash_diagnostic_layer::PassInstanceProcDownTheChain(inst, func);
}

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL vkGetDeviceProcAddr(VkDevice dev, const char* func) {
    const auto& name_map = crash_diagnostic_layer::GetNameToFuncPtrMap();
    const auto& item = name_map.find(func);
    if (item != name_map.end()) {
        if (item->second.function_type != crash_diagnostic_layer::kFuncTypeDev) {
            // See https://gitlab.khronos.org/vulkan/vulkan/-/merge_requests/6583
            // Validation will emit a warning if this happens
            return nullptr;
        } else {
            return reinterpret_cast<PFN_vkVoidFunction>(item->second.funcptr);
        }
    }
    return (PFN_vkVoidFunction)crash_diagnostic_layer::PassDeviceProcDownTheChain(dev, func);
}

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceLayerProperties(uint32_t* pPropertyCount,
                                                                         VkLayerProperties* pProperties) {
    return crash_diagnostic_layer::InterceptEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateInstanceExtensionProperties(const char* pLayerName,
                                                                        uint32_t* pPropertyCount,
                                                                        VkExtensionProperties* pProperties) {
    return crash_diagnostic_layer::InterceptEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice, uint32_t* pCount,
                                                                           VkLayerProperties* pProperties) {
    return crash_diagnostic_layer::InterceptEnumerateDeviceLayerProperties(physicalDevice, pCount, pProperties);
}

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL vkEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                                               const char* pLayerName, uint32_t* pCount,
                                                                               VkExtensionProperties* pProperties) {
    return crash_diagnostic_layer::InterceptEnumerateDeviceExtensionProperties(VK_NULL_HANDLE, pLayerName, pCount, pProperties);
}
#endif

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL
vkNegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct) {
    assert(pVersionStruct != NULL);
    assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);
    // Fill in the function pointers if our version is at least capable of having
    // the structure contain them.
    if (pVersionStruct->loaderLayerInterfaceVersion >= 2) {
        pVersionStruct->pfnGetInstanceProcAddr = &vkGetInstanceProcAddr;
        pVersionStruct->pfnGetDeviceProcAddr = &vkGetDeviceProcAddr;
        pVersionStruct->pfnGetPhysicalDeviceProcAddr = nullptr;
    }
    if (pVersionStruct->loaderLayerInterfaceVersion > CURRENT_LOADER_LAYER_INTERFACE_VERSION) {
        pVersionStruct->loaderLayerInterfaceVersion = CURRENT_LOADER_LAYER_INTERFACE_VERSION;
    }
    return VK_SUCCESS;
}


}  // extern "C"

// NOLINTEND
