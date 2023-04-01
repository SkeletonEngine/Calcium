#include "calcium/opengl/opengl_instance.hpp"

#include "calcium/common/instance.hpp"
#include "calcium/common/logger.hpp"
#include "calcium/opengl/opengl_window.hpp"

namespace Calcium {

OpenGlInstance::OpenGlInstance() {
  Instance::OnInstanceCreate();
  CALCIUM_LOG_INFO("Creating OpenGlInstance");
}

OpenGlInstance::~OpenGlInstance() {
  Instance::OnInstanceDestroy();
}

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
