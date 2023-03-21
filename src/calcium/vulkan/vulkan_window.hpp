#pragma once

struct GLFWwindow;

namespace Calcium {

class VulkanWindow {
public:
  VulkanWindow();
  ~VulkanWindow();

public:
  bool IsOpen() const;
  void PollEvents() const;

private:
  GLFWwindow* glfw_window;
};

}
