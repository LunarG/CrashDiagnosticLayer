# Build Instructions

1. [Requirements](#requirements)
2. [Building Overview](#building-overview)
3. [Generated source code](#generated-source-code)
4. [Dependencies](#dependencies)
5. [Linux Build](#building-on-linux)
6. [Windows Build](#building-on-windows)
7. [Installed Files](#cmake-installed-files)

## Requirements

1. CMake >= 3.22.1
2. C++17 compatible toolchain
3. Git
4. Python >= 3.10

NOTE: Python is needed for working on generated code, and helping grab
dependencies.
While it's not technically required, it's practically required for most users.

## Building Overview

The following will be enough for most people, for more detailed instructions,
see below.

```bash
git clone https://github.com/LunarG/CrashDiagnosticLayer.git
cd CrashDiagnosticLayer

# Update the dependencies and generate the appropriate build files
cmake -S . -B build -D UPDATE_DEPS=ON -D CMAKE_BUILD_TYPE=Debug
# Commence the build
cmake --build build --config Debug

# CMake 3.21+
cmake -S . -B build --preset dev
cmake --build build --config Debug
```

### CMakePresets.json (3.21+)

[CMakePresets.json](./CMakePresets.json) can save developer time by specifying
common build flags.

```bash
# Enables tests, enable werror, etc.
cmake -S . -B build/ --preset dev
```

## Generated source code

This repository contains generated source code in the `src/generated` directory
which is not intended to be modified directly.

The generated files are created using the Vulkan registry (`vk.xml`) pulled
from the `Vulkan-Headers` repo and the generation scripts in the `scripts`
folder.

The source can be generated using CMake by building the following target:

```bash
cmake -S . -B build -D CDL_CODEGEN=ON -D CMAKE_BUILD_TYPE=Debug
cmake --build build --target CDL_codegen
```

**NOTE:** This is only necessary when the Vulkan or SPIR-V header repo
commits have been updated and not something the standard user will need to
do.

## Dependencies

Currently this repo has a custom process for grabbing C/C++ dependencies.

Keep in mind this repo predates tools like `vcpkg`, `conan`, etc. Our process is
most similar to `vcpkg`.

By specifying `-D UPDATE_DEPS=ON` when configuring CMake we grab dependencies
listed in [known_good.json](scripts/known_good.json).

All we are doing is streamlining `building`/`installing` the `known good`
dependencies and helping CMake `find` the dependencies.

This is done via a combination of `Python` and `CMake` scripting.

Misc Useful Information:

- By default `UPDATE_DEPS` is `OFF`. The intent is to be friendly by default to
  system/language package managers.
- You can run `update_deps.py` manually but it isn't recommended for most users.

### How to test new dependency versions

Typically most developers alter `known_good.json` with the commit/branch they
are testing.

Alternatively you can modify `CMAKE_PREFIX_PATH` as follows.

```sh
# Delete the CMakeCache.txt which will cache find_* results
rm build -rf/
cmake -S . -B build/ ... -D CMAKE_PREFIX_PATH=~/foobar/my_custom_glslang_install/ ...
```


## Building On Linux

To build for Linux, follow the instructions in the
[Building Overview](#building-overview) section above.

Additional details and options are mentioned below.

### Linux Build Requirements

This repository is regularly built and tested on the two most recent Ubuntu LTS
versions.

```bash
sudo apt-get install git build-essential python3 cmake

# Linux WSI system libraries
sudo apt-get install libwayland-dev xorg-dev
```

### WSI Support Build Options

By default, the repository components are built with support for the
Vulkan-defined WSI display servers: Xcb, Xlib, and Wayland.
It is recommended to build the repository components with support for these
display servers to maximize their usability across Linux platforms.
If it is necessary to build these modules without support for one of the display
servers, the appropriate CMake option of the form `BUILD_WSI_xxx_SUPPORT` can be
set to `OFF`.

### Linux 32-bit support

Usage of this repository's contents in 32-bit Linux environments is not
officially supported.
However, since this repository is supported on 32-bit Windows, these modules
should generally work on 32-bit Linux.

Here are some notes for building 32-bit targets on a 64-bit Ubuntu "reference"
platform:

```bash
# 32-bit libs
# your PKG_CONFIG configuration may be different, depending on your distribution
sudo apt-get install gcc-multilib g++-multilib libx11-dev:i386
```

Set up your environment for building 32-bit targets:

```bash
export ASFLAGS=--32
export CFLAGS=-m32
export CXXFLAGS=-m32
export PKG_CONFIG_LIBDIR=/usr/lib/i386-linux-gnu
```


## Building On Windows

### Windows Development Environment Requirements

- Windows 10+
- Visual Studio

**Note:** Anything less than `Visual Studio 2019` is not guaranteed to
compile/work.

### Visual Studio Generator

Run CMake to generate
[Visual Studio project files](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#command-line-g-option).

```bash
# NOTE: By default CMake picks the latest version of Visual Studio as the default generator.
cmake -S . -B build --preset dev

# Open the Visual Studio solution
cmake --open build
```

See the
[CMake documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#visual-studio-generators)
for further information on Visual Studio generators.

**NOTE:** Windows developers don't have to develop in Visual Studio.
Visual Studio just helps streamlining the needed C++ toolchain requirements
(compilers, linker, etc).

## CMake Installed Files

The installation depends on the target platform

For UNIX operating systems:

- *install_dir*`/lib` : The Vulkan Crash Diagnostic Layer library
- *install_dir*`/share/vulkan/explicit_layer.d` : The layer json manifest

For WIN32:

- *install_dir*`/bin` : The Vulkan Crash Diagnostic Layer library
- *install_dir*`/bin` : The layer json manifest

### Software Installation

After you have built your project you can install using CMake's install
functionality.

CMake Docs:
- [Software Installation Guide](https://cmake.org/cmake/help/latest/guide/user-interaction/index.html#software-installation)
- [CLI for installing a project](https://cmake.org/cmake/help/latest/manual/cmake.1.html#install-a-project)

```sh
# EX: Installs Release artifacts into `build/install` directory.
# NOTE: --config is only needed for multi-config generators (Visual Studio, Xcode, etc)
cmake --install build/ --config Release --prefix build/install
```
