cmake_minimum_required(VERSION 3.24)
project(sudoku C)

set(CMAKE_C_STANDARD 99)

add_executable(sudoku main.c valid-board.c valid-board.h solver.c solver.h)
