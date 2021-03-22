# cmake_minimum_required(VERSION <specify CMake version here>)
project(Darren01 C)

set(CMAKE_C_STANDARD 99)
# FileHandling.c FileHandling.h Reports.c Reports.h header.h LinkedList.c  LinkedList.h
add_executable(Darren02 main.c FileHandling.c FileHandling.h Reports.c Reports.h header.h LinkedList.c  LinkedList.h)