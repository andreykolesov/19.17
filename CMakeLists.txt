cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled1 main.c
        libs/string/tasks/string_.h
        libs/string/tasks/string_.c
        libs/string/tasks/remove_non_letters.h
        libs/string/tasks/remove_adjacent_equal_letters.h
        libs/string/tasks/reverse_word.h
)
