#pragma once

#include "calcium/common/window.hpp"

struct GLFWwindow;

namespace Calcium {

class VulkanWindow {
public:
  VulkanWindow(const WindowCreateInfo& window_info);
  ~VulkanWindow();

public:
  bool IsOpen() const;
  void PollEvents() const;

private:
  GLFWwindow* glfw_window;
};

}
