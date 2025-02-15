cmake_minimum_required(VERSION 3.20.0)
project(Environment)
message("Generated with " $ENV{myenv})
add_executable(main main.cpp)
add_custom_target(EchoEnv ALL COMMAND echo "myenv in build 
is" $ENV{myenv})