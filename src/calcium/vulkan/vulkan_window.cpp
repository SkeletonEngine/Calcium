#include "calcium/vulkan/vulkan_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

VulkanWindow::VulkanWindow(const WindowCreateInfo& window_info) {
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [Vulkan]");
}

}
