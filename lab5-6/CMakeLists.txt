cmake_minimum_required(VERSION 3.7)
project(lab5_6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DynamicArray.h dog.cpp dog.h tests.cpp tests.h Controller.cpp Controller.h UiAdmin.cpp UiAdmin.h UserUi.cpp UserUi.h UserController.cpp UserController.h Repository.h)
add_executable(lab5_6 ${SOURCE_FILES} DynamicArray.h dog.cpp dog.h Repository.h)