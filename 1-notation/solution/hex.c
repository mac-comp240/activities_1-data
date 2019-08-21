#include <stdio.h>      // printf
#include <stdlib.h>     // free

// from binary_convert.c
#include "binary_convert.h"

/** 
 * print the hexidecimal table for 0 through F 
 */
void hex_table() {
  	
	unsigned int i;   //loop counter foe value to convert to a binary string
	char * bin_str;   // string that contains the binary value for an int
	
	printf("decimal   hex     binary\n");      // a header line
	for (i=0x0; i<=0xF; i++) {
		bin_str = nibble_to_bin_str(i);    // memory for bin_str allocated here
		
		printf("%2hhu     %2hhx      %s\n", i, i, bin_str);
		
		// memory for bin_str should get freed up before next call to
		// nibble_to_bin_str()
		free(bin_str);     
	}
}

/**
 * Print out the hex and binary values for all 8-bit positive values
 * between 00 and FF (0 and 255).
 * 
 */
void print_all_pos_bytes() {
	  	
	unsigned char i;   //loop counter foe value to convert to a binary string
	char * bin_str;   // string that contains the binary value for an int
	
	printf("decimal   hex     binary\n");      // a header line
	
	for (i=0x00; i<=0xFF; i++) {              // no need to change this
		
/****************************************************************************** 
 * TODO: use uchar_to_bin_str() to create each string, and free bin_str
 *         each time through the loop. Print padded width of 3 for the decimal
 *         and padded width of 2 for the hexadecimal representation
 *         (so the numbers will line up).
 * Try also: printing hex value in upper case.
 */
		bin_str = uchar_to_bin_str(i);    // memory for bin_str allocated here
		
		printf("%3hhu     %2hhX      %s\n", i, i, bin_str);
		
		// memory for bin_str should get freed up before next call to
		// char_to_bin_str()
		free(bin_str); 
/************************************ end TODO ***************************/
		
		// DO NOT REMOVE THIS:
		if (i == 0xFF) break;     // you will see why this is needed later

	}
	
}