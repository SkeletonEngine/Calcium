#pragma once

/* Compile time endianness checks using multicharacter constants */
#define CALCIUM_PLATFORM_LITTLE_ENDIAN_ABCD 0x41424344UL
#define CALCIUM_PLATFORM_BIG_ENDIAN_ABCD    0x44434241UL
#define CALCIUM_PLATFORM_PDP_ENDIAN_ABCD    0x42414443UL
#define CALCIUM_PLATFORM_ENDIAN_ORDER  ('ABCD')

#if CALCIUM_PLATFORM_ENDIAN_ORDER == CALCIUM_PLATFORM_LITTLE_ENDIAN_ABCD
  #define CALCIUM_PLATFORM_BYTE_ORDER_LITTLE_ENDIAN
#elif CALCIUM_PLATFORM_ENDIAN_ORDER == CALCIUM_PLATFORM_BIG_ENDIAN_ABCD
  #define CALCIUM_PLATFORM_BYTE_ORDER_BIG_ENDIAN
#elif CALCIUM_PLATFORM_ENDIAN_ORDER == CALCIUM_PLATFORM_PDP_ENDIAN_ABCD
  #define CALCIUM_PLATFORM_BYTE_ORDER_PDP_ENDIAN
#else
  #error "Unable to determine platform endianness"
#endif

/* Platform detection using predefined macros */
#if defined(__EMSCRIPTEN__)
  /* Compiling for the web */
    #define CALCIUM_PLATFORM_EMSCRIPTEN
    #error "Emscripten not yet supported"
#elif defined(_WIN32)
  /* Windows x64/x86 */
  #if defined(_WIN64)
    /* Windows x64  */
    #define CALCIUM_PLATFORM_WINDOWS
  #else
    /* Windows x86 */
    #error "x86 Builds are not supported!"
  #endif
#elif defined(__APPLE__) || defined(__MACH__)
  #include <TargetConditionals.h>
  /* TARGET_OS_MAC exists on all the platforms
     so we must check all of them (in this order)
     to ensure that we're running on mac
     and not some other Apple platform */
  #if TARGET_IPHONE_SIMULATOR == 1
    #error "IOS simulator not supported"
  #elif TARGET_OS_IPHONE == 1
    #define CALCIUM_PLATFORM_IOS
    #error "iOS not yet supported"
  #elif TARGET_OS_MAC == 1
    #define CALCIUM_PLATFORM_MACOS
  #else
    #error "Unknown Apple platform"
  #endif
/* We also have to check __ANDROID__ before __linux__
   since android is based on the linux kernel
   it has __linux__ defined */
#elif defined(__ANDROID__)
  #define CALCIUM_PLATFORM_ANDROID
  #error "Android not yet supported"
#elif defined(__linux__)
  #define CALCIUM_PLATFORM_LINUX
#else
  #error "Unknown platform"
#endif
