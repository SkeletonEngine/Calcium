#include "calcium/vulkan/vulkan_instance.hpp"

namespace Calcium {

VulkanWindow* VulkanInstance::CreateWindow() {
  return new VulkanWindow();
}

}
