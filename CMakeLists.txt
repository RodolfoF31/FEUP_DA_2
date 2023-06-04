cmake_minimum_required(VERSION 3.25)
project(projetoDA2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(projetoDA2
        Fileman.cpp
        Fileman.h
        Graph.cpp
        Graph.h
        main.cpp MenuMan.h MenuMan.cpp)
