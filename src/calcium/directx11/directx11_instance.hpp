#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class DirectX11Window;

class DirectX11Instance {
public:
  DirectX11Window* CreateWindow(const WindowCreateInfo& window_info);
  void DestroyWindow(DirectX11Window* window);

public:
  void BeginFrame();
  void EndFrame();

private:
  ResourceContainer<DirectX11Window, WindowCreateInfo> windows;
};

}
