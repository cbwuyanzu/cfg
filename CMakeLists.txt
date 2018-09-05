cmake_minimum_required(VERSION 3.12)
project(cfg C)

set(CMAKE_C_STANDARD 99)

add_executable(cfg main.c cfg.c cfg.h)