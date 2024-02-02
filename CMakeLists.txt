cmake_minimum_required(VERSION 3.28.0)

project(main VERSION 0.1.0 LANGUAGES C CXX)

add_executable(main
    main.cpp
)

set_target_properties(main PROPERTIES
    cxx_standart 17
    cxx_standart_required on
)