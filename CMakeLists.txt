cmake_minimum_required(VERSION 3.19)
project(FDM)

set(CMAKE_CXX_STANDARD 20)

add_executable(FDM main.cpp mesh.cpp mesh.h helper.h Fields.cpp Fields.h)