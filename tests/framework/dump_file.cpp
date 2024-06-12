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
#include "dump_file.h"
#include <gtest/gtest.h>
#include <yaml-cpp/yaml.h>
#include <regex>

namespace dump {

static void ParseSettings(std::map<std::string, std::string>& settings, const YAML::Node& in_node) {
    for (const auto& node : in_node) {
        std::string k = node.first.as<std::string>();
        std::string v = node.second.as<std::string>();
        // there shouldn't be duplicate settings keys
        ASSERT_EQ(settings.count(k), 0);
        settings[k] = v;
    }
}

static void ParseAppInfo(Instance& instance, const YAML::Node& in_node) {
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "application") {
            instance.application = node.second.as<std::string>();
        } else if (key == "applicationVersion") {
            instance.applicationVersion = node.second.as<uint32_t>();
        } else if (key == "engine") {
            instance.engine = node.second.as<std::string>();
        } else if (key == "engineVersion") {
            instance.engineVersion = node.second.as<uint32_t>();
        } else if (key == "apiVersion") {
            instance.apiVersion = node.second.as<std::string>();  // printed by CDL in a custom format
        } else {
            FAIL() << "Unkown applicationInfo key: " << key;
        }
    }
}

static void ParseHandle(Handle& handle, const YAML::Node& node) {
    std::string value = node.as<std::string>();
    const std::regex re("(0x[0-9a-fA-F]+) *\\[(.*)\\]");
    std::smatch base_match;

    if (std::regex_match(value, base_match, re)) {
        handle.value = std::stoll(base_match[1], nullptr, 16);
        handle.name = base_match[2];
    } else {
        FAIL() << "Bad handle value:" << value;
    }
}

static void ParseInstance(Instance& instance, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            ParseHandle(instance.handle, node.second);
        } else if (key == "applicationInfo") {
            ASSERT_TRUE(node.second.IsMap());
            ParseAppInfo(instance, node.second);
        } else if (key == "extensions") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                instance.extensions.push_back(elem.as<std::string>());
            }
        } else {
            FAIL() << "Unkown Instance key: " << key;
        }
    }
}

static void ParseSemaphoreInfo(SemaphoreInfo& info, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            ParseHandle(info.handle, node.second);
        } else if (key == "type") {
            info.type = node.second.as<std::string>();
        } else if (key == "value") {
            info.value = node.second.as<uint64_t>();
        } else if (key == "lastValue") {
            info.lastValue = node.second.as<uint64_t>();
        } else {
            FAIL() << "Unkown SemaphoreInfo key: " << key;
        }
    }
}

static void ParseSubmitInfo(SubmitInfo& info, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "id") {
            info.id = node.second.as<uint64_t>();
        } else if (key == "state") {
            info.state = node.second.as<std::string>();
        } else if (key == "start_seq") {
            info.start_seq = node.second.as<uint64_t>();
        } else if (key == "end_seq") {
            info.end_seq = node.second.as<uint64_t>();
        } else if (key == "CommandBuffers") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                info.CommandBuffers.push_back(elem.as<std::string>());
            }
        } else if (key == "SignalSemaphores") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                SemaphoreInfo sem_info;
                ParseSemaphoreInfo(sem_info, elem);
                info.SignalSemaphores.emplace_back(std::move(sem_info));
            }
        } else if (key == "WaitSemaphores") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                SemaphoreInfo sem_info;
                ParseSemaphoreInfo(sem_info, elem);
                info.WaitSemaphores.emplace_back(std::move(sem_info));
            }
        } else {
            FAIL() << "Unkown SubmitInfo key: " << key;
        }
    }
}

static void ParseSubmit(Submit& submit, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "id") {
            submit.id = node.second.as<uint32_t>();
        } else if (key == "startSeq") {
            submit.startSeq = node.second.as<uint64_t>();
        } else if (key == "endSeq") {
            submit.endSeq = node.second.as<uint64_t>();
        } else if (key == "type") {
            submit.type = node.second.as<std::string>();
        } else if (key == "SubmitInfos") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                SubmitInfo submit_info;
                ParseSubmitInfo(submit_info, elem);
                submit.SubmitInfos.emplace_back(std::move(submit_info));
            }
        } else {
            FAIL() << "Unkown Submit key: " << key;
        }
    }
}

