# Crash Diagnostic Layer

The Crash Diagnostic Layer (CDL)  is a Vulkan layer to help track down and identify the cause of GPU hangs and crashes. It works by instrumenting command buffers with completion tags. When an error is detected a log file containing incomplete command buffers is written. Often the last complete or incomplete commands are responsible for the crash.

This product started development as part of Google's Stadia project, as the [Graphics Flight Recorder](https://github.com/googlestadia/gfr), but was never officially supported until taken over by LunarG.


## Building

See the associated [BUILD.md](./BUILD.md) file for details on how to build the Crash Diagnostic Layer for various platforms.

## Runtime requirements

CDL uses the following extensions. If an extension is not present, some functionality might be disabled.

- `VK_KHR_timeline_semaphore` (or Vulkan 1.2) - used to track forward progress of queue submissions
- `VK_NV_device_diagnostic_commands` - used to track forward progress within command buffers
- `VK_AMD_buffer_marker` - used to track forward progress within command buffers (if the NV extension is not present) and the state of binary semaphores.
- `VK_AMD_device_coherent_memory` - improves the accuracy of VK_AMD_buffer_marker tracking
- `VK_EXT_device_fault` - allows drivers to report data related to a `VK_ERROR_DEVICE_LOST`, such as invalid device addresses.
- `VK_EXT_device_address_binding_report` - allows drivers to report lifecycle information about device address assignments, which can help identify the source of device faults.

## Running

CDL can be used as an explicit or implicit layer. The loader's documentation describes [the difference between implicit and explicit layers](https://github.com/KhronosGroup/Vulkan-Loader/blob/main/docs/LoaderApplicationInterface.md#implicit-vs-explicit-layers), but the relevant bit here is that implicit layers are meant to be available  to all applications on the system, even if the application doesn't explicitly enable the layer. On the other hand, explicit layers are easier to use when doing application development.

### Explicit Layer

To use CDL as an explicit layer, enable it with `vkconfig` or do the following:

1. The directory containing the file `VkLayer_crash_diagnostic.json` is included in the layer search path, by including it in either the `VK_LAYER_PATH` or `VK_ADD_LAYER_PATH` environment variable or by using `vkconfig`.
2. Include the layer name in the VK_INSTANCE_LAYERS environment variable or the ppEnabledLayerNames field of [VkInstanceCreateInfo](https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkInstanceCreateInfo.html).

### Implicit Layer

When using CDL as an implicit layer, it is disabled by default. To enable the layer's functionality, set the `CDL_ENABLE` environment variable to 1.


#### Registering the Layer

In order to be discovered by the Vulkan loader at runtime, implicit layers must be registered. The registration process is platform-specific and is discussed in detail in the [Vulkan-Loader documentation](https://github.com/KhronosGroup/Vulkan-Loader/blob/main/docs/LoaderLayerInterface.md#layer-discovery). In all cases, it is the layer manifest (the .json file) that is registered; the manifest contains a relative path to the layer library, which can be in a separate directory.

## Basic Usage

Once the layer is enabled, if `vkQueueSubmit()` or other Vulkan functions returns a fatal error code (usually `VK_ERROR_DEVICE_LOST`), a log of the command buffers that failed to execute are written to disk.

### Logging

CDL outputs messages at runtime to indicate it is enabled, to trace certain commands, and to report when a gpu crash has occurred.  The `message_severity`, `log_file`, `trace_on` and `trace_all_semaphores` configuration settings control which messages are output and where they are sent.

`VK_EXT_debug_utils` and `VK_EXT_debug_report` extensions can also be used to receive log messages directly in the application.

### Dump files

A unique log file directory is created every time an application is run with CDL enabled. The log file directories are named with the timestamp of the format YYYY-MM-DD-HHMMSS.  This prevents subsequent runs from overwriting old data, in case the application is non-deterministic and producing different crashes on each run. The location of these files is platform-specific:

 - Linux: `${HOME}/cdl/`
 - Windows: `%USERPROFILE%\cdl\`

The output directory for dump files can be changed using the `output_path` configuration setting, described below.

The name of the dump file is `cdl_dump.yaml`, since the file is in the [YAML format](https://yaml.org/).  Other files, such as dumped shaders, may be present in the dump directory.


## Configuration

This layer implements the `VK_EXT_layer_settings` extension, so it can be configured with `vkconfig`, programmatically, or with environment variables.  See the [manifest for this layer](src/crash_diagnostic_layer.json.in) and the [layer manifest schema](https://github.com/LunarG/VulkanTools/blob/main/vkconfig_core/layers/layers_schema.json) for full details. The discussion below uses the `key` field to identify each setting, the `env` field defines the corresponding environment variable, and the `label` field defines the text you will see when using `vkconfig`.

- `watchdog_timeout_ms`can be set to enable a watchdog thread that monitors the time between queue submissions. If this timeout value (specified in milliseconds) is hit without a queue submission, the gpu is assumed to be crashed and a dump file is created.

- `output_path` can be set to override the directory where log files and shader binaries are written. This can be a full path (starting with `/` or a drive letter) or a path relative to the application current working directory.
- `dump_queue_submissions`  controls which queue submissions are dumped. `running` causes only the submission currently executing to be dumped. `pending` will also dump any submissions that have not started execution.
- `dump_command_buffers`  controls which command buffers are dumped. `running` causes only the command buffer currently executing to be dumped. `pending` will also dump any command buffers that have not started execution. `all` will dump all known command buffers.
- `dump_commands`  controls which commands are dumped. `running` causes only the commands currently executing to be dumped. `pending` will also dump any commands that have not started execution. `all` will dump all commands in the command buffer.
- `dump_shaders` controls if shaders are included in the dump directory. Possible values for this setting are: `off` - no output, `on_crash` - only dump the shaders that are bound at the time of a gpu crash, `on_bind` - dump shaders only when they are bound, and `all` - dump all shaders as soon as they are created.
- `message_severity` can be set to a comma-separated list of the types of messages CDL should output to the default logger. Application defined loggers should control which messages they want to recieve with the options available in the `VK_EXT_debug_utils` or `VK_EXT_debug_report` extensions.
- `log_file` can be set to control where log messages are sent by the default logger. There are several special values. `stderr` and `stdout` send messages to the application console. `none` disables the default logger. Any other value is assumed to be an absolute or relative path to the log file.
- `trace_on` can be enabled to cause important commands, such as `vkQueueSubmit` to be logged as they occur.
- `trace_all_semaphores` enables logging messages about every vulkan command that uses semaphores.
- `instrument_all_commands` can be enabled to include completion markers around every vulkan command. This may allow more accuratute fault locations at the expense of larger command buffers and reduced performance. 
- `track_semaphores` enables detailed semaphore state reporting in runtime logging and dump files. `VK_AMD_buffer_marker` is required for this feature.
