#pragma once

namespace Calcium {

class DirectX11Window {
public:
  DirectX11Window();
  ~DirectX11Window();

public:
  bool IsOpen() const;
  void PollEvents() const;
};

}
