cmake_minimum_required(VERSION 3.30)
project(Lunar_Tech C)

set(CMAKE_C_STANDARD 17)

add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors -Wconversion)

add_executable(Lunar_Tech main.c)
