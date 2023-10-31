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
# LayerUtilsOutputGenerator - Generate command print utilities
class LayerUtilsOutputGenerator(CdlBaseOutputGenerator):
    def __init__(self):
        CdlBaseOutputGenerator.__init__(self)

    #
    # Called at beginning of processing as file is opened
    def generate(self):
        file_start = self.GenerateFileStart(os.path.basename(__file__))
        self.write(file_start)
        if self.filename == 'layer_utils.h':
            self.generateHeader()
        elif self.filename == 'layer_utils.cc':
            self.generateSource()
        else:
            self.write(f'\nFile name {self.filename} has no code to generate\n')
        self.write(self.GenerateFileEnd())

    def generateHeader(self):
        self.write('\n#pragma once')

        out = []
        out.append('\n#include <string>\n')
        out.append('\n#include <vulkan/vulkan.h>\n')
        out.append(self.GenerateNamespaceBegin())
        out.append('void GetResultString(VkResult result, std::string& result_string);\n')
        self.write("".join(out))

        out = []
        out.append(self.GenerateNamespaceEnd())
        self.write("".join(out))

    def generateSource(self):
        out = []
        out.append('\n#include "layer_utils.h"\n')
        out.append(self.GenerateNamespaceBegin())
        self.write("".join(out))

        out = []
        out.append('void GetResultString(VkResult result, std::string& result_string) {\n')
        result_enum = self.vk.enums['VkResult']
        if result_enum == None:
            print('ERROR: Failed to find VkResult enum')
            exit -1

        out.append('    switch (result) {\n')
        out.append('        default: result_string = "Unknown Error"; break;\n')
        for field in result_enum.fields:
            if field.protect is not None:
                out.append(f'#ifdef {field.protect}\n')
            out.append(f'        case {field.name}: result_string = "{field.name}"; break;\n')
            if field.protect is not None:
                out.append(f'#endif // {field.protect}\n')
        out.append('    }\n')
        out.append('}\n')
        self.write("".join(out))

        out = []
        out.append(self.GenerateNamespaceEnd())
        self.write("".join(out))
