#!/bin/bash

make s21_matrix.a
gcc -g ./unit_tests.c s21_matrix.a -o test.out -lcheck -lcheck -lpthread -lm -D_GNU_SOURCE -lrt
CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test.out
