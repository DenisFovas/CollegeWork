cmake_minimum_required(VERSION 3.6)
project(lab3_4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c material.h material.c repostiroy.c repostiroy.h ui.c ui.h controller.c controller.h)
add_executable(lab3_4 ${SOURCE_FILES})