#include "calcium/glfw/glfw_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {
namespace GlfwWindow {

static int num_open_windows = 0;

void OnGlfwWindowCreate() {
  if (num_open_windows == 0) {
    glfwInit();
  }

  ++num_open_windows;
}

void OnGlfwWindowDestroy() {
  --num_open_windows;

  if (num_open_windows == 0) {
    glfwTerminate();
  }
}

GLFWwindow* CreateGlfwWindow(const WindowCreateInfo& window_info, const char* default_title) {
  return glfwCreateWindow(window_info.width, window_info.height, window_info.title.empty() ? default_title : window_info.title.c_str(), nullptr, nullptr);
}

}
}
