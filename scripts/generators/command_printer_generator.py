#!/usr/bin/python3 -i
#
# Copyright (c) 2023 Valve Corporation
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
# CommandPrinterOutputGenerator - Generate command print utilities
class CommandPrinterOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)

        if self.filename == 'command_printer.h':
            self.generateHeader()
        elif self.filename == 'command_printer.cc':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')

        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once')

        out = []
        out.append('''
#include <iostream>
#include <vulkan/vulkan.h>

#include "command_common.h"
#include "object_name_db.h"

struct VkStruct {
    VkStructureType sType;
    void *pNext;
};

class ScopedOstream : public std::streambuf
{
public:
    explicit ScopedOstream(std::ostream &os, int indent = 4):
        os_(&os),
        sb_(os_->rdbuf()),
        line_start_(true),
        indent_(indent)
    {
        os_->rdbuf(this);
    }

    virtual ~ScopedOstream()
    {
        os_->rdbuf(sb_);
    }

protected:
    virtual int overflow(int ch) {
        if (line_start_ && ch != \'\\n\'){
            for (int i = 0; i < indent_; ++i) {
                sb_->sputc(' ');
            }
        }

        line_start_ = \'\\n\' == ch;
        return sb_->sputc(ch);
    }

private:
    std::ostream *os_;
    std::streambuf *sb_;
    bool line_start_;
    int indent_;
};

// Declare generic struct printer.
std::ostream & PrintVkStruct(std::ostream & os, const VkStruct *pStruct);

// Declare pNext chain printer.
std::ostream & PrintNextPtr(std::ostream & os, const void *pNext);
''')
        self.write("".join(out))

        self.write("\n// Declare enum to string functions.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'const char *{vkenum.name}ToString({vkenum.name} e);\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
        self.write("".join(out))

        self.write("\n// Declare ostream operators for enums.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'std::ostream &operator<<(std::ostream & os, const {vkenum.name} &t);\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
        self.write("".join(out))

        self.write("\n// Declare all ostream operators.\n")
        out = []
        for vkstruct in self.vk.structs.values():
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'std::ostream &operator<<(std::ostream & os, const {vkstruct.name} &t);\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
        self.write("".join(out))

        out = []
        out.append('''
// Declare print functions.

class CommandPrinter {
 public:
  void SetNameResolver(const ObjectInfoDB *name_resolver);

''')
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'  void Print{vkcommand.name[2:]}Args(std::ostream & os, const {vkcommand.name[2:]}Args &args);\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
        out.append('};\n');
        self.write("".join(out))

    def printArray(self, out, lengths, cur_length, prefix, member, usage_string, array_suffix):
        variable = chr(ord('i') + cur_length)
        index = '        '
        for i in range(0, cur_length):
            index += '  '
        out.append(f'{index}for (uint64_t {variable} = 0; {variable} < {lengths[cur_length]}; ++{variable}) {{\n')
        if cur_length == 0:
            out.append(f'{index}  ScopedOstream somember(os);\n')
        if cur_length < (len(lengths) - 1):
            self.printArray(out, lengths, cur_length + 1, prefix, member, usage_string, array_suffix)
        else:
            pointer_prefix = prefix
            pointer_suffix = ''
            pointer_count = member.cDeclaration.count('*')
            if pointer_count > len(lengths):
                pointer_prefix = '*(' + prefix
                pointer_suffix = ')'
            out.append(f'{index}  os << "{usage_string}:" << std::endl << {pointer_prefix}{member.name}{array_suffix}{pointer_suffix} << std::endl;\n')
        out.append(f'{index}}} // for {variable}\n')

    def printMember(self, out, member, prefix, is_pointer):
        out.append('  {\n')
        out.append('    os << "- # parameter:" << std::endl;\n')
        out.append('    ScopedOstream sop(os);\n')
        out.append(f'    os << "name:  {member.name}" << std::endl;\n')
        if is_pointer:
            prefix += '->'
        else:
            prefix += '.'
        if member.length is not None:

            static_array = not (member.staticArray is None or len(member.staticArray) == 0)
            lengths = []
            lengths_names = []
            if len(member.staticArray) > 1 or member.length.count(',') > 0:
                lengths = member.length.split(',')
                if len(lengths) > 1 and lengths[len(lengths) - 1] == '1':
                    lengths.pop()
            else:
                lengths.append(member.length)

            array_type = ''
            if member.const:
                array_type = 'Const'
            for i in range(len(lengths)):
                length_name = ''
                if '*' in lengths[i] or '+' in lengths[i] or '/' in lengths[i]:
                    elements = lengths[i].split(' ')
                    for j in range(len(elements)):
                        for k in range(len(elements[j])):
                            if elements[j][k] == '(':
                                continue
                            if elements[j][k].islower():
                                if k == 0:
                                    temp = prefix + elements[j]
                                else:
                                    temp = elements[j][:k] + prefix + elements[j][k:]
                                elements[j] = temp
                                break
                    lengths[i] = ''.join(elements)
                    length_name = '('
                    length_name += lengths[i] + ')'
                elif i == 0 and not static_array:
                    length_name = prefix + lengths[i]
                else:
                    length_name = lengths[i]
                if static_array:
                    array_type += 'Fixed'
                else:
                    array_type += 'Dynamic'
                array_type += 'Array('
                if i == len(lengths) - 1:
                    array_type += member.type
                lengths_names.append(length_name)
            for i in range(len(lengths)):
                array_type += ')'

            if member.type == 'char' and len(lengths) == 1:
                out.append(f'    // {member.name} -> Field -> {array_type}\n')
                out.append(f'    os << "value: " << {prefix}{member.name} << std::endl;\n')
            elif member.type == 'void':
                if static_array:
                    out.append('    {\n')
                else:
                    out.append(f'    if ({lengths_names[0]} == 0) {{\n')
                    out.append('      os << "value: nullptr" << std::endl;\n')
                    out.append('    } else {\n')
                out.append('      os << std::hex;\n')
                out.append('      os << "members:" << std::endl;\n')
                out.append('      {\n')
                out.append('        ScopedOstream soarray(os);\n')
                out.append(f'        const uint8_t *p = (const uint8_t *){prefix}{member.name};\n')
                out.append(f'        for (uint64_t i = 0; i < {lengths_names[0]}; ++i) {{\n')
                out.append('          os << "- 0x" << p[i] << std::endl;\n')
                out.append('        }\n')
                out.append('      }\n')
                out.append('      os << std::dec;\n')
                out.append('    }\n')
            else:
                out.append(f'    // {member.name} -> Field -> {array_type}\n')
                if static_array:
                    out.append('    {\n')
                else:
                    out.append(f'    if ({lengths_names[0]} == 0) {{\n')
                    out.append('      os << "value: nullptr" << std::endl;\n')
                    out.append('    } else {\n')
                out.append('      os << "members:" << std::endl;\n')
                out.append('      {\n')
                out.append('        ScopedOstream soarray(os);\n')
                out.append(f'        os << "- # {member.type}" << std::endl;\n')
                if member.type in self.vk.structs:
                    self.printArray(out, lengths_names, 0, prefix, member, 'members:', '')
                else:
                    self.printArray(out, lengths_names, 0, prefix, member, 'value: ', '')
                out.append('      }\n')
                out.append('    }\n')
        elif member.pointer:
            if member.name == 'pNext':
                out.append('    // pNext -> Field -> ConstNextPtr(void)\n')
                out.append('    os << "value: ";\n')
                out.append(f'    PrintNextPtr(os, {prefix}pNext);\n')
                out.append('    os << std::endl;\n')
            elif member.type == 'void':
                out.append('    // void\n')
                out.append('    os << "value: NOT_AVAILABLE" << std::endl;\n')
            elif member.type == 'char':
                out.append(f'    // {member.name} -> Field -> string\n')
                out.append(f'    os << "value: " << {prefix}{member.name} << std::endl;\n')
            else:
                out.append('    // pointer\n')
                out.append(f'    if ({prefix}{member.name} != nullptr) {{\n')
                if member.type in self.vk.structs:
                    out.append(f'      os <<  "members:" << std::endl << *{prefix}{member.name} << std::endl;\n')
                else:
                    out.append(f'      os << "value: *{prefix}{member.name}" << std::endl;\n')
                out.append('    } else {\n')
                out.append('      os << "value: nullptr" << std::endl;\n')
                out.append('    }\n')
        else:
            if member.type in self.vk.structs:
                out.append(f'    // {member.name} -> Field -> {member.type}\n')
                out.append(f'    os <<  "members:" << std::endl << {prefix}{member.name} << std::endl;\n')
            else:
                out.append(f'    // {member.name} -> Field -> {member.type}\n')
                out.append(f'    os << "value: " << {prefix}{member.name} << std::endl;\n')
        out.append('  }\n')

    def generateSource(self):
        out = []
        out.append('''
#include <streambuf>

#include "command_common.h"
#include "command_printer.h"
#include "util.h"

std::ostream &PrintNextPtr(std::ostream &os, const void *pNext) {
  if (pNext == nullptr) {
    os << "nullptr";
    return os;
  }

  os << std::endl;
  ScopedOstream sonextptr(os);
  const VkStruct *pStruct = reinterpret_cast<const VkStruct *>(pNext);
  PrintVkStruct(os, pStruct);
  return PrintNextPtr(os, pStruct->pNext);
}

const ObjectInfoDB *global_name_resolver = nullptr;
void CommandPrinter::SetNameResolver(const ObjectInfoDB *name_resolver) {
  global_name_resolver = name_resolver;
}
''')
        self.write("".join(out))

        self.write("// Handle ostream operators\n")
        out = []
        for vkhandle in self.vk.handles.values():
            out.extend([f'#ifdef {vkhandle.protect}\n'] if vkhandle.protect else [])
            out.append(f'std::ostream &operator<<(std::ostream& os, const {vkhandle.name} &a) {{')
            out.append('\n    auto handle = (uint64_t)(a);\n')
            namespace_ref = self.CreateNamespaceReference('Uint64ToStr(handle)')
            out.append(f'    os << {namespace_ref} << std::endl;\n')
            out.append('''
    auto debug_name = global_name_resolver->GetObjectDebugName(handle);
    if (debug_name.length() > 0) {
      os << "debugName: \\\"" << debug_name << "\\\"";
    }
    return os;
}
''')
            out.extend([f'#endif //{vkhandle.protect}\n'] if vkhandle.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Define enum to string functions.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'const char *{vkenum.name}ToString({vkenum.name} e) {{\n')
            out.append(f'  switch (e) {{\n')
            for enumfield in vkenum.fields:
                out.extend([f'#ifdef {enumfield.protect}\n'] if enumfield.protect else [])
                out.append(f'  case {enumfield.name}:\n')
                out.append(f'    return "{enumfield.name}";\n')
                out.extend([f'#endif //{enumfield.protect}\n'] if enumfield.protect else [])
            out.append(f'  default: return "Unknown {vkenum.name}";\n')
            out.append('  }\n}\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Define ostream operators for enums.\n")
        out = []
        for vkenum in [x for x in self.vk.enums.values() if len(x.fields) > 0]:
            out.extend([f'#ifdef {vkenum.protect}\n'] if vkenum.protect else [])
            out.append(f'std::ostream &operator<<(std::ostream & os, const {vkenum.name} &t) {{\n')
            out.append(f'  os << {vkenum.name}ToString(t);\n')
            out.append('  return os;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkenum.protect}\n'] if vkenum.protect else [])
            out.append('\n')
        self.write("".join(out))

        self.write("\n// Define all ostream operators.\n")
        out = []
        for vkstruct in self.vk.structs.values():
            # The VkWriteDescriptorSet struct has it's own custom function
            if vkstruct.name == 'VkWriteDescriptorSet':
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'std::ostream &operator<<(std::ostream & os, const {vkstruct.name} &t) {{\n')
            out.append('  ScopedOstream sos(os);\n')
            for member in vkstruct.members:
                self.printMember(out, member, 't', False)
            out.append('  return os;\n')
            out.append('}\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append('\n')
        self.write("".join(out))

        out = []
        out.append('''
std::ostream &operator<<(std::ostream &os, const VkWriteDescriptorSet &t) {
  ScopedOstream sos(os);
  os << "sType: ";
  os << t.sType << std::endl;

  os << "pNext: ";
  // void

  os << "dstSet: ";
  os << t.dstSet << std::endl;

  os << "dstBinding: ";
  os << t.dstBinding << std::endl;

  os << "dstArrayElement: ";
  os << t.dstArrayElement << std::endl;

  os << "descriptorCount: ";
  os << t.descriptorCount << std::endl;

  os << "descriptorType: ";
  os << t.descriptorType << std::endl;

  switch (t.descriptorType){
    case VK_DESCRIPTOR_TYPE_SAMPLER:
    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
      os << "pImageInfo: ";
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pImageInfo[i] << std::endl;
      }
      break;

    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
      os << "pTexelBufferView: ";
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pTexelBufferView[i] << std::endl;
      }
      break;

    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
      os << "pBufferInfo: ";
      for (uint32_t i = 0; i < t.descriptorCount; ++i) {
        os << t.pBufferInfo[i] << std::endl;
      }
      break;

    default:
      os << "Unknown Descriptor Type: " << t.descriptorType << std::endl;
  }

  return os;
}
''')
        self.write("".join(out))

        out = []
        out.append('//  Print out a VkStruct\n')
        out.append('std::ostream & PrintVkStruct(std::ostream & os, const VkStruct *pStruct) {\n')
        out.append('  switch (pStruct->sType) {\n')
        for vkstruct in self.vk.structs.values():
            if vkstruct.sType is None:
                continue
            out.extend([f'#ifdef {vkstruct.protect}\n'] if vkstruct.protect else [])
            out.append(f'  case {vkstruct.sType}:\n')
            out.append(f'    os << *reinterpret_cast<const {vkstruct.name} *>(pStruct);\n')
            out.append('    break;\n')
            out.extend([f'#endif //{vkstruct.protect}\n'] if vkstruct.protect else [])

        out.append('  default: break;\n')
        out.append('  }\n')
        out.append('  return os;\n')
        out.append('}\n')
        self.write("".join(out))

        self.write("\n// Define print functions.\n")
        out = []
        for vkcommand in filter(lambda x: self.CommandBufferCall(x), self.vk.commands.values()):
            out.extend([f'#ifdef {vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append(f'void CommandPrinter::Print{vkcommand.name[2:]}Args(\n')
            out.append(f'  std::ostream & os, const {vkcommand.name[2:]}Args &args) {{\n')
            for member in vkcommand.params:
                self.printMember(out, member, 'args', False)
            out.append('}\n')
            out.extend([f'#endif //{vkcommand.protect}\n'] if vkcommand.protect else [])
            out.append('\n')
        self.write("".join(out))
