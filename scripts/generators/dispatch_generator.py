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

import os
import sys
from generators.vulkan_object import (Queues, CommandScope)
from generators.cdl_base_generator import CdlBaseOutputGenerator
#
# DispatchOutputGenerator - Generate the dispatch tables
class DispatchOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'dispatch.h':
            self.generateHeader()
        elif self.filename == 'dispatch.cpp':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once\n')
        self.write('#include <vulkan/vk_layer.h>')
        self.write('#include <vulkan/vulkan.h>')
        self.write(self.GenerateNamespaceBegin())

        out = []
        out.append('\nstruct InstanceDispatchTable {\n')
        for vkcommand in filter(lambda x: self.InstanceCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  PFN_{vkcommand.name} {vkcommand.name[2:]};\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n\n')

        out.append('struct DeviceDispatchTable {\n')
        for vkcommand in filter(lambda x: not self.InstanceCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  PFN_{vkcommand.name} {vkcommand.name[2:]};\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n')

        out.append('''
void InitInstanceDispatchTable(VkInstance instance,
                               PFN_vkGetInstanceProcAddr pa,
                               InstanceDispatchTable *dt);
void InitDeviceDispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr pa,
                             DeviceDispatchTable *dt);
''')
        self.write("".join(out))
        self.write(self.GenerateNamespaceEnd())

    def generateSource(self):
        self.write('#include "dispatch.h"')
        self.write(self.GenerateNamespaceBegin())

        out = []
        out.append('''
void InitInstanceDispatchTable(VkInstance instance,
                               PFN_vkGetInstanceProcAddr pa,
                               InstanceDispatchTable *dt) {
''')
        # The android loader complains if you look up these functions with a non-null instance handle
        global_commands = ('vkCreateInstance', 'vkEnumerateInstanceExtensionProperties')
        for vkcommand in filter(lambda x: self.InstanceCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  dt->{vkcommand.name[2:]} =\n')
            instance_param = 'instance' if vkcommand.name not in global_commands else 'VK_NULL_HANDLE'
            out.append(f'    (PFN_{vkcommand.name})pa({instance_param}, "{vkcommand.name}");\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n\n')

        out.append('''void InitDeviceDispatchTable(VkDevice device, PFN_vkGetDeviceProcAddr pa,
                             DeviceDispatchTable *dt) {
''')
        for vkcommand in filter(lambda x: not self.InstanceCommand(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  dt->{vkcommand.name[2:]} =\n')
            out.append(f'    (PFN_{vkcommand.name})pa(device, "{vkcommand.name}");\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n\n')

        self.write("".join(out))
        self.write(self.GenerateNamespaceEnd())

