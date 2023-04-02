#include "calcium/vulkan/vulkan_instance_extensions.hpp"

#include <GLFW/glfw3.h>
#include <volk.h>

#include "calcium/common/platform.hpp"

namespace Calcium {
namespace Vulkan {

std::vector<const char*> GetRequiredInstanceExtensions() {
  /* glfw extensions:
     - VK_KHR_surface
     - platform-specific surface extensions e.g. VK_KHR_win32_surface
   */
  uint32_t glfw_extension_count;
  const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
  std::vector<const char*> extensions(glfw_extensions, glfw_extensions + glfw_extension_count);

  /* Debug extensions:
     - VK_EXT_debug_utils: Required for debug message callbacks
   */
#ifdef CALCIUM_BUILD_DEBUG
  extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

  /* macOS extensions:
     - VK_KHR_get_physical_device_properties2: Required for VK_KHR_portability_subset, which is required for MoltenVk
     - VK_KHR_portability_enumeration: Required for MoltenVk, but only since SDK version 1.3.216
   */
#ifdef CALCIUM_PLATFORM_MACOS
  uint32_t version;
  vkEnumerateInstanceVersion(&version);
  if (version >= VK_MAKE_API_VERSION(0, 1, 3, 216)) {
    extensions.push_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
  }
  extensions.push_back("VK_KHR_get_physical_device_properties2");
#endif

  return extensions;
}

}
}
