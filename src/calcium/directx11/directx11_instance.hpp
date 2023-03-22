#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class DirectX11Window;

class DirectX11Instance {
public:
  inline DirectX11Window* CreateWindow(const WindowCreateInfo& window_info) { return windows.Create(window_info); }
  inline void DestroyWindow(DirectX11Window* window)                        { windows.Remove(window);             };

private:
  ResourceContainer<DirectX11Window, WindowCreateInfo> windows;
};

}
