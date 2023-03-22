#pragma once

#include "calcium/common/window.hpp"

namespace Calcium {

class DirectX11Window {
public:
  DirectX11Window(const WindowCreateInfo& window_info);
  ~DirectX11Window();

public:
  bool IsOpen() const;
  void PollEvents() const;
};

}
