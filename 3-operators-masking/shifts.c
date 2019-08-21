/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// found in binary_convert.c
#include "binary_convert.h"

int main() {
	
	unsigned char x = 0xC3;
	signed char y = x;
	unsigned char uresult;  // for result of logical operation
	char sresult;           // for result of arithmetic operation
	
	char * result_str;   //for binary strings
	char * bin_str_x;
	
	printf("x\t\t\tx<<3\t\t\tx>>2\t\t\ty>>2\n");
	printf("Hex\tBinary\t\tHex\tBinary\t\tHex\tBinary\t\tHex\tBinary\n\n");
	
	////////////////////////   First Example
	// x
	bin_str_x = uchar_to_bin_str(x);
	printf("%hhX\t%s\t", x, bin_str_x);  //print without a newline
	// x << 3
	uresult = x << 3;
	result_str = uchar_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str);  //print without a newline 
	// x >> 2
	uresult = x >> 2;
	free(result_str);
	result_str = uchar_to_bin_str(uresult);
	printf("%hhX\t%s\t", uresult, result_str);  //print without a newline 
	// y >> 2
	sresult = y >> 2;
	free(result_str);
	result_str = uchar_to_bin_str(sresult);
	printf("%hhX\t%s\n", sresult, result_str);  //print with a newline
	
	free(result_str);
	free(bin_str_x);
	//////////////////////// end first example
	
	// continue with more examples here of your choosing
	
	return 0;
}