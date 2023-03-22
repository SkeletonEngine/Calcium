#include "calcium/vulkan/vulkan_window.hpp"

namespace Calcium {

VulkanWindow::VulkanWindow(const WindowCreateInfo& window_info) {
  GlfwWindow::OnGlfwWindowCreate();
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [Vulkan]");
}

VulkanWindow::~VulkanWindow() {
  glfwDestroyWindow(glfw_window);

  GlfwWindow::OnGlfwWindowDestroy();
}

}
