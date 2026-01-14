# packages\cpp\CMakeLists.txt

cmake_minimum_required(VERSION 3.20)
project(dsa_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_executable(cpp_iteration_tests
  src/concepts/iteration/test.cpp
  src/concepts/iteration/solution.cpp
)

target_include_directories(cpp_iteration_tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_test(NAME cpp_iteration_tests COMMAND cpp_iteration_tests)

