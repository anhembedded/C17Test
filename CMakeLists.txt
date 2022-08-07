cmake_minimum_required(VERSION 3.22)
project(C17Test C)

set(CMAKE_C_STANDARD 17)

add_executable(C17Test main.c u_stack/u_stack.c u_stack/u_stack.h)
