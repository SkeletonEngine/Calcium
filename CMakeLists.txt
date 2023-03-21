cmake_minimum_required(VERSION 3.0)
project(Calcium)

set(CALCIUM_SOURCE_FILES
  src/calcium/calcium.hpp
)
source_group("src/calcium" FILES ${CALCIUM_SOURCE_FILES})

set(CALCIUM_COMMON_SOURCE_FILES
  src/calcium/common/resource_container.hpp
)
source_group("src/calcium/common" FILES ${CALCIUM_COMMON_SOURCE_FILES})

set(CALCIUM_OPENGL_SOURCE_FILES
  src/calcium/opengl/opengl_instance.hpp src/calcium/opengl/opengl_instance.cpp
  src/calcium/opengl/opengl_window.hpp src/calcium/opengl/opengl_window.cpp
)
source_group("src/calcium/opengl" FILES ${CALCIUM_OPENGL_SOURCE_FILES})

set(CALCIUM_VULKAN_SOURCE_FILES
  src/calcium/vulkan/vulkan_instance.hpp src/calcium/vulkan/vulkan_instance.cpp
  src/calcium/vulkan/vulkan_window.hpp src/calcium/vulkan/vulkan_window.cpp
)
source_group("src/calcium/vulkan" FILES ${CALCIUM_VULKAN_SOURCE_FILES})

add_library(${PROJECT_NAME}
  ${CALCIUM_SOURCE_FILES}
  ${CALCIUM_COMMON_SOURCE_FILES}
  ${CALCIUM_OPENGL_SOURCE_FILES}
  ${CALCIUM_VULKAN_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(src/depend/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(src/test)
