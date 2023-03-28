#include "calcium/common/logger.hpp"

#include <memory>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Calcium {
namespace Logger {

static std::shared_ptr<spdlog::logger> static_logger;

spdlog::logger* GetLogger() {
  return static_logger.get();
}

void LoggerInit(LoggerLevel logger_level) {
  spdlog::set_pattern("%^[%n][%T] %v%$");
  static_logger = spdlog::stdout_color_mt("Calcium");

  LoggerSetLevel(logger_level);
}

void LoggerTerminate() {
  static_logger.reset();
}

void LoggerSetLevel(LoggerLevel level) {
  switch (level) {
    case LoggerLevel::kTrace: static_logger->set_level(spdlog::level::trace);    return;
    case LoggerLevel::kInfo:  static_logger->set_level(spdlog::level::info);     return;
    case LoggerLevel::kWarn:  static_logger->set_level(spdlog::level::warn);     return;
    case LoggerLevel::kError: static_logger->set_level(spdlog::level::err);      return;
    case LoggerLevel::kFatal: static_logger->set_level(spdlog::level::critical); return;
  }
}

}
}
