#include "calcium/vulkan/vulkan_window.hpp"

#include <GLFW/glfw3.h>

#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

VulkanWindow::VulkanWindow(const WindowCreateInfo& window_info) {
  GlfwWindow::OnGlfwWindowCreate();
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [Vulkan]");
}

VulkanWindow::~VulkanWindow() {
  glfwDestroyWindow(glfw_window);

  GlfwWindow::OnGlfwWindowDestroy();
}

bool VulkanWindow::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void VulkanWindow::PollEvents() const {
  glfwPollEvents();
}

}
