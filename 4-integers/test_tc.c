/*
 * Data activity 4
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "binary_convert.h"

int main() {
    // some limits: it's best to see what our mchine will give us
    printf("short is %zu bytes wide\n", sizeof(short));
	printf("min value of a short is: %hd\n", SHRT_MIN);
	printf("max value of a short is: %hd\n", SHRT_MAX);
	
	////////////////  two's complement values
	printf("\nA few two's complement values\n");
	
    short tmp = -32767;
	
    char * bin_str;
	bin_str = short_to_bin_str(tmp);
	printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);
	
	tmp = SHRT_MIN;
	bin_str = short_to_bin_str(tmp); 
    printf("%hd\t%04hx\t%s\n", tmp, tmp, bin_str);
	free(bin_str);
	
	////////////////  unsigned integer values
	printf("\nA few unsigned short integer values\n");
	// TODO: you add some unsigned values here using this declared variable:
	unsigned short utmp;
	
	
	///////////////////////////////// Part 3- keep commented until you work on this later
	/* create the hexidecimal table for all 1-byte signed numbers 
	signed char i;
	char * bin;   

	/*  uncomment this section for part 3 
	printf("decimal\thex\tbinary\n");

    for (i=-64; i<=63; i++) {	
		bin = char_to_bin_str(i);
		printf("%hhd\t%02hhx\t%s\n", i, i, bin);
		free(bin);

	}
	*/
    
}
