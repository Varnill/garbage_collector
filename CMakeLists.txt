cmake_minimum_required(VERSION 3.27)
project(garbage_collector C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(garbage_collector
        garbage_collector.c
        garbage_collector.h
        gc_collect.c
        gc_collect.h
        main.c
        sweep.c
        sweep.h
        gc_init.c
        gc_malloc.c)
