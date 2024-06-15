cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 17)

include_directories(./easyx/include)
link_directories(./easyx/lib64)
link_libraries(libeasyx.a)

add_executable(project main.cpp
        Block.h
        Move.h)
