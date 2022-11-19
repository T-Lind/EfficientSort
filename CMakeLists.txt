cmake_minimum_required(VERSION 3.23)
project(EfficientSort)

set(CMAKE_CXX_STANDARD 14)

add_executable(EfficientSort main.cpp BasicSort.cpp ParallelSort.cpp ParallelSort.h)
