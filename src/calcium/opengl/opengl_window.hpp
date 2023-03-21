#pragma once

struct GLFWwindow;

namespace Calcium {

class OpenGlWindow {
public:
  OpenGlWindow();
  ~OpenGlWindow();

public:
  bool IsOpen() const;
  void PollEvents() const;

private:
  GLFWwindow* glfw_window;
};

}
