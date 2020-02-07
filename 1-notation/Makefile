# Makefile for Activity 1

CC=gcc -std=c99

bin_hex: hex.c test.c binary_convert.c
	${CC} -o bin_hex binary_convert.c hex.c test.c

clean:
	rm -f bin_hex