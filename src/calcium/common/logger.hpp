#pragma once

#include <spdlog/spdlog.h>

#include "calcium/common/logger_level.hpp"

namespace Calcium {
namespace Logger {

void LoggerInit(LoggerLevel logger_level);
void LoggerTerminate();
void LoggerSetLevel(LoggerLevel level);

#ifdef CALCIUM_BUILD_DEBUG
  #define CALCIUM_LOGGER_INIT() ::Calcium::Logger::LoggerInit(::Calcium::Logger::LoggerLevel::kInfo)
#else
  #define CALCIUM_LOGGER_INIT() ::Calcium::Logger::LoggerInit(::Calcium::Logger::LoggerLevel::kWarn)
#endif

spdlog::logger* GetLogger();

#define CALCIUM_LOG_TRACE(...) ::Calcium::Logger::GetLogger()->trace(__VA_ARGS__)
#define CALCIUM_LOG_INFO(...)  ::Calcium::Logger::GetLogger()->info(__VA_ARGS__)
#define CALCIUM_LOG_WARN(...)  ::Calcium::Logger::GetLogger()->warn(__VA_ARGS__)
#define CALCIUM_LOG_ERROR(...) ::Calcium::Logger::GetLogger()->error(__VA_ARGS__)
#define CALCIUM_LOG_FATAL(...) ::Calcium::Logger::GetLogger()->critical(__VA_ARGS__)

}
}
