#include "calcium/opengl/opengl_window.hpp"

#include <GLFW/glfw3.h>

namespace Calcium {

OpenGlWindow::OpenGlWindow() {
  glfwInit();
  glfw_window = glfwCreateWindow(1280, 720, "Hello", nullptr, nullptr);
}

OpenGlWindow::~OpenGlWindow() {
  glfwDestroyWindow(glfw_window);
}

bool OpenGlWindow::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void OpenGlWindow::PollEvents() const {
  glfwPollEvents();
}

}
