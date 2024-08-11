cmake_minimum_required(VERSION 3.22)
project(Interview_assessment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the URL and destination for the json.hpp file
set(JSON_URL "https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp")
set(JSON_HPP "${CMAKE_SOURCE_DIR}/include/json.hpp")

# Download json.hpp if it doesn't exist
if(NOT EXISTS ${JSON_HPP})
    file(DOWNLOAD ${JSON_URL} ${JSON_HPP} SHOW_PROGRESS)
endif()


# Add include directory
include_directories(include)

#specify the output executable path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

