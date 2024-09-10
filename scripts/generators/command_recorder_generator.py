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

#
# CommandRecorderOutputGenerator - Generate the dispatch tables
class CommandRecorderOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_recorder.h':
            self.generateHeader()
        elif self.filename == 'command_recorder.cpp':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        out = []
        out.append('''
#include <cstring>
#include <iostream>
#include <vector>
#include <vulkan/vulkan.h>

#include "linear_allocator.h"
#include "command_common.h"

class CommandRecorder
{
  public:
  void Reset() { m_allocator.Reset(); }
''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace('vk', 'Record', 1).replace(f'{vkcommand.returnType} ', f'{vkcommand.name[2:]}Args*', 1)
            out.append(f'  {func_decl}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        out.append('''

  private:

    template <typename T> T *Alloc() { return new(m_allocator.Alloc(sizeof(T))) T; }
    template <typename T> T *CopyArray(const T *src, size_t start_index, size_t count) {
      auto ptr = reinterpret_cast<T *>(m_allocator.Alloc(sizeof(T) * count));
      std::memcpy(ptr, src, sizeof(T) * count);
      return ptr;
    }

    LinearAllocator<> m_allocator;
};
''')
        self.write("".join(out))

    def generateSource(self):
        out = []
        out.append('''
#include <iomanip>
#include <sstream>

#include "command_common.h"
#include "command_recorder.h"

// Declare CopyArray template functions. We need this declaration since the
// templates call each other and we don't have control over the order of the
// definitions.

