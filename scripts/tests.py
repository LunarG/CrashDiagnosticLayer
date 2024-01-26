#!/usr/bin/env python3
# Copyright (c) 2020-2024 Valve Corporation
# Copyright (c) 2020-2024 LunarG, Inc.

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

import subprocess
import sys
import os
import argparse
import common_ci

# Where all artifacts will ultimately be placed under
CI_BUILD_DIR = common_ci.RepoRelative('build-ci')
# Where all dependencies will be installed under
CI_EXTERNAL_DIR = f'{CI_BUILD_DIR}/external'

# Prepare the layer for testing
def BuildCDL(config, cmake_args, build_tests, sanitize):
    print("Log CMake version")
    cmake_ver_cmd = 'cmake --version'
    common_ci.RunShellCmd(cmake_ver_cmd)

    SRC_DIR = common_ci.PROJECT_SRC_DIR
    BUILD_DIR = f'{CI_BUILD_DIR}/cdl'



    print("Configure CDL")
    cmake_cmd = f'cmake -S {SRC_DIR} -B {BUILD_DIR}'
    cmake_cmd += f' -D CMAKE_BUILD_TYPE={config}'
    cmake_cmd += f' -D BUILD_TESTS={build_tests}'
    cmake_cmd += f' -D UPDATE_DEPS=ON -D UPDATE_DEPS_DIR={CI_EXTERNAL_DIR}'

    if cmake_args:
         cmake_cmd += f' {cmake_args}'


    if sanitize == 'none':
        cmake_cmd += ' -D BUILD_WERROR=ON'
    else:
        os.environ['CFLAGS'] = f'-fsanitize={sanitize}'
        os.environ['CXXFLAGS'] = f'-fsanitize={sanitize}'
        os.environ['LDFLAGS'] = f'-fsanitize={sanitize}'
        cmake_cmd += ' -D BUILD_WERROR=OFF'
    print('env', os.environ)
    print('cmake_cmd', cmake_cmd)
    common_ci.RunShellCmd(cmake_cmd)

    print("Build CDL")
    build_cmd = f'cmake --build {BUILD_DIR}'
    common_ci.RunShellCmd(build_cmd)


#
# Module Entrypoint
def Build(args):
    config = args.configuration
    sanitize = args.sanitize

    # Since this script uses Ninja to build Windows users need to be in a developer command prompt.
    if common_ci.IsWindows():
        # This environment variable is arbitrary. I just picked one set by the developer command prompt.
        if "VSCMD_ARG_TGT_ARCH" not in os.environ:
            print("This script must be invoked in a developer command prompt!")
            sys.exit(1)

    try:
        BuildCDL(config = config, cmake_args = args.cmake, build_tests = "ON", sanitize = sanitize)

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unknown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

#
# Run the Layer Validation Tests
def RunTests(args):
    print("Run Tests using Mock ICD")

    lvt_env = dict(os.environ)
    lvt_cmd = os.path.join(CI_BUILD_DIR, 'cdl', 'tests', 'cdl_tests')

    common_ci.RunShellCmd(lvt_cmd, env=lvt_env)

def Test(args):
    try:
        RunTests(args)

    except subprocess.CalledProcessError as proc_error:
        print('Command "%s" failed with return code %s' % (' '.join(proc_error.cmd), proc_error.returncode))
        sys.exit(proc_error.returncode)
    except Exception as unknown_error:
        print('An unknown error occured: %s', unknown_error)
        sys.exit(1)

    sys.exit(0)

if __name__ == '__main__':
    configs = ('release', 'debug')
    default_config = configs[0]

    sanitize_opts = ('none', 'address', 'thread')

    parser = argparse.ArgumentParser()
    parser.add_argument(
        '-c', '--config', dest='configuration',
        metavar='CONFIG', action='store',
        choices=configs, default=default_config,
        help='Build target configuration. Can be one of: {0}'.format(
            ', '.join(configs)))
    parser.add_argument(
        '-s', '--sanitize', dest='sanitize',
        metavar='SANITIZE', action='store',
        choices=sanitize_opts, default='none',
        help='-fsanitize setting. Can be one of: {0}'.format(', '.join(sanitize_opts)))
    parser.add_argument(
        '--cmake', dest='cmake',
        metavar='CMAKE', type=str,
        default='', help='Additional args to pass to cmake')
    parser.add_argument(
        '--build', dest='build',
        action='store_true', help='Build the layers')
    parser.add_argument(
        '--test', dest='test',
        action='store_true', help='Tests the layers')

    args = parser.parse_args()

    if (args.build):
        Build(args)
    if (args.test):
        Test(args)
