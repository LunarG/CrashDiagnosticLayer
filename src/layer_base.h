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
 ****************************************************************************/

#pragma once

#include <cassert>
#include <cstring>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

#include "dispatch.h"

namespace crash_diagnostic_layer {

typedef VkResult(VKAPI_PTR* PFN_vkSetInstanceLoaderData)(VkInstance instance, void* object);
typedef VkResult(VKAPI_PTR* PFN_vkSetDeviceLoaderData)(VkDevice device, void* object);

class Interceptor;

VkResult CreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator,
                        VkInstance* pInstance, Interceptor** interceptor);

// Declare our per-instance and per-device contexts.
// These are created and initialized in vkCreateInstance and vkCreateDevice.
struct InstanceData {
    VkInstance instance;
    InstanceDispatchTable dispatch_table;
    PFN_vkSetInstanceLoaderData pfn_set_instance_loader_data = nullptr;
    PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr = nullptr;
    Interceptor* interceptor;
};

struct DeviceData {
    VkDevice device;
    DeviceDispatchTable dispatch_table;
    PFN_vkSetDeviceLoaderData pfn_set_device_loader_data = nullptr;
    PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr = nullptr;
    Interceptor* interceptor;
};

uintptr_t DataKey(const void* object);
InstanceData* GetInstanceLayerData(uintptr_t key);
DeviceData* GetDeviceLayerData(uintptr_t key);

struct VkStruct {
    VkStructureType sType;
    const void* pNext;
};

VkLayerInstanceCreateInfo* GetLoaderInstanceInfo(const VkInstanceCreateInfo* create_info, VkLayerFunction func_type);
VkLayerDeviceCreateInfo* GetLoaderDeviceInfo(const VkDeviceCreateInfo* create_info, VkLayerFunction func_type);

VkResult SetInstanceLoaderData(VkInstance instance, void* obj);
VkResult SetDeviceLoaderData(VkDevice device, void* obj);

// Declare interceptor interface.

class Interceptor {
   public:
    virtual ~Interceptor() {}

    virtual const VkInstanceCreateInfo* GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo*) = 0;

    virtual const VkDeviceCreateInfo* GetModifiedDeviceCreateInfo(VkPhysicalDevice, const VkDeviceCreateInfo*) = 0;

#include "layer_base.h.inc"

};

}  // namespace crash_diagnostic_layer

#if defined(__GNUC__) && __GNUC__ >= 4
#define CDL_EXPORT __attribute__((visibility("default")))
#else
#define CDL_EXPORT
#endif

extern "C" {

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetInstanceProcAddr(VkInstance inst, const char* func);

CDL_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL CDL_GetDeviceProcAddr(VkDevice dev, const char* func);

CDL_EXPORT VKAPI_ATTR VkResult VKAPI_CALL
CDL_NegotiateLoaderLayerInterfaceVersion(VkNegotiateLayerInterface* pVersionStruct);

}  // extern "C"

