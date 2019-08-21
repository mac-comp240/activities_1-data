#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// found in binary_convert.c
#include "binary_convert.h"

int main() {
	
	unsigned char x = 0x66;
	unsigned char y = 0x39;
	unsigned char result;    // to hold result of each operation
	
	char * bin_str_x = uchar_to_bin_str(x);
	char * bin_str_y = uchar_to_bin_str(y);
	
	// to hold binary representation of each result;
	char * bin_str_result;
	
	// do 5 steps for each bitwise operation
	// 1. get a result
	result = x & y;
	// 2. convert to a string
	bin_str_result = uchar_to_bin_str(result);
	// 3. print x, y, and result
	printf("  %s\n", bin_str_x);          
	printf("& %s\n", bin_str_y);
	printf("  ---------\n");
	printf("  %s\t%x\n\n", bin_str_result, result);
	// 4. free up memory for the result string, because we will create more
	free(bin_str_result);
	// 5. assert to test the result
	assert(result == 0x20);
	
	// do 5 steps for each bitwise operation
	// 1. get a result
	result = x | y;
	// 2. convert to a string
	bin_str_result = uchar_to_bin_str(result);
	// 3. print x, y, and result
	printf("  %s\n", bin_str_x);          
	printf("| %s\n", bin_str_y);
	printf("  ---------\n");
	printf("  %s\t%x\n\n", bin_str_result, result);
	// 4. free up memory for the result string, because we will create more
	free(bin_str_result);
	// 5. assert to test the result
	assert(result == 0x7f);
	
	// do 5 steps for each bitwise operation
	// 1. get a result
	char * bin_str_x_complement = uchar_to_bin_str(~x);
	char * bin_str_y_complement = uchar_to_bin_str(~y);
	result = ~x | ~y;
	// 2. convert to a string
	bin_str_result = uchar_to_bin_str(result);
	// 3. print x, y, and result
	printf("  %s\n", bin_str_x_complement);         
	printf("| %s\n", bin_str_y_complement);
	printf("  ---------\n");
	printf("  %s\t%x\n\n", bin_str_result, result);
	// 4. free up memory for the result string, because we will create more
	free(bin_str_result);
	free(bin_str_x_complement);
	free(bin_str_y_complement);
	// 5. assert to test the result
	assert(result == 0xdf);
	
	// The rest of the examples can be tested with asserts easily.
	
	result = x & !y;
	assert(result == 0);
	
	result = x && y;
	assert(result == 1);
	
	result = x || y;
	assert(result == 1);
	
	result = !x || !y;
	assert(result == 0);
	
	result = x && ~y;
	assert(result == 1);
	
	
	///////////////////////  clean up (leave this code here)
	free(bin_str_x);
	free(bin_str_y);
	return 0;
}