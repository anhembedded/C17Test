cmake_minimum_required(VERSION 3.22)
project(C17Test C)

set(CMAKE_C_STANDARD 17)

add_executable(C17Test main.c u_stack/u_stack.c u_stack/u_stack.h u_stdint.h ChiChi/220805.c ChiChi/220805.h)
include_directories(E:/Project/ArduinoForTrademask/src/C17Test)
include_directories(E:/Project/ArduinoForTrademask/src/C17Test/ChiChi)