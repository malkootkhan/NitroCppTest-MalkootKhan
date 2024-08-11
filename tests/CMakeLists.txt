cmake_minimum_required(VERSION 3.22)
project(RecIntersection)

# Download and build GoogleTest only if necessary
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(test_rectangle test_rectangle.cpp)

# Link GoogleTest and the main project library
target_link_libraries(test_rectangle gtest gtest_main rectangle)

# Add the test to CTest
enable_testing()
add_test(NAME test_rectangle COMMAND test_rectangle)

