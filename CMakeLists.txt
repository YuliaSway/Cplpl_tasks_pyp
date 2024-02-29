cmake_minimum_required(VERSION 3.5)

project(03_homework)

add_executable(03_homework 
    game.cpp
    set_value.h
    set_value.cpp
    input_user_value.h
    input_user_value.cpp
    records_file.h
    records_file.cpp
)

set_target_properties(03_homework PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)