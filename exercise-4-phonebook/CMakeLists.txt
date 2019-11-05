cmake_minimum_required(VERSION 3.12)
project(exercise_4_phonebook)

set(CMAKE_CXX_STANDARD 14)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
set(CMAKE_CXX_FLAGS_DEBUG "-d=NDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(exercise_4_phonebook ${SOURCES})