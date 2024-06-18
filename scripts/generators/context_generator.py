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
from generators.cdl_base_generator import CdlBaseOutputGenerator

#NOTE: This generator only handles command buffer related overrides.
# Everything else should be done manually in cdl.h/cpp.
custom_pre_intercept_functions = (
   'vkBeginCommandBuffer',
   'vkResetCommandBuffer',
   'vkCmdBindPipeline'
)

custom_post_intercept_functions = ()

#
# InterceptCommandsOutputGenerator - Generate the dispatch tables
class InterceptContextGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'cdl_commands.h.inc':
            self.generateContextCommandsHeader()
        elif self.filename == 'cdl_commands.cpp.inc':
            self.generateContextCommandsSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateContextCommandsHeader(self):
        out = []
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(' vk', ' Post', 1).replace(';', ' override;')
            pre_func_decl = post_func_decl.replace('Post', 'Pre', 1)
            override_func_decl = post_func_decl.replace('Post', '', 1)
            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f',\n    {vkcommand.returnType}                                    result)')
            if self.InterceptPreCommand(vkcommand):
                out.append(f'{pre_func_decl}\n')
            if self.InterceptPostCommand(vkcommand):
                out.append(f'{post_func_decl}\n')
            if self.InterceptOverrideCommand(vkcommand):
                out.append(f'{override_func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

    def generateContextCommandsSource(self):
        out = []

        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            post_func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace(';', ' {').replace(' vk', ' Context::Post', 1)
            pre_func_decl = post_func_decl.replace('Context::Post', 'Context::Pre', 1)
            pre_func_call = '  '
            post_func_call = '  '
            if self.CommandHasReturn(vkcommand):
                post_func_decl = post_func_decl.replace(')', f',\n    {vkcommand.returnType}                                    result)')
                pre_func_call += 'return '
                post_func_call += 'return '
            pre_func_call += f'p_cmd->Pre{vkcommand.name[2:]}('
            post_func_call += f'p_cmd->Post{vkcommand.name[2:]}('
            count = 0
            for vkparam in vkcommand.params:
                if count != 0:
                    pre_func_call += ', '
                    post_func_call += ', '
                pre_func_call += vkparam.name
                post_func_call += vkparam.name
                count += 1
            if self.CommandHasReturn(vkcommand):
                post_func_call += ', result'
            pre_func_call += ');'
            post_func_call += ');'

            # Skip vkCmdBindPipeline pre call since it's implemented by hand
            if not (vkcommand.name in custom_pre_intercept_functions):
                out.append(f'{pre_func_decl}\n')
                out.append('  auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);\n')
                out.append(f'{pre_func_call}\n')
                out.append('}\n')

            if not (vkcommand.name in custom_post_intercept_functions):
                out.append(f'{post_func_decl}\n')
                out.append('  auto p_cmd = crash_diagnostic_layer::GetCommandBuffer(commandBuffer);\n')
                out.append(f'{post_func_call}\n')
                out.append('}\n')

            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))

