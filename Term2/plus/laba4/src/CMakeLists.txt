cmake_minimum_required(VERSION 3.11)
include(FetchContent)

project(dnd)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

FetchContent_Declare(
   raylib
   GIT_REPOSITORY https://github.com/raysan5/raylib.git
   GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(dnd 
   main.cpp
   incls/classes.cpp
   incls/funcs.cpp
)

target_link_libraries(dnd PRIVATE raylib)
target_include_directories(dnd PRIVATE ${PROJECT_SOURCE_DIR}/incls)
