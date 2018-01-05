##
## Configuration
##
cmake_minimum_required(VERSION 3.1)
project(test_dynamic_fsa)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

if(UNIX)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++98")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
endif()

# Get log library files
file(GLOB SOURCES main.cpp Machine.cpp)
set(TEST_FSA test_dynamic_fsa)
add_executable(${TEST_FSA} ${SOURCES})
