#include "calcium/directx11/directx11_instance.hpp"

#include "calcium/common/logger.hpp"
#include "calcium/directx11/directx11_window.hpp"

namespace Calcium {

DirectX11Instance::DirectX11Instance() {
  CALCIUM_LOGGER_INIT();
}

DirectX11Window* DirectX11Instance::CreateWindow(const WindowCreateInfo& window_info) {
  return windows.Create(window_info);
}

void DirectX11Instance::DestroyWindow(DirectX11Window* window) {
  windows.Remove(window);
};

void DirectX11Instance::BeginFrame() {

}

void DirectX11Instance::EndFrame() {

}

}
