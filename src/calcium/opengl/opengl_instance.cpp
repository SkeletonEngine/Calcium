#include "calcium/opengl/opengl_instance.hpp"

#include "calcium/opengl/opengl_window.hpp"

namespace Calcium {

OpenGlWindow* OpenGlInstance::CreateWindow(const WindowCreateInfo& window_info) { 
  return windows.Create(window_info);
}

void OpenGlInstance::DestroyWindow(OpenGlWindow* window) {
  windows.Remove(window);
};

void OpenGlInstance::BeginFrame() {

}

void OpenGlInstance::EndFrame() {

}

}
