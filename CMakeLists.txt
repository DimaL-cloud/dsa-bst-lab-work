cmake_minimum_required(VERSION 3.23)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task1BST
        sources/Task1BST.cpp
        sources/entities/Student.cpp
        sources/data_structures/BinarySearchTree.cpp
        sources/data_structures/ArrayTrie.cpp
        sources/data_structures/MapTrie.cpp)

add_executable(Task2Trie
        sources/Task2Trie.cpp
        sources/entities/Student.cpp
        sources/data_structures/BinarySearchTree.cpp
        sources/data_structures/ArrayTrie.cpp
        sources/data_structures/MapTrie.cpp)

add_executable(Task3SameTree sources/Task3SameTree.cpp)