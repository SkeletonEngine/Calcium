#include <calcium/calcium.hpp>

int main() {
  Calcium::VulkanInstance instance;

  auto window = instance.CreateWindow({ 600, 400 });

  while (window->IsOpen()) {
    window->PollEvents();
  }
}
