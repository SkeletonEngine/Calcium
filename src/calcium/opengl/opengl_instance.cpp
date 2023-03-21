#include "calcium/opengl/opengl_instance.hpp"

namespace Calcium {

OpenGlWindow* OpenGlInstance::CreateWindow() {
  return new OpenGlWindow();
}

}
