#!/usr/bin/python3 -i
#
# Copyright 2023-2024 LunarG, Inc.
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
from generators.cdl_base_generator import CdlBaseOutputGenerator, InterceptFlag

#
# LayerBaseOutputGenerator - Generate command print utilities
class LayerBaseOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)
        if self.filename == 'layer_base.h.inc':
            self.generateHeader()
        elif self.filename == 'layer_base.cpp.inc':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')
        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once')

        out = []
        for vkcommand in self.vk.commands.values():
            attrs = self.intercept_functions.get(vkcommand.name, None)
            if attrs is None:
                if self.CommandBufferCall(vkcommand):
                    attrs = InterceptFlag.NORMAL
                else:
                    continue
            if attrs & InterceptFlag.PRE:
                out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
                func_call = '    virtual ' + vkcommand.cPrototype.replace('\n','\n    ').replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '')
                func_call = func_call.replace(' vk', ' Pre')
                if vkcommand.returnType is not None and vkcommand.returnType != 'void':
                    func_call = func_call.replace(';', ' { return VK_SUCCESS; }')
                else:
                    func_call = func_call.replace(';', ' {}')
                out.append(f'{func_call}\n')
                out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
                out.append('\n')
            if attrs & InterceptFlag.POST:
                out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
                func_call = '    virtual ' + vkcommand.cPrototype.replace('\n', '\n    ').replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '')
                func_call = func_call.replace(' vk', ' Post')

                if vkcommand.returnType is not None and vkcommand.returnType != 'void':
                    func_call = func_call.replace(');', f',\n        {vkcommand.returnType}                                    result);')
                if vkcommand.returnType is not None and vkcommand.returnType != 'void':
                    func_call = func_call.replace(';', ' { return result; }')
                else:
                    func_call = func_call.replace(';', ' {}')
                out.append(f'{func_call}\n')
                out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
                out.append('\n')
            if attrs & InterceptFlag.OVERRIDE:
                out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
                func_call = '    virtual ' + vkcommand.cPrototype.replace('\n', '\n    ').replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '')
                func_call = func_call.replace(' vk', ' ')
                if vkcommand.returnType is not None and vkcommand.returnType != 'void':
                    func_call = func_call.replace(';', ' = 0;')
                out.append(f'{func_call}\n')
                out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
                out.append('\n')
        self.write("".join(out))

        out = []

    def getApiFunctionType(self, command):
            if command.name in [
                    'vkCreateInstance',
                    'vkEnumerateInstanceVersion',
                    'vkEnumerateInstanceLayerProperties',
                    'vkEnumerateInstanceExtensionProperties',
                ]:
                return 'kFuncTypeInst'
            elif command.params[0].type == 'VkInstance':
                return'kFuncTypeInst'
            elif command.params[0].type == 'VkPhysicalDevice':
                return'kFuncTypePdev'
            else:
                return'kFuncTypeDev'

    def generateSource(self):
        out = []
        for vkcommand in self.vk.commands.values():
            attrs = self.intercept_functions.get(vkcommand.name, None)
            if attrs is None:
                if self.CommandBufferCall(vkcommand):
                    attrs = InterceptFlag.NORMAL
                else:
                    continue
            if attrs & (InterceptFlag.CUSTOM | InterceptFlag.OVERRIDE):
                continue

            lower_function_call = vkcommand.name + '('
            count = 0
            for vkparam in vkcommand.params:
                if count > 0:
                    lower_function_call += ', '
                lower_function_call += vkparam.name
                count += 1
            lower_function_call += ');\n'

            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_call = 'static ' + vkcommand.cPrototype.replace(' vk', ' Intercept').replace(';', ' {')
            out.append(f'{func_call}\n')

            if self.CommandHasReturn(vkcommand):
                default_value = self.GetDefaultReturnValue(vkcommand.returnType)
                out.append(f'  {vkcommand.returnType} result = {default_value};\n')
                out.append('\n')

            if self.InstanceCommand(vkcommand):
                out.append(f'  auto layer_data = GetInstanceLayerData(DataKey({vkcommand.params[0].name}));\n')
            else:
                out.append(f'  auto layer_data = GetDeviceLayerData(DataKey({vkcommand.params[0].name}));\n')

            if attrs & InterceptFlag.PRE:
              pre_func = lower_function_call.replace('vk', 'layer_data->interceptor->Pre')
              out.append(f'  {pre_func}')
              out.append('\n')

            out.append(f'  PFN_{vkcommand.name} pfn = layer_data->dispatch_table.{vkcommand.name[2:]};\n')
            out.append('  if (pfn != nullptr) {\n')
            out.append('    ')
            if self.CommandHasReturn(vkcommand):
                out.append('result = ')
            pfn_call = lower_function_call.replace(f'{vkcommand.name}', 'pfn')
            out.append(f'{pfn_call}')
            out.append('  }\n')
            out.append('\n')

            if attrs & InterceptFlag.POST:
              out.append('  ')
              post_call = lower_function_call.replace('vk', 'layer_data->interceptor->Post')
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
typedef enum ApiFunctionType { kFuncTypeInst = 0, kFuncTypePdev = 1, kFuncTypeDev = 2 } ApiFunctionType;

typedef struct {
    ApiFunctionType function_type;
    void* funcptr;
} function_data;

const std::unordered_map<std::string, function_data> &GetNameToFuncPtrMap() {
    static const std::unordered_map<std::string, function_data> name_to_func_ptr_map = {
''')
        for command in filter(self.NeedsIntercept, self.vk.commands.values()):
            out.extend([f'#ifdef {command.protect}\n'] if command.protect else [])
            out.append(f'    {{"{command.name}", {{{self.getApiFunctionType(command)}, (void*)Intercept{command.name[2:]}}}}},\n')
            out.extend([f'#endif //{command.protect}\n'] if command.protect else [])
        out.append('};\n')
        out.append(' return name_to_func_ptr_map;\n')
        out.append('};\n')
        self.write("".join(out))

