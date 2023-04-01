#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class OpenGlWindow;

class OpenGlInstance {
public:
  OpenGlInstance();
  ~OpenGlInstance();

public:
  OpenGlWindow* CreateWindow(const WindowCreateInfo& window_info);
  void DestroyWindow(OpenGlWindow* window);

public:
  void BeginFrame();
  void EndFrame();

private:
  ResourceContainer<OpenGlWindow, WindowCreateInfo> windows;
};

}
