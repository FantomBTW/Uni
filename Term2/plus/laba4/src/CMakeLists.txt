cmake_minimum_required(VERSION 3.11)

project(dnd-simulation-test)

add_executable(../bin/exe 
        main.cpp
        classes.cpp
        funcs.cpp
)

target_link_libraries(dnd-simulation-test PRIVATE raylib)
target_include_directories(dnd-simulation-test PRIVATE ${PROJECT_SOURCE_DIR}/incls)

