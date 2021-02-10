cmake_minimum_required(VERSION 3.17)
project(Week3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Week3
        2darray.c
        pointer.c
        pointerArray.c
        stringExamples.c
        stringFunct2_long.c
        stringPointers.c "Question2 .c" countWords.c)
