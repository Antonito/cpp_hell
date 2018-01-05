##
## Configuration
##
cmake_minimum_required(VERSION 3.1)
project(test_function)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

# We're compiling in C++11 in order to test std::bind assignation
if(UNIX)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++11")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
endif()

# Get log library files
file(GLOB SOURCES main.cpp)
set(TEST_FUNCTION test_function)
add_executable(${TEST_FUNCTION} ${SOURCES})
