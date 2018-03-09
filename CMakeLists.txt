cmake_minimum_required(VERSION 3.9)
project(ArbolAVLArchivos)

set(CMAKE_CXX_STANDARD 11)

add_executable(ArbolAVLArchivos
        arbolavl.cpp
        arbolavl.h
        datafile.cpp
        datafile.h
        main.cpp
        nodo.cpp
        nodo.h)
