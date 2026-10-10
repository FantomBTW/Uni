cmake_minimum_required(VERSION 3.14)
project(exe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(
    exe
    main.cpp
)

#target_link_libraries(exe PRIVATE ftxui::screen ftxui::dom ftxui::component)
