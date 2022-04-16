cmake_minimum_required(VERSION 3.22)
project(OOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(OOP main.cpp DOM/Engine.cpp DOM/Engine.h DOM/DieselEngine.cpp DOM/DieselEngine.h DOM/JetEngine.cpp DOM/JetEngine.h Utilities/RoundedDoublyLinkedList.cpp Utilities/RoundedDoublyLinkedList.h)
