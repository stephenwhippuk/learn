cmake_minimum_required(VERSION 3.5)

set(sources 
    print.cpp
    read.cpp
)
add_library(mylib ${sources})
target_include_directories(mylib PUBLIC include)
