cmake_minimum_required(VERSION 3.17)
project(Q13 C)

set(CMAKE_C_STANDARD 99)

add_executable(Q13 interp1.c interp1.h plot.c tga.c tga.h)