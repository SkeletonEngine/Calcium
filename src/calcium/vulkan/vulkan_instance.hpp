#pragma once

#include <volk.h>

#include "calcium/common/resource_container.hpp"
#include "calcium/common/window.hpp"

namespace Calcium {

class VulkanWindow;

class VulkanInstance {
public:
  VulkanInstance();
  ~VulkanInstance();

public:
  VulkanWindow* CreateWindow(const WindowCreateInfo& window_info);
  void DestroyWindow(VulkanWindow* window);

public:
  void BeginFrame();
  void EndFrame();

private:
  VkInstance instance;

private:
  ResourceContainer<VulkanWindow, WindowCreateInfo> windows;
};

}
