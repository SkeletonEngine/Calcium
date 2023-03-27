#include "calcium/opengl/opengl_window.hpp"

namespace Calcium {

OpenGlWindow::OpenGlWindow(const WindowCreateInfo& window_info) {
  glfw_window = GlfwWindow::CreateGlfwWindow(window_info, "Calcium [OpenGl]");
}

}
