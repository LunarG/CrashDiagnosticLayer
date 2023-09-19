# Crash Diagnostic Layer

The Crash Diagnostic Layer (CDL)  is a Vulkan layer to help track down and
identify the cause of GPU hangs and crashes.
It works by instrumenting command buffers with completion tags.
When an error is detected a log file containing incomplete command buffers is
written.
Often the last complete or incomplete commands are responsible for the crash.

This product started development as part of Google's Stadia project, but was
never officially supported until taken over by LunarG.


## Prerequisites

1. CMake >= 3.17.2
2. C++17 compatible toolchain
3. Git
4. Python >= 3.10
- Confirm support for the `VK_AMD_buffer_marker` device extension.

**NOTE:** Python is needed for working on generated code, and helping grab
dependencies.
While it's not technically required, it's practically required for most users.


## Building Overview

The following will be enough for most people, for more detailed instructions,
see below.

```bash
git clone https://github.com/LunarG/CrashDiagnosticLayer.git
cd CrashDiagnosticLayer

cmake -S . -B build -D UPDATE_DEPS=ON -D CMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
```

### Generating Layer Support Code

The Crash Diagnostic Layer uses Python 3 and the Vulkan XML registry (pulled
from the
[Vulkan Headers Github Repository](https://github.com/KhronosGroup/Vulkan-Headers)
) to generate much of the supported layer's binding.

**NOTE** This is not a normal build step and only required if updating the
repository to use a newer version of the `Vulkan-Header` repo in the
`scritps/known_good.json` file.

To rebuild the source files in the `src/generated` folder, add the
`-D CDL_CODEGEN=ON` flag to the CMake build files generation step and build
against the `CDL_codegen` target.

```bash
cmake -S . -B build -D CDL_CODEGEN=ON -D CMAKE_BUILD_TYPE=Debug
cmake --build build --target CDL_codegen
```

This should update the layer's bindings to the version of Vulkan-Headers in the
`external` directory.

This does not mean that CDL will be fully compatible with newer SDK versions.
For example new commands will not be instrumented by default (only if
`CDL_INSTRUMENT_ALL_COMMANDS` is enabled).
Furthermore certain changes in Vulkan functionality may affect how effective CDL
functions.
Commands or new API's that affect how command buffers are recorded or submitted
many not work properly unless CDL is updated.


### Building on Windows

Run cmake:
```
> cmake -Bbuild -DCMAKE_GENERATOR_PLATFORM=x64 -H.
```
Open the solution: `build\CDL.sln`

The resulting `dll` and `json` will be output to `{BUILD_FOLDER}\src\` which
in this case should be `build\src`.


### Building on Linux

```
$ cmake -Bbuild -H.
$ cd build
$ make -j 8
```

The resulting `so` and `json` files will be output to `{BUILD_FOLDER}\src`
which in this case should be `build\src`.


### Building for Android

#### Android Build Requirements

Additional requirements for building for Android:

- CMake 3.21+ (newer than non-Android build)
- NDK r25+
- Ninja 1.10+
- Android SDK Build-Tools 34.0.0+
- Java JDK 1.11 or newer

To install Android SDK/NDK:

- Download [Android Studio](https://developer.android.com/studio)
- Install (https://developer.android.com/studio/install)
- From the `Welcome to Android Studio` splash screen, add the following components using the SDK Manager:
  - SDK Platforms > Android 8.0 and newer (API Level 26 or higher)
  - SDK Tools > Android SDK Build-Tools
  - SDK Tools > Android SDK Platform-Tools
  - SDK Tools > Android SDK Tools
  - SDK Tools > NDK
  - SDK Tools > CMake

#### Add Android specifics to environment

NOTE: The following commands are streamlined for Linux but easily transferable to other platforms.
The main intent is setting 2 environment variables and ensuring the NDK and build tools are in the `PATH`.

```sh
# Set environment variables
# https://github.com/actions/runner-images/blob/main/images/linux/Ubuntu2204-Readme.md#environment-variables-2
export ANDROID_SDK_ROOT=$HOME/Android/Sdk
export ANDROID_NDK_HOME=$ANDROID_SDK_ROOT/ndk/X.Y.Z

# Modify path
export PATH=$ANDROID_NDK_HOME:$PATH
export PATH=$ANDROID_SDK_ROOT/build-tools/X.Y.Z:$PATH

# (Optional if there's a new enough version of CMake + Ninja)
export PATH=$ANDROID_SDK_ROOT/cmake/3.22.1/bin:$PATH

# Verify SDK build-tools is set correctly
which aapt

# Verify NDK path is set correctly
which ndk-build

# Verify CMake/Ninja are in the path
which cmake
which ninja
```

#### Android Build

1. Building libraries to package with the APK

Invoking CMake directly to build the binary is relatively simple.

See https://developer.android.com/ndk/guides/cmake#command-line for CMake NDK documentation.

```sh
# Build release binary for arm64-v8a
cmake -S . -B build \
  -D CMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_HOME/build/cmake/android.toolchain.cmake \
  -D ANDROID_PLATFORM=26 \
  -D CMAKE_ANDROID_ARCH_ABI=arm64-v8a \
  -D CMAKE_ANDROID_STL_TYPE=c++_static \
  -D ANDROID_USE_LEGACY_TOOLCHAIN_FILE=NO \
  -D CMAKE_BUILD_TYPE=Release \
  -D UPDATE_DEPS=ON \
  -G Ninja

cmake --build build

cmake --install build --prefix build/install
```

Next, package the library into the corresponding APK under the appropriate lib
directory based on the ABI:
https://en.wikipedia.org/wiki/Apk_(file_format)#Package_contents



## Register the Layer

CDL is an implicit layer.
The loader's documentation describes
[the difference between implicit and explicit layers](https://github.com/KhronosGroup/Vulkan-LoaderAndValidationLayers/blob/master/loader/LoaderAndLayerInterface.md#implicit-vs-explicit-layers),
but the relevant bit here is that implicit layers are meant to be available to
all applications on the system, even if the application doesn't explicitly
enable the layer.

In order to be discovered by the Vulkan loader at runtime, implicit layers must
be registered.
The registration process is platform-specific.
In all cases, it is the layer manifest (the .json file) that is registered; the
manifest contains a relative path to the layer library, which can be in a
separate directory (but usually isn't).

### Overriding Platform Layer Discovery

It is possible to override the loader's usual layer discovery process by doing
the following:

 - Setting `VK_LAYER_PATH` to the directory(s) to search for layer manifest
   files.
 - Setting/Adding the layer name (`VK_LAYER_LUNARG_crash_diagnostic`)
   to `VK_INSTANCE_LAYERS`
 - On Linux/Mac, adding the location of the layer library to the appropriate
   dynamic library search path (for example `LD_LIBRARY_PATH`)

### Registering on Windows

On Windows, implicit layers must be added to the registry in order to be found
by the Vulkan loader.
See the loader's documentation on
[Windows Layer Discovery](https://github.com/KhronosGroup/Vulkan-Loader/blob/master/loader/LoaderAndLayerInterface.md#windows-layer-discovery)
for more information.

Using regedit, open one of the following keys:
- `HKEY_LOCAL_MACHINE\SOFTWARE\Khronos\Vulkan\ImplicitLayers`
- `HKEY_CURRENT_USER\SOFTWARE\Khronos\Vulkan\ImplicitLayers`

Add a new DWORD value to this key:
- Name: full path to the `CDL.json` file, `{BUILD_FOLDER}/src/VkLayer_CDL.json.json`.
- Value: 0

### Registering on Linux

On Linux, implicit layer manifests can be copied into any of the following directories:
- /usr/local/etc/vulkan/implicit_layer.d
- /usr/local/share/vulkan/implicit_layer.d
- /etc/vulkan/implicit_layer.d
- /usr/share/vulkan/implicit_layer.d
- $HOME/.local/share/vulkan/implicit_layer.d

The Linux manifest is found in `{BUILD_FOLDER}/src/VkLayer_CDL.json`.

See the loader's documentation on
[Linux Layer Discovery](https://github.com/KhronosGroup/Vulkan-Loader/blob/master/loader/LoaderAndLayerInterface.md#linux-layer-discovery)
for more information.

### Registering on Android

**TBD**

## Basic Usage

Some implicit layers are always on, others must be activated manually.
CDL falls into the later category and is disabled by default.
To enable the layer's functionality, set the `CDL_ENABLE` environment variable
to 1.

Once enabled, if `vkQueueSubmit()` or other Vulkan functions returns a fatal
error code (VK_ERROR_DEVICE_LOST or similar), a log of the command buffers that
failed to execute are written to disk.

The default log file location is:

 - Linux: `/var/log/CDL/CDL.log`
 - Windows: `%USERPROFILE%\CDL\CDL.log`.

This can be changed by using the `CDL_OUTPUT_PATH` environment variable defined
below in the [Advanced Configuration Section](#advanced-configuration).


## Advanced Configuration

Some additional environment variables are supported, mainly intended for debugging the layer itself.
- `CDL_OUTPUT_PATH` can be set to override the directory where log files and shader binaries are written.
- If `CDL_TRACE_ON` is set to 1, all Vulkan API calls intercepted by the layer will be logged to
the console.
- If `CDL_DUMP_ALL_COMMAND_BUFFERS` is set to 1, all command buffers will be output when a log is created, even if they are determined to be complete.
- If `CDL_INSTRUMENT_ALL_COMMANDS` is set to 1, all commands will be instrumented.
- If `CDL_WATCHDOG_TIMEOUT_MS` is set to a non-zero number, a watchdog thread will be created. This will trigger if the application fails to submit new commands within a set time (in milliseconds) and a log will be created as if the a lost device error was encountered.
- If `CDL_TRACK_SEMAPHORES` is set to 1, semaphore value tracking will be enabled.
- If `CDL_TRACE_ALL_SEMAPHORES` is set to 1, semaphore events will be logged to console.

- If `CDL_SHADERS_DUMP` is set to 1, all shaders will be dumped to disk when created.
- If `CDL_SHADERS_DUMP_ON_BIND` is set to 1, shaders will be dumped to disk when they are bound.  This can reduce the number of shaders dumped to those referenced by the application.
- If `CDL_SHADERS_DUMP_ON_CRASH` is set to 1, bound shaders will be dumped to disk when a crash is detected.  This will use more memory as shader code will be kept residient in case of a crash.

