#pragma once

#include <GLFW/glfw3.h>

#include "calcium/common/window.hpp"
#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

class VulkanWindow {
public:
  VulkanWindow(const WindowCreateInfo& window_info);
  ~VulkanWindow();

public:
  inline void SetPosition(int x, int y, int monitor = 0) { GlfwWindow::PositionGlfwWindow(glfw_window, x, y, monitor, false); }
  inline void Center(int monitor = 0)                    { GlfwWindow::PositionGlfwWindow(glfw_window, 0, 0, monitor, true);  }

public:
  bool IsOpen() const     { return !glfwWindowShouldClose(glfw_window); }
  void PollEvents() const { glfwPollEvents(); };

private:
  GLFWwindow* glfw_window;
};

}
