// includes of standard C libraries
#include <stdio.h>  // printf for printing to terminal

// function declarations
void aFunction(int aNumber);

// main
// This program simply prints a rather meaningless
// message as an example.
// 
int main() {
    printf("hello world\n");
	// 42: the answer to life, the universe, and everything
    aFunction(42);  
}

/* aFunction
 * This function takes an integer and prints it.
 */ 
void aFunction(int aNumber) {
    printf("Your number is: %d\n", aNumber);
}