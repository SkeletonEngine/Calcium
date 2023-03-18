cmake_minimum_required(VERSION 3.0)
project(CalciumTests)

set(CALCIUM_TESTS_SOURCE_FILES
  main.cpp
)
source_group("src" FILES ${CALCIUM_TESTS_SOURCE_FILES})

add_executable(${PROJECT_NAME}
  ${CALCIUM_TESTS_SOURCE_FILES}
)
target_link_libraries(${PROJECT_NAME} PRIVATE Calcium)
