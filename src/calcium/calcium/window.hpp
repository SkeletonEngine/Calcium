#pragma once

struct GLFWwindow;

namespace Calcium {

class Window {
public:
  Window();
  ~Window();

public:
  bool IsOpen() const;

public:
  static void PollEvents();

private:
  GLFWwindow* glfw_window;
};

}
