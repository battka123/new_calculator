cmake_minimum_required(VERSION 3.23)
project(new_calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(new_calculator main.cpp header.hpp if_cifra.cpp if_operacia.cpp magic.cpp)
