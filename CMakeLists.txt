cmake_minimum_required(VERSION 3.0)
project(Calcium)

set(CALCIUM_SOURCE_FILES
  src/calcium/calcium.hpp src/calcium/calcium.cpp
)
source_group("src/calcium" FILES ${CALCIUM_SOURCE_FILES})

add_library(${PROJECT_NAME}
  ${CALCIUM_SOURCE_FILES}
)
target_include_directories(${PROJECT_NAME} PUBLIC src)

add_subdirectory(src/test)
