#include "calcium/vulkan/vulkan_instance.hpp"

#include "calcium/vulkan/vulkan_window.hpp"

namespace Calcium {

VulkanWindow* VulkanInstance::CreateWindow(const WindowCreateInfo& window_info) {
  return windows.Create(window_info);
}

void VulkanInstance::DestroyWindow(VulkanWindow* window) {
  windows.Remove(window);
};

void VulkanInstance::BeginFrame() {

}

void VulkanInstance::EndFrame() {

}

}
