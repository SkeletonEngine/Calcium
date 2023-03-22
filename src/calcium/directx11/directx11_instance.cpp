#include "calcium/directx11/directx11_instance.hpp"

#include "calcium/directx11/directx11_window.hpp"

namespace Calcium {

DirectX11Window* DirectX11Instance::CreateWindow() {
  return windows.Create();
}

}