''')
        # Find all the types that are used by command buffer related calls. These are the only
        # ones we need to record and skipping the rest of the spec avoids many tricky corner cases
        # and 20k lines of unused code.
        #
        cmd_types = set()

        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            for vkparam in vkcommand.params:
                cmd_types.add(vkparam.type)

        for vkstruct in self.vk.structs.values():
            if vkstruct.name not in cmd_types:
                continue
            for vkmember in vkstruct.members:
                cmd_types.add(vkmember.type)

        out.append('template<>\n')
        out.append('uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, size_t start_index, size_t count);\n')
        for vkstruct in self.vk.structs.values():
            if vkstruct.name not in cmd_types:
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('template<>\n')
            out.append(f'{vkstruct.name}* CommandRecorder::CopyArray<{vkstruct.name}>(const {vkstruct.name}* src, size_t start_index, size_t count);\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
        out.append('\n\n// Define CopyArray template functions.\n\n')

        out.append('template<>\n')
        out.append('uint8_t* CommandRecorder::CopyArray<uint8_t>(const uint8_t* src, size_t start_index, size_t count) {\n')
        out.append('    auto ptr = reinterpret_cast<uint8_t*>(m_allocator.Alloc(sizeof(uint8_t) * count));\n')
        out.append('    memcpy(ptr, src, sizeof(uint8_t) * count);\n')
        out.append('    return ptr;\n')
        out.append('}\n')
        for vkstruct in self.vk.structs.values():
            if vkstruct.name not in cmd_types:
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('template<>\n')
            out.append(f'{vkstruct.name}* CommandRecorder::CopyArray<{vkstruct.name}>(const {vkstruct.name}* src, size_t start_index, size_t count) {{\n')
            out.append(f'  auto ptr = reinterpret_cast<{vkstruct.name}*>(m_allocator.Alloc(sizeof({vkstruct.name}) * count));\n')
            out.append('  for (uint64_t i = 0; i < count; ++i) {\n')
            src_struct = 'src[start_index + i]'
            for vkmember in vkstruct.members:
                if vkmember.fixedSizeArray is not None and len(vkmember.fixedSizeArray) > 0 and 'PFN_' not in vkmember.type:
                    out.append(f'  for (uint32_t j = 0; j < {vkmember.fixedSizeArray[0]}; ++j) {{\n')
                    out.append(f'    ptr[i].{vkmember.name}[j] = {src_struct}.{vkmember.name}[j];\n')
                    out.append('  }\n')
                # https://github.com/LunarG/CrashDiagnosticLayer/issues/102 we need to deep copy the pNext chain here
                elif vkmember.name == 'pNext':
                    out.append(f'  ptr[i].{vkmember.name} = nullptr; // pNext deep copy not implemented\n')
                elif vkmember.pointer and 'void' != vkmember.type:
                    out.append(f'    ptr[i].{vkmember.name} = nullptr;\n')
                    out.append(f'  if ({src_struct}.{vkmember.name}) {{\n')
                    if vkmember.length is not None and len(vkmember.length) > 0:
                        lengths = vkmember.length.split(',')
                        out.append(f'    ptr[i].{vkmember.name} = CopyArray({src_struct}.{vkmember.name}, static_cast<uint64_t>(0U), static_cast<uint64_t>({src_struct}.{lengths[0]}));\n')
                        # TODO: this only handles 2d arrays with a constant 2nd dimension
                        # because that's all that is in vk.xml right now
                        if len(lengths) > 1:
                            out.append(f'for (uint64_t j = 0; j < uint64_t({src_struct}.{lengths[0]}); j++) {{\n')
                            out.append(f'    const_cast<{vkmember.type} **>(ptr[i].{vkmember.name})[j] = CopyArray({src_struct}.{vkmember.name}[j], static_cast<uint64_t>(0U), static_cast<uint64_t>({lengths[1]}));\n')
                            out.append('}')

                    elif vkmember.type == 'char':
                        out.append(f'    ptr[i].{vkmember.name} = CopyArray<>({src_struct}.{vkmember.name}, 0, strlen({src_struct}.{vkmember.name}) + 1);\n')
                    else:
                        out.append(f'    ptr[i].{vkmember.name} = CopyArray({src_struct}.{vkmember.name}, static_cast<uint64_t>(0U), static_cast<uint64_t>(1U));\n')
                    out.append('  }\n')
                elif vkmember.length is not None and len(vkmember.length) > 0:
                    out_type = vkmember.cDeclaration.replace(vkmember.name, '').strip()
                    out.append(f'    ptr[i].{vkmember.name} = reinterpret_cast<{out_type}>(CopyArray(reinterpret_cast<const uint8_t*>({src_struct}.{vkmember.name}), static_cast<uint64_t>(0U), static_cast<uint64_t>({src_struct}.{vkmember.length})));\n')
                else:
                    out.append(f'  ptr[i].{vkmember.name} = {src_struct}.{vkmember.name};\n')
            out.append('  }\n')
            out.append('  return ptr;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('\n')

        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            func_decl = vkcommand.cPrototype.replace('VKAPI_ATTR ', '').replace('VKAPI_CALL ', '').replace('vk', 'CommandRecorder::Record').replace(f'{vkcommand.returnType} ', f'{vkcommand.name[2:]}Args*', 1).replace(';', ' {', 1)
            out.append(f'{func_decl}\n')
            out.append(f'  auto *args = Alloc<{vkcommand.name[2:]}Args>();\n')
            for vkparam in vkcommand.params:
                if vkparam.fixedSizeArray is not None and len(vkparam.fixedSizeArray) > 0:
                    out.append(f'  for (uint32_t i = 0; i < {vkparam.length}; ++i) {{\n')
                    out.append(f'    args->{vkparam.name}[i] = {vkparam.name}[i];\n')
                    out.append('  }\n')
                elif vkparam.pointer and 'void' != vkparam.type:
                    out.append(f'  if ({vkparam.name}) {{\n')
                    if vkparam.length is not None and len(vkparam.length) > 0:
                        out.append(f'    args->{vkparam.name} = CopyArray({vkparam.name}, static_cast<size_t>(0U), static_cast<size_t>({vkparam.length}));\n')
                    else:
                        out.append(f'    args->{vkparam.name} = CopyArray({vkparam.name}, static_cast<size_t>(0U), static_cast<size_t>(1U));\n')
                    out.append('  }\n')
                elif vkparam.length is not None and len(vkparam.length) > 0:
                    out.append(f'    args->{vkparam.name} = CopyArray(reinterpret_cast<const uint8_t*>({vkparam.name}), static_cast<size_t>(0U), static_cast<size_t>({vkparam.length}));\n')
                else:
                    out.append(f'  args->{vkparam.name} = {vkparam.name};\n')
            out.append('  return args;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))
