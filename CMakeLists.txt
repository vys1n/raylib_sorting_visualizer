cmake_minimum_required(VERSION 3.20)

project(sorting_visualizer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(raylib)

add_executable(sorting_visualizer main.cpp)

target_link_libraries(sorting_visualizer PRIVATE raylib)
