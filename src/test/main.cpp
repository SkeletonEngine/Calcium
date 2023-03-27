#include <calcium/calcium.hpp>

int main() {
  Calcium::VulkanInstance instance;

  auto window = instance.CreateWindow({ 600, 400 });
  window->Center();

  while (window->IsOpen()) {
    window->PollEvents();

    instance.BeginFrame();
    instance.EndFrame();
  }
}
