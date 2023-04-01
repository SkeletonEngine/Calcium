#pragma once

#include "calcium/common/logger.hpp"

#ifdef CALCIUM_BUILD_DEBUG

  #include "calcium/common/platform.hpp"

  /* Debugbreak macro */
  #if defined(CALCIUM_PLATFORM_WINDOWS)
    #define CALCIUM_DEBUGBREAK() __debugbreak()
  #elif defined(CALCIUM_PLATFORM_MACOS) || defined(CALCIUM_PLATFORM_LINUX)
    #include <signal.h>
    #define CALCIUM_DEBUGBREAK() raise(SIGTRAP)
  #else
    #error "CALCIUM_DEBUGBREAK not implemented for this platform"
  #endif

  /* Assert/call macros */
  #include <filesystem>

  #define CALCIUM_CONCAT_INTERNAL(x, y) x##y
  #define CALCIUM_CONCAT(x, y) CALCIUM_CONCAT_INTERNAL(x, y)

  #define CALCIUM_EXPAND_MACRO(x) x
  #define CALCIUM_STRINGIFY_MACRO(x) #x

  #define CALCIUM_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { CALCIUM_LOG_ERROR(msg, __VA_ARGS__); CALCIUM_DEBUGBREAK(); } }
  #define CALCIUM_INTERNAL_ASSERT_WITH_MSG(type, check, ...) CALCIUM_INTERNAL_ASSERT_IMPL(type, check, "Assert failed: {0}", __VA_ARGS__)
  #define CALCIUM_INTERNAL_ASSERT_NO_MSG(type, check) CALCIUM_INTERNAL_ASSERT_IMPL(type, check, "Assert '{0}' failed at {1}:{2}", CALCIUM_STRINGIFY_MACRO(check), ::std::filesystem::path(__FILE__).filename().string(), __LINE__)

  #define CALCIUM_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
  #define CALCIUM_INTERNAL_ASSERT_GET_MACRO(...) CALCIUM_EXPAND_MACRO( CALCIUM_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, CALCIUM_INTERNAL_ASSERT_WITH_MSG, CALCIUM_INTERNAL_ASSERT_NO_MSG) )

  #define CALCIUM_ASSERT(...) CALCIUM_EXPAND_MACRO( CALCIUM_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
  #define CALCIUM_CALL(x) { auto CALCIUM_CONCAT(result, __LINE__) = (x); if (!(CALCIUM_CONCAT(result, __LINE__))) { CALCIUM_ASSERT(0); } }

#else

  #define CALCIUM_DEBUGBREAK()
  #define CALCIUM_ASSERT(...)
  #define CALCIUM_CALL(x) x

#endif
