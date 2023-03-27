#include "calcium/glfw/glfw_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

static int num_open_windows = 0;

GlfwWindow::GlfwWindow() {
  if (num_open_windows == 0) {
    glfwInit();
  }

  ++num_open_windows;
}

GlfwWindow::~GlfwWindow() {
  --num_open_windows;

  if (num_open_windows == 0) {
    glfwTerminate();
  }
}

GLFWwindow* GlfwWindow::CreateGlfwWindow(const WindowCreateInfo& window_info, const char* default_title) {
  return glfwCreateWindow(window_info.width, window_info.height, window_info.title.empty() ? default_title : window_info.title.c_str(), nullptr, nullptr);
}

static GLFWmonitor* ChooseMonitorIfExists(int monitor) {
  int monitor_count;
  GLFWmonitor** monitors = glfwGetMonitors(&monitor_count);
  if (monitor < monitor_count) {
    return monitors[monitor];
  }
  else {
    return monitors[0];
  }
}

void GlfwWindow::SetPosition(int x, int y, int monitor, bool relative_to_center) {
  GLFWmonitor* chosen_monitor = ChooseMonitorIfExists(monitor);

  const GLFWvidmode* mode = glfwGetVideoMode(chosen_monitor);
  if (!mode) return;

  int monitor_x, monitor_y;
  glfwGetMonitorPos(chosen_monitor, &monitor_x, &monitor_y);

  int window_width, window_height;
  glfwGetWindowSize(glfw_window, &window_width, &window_height);

  int window_x = relative_to_center ? (monitor_x + (mode->width - window_width) / 2) + x : monitor_x + x;
  int window_y = relative_to_center ? (monitor_y + (mode->height - window_height) / 2) + y : monitor_y + y;

  glfwSetWindowPos(glfw_window, window_x, window_y);
}

void GlfwWindow::Center(int monitor) {
  SetPosition(0, 0, monitor, true);
}

bool GlfwWindow::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void GlfwWindow::PollEvents() {
  glfwPollEvents();
}

}
