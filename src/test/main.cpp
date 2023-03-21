#include <calcium/calcium.hpp>

int main() {
  Calcium::VulkanInstance instance;

  auto window = instance.CreateWindow();

  while (window->IsOpen()) {
    window->PollEvents();
  }
}
