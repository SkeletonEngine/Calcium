#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class VulkanWindow;

class VulkanInstance {
public:
  inline VulkanWindow* CreateWindow(const WindowCreateInfo& window_info) { return windows.Create(window_info); }
  inline void DestroyWindow(VulkanWindow* window)                        { windows.Remove(window);             };

private:
  ResourceContainer<VulkanWindow, WindowCreateInfo> windows;
};

}
