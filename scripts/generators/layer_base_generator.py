#!/usr/bin/python3 -i
#
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

import os
import sys
from generators.vulkan_object import (Queues, CommandScope)
from generators.gfr_base_generator import GfrBaseOutputGenerator

#
# LayerBaseOutputGenerator - Generate command print utilities
class LayerBaseOutputGenerator(GfrBaseOutputGenerator):
    def __init__(self):
        GfrBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)
        if self.filename == 'layer_base.h':
            self.generateHeader()
        elif self.filename == 'layer_base.cc':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')
        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once')

        out = []
        out.append('''

#include <cassert>
#include <cstring>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vulkan/vk_layer.h>
#include <vulkan/vulkan.h>

#include "dispatch.h"
''')

        out.append(self.GenerateNamespaceBegin())

        out.append('''

typedef VkResult (VKAPI_PTR *PFN_vkSetInstanceLoaderData)(VkInstance instance, void* object);
typedef VkResult (VKAPI_PTR *PFN_vkSetDeviceLoaderData)(VkDevice device, void* object);

// Functions defined elsewhere but used in the matching source file
VkResult CreateDevice(PFN_vkCreateDevice pfn, VkPhysicalDevice physicalDevice,
                      const VkDeviceCreateInfo *pCreateInfo,
                      const VkAllocationCallbacks *pAllocator,
                      VkDevice *pDevice);
void DestroyDevice(PFN_vkDestroyDevice pfn, VkDevice device,
                   const VkAllocationCallbacks *pAllocator);

// Declare our per-instance and per-device contexts.
// These are created and initialized in vkCreateInstance and vkCreateDevice.
struct InstanceData {
  VkInstance instance;
  InstanceDispatchTable dispatch_table;
  PFN_vkSetInstanceLoaderData pfn_set_instance_loader_data = nullptr;
  PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr = nullptr;
};

struct DeviceData {
  VkDevice device;
  DeviceDispatchTable dispatch_table;
  PFN_vkSetDeviceLoaderData pfn_set_device_loader_data = nullptr;
  PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr = nullptr;
};

uintptr_t DataKey(const void *object);
InstanceData* GetInstanceLayerData(uintptr_t key);
DeviceData* GetDeviceLayerData(uintptr_t key);

struct VkStruct {
  VkStructureType sType;
  const void*     pNext;
};

VkStruct *FindOnChain(VkStruct *s, VkStructureType type);

VkLayerInstanceCreateInfo *GetLoaderInstanceInfo(
    const VkInstanceCreateInfo *create_info, VkLayerFunction func_type);
VkLayerDeviceCreateInfo *GetLoaderDeviceInfo(
    const VkDeviceCreateInfo *create_info, VkLayerFunction func_type);

VkResult SetInstanceLoaderData(VkInstance instance, void *obj);
VkResult SetDeviceLoaderData(VkDevice device, void *obj);

const VkInstanceCreateInfo *
GetModifiedInstanceCreateInfo(const VkInstanceCreateInfo *pCreateInfo);

const VkDeviceCreateInfo *
GetModifiedDeviceCreateInfo(VkPhysicalDevice physicalDevice,
                            const VkDeviceCreateInfo *pCreateInfo);
''')
        self.write("".join(out))

        self.write("\n// Declare layer version of Vulkan API functions.\n")
        out = []
        for vkcommand in filter(lambda x: self.InterceptCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_call = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' Intercept')
            out.append(f'{func_call}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Declare pre-intercept functions.\n")
        out = []
        for vkcommand in filter(lambda x: self.InterceptPreCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_call = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' InterceptPre')
            out.append(f'{func_call}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Declare post-intercept functions.\n")
        out = []
        for vkcommand in filter(lambda x: self.InterceptPostCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_call = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' InterceptPost')

            if vkcommand.returnType is not None and vkcommand.returnType != 'void':
                func_call = func_call.replace(');', f',\n    {vkcommand.returnType}                                    result);')

            out.append(f'{func_call}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

        out = []

        out.append(self.GenerateNamespaceEnd())
        out.append('''

#if defined(__GNUC__) && __GNUC__ >= 4
#define GFR_EXPORT __attribute__((visibility("default")))
#else
#define GFR_EXPORT
#endif

extern "C" {

GFR_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL
GFR_GetInstanceProcAddr(VkInstance inst, const char* func);

GFR_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL
GFR_GetDeviceProcAddr(VkDevice dev, const char* func);

GFR_EXPORT VKAPI_ATTR VkResult VKAPI_CALL
GFR_NegotiateLoaderLayerInterfaceVersion(
    VkNegotiateLayerInterface* pVersionStruct);

} // extern "C"
''')
        self.write("".join(out))

    def generateSource(self):
        out = []
        out.append('''
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
''')

        out.append(self.GenerateNamespaceBegin())

        out.append('\nconstexpr VkLayerProperties layer_properties = {\n')
        layer_name = self.GetLayerName()
        layer_version = self.GetLayerVersion()
        layer_description = self.GetLayerDescription()
        out.append(f'    "{layer_name}", VK_HEADER_VERSION,\n')
        out.append(f'    {layer_version},\n')
        out.append(f'    "{layer_description}"\n')
        out.append('};\n')

        out.append('''
namespace {

// Generally we expect to get the same device and instance, so we keep them handy
static thread_local InstanceData* last_used_instance_data = nullptr;
static thread_local DeviceData* last_used_device_data = nullptr;

std::mutex g_instance_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<InstanceData>> g_instance_data;

std::mutex g_device_mutex;
std::unordered_map<uintptr_t, std::unique_ptr<DeviceData>> g_device_data;

} // namespace

uintptr_t DataKey(const void *object) {
   return (uintptr_t)(*(void **)object);
}

InstanceData* GetInstanceLayerData(uintptr_t key) {
  if (last_used_instance_data &&
      DataKey(last_used_instance_data->instance) == key) {
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
  if (last_used_device_data &&
      DataKey(last_used_device_data->device) == key) {
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

VkStruct *FindOnChain(VkStruct *s, VkStructureType type) {
  VkStruct *n = (VkStruct *)s->pNext;
  while (n && n->sType != type) {
    n = (VkStruct *)n->pNext;
  }
  return n;
}

VkLayerInstanceCreateInfo *GetLoaderInstanceInfo(
    const VkInstanceCreateInfo *create_info, VkLayerFunction func_type) {
  VkStruct *n = (VkStruct *)create_info;
  while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO))) {
    VkLayerInstanceCreateInfo *vci = (VkLayerInstanceCreateInfo *)n;
    if (vci->function == func_type) {
      return vci;
    }
  }
  return nullptr;
}

VkLayerDeviceCreateInfo *GetLoaderDeviceInfo(
    const VkDeviceCreateInfo *create_info, VkLayerFunction func_type) {
  VkStruct *n = (VkStruct *)create_info;
  while ((n = FindOnChain(n, VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO))) {
    VkLayerDeviceCreateInfo *vdi = (VkLayerDeviceCreateInfo *)n;
    if (vdi->function == func_type) {
      return vdi;
    }
  }
  return nullptr;
}

VkResult SetInstanceLoaderData(VkInstance instance, void *obj)
{
  InstanceData *instance_data = GetInstanceLayerData(DataKey(instance));
  return instance_data->pfn_set_instance_loader_data(instance, obj);
}

VkResult SetDeviceLoaderData(VkDevice device, void *obj)
{
  DeviceData *device_data = GetDeviceLayerData(DataKey(device));
  return device_data->pfn_set_device_loader_data(device, obj);
}

''')
        self.write("".join(out))

        self.write("\n// Declare the list of implemented instance and device extensions.\n")
        out = []
        out.append(f'static constexpr std::array<VkExtensionProperties, {len(self.implemented_instance_extensions)}> instance_extensions{{{{\n')
        for vkext in self.vk.extensions.values():
            if vkext.device or not (vkext.name in self.implemented_instance_extensions):
                continue
            version_string = vkext.nameString.replace('EXTENSION_NAME', 'SPEC_VERSION')
            out.append(f'    {{{vkext.nameString}, {version_string}}},\n')
        out.append("}};\n")
        out.append(f'static constexpr std::array<VkExtensionProperties, {len(self.implemented_device_extensions)}> device_extensions{{{{\n')
        for vkext in self.vk.extensions.values():
            if vkext.instance or not (vkext.name in self.implemented_device_extensions):
                continue
            version_string = vkext.nameString.replace('EXTENSION_NAME', 'SPEC_VERSION')
            out.append(f'    {{{vkext.nameString}, {version_string}}},\n')
        out.append("}};\n")
        self.write("".join(out))

        self.write("\n// Implement layer version of Vulkan API functions.\n")
        out = []
        #for vkcommand in filter(lambda x: x.name not in self.custom_intercept_commands, self.vk.commands.values()):
        for vkcommand in filter(lambda x: self.InterceptCommand(x) and (not x.name in self.custom_intercept_commands), self.vk.commands.values()):
            lower_function_call = vkcommand.name + '('
            count = 0
            for vkparam in vkcommand.params:
                if count > 0:
                    lower_function_call += ', '
                lower_function_call += vkparam.name
                count += 1
            lower_function_call += ');\n'

            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_call = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' Intercept').replace(';', ' {')
            out.append(f'{func_call}\n')

            if self.CommandHasReturn(vkcommand):
                default_value = self.GetDefaultReturnValue(vkcommand.returnType)
                out.append(f'  {vkcommand.returnType} result = {default_value};\n')
                out.append('\n')

            if self.InterceptPreCommand(vkcommand):
              pre_func = lower_function_call.replace('vk', 'InterceptPre')
              out.append(f'  {pre_func}')
              out.append('\n')

            if self.InstanceCommand(vkcommand):
                out.append(f'  auto layer_data = GetInstanceLayerData(DataKey({vkcommand.params[0].name}));\n')
            else:
                out.append(f'  auto layer_data = GetDeviceLayerData(DataKey({vkcommand.params[0].name}));\n')
            out.append(f'  PFN_{vkcommand.name} pfn = layer_data->dispatch_table.{vkcommand.name[2:]};\n')
            out.append('  if (pfn != nullptr) {\n')
            out.append('    ')
            if self.CommandHasReturn(vkcommand):
                out.append('result = ')
            pfn_call = lower_function_call.replace(f'{vkcommand.name}', 'pfn')
            out.append(f'{pfn_call}')
            out.append('  }\n')
            out.append('\n')

            if self.InterceptPostCommand(vkcommand):
              out.append('  ')
              post_call = lower_function_call.replace('vk', 'InterceptPost')
              if self.CommandHasReturn(vkcommand):
                  out.append('result = ')
                  post_call = post_call.replace(')', ', result)')
              out.append(f'{post_call}')

            if self.CommandHasReturn(vkcommand):
                out.append('  return result;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

        out = []
        out.append('''
VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassInstanceProcDownTheChain(
  VkInstance inst, const char* func) {
  // Get the instance data.
  auto id = GetInstanceLayerData(DataKey(inst));
  // Pass down the instance proc address call through the chain.
  return (PFN_vkVoidFunction)id->pfn_next_instance_proc_addr(inst, func);
}

VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL PassDeviceProcDownTheChain(
  VkDevice dev, const char* func) {
  // Get the device data.
  auto dd = GetDeviceLayerData(DataKey(dev));
  // Pass down the device proc address call through the chain.
  return (PFN_vkVoidFunction)dd->pfn_next_device_proc_addr(dev, func);
}

/*****************************************************************************/
/*                         Custom Intercept Functions                        */
/*****************************************************************************/

VKAPI_ATTR VkResult VKAPI_CALL InterceptCreateInstance(const VkInstanceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkInstance* pInstance) {
  // Find the create info
  VkLayerInstanceCreateInfo *layer_create_info = GetLoaderInstanceInfo(pCreateInfo, VK_LAYER_LINK_INFO);
  if (layer_create_info == NULL)
  {
    // No loader instance create info
    return VK_ERROR_INITIALIZATION_FAILED;
  }

  PFN_vkGetInstanceProcAddr pfn_get_instance_proc_addr = layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
  PFN_vkCreateInstance pfn_create_instance = (PFN_vkCreateInstance)pfn_get_instance_proc_addr(NULL, "vkCreateInstance");
  if (pfn_create_instance == NULL) return VK_ERROR_INITIALIZATION_FAILED;

  // Move chain on for the next layer.
  layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

  InterceptPreCreateInstance(pCreateInfo, pAllocator, pInstance);

  const VkInstanceCreateInfo *pFinalCreateInfo = GetModifiedInstanceCreateInfo(pCreateInfo);

  auto result = pfn_create_instance(pFinalCreateInfo, pAllocator, pInstance);
  if (VK_SUCCESS != result)
  {
    return result;
  }

  auto id = std::make_unique<InstanceData>();
  id->instance = *pInstance;
  auto chain_info = GetLoaderInstanceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
  id->pfn_set_instance_loader_data = chain_info->u.pfnSetInstanceLoaderData;
  id->pfn_next_instance_proc_addr = pfn_get_instance_proc_addr;
  InitInstanceDispatchTable(*pInstance, pfn_get_instance_proc_addr, &id->dispatch_table);

  {
    std::lock_guard<std::mutex> lock(g_instance_mutex);
    g_instance_data[DataKey(*pInstance)] = std::move(id);
  }

  result = InterceptPostCreateInstance(pFinalCreateInfo, pAllocator, pInstance, result);

  return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyInstance(
    VkInstance instance, const VkAllocationCallbacks *pAllocator) {

  auto instance_key = DataKey(instance);
  InstanceData *instance_data = GetInstanceLayerData(instance_key);
  auto pfn_destroy_instance = instance_data->dispatch_table.DestroyInstance;
  pfn_destroy_instance(instance, pAllocator);

  FreeInstanceLayerData(instance_key);
}

VkResult InterceptCreateDevice(VkPhysicalDevice gpu,
                               const VkDeviceCreateInfo *pCreateInfo,
                               const VkAllocationCallbacks *pAllocator,
                               VkDevice *pDevice) {

  VkLayerDeviceCreateInfo *layer_create_info =
      GetLoaderDeviceInfo(pCreateInfo, VK_LAYER_LINK_INFO);

  // Get the instance data.
  auto instance_data = GetInstanceLayerData(DataKey(gpu));

  // Get the proc addr pointers for this layer and update the chain for the next
  // layer.
  PFN_vkGetInstanceProcAddr pfn_next_instance_proc_addr =
      layer_create_info->u.pLayerInfo->pfnNextGetInstanceProcAddr;
  PFN_vkGetDeviceProcAddr pfn_next_device_proc_addr =
      layer_create_info->u.pLayerInfo->pfnNextGetDeviceProcAddr;
  PFN_vkCreateDevice pfn_create_device =
      (PFN_vkCreateDevice)pfn_next_instance_proc_addr(instance_data->instance,
                                                      "vkCreateDevice");
  layer_create_info->u.pLayerInfo = layer_create_info->u.pLayerInfo->pNext;

  const VkDeviceCreateInfo *pFinalCreateInfo =
      GetModifiedDeviceCreateInfo(gpu, pCreateInfo);

  VkResult result = CreateDevice(pfn_create_device, gpu, pFinalCreateInfo,
                                 pAllocator, pDevice);
  if (VK_SUCCESS != result) {
    return result;
  }

  auto dd = std::make_unique<DeviceData>();
  dd->device = *pDevice;
  auto chain_info =
      GetLoaderDeviceInfo(pFinalCreateInfo, VK_LOADER_DATA_CALLBACK);
  dd->pfn_set_device_loader_data = chain_info->u.pfnSetDeviceLoaderData;
  dd->pfn_next_device_proc_addr = pfn_next_device_proc_addr;
  InitDeviceDispatchTable(*pDevice, pfn_next_device_proc_addr,
                          &dd->dispatch_table);
  {
    std::lock_guard<std::mutex> lock(g_device_mutex);
    g_device_data[DataKey(*pDevice)] = std::move(dd);
  }

  result = InterceptPostCreateDevice(gpu, pFinalCreateInfo, pAllocator, pDevice,
                                     result);

  return result;
}

VKAPI_ATTR void VKAPI_CALL InterceptDestroyDevice(
    VkDevice device, const VkAllocationCallbacks *pAllocator) {

  auto device_key = DataKey(device);
  DeviceData *device_data = GetDeviceLayerData(device_key);
  auto pfn_destroy_device = device_data->dispatch_table.DestroyDevice;
  pfn_destroy_device(device, pAllocator);

  FreeDeviceLayerData(device_key);
}

VkResult
InterceptEnumerateInstanceLayerProperties(uint32_t *pPropertyCount,
                                          VkLayerProperties *pProperties) {

  VkResult result = VK_SUCCESS;
  uint32_t copy_count = *pPropertyCount;
  if (pProperties != nullptr && *pPropertyCount > 0) {
    *pProperties = layer_properties;
  }
  *pPropertyCount = 1;
  return result;
}

VkResult
InterceptEnumerateDeviceLayerProperties(VkPhysicalDevice physicalDevice,
                                        uint32_t *pPropertyCount,
                                        VkLayerProperties *pProperties) {
  (void)physicalDevice;
  VkResult result = VK_SUCCESS;
  uint32_t copy_count = *pPropertyCount;
  if (pProperties != nullptr && *pPropertyCount > 0) {
    *pProperties = layer_properties;
  }
  *pPropertyCount = 1;
  return result;
}

VkResult InterceptEnumerateInstanceExtensionProperties(const char *pLayerName,
                                                       uint32_t *pPropertyCount,
                                                       VkExtensionProperties *pProperties) {
  bool layer_requested = (nullptr == pLayerName ||''')
        layer_name = self.GetLayerName()
        out.append(f'        strcmp(pLayerName, "{layer_name}"));\n')
        out.append('''  if (!layer_requested) {
    return VK_ERROR_LAYER_NOT_PRESENT;
  }
  if (nullptr == pProperties) {
    *pPropertyCount += static_cast<uint32_t>(instance_extensions.size());
    return VK_SUCCESS;
  } else if (*pPropertyCount > 0) {
    *pPropertyCount = static_cast<uint32_t>(instance_extensions.size());
    memcpy(pProperties, instance_extensions.data(),
           instance_extensions.size() * sizeof(VkExtensionProperties));
  }
  VkResult result = VK_SUCCESS;

  return result;
}

VkResult InterceptEnumerateDeviceExtensionProperties(VkPhysicalDevice physicalDevice,
                                                     const char *pLayerName,
                                                     uint32_t *pPropertyCount,
                                                     VkExtensionProperties *pProperties) {

  // we want to append our extensions, removing duplicates.
  InstanceData *instance_data = GetInstanceLayerData(DataKey(physicalDevice));

  uint32_t num_other_extensions = 0;
  VkResult result =
      instance_data->dispatch_table.EnumerateDeviceExtensionProperties(
          physicalDevice, nullptr, &num_other_extensions, nullptr);
  if (result != VK_SUCCESS) {
    return result;
  }

  // call down to get other device properties
  std::vector<VkExtensionProperties> extensions(num_other_extensions);
  result = instance_data->dispatch_table.EnumerateDeviceExtensionProperties(
      physicalDevice, pLayerName, &num_other_extensions, &extensions[0]);

  // add our extensions if we have any and requested
  bool layer_requested =''')
        layer_name = self.GetLayerName()
        out.append(f'      (nullptr == pLayerName || strcmp(pLayerName, "{layer_name}"));\n')
        out.append('''
  if (result == VK_SUCCESS && layer_requested) {
    // not just our layer, we expose all our extensions
    uint32_t max_extensions = *pPropertyCount;

    // set and copy base extensions
    *pPropertyCount = num_other_extensions;

    // find our unique extensions that need to be added
    uint32_t num_additional_extensions = 0;
    auto num_device_extensions = device_extensions.size();
    std::vector<const VkExtensionProperties *> additional_extensions(
        num_device_extensions);

    for (size_t i = 0; i < num_device_extensions; ++i) {
      bool is_unique_extension = true;

      for (size_t j = 0; j < num_other_extensions; ++j) {
        if (0 == strcmp(extensions[j].extensionName,
                        device_extensions[i].extensionName)) {
          is_unique_extension = false;
          break;
        }
      }

      if (is_unique_extension) {
        additional_extensions[num_additional_extensions++] =
            &device_extensions[i];
      }
    }

    // null properties, just count total extensions
    if (nullptr == pProperties) {
      *pPropertyCount += num_additional_extensions;
    } else {
      uint32_t numExtensions = std::min(num_other_extensions, max_extensions);

      memcpy(pProperties, &extensions[0],
             numExtensions * sizeof(VkExtensionProperties));

      for (size_t i = 0;
           i < num_additional_extensions && numExtensions < max_extensions;
           ++i) {
        pProperties[numExtensions++] = *additional_extensions[i];
      }

      *pPropertyCount = numExtensions;

      // not enough space for all extensions
      if (num_other_extensions + num_additional_extensions > max_extensions) {
        result = VK_INCOMPLETE;
      }
    }
  }

  return result;
}
''')
        self.write("".join(out))

        out = []
        out.append(self.GenerateNamespaceEnd())
        out.append('''
extern "C" {

GFR_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GFR_GetInstanceProcAddr(
    VkInstance inst, const char *func) {
''')
        self.write("".join(out))

        out = []
        for vkcommand in filter(lambda x: self.InstanceCommand(x) and self.InterceptCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'if (0 == strcmp(func, "{vkcommand.name}"))\n')
            out.append(f'  return (PFN_vkVoidFunction)graphics_flight_recorder::Intercept{vkcommand.name[2:]};\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            
        out.append('''
  // If the function was not found, just pass it down the chain to support
  // unregistered extensions, such as vkSwapchainCallbackEXT.
  return (PFN_vkVoidFunction)graphics_flight_recorder::PassInstanceProcDownTheChain(inst, func);
}

GFR_EXPORT VKAPI_ATTR PFN_vkVoidFunction VKAPI_CALL GFR_GetDeviceProcAddr(
    VkDevice dev, const char *func) {
''')
        self.write("".join(out))

        out = []
        for vkcommand in filter(lambda x: not self.InstanceCommand(x) and self.InterceptCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  if (0 == strcmp(func, "{vkcommand.name}"))\n')
            out.append(f'    return (PFN_vkVoidFunction)graphics_flight_recorder::Intercept{vkcommand.name[2:]};\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            
        out.append('''
  // If the function was not found, just pass it down the chain to support
  // unregistered extensions, such as vkSwapchainCallbackEXT.
  return (PFN_vkVoidFunction)graphics_flight_recorder::PassDeviceProcDownTheChain(dev, func);
} // NOLINT(readability/fn_size)

GFR_EXPORT VKAPI_ATTR VkResult VKAPI_CALL GFR_NegotiateLoaderLayerInterfaceVersion(
    VkNegotiateLayerInterface *pVersionStruct) {
  assert(pVersionStruct != NULL);
  assert(pVersionStruct->sType == LAYER_NEGOTIATE_INTERFACE_STRUCT);
  // Fill in the function pointers if our version is at least capable of having
  // the structure contain them.
  if (pVersionStruct->loaderLayerInterfaceVersion >= 2) {
    pVersionStruct->pfnGetInstanceProcAddr = &GFR_GetInstanceProcAddr;
    pVersionStruct->pfnGetDeviceProcAddr = &GFR_GetDeviceProcAddr;
    pVersionStruct->pfnGetPhysicalDeviceProcAddr = nullptr;
  }
  if (pVersionStruct->loaderLayerInterfaceVersion >
      CURRENT_LOADER_LAYER_INTERFACE_VERSION) {
    pVersionStruct->loaderLayerInterfaceVersion =
        CURRENT_LOADER_LAYER_INTERFACE_VERSION;
  }
  return VK_SUCCESS;
}

} // extern "C"

''')
        self.write("".join(out))
