cmake_minimum_required(VERSION 3.7)
project(ProjectImplementation)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Book.cpp Book.h Set.h Tests.cpp Tests.h UI.cpp UI.h)
add_executable(ProjectImplementation ${SOURCE_FILES})