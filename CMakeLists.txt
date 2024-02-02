cmake_minimum_required(VERSION 3.28.0)

project(hello_world VERSION 0.1.0 LANGUAGES C CXX)

add_executable(hello_world
    hello_world.cpp
    example.h
    example.cpp    
    move_me_out.h
    move_me_out.cpp
)

set_target_properties(hello_world PROPERTIES
    cxx_standart 17
    cxx_standart_required on
)