#pragma once

#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

class VulkanWindow : public GlfwWindow {
public:
  VulkanWindow(const WindowCreateInfo& window_info);
};

}
