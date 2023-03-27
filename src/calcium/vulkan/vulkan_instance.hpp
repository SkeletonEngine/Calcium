#pragma once

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class VulkanWindow;

class VulkanInstance {
public:
  VulkanWindow* CreateWindow(const WindowCreateInfo& window_info);
  void DestroyWindow(VulkanWindow* window);

public:
  void BeginFrame();
  void EndFrame();

private:
  ResourceContainer<VulkanWindow, WindowCreateInfo> windows;
};

}
