cmake_minimum_required(VERSION 3.23)
project(sort_algs_c C)

include(CTest)

set(CMAKE_C_STANDARD 99)

add_executable(sort_algs
        main.c
        indx_list.h)

add_executable(sort_algs_test
        sort_algs_tests.c
        third_party/cutest-1.5/CuTest.c
        third_party/cutest-1.5/CuTest.h)

add_test(NAME sort_algs_test COMMAND sort_algs_test)