#pragma once

#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

class OpenGlWindow : public GlfwWindow {
public:
  OpenGlWindow(const WindowCreateInfo& window_info);
};

}
