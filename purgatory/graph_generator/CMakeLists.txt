##
## Configuration
##
cmake_minimum_required(VERSION 3.1)
project(graph_generator)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

if(UNIX)
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++98")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}")
endif()

# Get log library files
file(GLOB SOURCES main.cpp State.cpp FSA.cpp Matcher.cpp ExpressionParser.cpp)
set(GRAPH_GENERATOR graph_generator)
add_executable(${GRAPH_GENERATOR} ${SOURCES})
