cmake_minimum_required(VERSION 3.0)
project(Calcium)

# Figure out what platform we are building for
if (LINUX)
  set(CALCIUM_PLATFORM_LINUX TRUE)
elseif (APPLE)
  set(CALCIUM_PLATFORM_MACOS TRUE)
elseif (WIN32)
  set(CALCIUM_PLATFORM_WINDOWS TRUE)
endif()

# Figure out what backends are available based on the platform and other stuff
if (CALCIUM_PLATFORM_LINUX OR CALCIUM_PLATFORM_MACOS OR CALCIUM_PLATFORM_WINDOWS)
  set(CALCIUM_BACKEND_OPENGL TRUE)
  find_package(Vulkan)
  if (Vulkan_FOUND)
    set(CALCIUM_BACKEND_VULKAN TRUE)
  endif()
endif()
if (CALCIUM_PLATFORM_WINDOWS)
  set(CALCIUM_BACKEND_DIRECTX11 TRUE)
endif()

# Source files
set(CALCIUM_SOURCE_FILES
  src/calcium/calcium.hpp
)
source_group("src/calcium" FILES ${CALCIUM_SOURCE_FILES})

set(CALCIUM_COMMON_SOURCE_FILES
  src/calcium/common/resource_container.hpp
  src/calcium/common/window.hpp
)
source_group("src/calcium/common" FILES ${CALCIUM_COMMON_SOURCE_FILES})

if (CALCIUM_BACKEND_OPENGL OR CALCIUM_BACKEND_VULKAN)
  set(CALCIUM_GLFW_SOURCE_FILES
    src/calcium/glfw/glfw_window.hpp src/calcium/glfw/glfw_window.cpp
  )
  source_group("src/calcium/glfw" FILES ${CALCIUM_GLFW_SOURCE_FILES})
endif()

if (CALCIUM_BACKEND_OPENGL)
  set(CALCIUM_OPENGL_SOURCE_FILES
    src/calcium/opengl/opengl_instance.hpp src/calcium/opengl/opengl_instance.cpp
    src/calcium/opengl/opengl_window.hpp src/calcium/opengl/opengl_window.cpp
  )
  source_group("src/calcium/opengl" FILES ${CALCIUM_OPENGL_SOURCE_FILES})
endif()

if (CALCIUM_BACKEND_VULKAN)
  set(CALCIUM_VULKAN_SOURCE_FILES
    src/calcium/vulkan/vulkan_instance.hpp src/calcium/vulkan/vulkan_instance.cpp
    src/calcium/vulkan/vulkan_window.hpp src/calcium/vulkan/vulkan_window.cpp
  )
  source_group("src/calcium/vulkan" FILES ${CALCIUM_VULKAN_SOURCE_FILES})
endif()

if (CALCIUM_BACKEND_DIRECTX11)
  set(CALCIUM_DIRECTX11_SOURCE_FILES
    src/calcium/directx11/directx11_instance.hpp src/calcium/directx11/directx11_instance.cpp
    src/calcium/directx11/directx11_window.hpp src/calcium/directx11/directx11_window.cpp
  )
  source_group("src/calcium/directx11" FILES ${CALCIUM_DIRECTX11_SOURCE_FILES})
endif()

# Target
add_library(${PROJECT_NAME}
  ${CALCIUM_SOURCE_FILES}
  ${CALCIUM_GLFW_SOURCE_FILES}
  ${CALCIUM_COMMON_SOURCE_FILES}
  ${CALCIUM_OPENGL_SOURCE_FILES}
  ${CALCIUM_VULKAN_SOURCE_FILES}
  ${CALCIUM_DIRECTX11_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Platform and backend defines
if (CALCIUM_PLATFORM_LINUX)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_PLATFORM_LINUX")
elseif (CALCIUM_PLATFORM_MACOS)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_PLATFORM_MACOS")
elseif (CALCIUM_PLATFORM_WINDOWS)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_PLATFORM_WINDOWS")
endif()
if (CALCIUM_BACKEND_OPENGL)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_BACKEND_OPENGL")
endif()
if (CALCIUM_BACKEND_VULKAN)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_BACKEND_VULKAN")
endif()
if (CALCIUM_BACKEND_DIRECTX11)
  target_compile_definitions(${PROJECT_NAME} PUBLIC "CALCIUM_BACKEND_DIRECTX11")
endif()

# Submodules
add_subdirectory(src/depend/glfw)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)

add_subdirectory(src/test)
