#pragma once

#include "calcium/common/window.hpp"

struct GLFWwindow;

namespace Calcium {
namespace GlfwWindow {

void OnGlfwWindowCreate();
void OnGlfwWindowDestroy();

GLFWwindow* CreateGlfwWindow(const WindowCreateInfo& window_info, const char* default_title);

void PositionGlfwWindow(GLFWwindow* glfw_window, int x, int y, int monitor, bool relative_to_center);

}
}
