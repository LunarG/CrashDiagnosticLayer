#!/usr/bin/python3 -i
#
# Copyright (c) 2023-2024 LunarG, Inc.
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

from generators.base_generator import BaseGenerator
from enum import IntEnum

# class syntax
class InterceptFlag(IntEnum):
    PRE = (1 << 0)
    POST = (1 << 1)
    NORMAL = (PRE | POST)
    # Single hook generated rather than Pre/Post. This hook must dispatch the call
    OVERRIDE = (1 << 2)
    # Intercept* function is hand coded
    CUSTOM = (1 << 3)

#NOTE: anything named vkCmd* is implicitly a NORMAL intercept so it doesn't need to be
# in the table below
intercept_functions = {
        'vkAcquireNextImageKHR' : InterceptFlag.NORMAL,
        'vkAllocateCommandBuffers': InterceptFlag.NORMAL,
        'vkCreateCommandPool': InterceptFlag.NORMAL,
        'vkCreateComputePipelines': InterceptFlag.POST,
        'vkCreateDebugReportCallbackEXT': InterceptFlag.NORMAL,
        'vkCreateDebugUtilsMessengerEXT': InterceptFlag.NORMAL,
        'vkCreateDevice': InterceptFlag.CUSTOM | InterceptFlag.POST,
        'vkCreateGraphicsPipelines': InterceptFlag.POST,
        'vkCreateInstance': InterceptFlag.CUSTOM | InterceptFlag.POST,
        'vkCreateSemaphore': InterceptFlag.NORMAL,
        'vkCreateShaderModule': InterceptFlag.POST,
        'vkDebugMarkerSetObjectNameEXT': InterceptFlag.NORMAL,
        'vkDestroyCommandPool': InterceptFlag.NORMAL,
        'vkDestroyDebugReportCallbackEXT': InterceptFlag.NORMAL,
        'vkDestroyDebugUtilsMessengerEXT': InterceptFlag.NORMAL,
        'vkDestroyDevice': InterceptFlag.CUSTOM | InterceptFlag.PRE,
        'vkDestroyInstance': InterceptFlag.CUSTOM | InterceptFlag.PRE,
        'vkDestroyPipeline': InterceptFlag.NORMAL,
        'vkDestroySemaphore': InterceptFlag.NORMAL,
        'vkDestroyShaderModule': InterceptFlag.PRE,
        'vkDeviceWaitIdle': InterceptFlag.NORMAL,
        'vkEnumerateDeviceExtensionProperties': InterceptFlag.CUSTOM | InterceptFlag.POST,
        'vkEnumerateDeviceLayerProperties': InterceptFlag.CUSTOM,
        'vkEnumerateInstanceExtensionProperties': InterceptFlag.CUSTOM,
        'vkEnumerateInstanceLayerProperties': InterceptFlag.CUSTOM,
        'vkFreeCommandBuffers': InterceptFlag.NORMAL,
        'vkGetDeviceQueue': InterceptFlag.POST,
        'vkGetDeviceQueue2': InterceptFlag.POST,
        'vkGetFenceStatus': InterceptFlag.NORMAL,
        'vkGetPhysicalDeviceToolProperties': InterceptFlag.CUSTOM,
        'vkGetPhysicalDeviceToolPropertiesEXT': InterceptFlag.CUSTOM,
        'vkGetQueryPoolResults': InterceptFlag.NORMAL,
        'vkGetSemaphoreCounterValue': InterceptFlag.NORMAL,
        'vkGetSemaphoreCounterValueKHR': InterceptFlag.NORMAL,
        'vkQueueBindSparse': InterceptFlag.OVERRIDE,
        'vkQueuePresentKHR': InterceptFlag.NORMAL,
        'vkQueueSubmit': InterceptFlag.OVERRIDE,
        'vkQueueSubmit2': InterceptFlag.OVERRIDE,
        'vkQueueSubmit2KHR': InterceptFlag.OVERRIDE,
        'vkQueueWaitIdle': InterceptFlag.NORMAL,
        'vkResetCommandPool': InterceptFlag.NORMAL,
        'vkSetDebugUtilsObjectNameEXT': InterceptFlag.NORMAL,
        'vkSignalSemaphore': InterceptFlag.NORMAL,
        'vkSignalSemaphoreKHR': InterceptFlag.NORMAL,
        'vkWaitForFences': InterceptFlag.NORMAL,
        'vkWaitSemaphores': InterceptFlag.NORMAL,
        'vkWaitSemaphoresKHR': InterceptFlag.NORMAL,
}

namespace = 'crash_diagnostic_layer'

#
# CdlBaseOutputGenerator - Base Generator for the whole Crash Diagnostic Layer
class CdlBaseOutputGenerator(BaseGenerator):
    def __init__(self):
        BaseGenerator.__init__(self)
        self.intercept_functions = intercept_functions

    def GenerateFileStart(self, filename):
        file_start = f'''
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
* ***   Update source file {filename} for modifications
* *** ---- WARNING! ----
*
****************************************************************************/\n

// NOLINTBEGIN
'''
        return file_start

    def GenerateFileEnd(self):
        file_end = '\n// NOLINTEND\n'
        return file_end

    def GenerateNamespaceBegin(self):
        namespace_text = f'\nnamespace {namespace} {{\n'
        return namespace_text

    def GenerateNamespaceEnd(self):
        namespace_text = f'\n}} // namespace {namespace}\n'
        return namespace_text

    def CreateNamespaceReference(self, item):
        namespace_text = f'{namespace}::{item}'
        return namespace_text

    def CommandBufferCall(self, command):
        intercept = (command.name.startswith('vkCmd') or
                     command.params[0].type == 'VkCommandBuffer')
        return intercept

    def NeedsIntercept(self, command):
        intercept = (self.CommandBufferCall(command) or
                        intercept_functions.get(command.name, None) is not None)
        return intercept

    def InterceptPreCommand(self, command):
        attrs = intercept_functions.get(command.name, None)
        if attrs is not None:
            return (attrs & InterceptFlag.PRE) != 0
        return self.CommandBufferCall(command)

    def InterceptPostCommand(self, command):
        attrs = intercept_functions.get(command.name, None)
        if attrs is not None:
            return (attrs & InterceptFlag.POST) != 0
        return self.CommandBufferCall(command)

    def InterceptGenerateSource(self, command):
        attrs = intercept_functions.get(command.name, None)
        if attrs is not None:
            return (attrs & InterceptFlag.CUSTOM) == 0
        return self.CommandBufferCall(command)

    def InterceptOverrideCommand(self, command):
        attrs = intercept_functions.get(command.name, None)
        return attrs is not None and (attrs & InterceptFlag.OVERRIDE) != 0

    def InstanceCommand(self, command):
        return command.instance or command.params[0].type == 'VkPhysicalDevice'

    def CommandHasReturn(self, command):
        return command.returnType is not None and command.returnType != 'void'

    def GetDefaultReturnValue(self, return_type):
        return_string = ''
        if return_type == 'VkResult':
            return_string = 'VK_SUCCESS'
        elif return_type in self.vk.structs.values():
            return_string = 'nullptr'
        elif 'int' in return_type and '64' not in return_type:
            return_string = '0'
        elif 'int64' in return_type or 'Address' in return_type or 'Size' in return_type:
            return_string = '0ULL'
        elif return_type == 'VkBool32':
            return_string = 'VK_FALSE'
        elif 'PFN_' in return_type:
            return_string = 'nullptr'
        elif 'PFN_' in return_type:
            return_string = 'UNKNOWN_VALUE'
        return return_string
