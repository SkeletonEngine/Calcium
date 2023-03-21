#pragma once

#include "calcium/common/resource_container.hpp"

namespace Calcium {

class OpenGlWindow;

class OpenGlInstance {
public:
  OpenGlWindow* CreateWindow();

private:
  ResourceContainer<OpenGlWindow> windows;
};

}
