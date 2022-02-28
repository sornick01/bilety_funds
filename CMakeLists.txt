cmake_minimum_required(VERSION 3.21)
project(bilety_funds)

set(CMAKE_CXX_STANDARD 14)

include_directories(avl_tree)
include_directories(bil7)
include_directories(splay_tree)

add_executable(bilety_funds
        avl_tree/avl_tree.hpp
        avl_tree/avl_tree_.hpp
        avl_tree/main.cpp
        bil1/ex6.cpp
        bil12/ex5.c
        bil13/ex5.c
        bil3/ex5.c
        bil3/ex6.cpp
        bil4/ex6.cpp
        bil7/ex5.cpp
        bil7/ex5.hpp
        bil7/ex6.cpp
        splay_tree/splay_tree.hpp
        border_method.c
        postfix.cpp)
