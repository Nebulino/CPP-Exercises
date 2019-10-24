# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.5)

# project(<project name>)

#set(CMAKE_CXX_STANDARD <number of the C++ standard>)
set(CMAKE_CXX_STANDARD 14)

# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE Release)
# endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-d=NDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# include_directories(<dir to use as include "headers">)
include_directories(include)

# file (<scope> <name of the variable> <dir where to find the file(s)>)
file(GLOB SOURCES "src/*.cpp")

# add_executable(<name of the executable>
#                <files/dir/var/... where to find SOURCES>>)
add_executable(run_me ${SOURCES})
