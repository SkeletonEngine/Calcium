#include <calcium/calcium.hpp>

int main() {
  Calcium::OpenGlInstance instance;

  auto window = instance.CreateWindow({ 600, 400 });
  window->Center();

  while (window->IsOpen()) {
    window->PollEvents();

    instance.BeginFrame();
    instance.EndFrame();
  }
}
