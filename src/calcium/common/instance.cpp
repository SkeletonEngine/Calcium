#include "calcium/common/instance.hpp"

#include "calcium/common/logger.hpp"

namespace Calcium {
namespace Instance {

static int num_instances = 0;

void OnInstanceCreate() {
  ++num_instances;
  if (num_instances == 1) {
    CALCIUM_LOGGER_INIT();
  }
}

void OnInstanceDestroy() {
  if (num_instances == 1) {
    Logger::LoggerTerminate();
  }
  --num_instances;
}

}
}
