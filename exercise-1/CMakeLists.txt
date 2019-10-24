cmake_minimum_required(VERSION 3.5)
project(es1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(es1 ${SOURCES})