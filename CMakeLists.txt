cmake_minimum_required(VERSION 3.24)
project(json)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

file(GLOB SRC src/*)
file(GLOB INCLUDE include/json/*)
include_directories(include)
add_library(json ${SRC} ${INCLUDE})

file(GLOB TESTS tests/*)
add_executable(json_tests ${TESTS})
target_link_libraries(json_tests json)
