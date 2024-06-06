/*
 * Copyright (c) 2024 The Khronos Group Inc.
 * Copyright (c) 2024 Valve Corporation
 * Copyright (c) 2024 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <filesystem>
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace dump {

struct Handle {
    uint64_t value{0};
    std::string name;
};

struct Instance {
    Handle handle;
    std::string application;
    uint32_t applicationVersion{0};
    std::string engine;
    uint32_t engineVersion{0};
    std::string apiVersion;

    std::vector<std::string> extensions;
};

struct SemaphoreInfo {
    Handle handle;
    std::string type;
    uint64_t value{0};
    uint64_t lastValue{0};
};

struct SubmitInfo {
    uint32_t id{0};
    uint64_t start_seq{0};
    uint64_t end_seq{0};
    std::string state;
    std::vector<std::string> CommandBuffers;
    std::vector<SemaphoreInfo> SignalSemaphores;
    std::vector<SemaphoreInfo> WaitSemaphores;
};

struct Submit {
    uint32_t id{0};
    std::string type;
    std::string fence;
    uint64_t startSeq{0};
    uint64_t endSeq{0};
    std::vector<SubmitInfo> SubmitInfos;
};

struct Queue {
    Handle handle;
    uint32_t qfi{0};
    uint32_t index{0};
    uint32_t flags{0};
    uint64_t completedSeq{0};
    uint64_t submittedSeq{0};

    std::vector<Submit> submits;
};

struct Command {
    uint32_t id{0};
    uint32_t checkpointValue{0};
    std::string name;
    std::string state;
    std::string message;
    // parameters?
};

struct CommandBuffer {
    Handle handle;
    std::string state;
    Handle commandPool;
    Handle queue;
    Handle fence;
    uint64_t queueSeq{0};
    std::string level;
    bool simultaneousUse{false};
    uint32_t beginValue{0};
    uint32_t endValue{0};
    uint32_t topCheckpointValue{0};
    uint32_t bottomCheckpointValue{0};
    uint32_t lastStartedCommand{0};
    uint32_t lastCompletedCommand{0};

    std::vector<Command> commands;
};

struct WaitingThread {
    uint64_t pid{0};
    uint64_t tid{0};
    std::string waitType;

    std::vector<SemaphoreInfo> wait_semaphores;
};

struct AddressRecord {
    uint64_t begin{0};
    uint64_t end{0};
    std::string type;
    Handle handle;
    bool currentlyBound{false};
};

struct FaultAddressRange {
    std::string type;
    uint64_t begin{0};
    uint64_t end{0};
    std::optional<AddressRecord> prior;
    std::optional<AddressRecord> next;
};

struct DeviceFaultInfo {
    std::string description;
    std::vector<FaultAddressRange> fault_address_ranges;
};

struct Device {
    Handle handle;
    std::string deviceName;
    std::string apiVersion;
    std::string driverVersion;
    uint32_t vendorID{0};
    uint32_t deviceID{0};

    std::vector<std::string> extensions;

    std::vector<Queue> queues;
    std::vector<CommandBuffer> incomplete_cbs;
    std::vector<CommandBuffer> all_cbs;
    std::vector<WaitingThread> waiting_threads;

    std::optional<DeviceFaultInfo> fault_info;
};

struct File {
    std::string version;
    std::string startTime;
    std::string timeSinceStart;

    std::map<std::string, std::string> settings;

    Instance instance;

    std::vector<Device> devices;
};

void Parse(File& file, const std::filesystem::path& path);

}  // namespace dump
