#include "calcium/calcium/window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

Window::Window() {
  glfwInit();
  glfw_window = glfwCreateWindow(1280, 720, "Hello", nullptr, nullptr);
}

Window::~Window() {
  glfwDestroyWindow(glfw_window);
}

bool Window::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void Window::PollEvents() {
  glfwPollEvents();
}

}
