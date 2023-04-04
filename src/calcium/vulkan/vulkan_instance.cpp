#include "calcium/vulkan/vulkan_instance.hpp"

#include <vector>

#include <GLFW/glfw3.h>
#include <volk.h>

#include "calcium/common/instance.hpp"
#include "calcium/vulkan/vulkan_assert.hpp"
#include "calcium/vulkan/vulkan_debug_messenger.hpp"
#include "calcium/vulkan/vulkan_instance_extensions.hpp"
#include "calcium/vulkan/vulkan_window.hpp"

namespace Calcium {

static int num_instances = 0;

VulkanInstance::VulkanInstance() {
  Instance::OnInstanceCreate();
  CALCIUM_LOG_INFO("Creating VulkanInstance");

  /* Load enough vulkan functions to create an instance */
  ++num_instances;
  if (num_instances == 1) {
    volkInitialize();
  }

  /* Create VkInstance */
  VkApplicationInfo app_info { VK_STRUCTURE_TYPE_APPLICATION_INFO };
  app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.pEngineName = "Calcium";
  app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo instance_info { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
  instance_info.pApplicationInfo = &app_info;
  
  /* Find required instance extensions */
  auto required_extensions = Vulkan::GetRequiredInstanceExtensions();
  instance_info.enabledExtensionCount = (uint32_t)required_extensions.size();
  instance_info.ppEnabledExtensionNames = required_extensions.data();

  /* Add validation layers */
#ifdef CALCIUM_BUILD_DEBUG
  CALCIUM_ASSERT(Vulkan::AreAllValidationLayersSupported());
  VkDebugUtilsMessengerCreateInfoEXT debug_messenger_info = Vulkan::CreateDebugMessengerCreateInfo();
  Vulkan::SetValidationLayers(instance_info);
  instance_info.pNext = &debug_messenger_info;
#endif

  /* Create VkInstance */
  VK_CALL(vkCreateInstance(&instance_info, allocator, &instance));

  /* Load the rest of the vulkan functions */
  if (num_instances == 1) {
    volkLoadInstance(instance);
  }

}

VulkanInstance::~VulkanInstance() {
  vkDestroyInstance(instance, allocator);
  --num_instances;
  Instance::OnInstanceDestroy();
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
