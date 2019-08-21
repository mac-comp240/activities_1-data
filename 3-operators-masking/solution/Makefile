#You will fill this in yourself for practice
#Ultimately it should build and clean three executable programs
CC=gcc -std=c11

all: bit_logical shifts mask             #other program executables will go here
	

bit_logical: bit_logical.c binary_convert.c binary_convert.h
	${CC} -o bit_logical bit_logical.c binary_convert.c
	
shifts: shifts.c binary_convert.c binary_convert.h
	${CC} -o shifts shifts.c binary_convert.c
	
mask: mask.c
	${CC} -o mask mask.c
	
clean:
	 rm -f bit_logical shifts mask