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

namespace dump {

static void ParseSettings(std::map<std::string, std::string> &settings, const YAML::Node &settings_node) {
    for (const auto& node : settings_node) {
        std::string k = node.first.as<std::string>();
        std::string v = node.second.as<std::string>();
	ASSERT_FALSE(k);
	settings[k] = v;
    }
}

static void ParseAppInfo(Instance& instance, const YAML::Node &app_info_node) {
    for (const auto& node : app_info_node) {
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
	    //TODO instance.apiVersion = node.second.as<uint32_t>();
	}
    }
}

static void ParseInstance(Instance& instance, const YAML::Node& instance_node) {
    ASSERT_TRUE(instance_node);
    ASSERT_TRUE(instance_node.IsMap());
    for (const auto& node : instance_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            instance.handle = node.second.as<std::string>();
        } else if (key == "applicationInfo") {
            ASSERT_TRUE(node.second.IsMap());
            ParseAppInfo(instance, node.second);
        } else if (key == "instanceExtensions") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                instance.extensions.push_back(elem.as<std::string>());
            }
        }
    }
}

static void ParseDevice(Device& device, const YAML::Node& device_node) {
    ASSERT_TRUE(device_node);
    ASSERT_TRUE(device_node.IsMap());
    for (const auto& node : device_node) {
        std::string key = node.first.as<std::string>();
        if (key == "handle") {
            device.handle = node.second.as<std::string>();
        } else if (key == "deviceName") {
            device.deviceName = node.second.as<std::string>();
        } else if (key == "apiVersion") {
            //TODO device.apiVersion = node.second.as<std::string>();
        } else if (key == "driverVersion") {
            //TODO device.driverVersion = node.second.as<std::string>();
        } else if (key == "vendorID") {
            device.vendorID = node.second.as<uint32_t>();
        } else if (key == "deviceID") {
            device.deviceID = node.second.as<uint32_t>();
        } else if (key == "extensions") {
            ASSERT_TRUE(node.second.IsSequence());
            for (const auto& elem : node.second) {
                device.extensions.push_back(elem.as<std::string>());
            }
        }
    }
}

void Parse(File& dump_file, const std::filesystem::path &search_path) {
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
        } else if (key == "settings") {
            ParseSettings(dump_file.settings, node.second);
        } else if (key == "SystemInfo") {
            //TODO ParseSystemInfo(dump_file.systemInfo, node.second);
        } else if (key == "Instance") {
            ParseInstance(dump_file.instance, node.second);
        } else if (key == "Device") {
	    Device device;
            ParseDevice(device, node.second);
	    dump_file.emplace_back(std::move(device));
        } else {
            FAIL() << "Unkown top level key: " << key;
        }
    }
}

} // namespace dump
