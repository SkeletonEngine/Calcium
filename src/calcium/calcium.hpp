#pragma once

#ifdef CALCIUM_BACKEND_OPENGL
  #include "calcium/opengl/opengl_instance.hpp"
  #include "calcium/opengl/opengl_window.hpp"
#endif

#ifdef CALCIUM_BACKEND_VULKAN
  #include "calcium/vulkan/vulkan_instance.hpp"
  #include "calcium/vulkan/vulkan_window.hpp"
#endif
