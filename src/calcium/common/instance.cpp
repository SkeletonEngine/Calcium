#include "calcium/common/instance.hpp"

#include <GLFW/glfw3.h>

#include "calcium/common/logger.hpp"

namespace Calcium {
namespace Instance {

static int num_instances = 0;

void OnInstanceCreate() {
  ++num_instances;
  if (num_instances == 1) {
    CALCIUM_LOGGER_INIT();
    glfwInit();
  }
}

void OnInstanceDestroy() {
  if (num_instances == 1) {
    glfwTerminate();
    Logger::LoggerTerminate();
  }
  --num_instances;
}

}
}
