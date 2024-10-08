/*
 Copyright 2018 Google Inc.
 Copyright 2023-2024 LunarG, Inc.

 Licensed under the Apache License, Version 2.0 (the "License") override;
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#pragma once

#include <vulkan/vulkan.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace YAML {
class Emitter;
}  // namespace YAML

namespace crash_diagnostic_layer {

class Device;

// =============================================================================
// ActiveDescriptorSets
// Tracks the current state of descriptors after multiple bindings.
// Used to display the expected state of the GPU when dumping logs.
// =============================================================================
class ActiveDescriptorSets {
   public:
    void Reset();
    void Bind(uint32_t first_set, uint32_t set_count, const VkDescriptorSet* sets);

    YAML::Emitter& Print(Device& device, YAML::Emitter& stream) const;

   private:
    void Insert(VkDescriptorSet set, uint32_t index);

    std::map<uint32_t, VkDescriptorSet> descriptor_sets_;
};

}  // namespace crash_diagnostic_layer
