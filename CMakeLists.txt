cmake_minimum_required(VERSION 3.0)
project(Calcium)

set(CALCIUM_SOURCE_FILES
  src/calcium/calcium.hpp
)
source_group("src/calcium" FILES ${CALCIUM_SOURCE_FILES})

set(CALCIUM_CALCIUM_SOURCE_FILES
  src/calcium/calcium/window.hpp
)
source_group("src/calcium/calcium" FILES ${CALCIUM_CALCIUM_SOURCE_FILES})

set(CALCIUM_OPENGL_SOURCE_FILES
  src/calcium/opengl/opengl_window.cpp
)
source_group("src/calcium/opengl" FILES ${CALCIUM_OPENGL_SOURCE_FILES})

add_library(${PROJECT_NAME}
  ${CALCIUM_SOURCE_FILES}
  ${CALCIUM_CALCIUM_SOURCE_FILES}
  ${CALCIUM_OPENGL_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(src/depend/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(src/test)
