#pragma once

#include "calcium/common/window.hpp"

struct GLFWwindow;

namespace Calcium {

class GlfwWindow {
public:
  GlfwWindow();
  virtual ~GlfwWindow();

protected:
  GLFWwindow* CreateGlfwWindow(const WindowCreateInfo& window_info, const char* default_title);

public:
  void SetPosition(int x, int y, int monitor = 0, bool relative_to_center = false);
  void Center(int monitor = 0);

public:
  bool IsOpen() const;

public:
  static void PollEvents();

protected:
  GLFWwindow* glfw_window;
};

}
