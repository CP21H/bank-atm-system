cmake_minimum_required(VERSION 3.24)
project(bankManagement)

set(CMAKE_CXX_STANDARD 17)

add_executable(bankManagement main.cpp account.cpp account.h)
