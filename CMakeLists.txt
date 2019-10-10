cmake_minimum_required(VERSION 3.6)
message (STATUS "CMake version: ${CMAKE_VERSION}")
message (STATUS "CMAKE_CXX_COMPILER '${CMAKE_CXX_COMPILER}' ")

project(cpp_base64)

add_library(cpp_base64 base64.h base64.cpp)

option(BUILD_TEST ON)
if (BUILD_TEST)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()
add_executable(UnitTest_LibBase64 test.cpp)
target_link_libraries(UnitTest_LibBase64 cpp_base64 GTest::Main GTest::GTest)
add_test(base64_test UnitTest_LibBase64)
endif (BUILD_TEST)