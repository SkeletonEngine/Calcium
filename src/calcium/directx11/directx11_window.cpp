#include "calcium/directx11/directx11_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

DirectX11Window::DirectX11Window(const WindowCreateInfo& window_info) {
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [DirectX11]");
}

}
