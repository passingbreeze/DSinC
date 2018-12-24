cmake_minimum_required(VERSION 3.11)
project(DSinC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall")

add_executable(DSinC list.c)