static void ParseQueue(Queue& queue, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            ParseHandle(queue.handle, node.second);
        } else if (key == "queueFamilyIndex") {
            queue.qfi = node.second.as<uint32_t>();
        } else if (key == "index") {
            queue.index = node.second.as<uint32_t>();
        } else if (key == "flags") {
            // TODO
        } else if (key == "completedSeq") {
            queue.completedSeq = node.second.as<uint64_t>();
        } else if (key == "submittedSeq") {
            queue.submittedSeq = node.second.as<uint64_t>();
        } else if (key == "IncompleteSubmits") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                Submit submit;
                ParseSubmit(submit, elem);
                queue.submits.emplace_back(std::move(submit));
            }

        } else {
            FAIL() << "Unkown Queue key: " << key;
        }
    }
}

static void ParseCommand(Command& cmd, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "id") {
            cmd.id = node.second.as<uint32_t>();
        } else if (key == "checkpointValue") {
            cmd.checkpointValue = node.second.as<uint32_t>();
        } else if (key == "name") {
            cmd.name = node.second.as<std::string>();
        } else if (key == "state") {
            cmd.state = node.second.as<std::string>();
        } else if (key == "message") {
            cmd.message = node.second.as<std::string>();
        } else if (key == "parameters") {
            // TODO
        } else if (key == "internalState") {
            // TODO
        } else if (key == "labels") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                cmd.labels.push_back(elem.as<std::string>());
            }
        } else {
            FAIL() << "Unkown Command key: " << key;
        }
    }
}

static void ParseCommandBuffer(CommandBuffer& cb, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "state") {
            cb.state = node.second.as<std::string>();
        } else if (key == "handle") {
            ParseHandle(cb.handle, node.second);
        } else if (key == "commandPool") {
            ParseHandle(cb.commandPool, node.second);
        } else if (key == "queue") {
            ParseHandle(cb.queue, node.second);
        } else if (key == "fence") {
            ParseHandle(cb.fence, node.second);
        } else if (key == "queueSeq") {
            cb.queueSeq = node.second.as<uint64_t>();
        } else if (key == "level") {
            cb.level = node.second.as<std::string>();
        } else if (key == "simultaneousUse") {
            cb.simultaneousUse = node.second.as<bool>();
        } else if (key == "beginValue") {
            cb.beginValue = node.second.as<uint32_t>();
        } else if (key == "endValue") {
            cb.endValue = node.second.as<uint32_t>();
        } else if (key == "topCheckpointValue") {
            cb.topCheckpointValue = node.second.as<uint32_t>();
        } else if (key == "bottomCheckpointValue") {
            cb.bottomCheckpointValue = node.second.as<uint32_t>();
        } else if (key == "lastStartedCommand") {
            cb.lastStartedCommand = node.second.as<uint32_t>();
        } else if (key == "lastCompletedCommand") {
            cb.lastCompletedCommand = node.second.as<uint32_t>();
        } else if (key == "Commands") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                Command cmd;
                ParseCommand(cmd, elem);
                cb.commands.emplace_back(std::move(cmd));
            }
        } else {
            FAIL() << "Unkown CommandBuffer key: " << key;
        }
    }
}

static void ParseWaitingThread(WaitingThread& wt, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "PID") {
            wt.pid = node.second.as<uint64_t>();
        } else if (key == "TID") {
            wt.tid = node.second.as<uint64_t>();
        } else if (key == "waitType") {
            wt.waitType = node.second.as<std::string>();
        } else if (key == "WaitSemaphores") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                SemaphoreInfo sem_info;
                ParseSemaphoreInfo(sem_info, elem);
                wt.wait_semaphores.emplace_back(std::move(sem_info));
            }
        } else {
            FAIL() << "Unkown WaitingThread key: " << key;
        }
    }
}

static void ParseAddressRecord(AddressRecord& record, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "type") {
            record.type = node.second.as<std::string>();
        } else if (key == "handle") {
            ParseHandle(record.handle, node.second);
        } else if (key == "begin") {
            record.begin = node.second.as<uint64_t>();
        } else if (key == "end") {
            record.end = node.second.as<uint64_t>();
        } else if (key == "currentlyBound") {
            record.currentlyBound = node.second.as<bool>();
        } else {
            FAIL() << "Unkown AddressRecord key: " << key;
        }
    }
}

