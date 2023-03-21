#pragma once

#include "calcium/common/resource_container.hpp"

namespace Calcium {

class VulkanWindow;

class VulkanInstance {
public:
  VulkanWindow* CreateWindow();

private:
  ResourceContainer<VulkanWindow> windows;
};

}
