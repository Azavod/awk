cmake_minimum_required(VERSION 3.12)

project(awk)

set(CMAKE_C_STANDARD 99)

add_executable(
        awk_by_zavodov
        main.c
        interpreter.c interpreter.h
        utils.c utils.h
        parser.c parser.h functions.c functions.h)
