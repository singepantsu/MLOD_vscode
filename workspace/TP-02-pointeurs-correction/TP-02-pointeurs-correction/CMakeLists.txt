
# 1. Create build directory
# mkdir build && cd build

# 2. generate Makefile or ninja or XXX
# cmake ..
# OR
# cmake -DCMAKE_BUILD_TYPE=Debug ..

# 3. run compilation
# cmake --build .
# OR
# make
# OR
# make -j VERBOSE=1

# CTest -T

cmake_minimum_required(VERSION 3.10)
# set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS "-Wall -W -std=c99")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")

project(TP2)

add_executable(01-echangeContenu 01-echangeContenu.c)

add_executable(02-convexe-main 02-convexe-main.c 02-convexe.c)

add_executable(03-matrices-main 03-matrices.c 03-matrices-main.c)

add_executable(04-dates-main 04-dates-main.c 04-dates.c)

include (CTest)

# find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no" )

# add_test(04-dates-test 04-dates-main)
add_test(NAME 04-dates-test COMMAND sh -c "$<TARGET_FILE:04-dates-main> < ../04-dates.txt")

# valgrind commandline tool required
# ctest -T memcheck

# find_program(VALGRIND "valgrind")
# if(VALGRIND)
#        add_custom_target(04-dates-memorytest
#            COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no --num-callers=20 $<TARGET_FILE:04-dates-main> < ../04-dates.txt)
# endif()