cmake_minimum_required(VERSION 3.22)
project(C17Test C)

set(CMAKE_C_STANDARD 17)

add_executable(C17Test main.c u_stack/u_stack.c u_stack/u_stack.h u_stdint.h ChiChi/220805.c ChiChi/220805.h u_linkedList/u_linkedList.c u_linkedList/u_linkedList.h main.h ChiChi/m_main.c file/m_file.c file/m_file.h)
include_directories(${MY_CURRENT_DIR}/)
include_directories(ChiChi)