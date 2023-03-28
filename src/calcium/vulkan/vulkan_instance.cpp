#include "calcium/vulkan/vulkan_instance.hpp"

#include <GLFW/glfw3.h>
#include <volk.h>

#include "calcium/vulkan/vulkan_assert.hpp"
#include "calcium/vulkan/vulkan_window.hpp"

namespace Calcium {

static int num_instances = 0;

VulkanInstance::VulkanInstance() {
  CALCIUM_LOGGER_INIT();

  /* Initialise volk */
  if (num_instances == 0) {
    volkInitialize();
  }
  ++num_instances;

  /* Create VkInstance */
  VkApplicationInfo app_info { };
  app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.pEngineName = "Calcium";
  app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo create_info { };
  create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo = &app_info;

  uint32_t glfw_extension_count = 0;
  const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

  create_info.enabledExtensionCount = glfw_extension_count;
  create_info.ppEnabledExtensionNames = glfw_extensions;

  create_info.enabledLayerCount = 0;
  VK_CALL(vkCreateInstance(&create_info, nullptr, &instance));
}

VulkanInstance::~VulkanInstance() {
  --num_instances;
}

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
