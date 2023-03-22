#pragma once

#include "calcium/common/resource_container.hpp"

namespace Calcium {

class DirectX11Window;

class DirectX11Instance {
public:
  DirectX11Window* CreateWindow();

private:
  ResourceContainer<DirectX11Window> windows;
};

}
