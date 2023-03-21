#include "calcium/vulkan/vulkan_instance.hpp"

#include "calcium/vulkan/vulkan_window.hpp"

namespace Calcium {

VulkanWindow* VulkanInstance::CreateWindow() {
  return windows.Create();
}

}
