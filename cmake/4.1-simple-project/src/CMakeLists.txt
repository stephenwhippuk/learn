cmake_minimum_required(VERSION 3.5)

set(sources 
    main.cpp
)

add_executable(SimpleProject ${sources})
add_subdirectory(lib)
target_link_libraries(SimpleProject PRIVATE mylib)
