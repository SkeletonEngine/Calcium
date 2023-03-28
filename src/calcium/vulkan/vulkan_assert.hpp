#pragma once

#include "calcium/common/assert.hpp"

#ifdef CALCIUM_BUILD_DEBUG

  #include <volk.h>

  namespace Calcium {
    const char* VkResultString(VkResult result);
  }

  #define VK_CALL(vkresult) { VkResult CALCIUM_CONCAT(result, __LINE__) = (vkresult); if (CALCIUM_CONCAT(result, __LINE__) != VK_SUCCESS) { CALCIUM_ASSERT(0, ::Calcium::VkResultString( CALCIUM_CONCAT(result, __LINE__) ) ) } }

#else

  #define VK_CALL(vkresult) vkresult

#endif
