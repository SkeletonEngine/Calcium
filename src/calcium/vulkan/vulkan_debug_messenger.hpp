#pragma once

#include <volk.h>

namespace Calcium {
namespace Vulkan {

VkDebugUtilsMessengerCreateInfoEXT CreateDebugMessengerCreateInfo();
bool AreAllValidationLayersSupported();
void SetValidationLayers(VkInstanceCreateInfo& instance_info);

}
}
