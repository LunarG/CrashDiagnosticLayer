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
from generators.cdl_base_generator import CdlBaseOutputGenerator
#
# CommandCommonOutputGenerator - Generate command output and storage
class CommandCommonOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_common.h':
            self.generateHeader()
        elif self.filename == 'command_common.cpp':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once\n')
        self.write('#include <cstring>')
        self.write('#include <iostream>')
        self.write('#include <vector>')
        self.write('#include <vulkan/vulkan.h>')

        #
        # List the enum for the commands
        out = []
        out.append('''
// Enumerate commands that have one parameter of type VkCommandBuffer.
struct Command
{
  enum Type {
    kUnknown,\n\n''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'    k{vkcommand.name[2:]},\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('''}; // enum Type

  public:
  static const char *GetCommandName(const Command &cmd);

  Type type;
  uint32_t id;
  void *parameters;
}; // struct Command

// Define structs for command parameters
''')

        self.write("".join(out))

        #
        # For each CMD_TYPE give a string name
        out = []
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'struct {vkcommand.name[2:]}Args {{\n')
            for vkparam in vkcommand.params:
                param_stripped = vkparam.cDeclaration.strip()
                if vkparam.const and not vkparam.pointer:
                    param_decl = param_stripped[6:]
                else:
                    param_decl = param_stripped
                out.append(f'    {param_decl};\n')
            out.append('};\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')

        self.write("".join(out))

    def generateSource(self):
        self.write('#include "command_common.h"')

        #
        # For each CMD_TYPE give a string name add a *-recording VUID
        # Each vkCmd* will have one
        out = []
        out.append('''
// Returns the name of given command. This only cares for commands that have one
// parameter of type VkCommandBuffer.
const char *Command::GetCommandName(const Command &cmd) {
  switch (cmd.type) {
  default:
  case Command::Type::kUnknown:
    return "Unknown";

''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  case Command::Type::k{vkcommand.name[2:]}:\n')
            out.append(f'    return "{vkcommand.name}";\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])

        out.append('  } // switch (cmd.type) \n')
        out.append('} // Command::GetCommandName()\n')
        self.write("".join(out))
