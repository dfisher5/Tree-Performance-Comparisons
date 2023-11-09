cmake_minimum_required(VERSION 3.15)
project(M3AP-ssteve10-dfisher5)

set(CMAKE_CXX_STANDARD 17)

add_executable(main
        "AvlTree.h"
        BinarySearchTree.h
        "SplayTree.h" main.cpp Spotify.cpp)