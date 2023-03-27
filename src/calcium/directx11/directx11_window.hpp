#pragma once

#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

class DirectX11Window : public GlfwWindow {
public:
  DirectX11Window(const WindowCreateInfo& window_info);
};

}
