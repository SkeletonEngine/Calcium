#include "calcium/opengl/opengl_window.hpp"

#include <GLFW/glfw3.h>

#include "calcium/glfw/glfw_window.hpp"

namespace Calcium {

OpenGlWindow::OpenGlWindow(const WindowCreateInfo& window_info) {
  GlfwWindow::OnGlfwWindowCreate();
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [OpenGl]");
}

OpenGlWindow::~OpenGlWindow() {
  glfwDestroyWindow(glfw_window);

  GlfwWindow::OnGlfwWindowDestroy();
}

bool OpenGlWindow::IsOpen() const {
  return !glfwWindowShouldClose(glfw_window);
}

void OpenGlWindow::PollEvents() const {
  glfwPollEvents();
}

}
