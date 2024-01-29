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

See the associated [BUILD.md](./BUILD.md) file for details on how
to build the Crash Diagnostic Layer for various platforms.


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