static void ParseFaultAddressRange(FaultAddressRange& range, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "type") {
            range.type = node.second.as<std::string>();
        } else if (key == "begin") {
            range.begin = node.second.as<uint64_t>();
        } else if (key == "end") {
            range.end = node.second.as<uint64_t>();
        } else if (key == "priorAddressRecord") {
            ASSERT_FALSE(range.prior.has_value());
            AddressRecord rec;
            ParseAddressRecord(rec, node.second);
            range.prior = rec;
        } else if (key == "nextAddressRecord") {
            ASSERT_FALSE(range.next.has_value());
            AddressRecord rec;
            ParseAddressRecord(rec, node.second);
            range.next = rec;
        } else {
            FAIL() << "Unkown FaultAddressRange key: " << key;
        }
    }
}

static void ParseDeviceFaultInfo(DeviceFaultInfo& fault, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "description") {
            fault.description = node.second.as<std::string>();
        } else if (key == "faultAddressRanges") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                FaultAddressRange range;
                ParseFaultAddressRange(range, elem);
                fault.fault_address_ranges.emplace_back(std::move(range));
            }
        } else {
            FAIL() << "Unkown DeviceFaultInfo key: " << key;
        }
    }
}

static void ParseDevice(Device& device, const YAML::Node& in_node) {
    ASSERT_TRUE(in_node);
    ASSERT_TRUE(in_node.IsMap());
    for (const auto& node : in_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            ParseHandle(device.handle, node.second);
        } else if (key == "deviceName") {
            device.deviceName = node.second.as<std::string>();
        } else if (key == "apiVersion") {
            device.apiVersion = node.second.as<std::string>();  // printed by CDL in a custom format
        } else if (key == "driverVersion") {
            device.driverVersion = node.second.as<std::string>();  // printed by CDL in a custom format
        } else if (key == "vendorID") {
            device.vendorID = node.second.as<uint32_t>();
        } else if (key == "deviceID") {
            device.deviceID = node.second.as<uint32_t>();
        } else if (key == "Queues") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                Queue q;
                ParseQueue(q, elem);
                device.queues.emplace_back(std::move(q));
            }
        } else if (key == "CommandBuffers") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                CommandBuffer cb;
                ParseCommandBuffer(cb, elem);
                device.command_buffers.emplace_back(std::move(cb));
            }
        } else if (key == "WaitingThreads") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                WaitingThread wt;
                ParseWaitingThread(wt, elem);
                device.waiting_threads.emplace_back(std::move(wt));
            }
        } else if (key == "extensions") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                device.extensions.push_back(elem.as<std::string>());
            }
        } else if (key == "DeviceFaultInfo") {
            ASSERT_FALSE(device.fault_info.has_value());
            DeviceFaultInfo fault;
            ParseDeviceFaultInfo(fault, node.second);
            device.fault_info = fault;
        } else {
            FAIL() << "Unkown Device key: " << key;
        }
    }
}

void Parse(File& dump_file, const std::filesystem::path& search_path) {
    std::filesystem::path file;
    std::filesystem::recursive_directory_iterator iter(search_path), end;
    for (; iter != end; ++iter) {
        // There should be only 1 dump file in the search path.
        // Check that instead of breaking out on the first one found.
        if (iter->path().filename() == "cdl_dump.yaml") {
            ASSERT_TRUE(file.empty());
            file = iter->path();
        }
    }
    ASSERT_FALSE(file.empty());

    YAML::Node root = YAML::LoadFile(file.string());
    ASSERT_TRUE(root);
    ASSERT_TRUE(root.IsMap());
    for (const auto& node : root) {
        std::string key = node.first.as<std::string>();
        if (key == "version") {
            dump_file.version = node.second.as<std::string>();
        } else if (key == "startTime") {
            dump_file.startTime = node.second.as<std::string>();
        } else if (key == "timeSinceStart") {
            dump_file.timeSinceStart = node.second.as<std::string>();
        } else if (key == "Settings") {
            ParseSettings(dump_file.settings, node.second);
        } else if (key == "SystemInfo") {
            // TODO ParseSystemInfo(dump_file.systemInfo, node.second);
        } else if (key == "Instance") {
            ParseInstance(dump_file.instance, node.second);
        } else if (key == "Device") {
            Device device;
            ParseDevice(device, node.second);
            dump_file.devices.emplace_back(std::move(device));
        } else {
            FAIL() << "Unkown top level key: " << key;
        }
    }
}

}  // namespace dump
