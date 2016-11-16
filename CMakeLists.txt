cmake_minimum_required(VERSION 2.8.9)

project (real_program)

# Enable all warnings
add_compile_options(-Wall -Wextra -Werror -Wpedantic)
# Use C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
# set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/inc)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
# NOTE:
#       PROJECT_SOURCE_DIR refers to the most recent project() calls directory
#       CMAKE_SOURCE_DIR   refers to the CMakeLists.txt files directory.

# set(CMAKE_VERBOSE_MAKEFILE ON)
add_executable(real_program ${SOURCES})
