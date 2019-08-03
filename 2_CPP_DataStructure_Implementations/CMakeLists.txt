cmake_minimum_required(VERSION 3.14)
project(2_CPP_DataStructure_Implementations)

set(CMAKE_CXX_STANDARD 17)

add_executable(2_CPP_DataStructure_Implementations
        1_Unsorted-List_Linked_CPP/UnsortedList.cpp
        1_Unsorted-List_Linked_CPP/UnsortedList.h
        0_Auxiliary/ItemType.cpp
        0_Auxiliary/ItemType.h
        main.cpp 3_Stack_cpp/ArrayStack.cpp 3_Stack_cpp/ArrayStack.h)