cmake_minimum_required(VERSION 3.5)
project(simple-project LANGUAGES CXX VERSION 0.0.1)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
add_subdirectory(src)
