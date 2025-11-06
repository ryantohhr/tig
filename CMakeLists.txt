cmake_minimum_required(VERSION 4.1)
project(tig)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources "src/*.c")

add_executable(tig ${sources})

target_include_directories(tig PUBLIC src)

