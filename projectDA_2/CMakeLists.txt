cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Models/stadiums.cpp Models/stadiums.h Models/shipping.cpp Models/shipping.h Models/tourism.cpp Models/tourism.h)
