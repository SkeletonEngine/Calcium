#include "vulkan_debug_messenger.hpp"

#include <vector>

#include <volk.h>

#include "calcium/common/logger.hpp"

namespace Calcium {
namespace Vulkan {

const static std::vector<const char*> kValidationLayers = {
  "VK_LAYER_KHRONOS_validation"
};

static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT message_severity,
    VkDebugUtilsMessageTypeFlagsEXT message_type,
    const VkDebugUtilsMessengerCallbackDataEXT* callback_data,
    void* user_data) {
  
  switch (message_severity) {
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT: CALCIUM_LOG_TRACE(callback_data->pMessage); break;
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:    CALCIUM_LOG_INFO(callback_data->pMessage);  break;
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT: CALCIUM_LOG_WARN(callback_data->pMessage);  break;
    case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:   CALCIUM_LOG_ERROR(callback_data->pMessage); break;
    default:                                              CALCIUM_LOG_FATAL(callback_data->pMessage); break;
  }
  
  return VK_FALSE;
}

static VkDebugUtilsMessengerCreateInfoEXT CreateDebugMessengerInfo() {
  VkDebugUtilsMessengerCreateInfoEXT messenger_info { };
  messenger_info.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
  messenger_info.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
    | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
  messenger_info.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
    | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
  messenger_info.pfnUserCallback = DebugCallback;
  messenger_info.pUserData = nullptr;
  return messenger_info;
}

const static VkDebugUtilsMessengerCreateInfoEXT kDebugMessengerInfo = Vulkan::CreateDebugMessengerInfo();

static bool AreAllValidationLayersSupported() {
  /* List all available validation layers */
  uint32_t layer_count;
  vkEnumerateInstanceLayerProperties(&layer_count, nullptr);
  std::vector<VkLayerProperties> available_layers(layer_count);
  vkEnumerateInstanceLayerProperties(&layer_count, available_layers.data());

  /* Check that all requested validation layers are in the list */
  for (const char* layer_name : kValidationLayers) {
    bool layer_found = false;

    for (const auto& layerProperties : available_layers) {
      if (strcmp(layer_name, layerProperties.layerName) == 0) {
        layer_found = true;
        break;
      }
    }

    if (!layer_found) {
      return false;
    }
  }

  return true;
}

void AddDebugMessenger(VkInstanceCreateInfo& instance_info) {
  instance_info.enabledLayerCount = (uint32_t)kValidationLayers.size();
  instance_info.ppEnabledLayerNames = kValidationLayers.data();
  instance_info.pNext = &kDebugMessengerInfo;
}

}
}
