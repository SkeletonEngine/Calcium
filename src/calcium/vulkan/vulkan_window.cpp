#include "calcium/vulkan/vulkan_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

VulkanWindow::VulkanWindow() {
  glfwInit();
  glfw_window = glfwCreateWindow(1280, 720, "Hello", nullptr, nullptr);
}

VulkanWindow::~VulkanWindow() {
  glfwDestroyWindow(glfw_window);
}

bool VulkanWindow::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void VulkanWindow::PollEvents() const {
  glfwPollEvents();
}

}
