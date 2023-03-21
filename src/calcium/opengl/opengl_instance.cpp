#include "calcium/opengl/opengl_instance.hpp"

#include "calcium/opengl/opengl_window.hpp"

namespace Calcium {

OpenGlWindow* OpenGlInstance::CreateWindow() {
  return windows.Create();
}

}
