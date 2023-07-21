cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Secure_Data_Exchange)

add_executable(Secure_Data_Exchange main.cpp data.cpp swap.cpp)