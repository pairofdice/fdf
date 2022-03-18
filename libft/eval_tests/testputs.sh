#!/bin/bash

clang ft_putnbr_test.c ../ft_putchar.c ../ft_putnbr.c
echo "putnbr:" > output
./a.out | cat -e >> output
clang ft_putchar_test.c ../ft_putchar.c
echo "putchar:" >> output
./a.out | cat -e >> output