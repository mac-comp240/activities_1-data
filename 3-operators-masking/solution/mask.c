/*
 * Complete version of mask.c from Problem 3 of data activity 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// in this file
unsigned int least1x_most3y(unsigned int x, unsigned int y);
void testit(unsigned int x, unsigned int y, unsigned int expected);

int main() {
	unsigned int x;
	unsigned int y;
	
	unsigned int test;
	
	// test x 0, y something else with distinctive bytes
	x = 0x00;
	y = 0xabcdefff;
	test = least1x_most3y(x,y);
	assert(test == 0xabcdef00);
	
	// NOTE: notice how using the additional function provided below
	//       makes each test a 1-liner.
	//       This next one is equivlaent to that above.
	testit(0x0, 0xabcdefff, 0xabcdef00);
	
	testit(0x1, 0xabcdefff, 0xabcdef01);
	// x filled with 1's in least significant byte
	testit(0xFF, 0xabcdef00, 0xabcdefff);   
	testit(0xFFABCDAA, 0x0, 0x000000AA);  // y 0
	testit(0xFFABCDAA, 0x1, 0x000000AA);  // y 1
	// check boundary between 2nd and 3rd byte
	testit(0xFFABCDAA, 0xff00, 0x0000ffAA);
	// check boundary between 2nd and 3rd byte
	// with zeros in 3 most significant bytes of x
	testit(0x000000AA, 0xff00, 0x0000ffAA);
	
	return 0;
}

/**
 * returns an unsigned value that contains the 3 most significant bytes
 * of y followed by the least significant byte of x.
 */
unsigned int least1x_most3y(unsigned int x, unsigned int y) {
	unsigned int mask;
	
	mask = 0xFF;
	
	return (y & ~mask) | (x & mask);
}

/*
 * A way to reuse a common set of code used in tests.
 */
void testit(unsigned int x, unsigned int y, unsigned int expected) {
	unsigned int test = least1x_most3y(x,y);
	assert(test == expected);
}