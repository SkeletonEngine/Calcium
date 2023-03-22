#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class OpenGlWindow;

class OpenGlInstance {
public:
  inline OpenGlWindow* CreateWindow(const WindowCreateInfo& window_info) { return windows.Create(window_info); }
  inline void DestroyWindow(OpenGlWindow* window)                        { windows.Remove(window);             };

private:
  ResourceContainer<OpenGlWindow, WindowCreateInfo> windows;
};

}
