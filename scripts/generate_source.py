#!/usr/bin/env python3
# Copyright (c) 2021-2023 The Khronos Group Inc.
# Copyright (c) 2021-2023 Valve Corporation
# Copyright (c) 2021-2023 LunarG, Inc.
# Copyright (c) 2021-2023 Google Inc.
# Copyright (c) 2023-2023 RasterGrid Kft.
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

import argparse
import filecmp
import os
import shutil
import subprocess
import sys
import tempfile
import difflib
import json
from common_codegen import repo_relative
from run_generator import RunGenerator

def main(argv):
    # files to exclude from --verify check
    verify_exclude = ['.clang-format']

    generated_layer_files = [
        'command.h.inc',
        'command.cpp.inc',
        'command_common.h',
        'command_common.cpp',
        'command_printer.h',
        'command_printer.cpp',
        'command_printer_structs.cpp',
        'command_printer_types.cpp',
        'command_recorder.h',
        'command_recorder.cpp',
        'command_tracker.h',
        'command_tracker.cpp',
        'dispatch.h',
        'dispatch.cpp',
        'cdl_commands.h.inc',
        'cdl_commands.cpp.inc',
        'layer_base.h',
        'layer_base.cpp',
    ]

    parser = argparse.ArgumentParser(description='Generate source code for this repository')
    parser.add_argument('--api',
                        default='vulkan',
                        choices=['vulkan'],
                        help='Specify API name to generate')
    parser.add_argument('registry', metavar='REGISTRY_PATH', help='path to the Vulkan-Headers registry directory')
    parser.add_argument('grammar', metavar='GRAMMAR_PATH', help='path to the SPIRV-Headers grammar directory')
    parser.add_argument('--generated-version', help='sets the header version used to generate the repo')
    group = parser.add_mutually_exclusive_group()
    group.add_argument('--target', help='only generate file name passed in')
    group.add_argument('-i', '--incremental', action='store_true', help='only update repo files that change')
    group.add_argument('-v', '--verify', action='store_true', help='verify repo files match generator output')
    args = parser.parse_args(argv)

    # We need modules from the registry directory, add it here so no one has to set it in PYTHONPATH
    sys.path.insert(0, args.registry)

    repo_dir = repo_relative('src/generated')

    # get directory where generators will run
    if args.verify or args.incremental:
        # generate in temp directory so we can compare or copy later
        temp_obj = tempfile.TemporaryDirectory(prefix='cdl_codegen_')
        temp_dir = temp_obj.name
        gen_dir = temp_dir
    else:
        # generate directly in the repo
        gen_dir = repo_dir

    # Filter if --target is passed in
    generated_layer_files = [x for x in generated_layer_files if (args.target and args.target == x) or (args.target is None)]
    for index, file in enumerate(generated_layer_files, start=1):
        registry = os.path.abspath(os.path.join(args.registry,  'vk.xml'))
        grammar = os.path.abspath(os.path.join(args.grammar,  'spirv.core.grammar.json'))
        scripts = os.path.dirname(args.registry)
        print(f'[{index}|{len(generated_layer_files)}] Generating {file}')
        RunGenerator(args.api, registry, grammar, scripts, gen_dir, file)

    # optional post-generation steps
    if args.verify:
        # compare contents of temp dir and repo
        temp_files = set(os.listdir(temp_dir))
        repo_files = set(os.listdir(repo_dir))
        files_match = True
        for filename in sorted((temp_files | repo_files) - set(verify_exclude)):
            temp_filename = os.path.join(temp_dir, filename)
            repo_filename = os.path.join(repo_dir, filename)
            if filename not in repo_files:
                print('ERROR: Missing repo file', filename)
                files_match = False
            elif filename not in temp_files:
                print('ERROR: Missing generator for', filename)
                files_match = False
            elif not filecmp.cmp(temp_filename, repo_filename, shallow=False):
                print('ERROR: Repo files do not match generator output for', filename)
                files_match = False
                # print line diff on file mismatch
                with open(temp_filename) as temp_file, open(repo_filename) as repo_file:
                    print(''.join(difflib.unified_diff(temp_file.readlines(),
                                                       repo_file.readlines(),
                                                       fromfile='temp/' + filename,
                                                       tofile=  'repo/' + filename)))

        # return code for test scripts
        if files_match:
            print('SUCCESS: Repo files match generator output')
            return 0
        return 1

    elif args.incremental:
        # copy missing or differing files from temp directory to repo
        for filename in os.listdir(temp_dir):
            temp_filename = os.path.join(temp_dir, filename)
            repo_filename = os.path.join(repo_dir, filename)
            if not os.path.exists(repo_filename) or \
               not filecmp.cmp(temp_filename, repo_filename, shallow=False):
                print('update', repo_filename)
                shutil.copyfile(temp_filename, repo_filename)

    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))

