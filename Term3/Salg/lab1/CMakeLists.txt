cmake_minimum_required(VERSION 3.14)
project(exe)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
   ftxui
   GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
   GIT_TAG main
)

FetchContent_MakeAvailable(ftxui)

add_executable(
    exe
    main.cpp
    csv/csv.cpp
    tui/menu.cpp
    sort/basesorts.cpp
    sort/mergesort.cpp
)

target_link_libraries(exe PRIVATE ftxui::screen ftxui::dom ftxui::component)
