#include <calcium/calcium.hpp>

int main() {
  Calcium::Window window;

  while (window.IsOpen()) {
    Calcium::Window::PollEvents();
  }
}
