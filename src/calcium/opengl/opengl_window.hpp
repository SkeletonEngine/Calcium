#pragma once

#include "calcium/common/window.hpp"

struct GLFWwindow;

namespace Calcium {

class OpenGlWindow {
public:
  OpenGlWindow(const WindowCreateInfo& window_info);
  ~OpenGlWindow();

public:
  bool IsOpen() const;
  void PollEvents() const;

private:
  GLFWwindow* glfw_window;
};

}
