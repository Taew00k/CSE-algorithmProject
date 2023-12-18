cmake_minimum_required(VERSION 3.27)
project(CSE_algorithmProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=CP949")

add_executable(CSE_algorithmProject
#        BestRoom/House.h
        BestRoom/main.cpp
        BestRoom/CalculatePoint.cpp
        BestRoom/QuickSort.cpp
        BestRoom/PancakeSort.cpp
        BestRoom/ShellSort.cpp
        BestRoom/InsertionSort.cpp
)
