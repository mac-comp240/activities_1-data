/*
 * Task 1: replace this line with comments about this file and your name
 */ 
#include <stdio.h>        // printf
#include <stdlib.h>       // free  
#include <limits.h>       // named constants for min, max of C integer data types
#include <assert.h>       // assert
#include <string.h>       // strcmp

// include declarations for functions in binary_convert.c
#include "binary_convert.h"

// declarations for functions in hex.c
// Note that we don't yet have a file called hex.h.
void hex_table();
void print_all_pos_bytes();

// declarations for functions in this file
void try_uchars();
void try_ushorts();
void try_uints();
void try_ulongs();

void try_chars();
void try_shorts();
void try_ints();
void try_longs();

/////////////////////////////////////////////////////////////////////////////
/**
 * Display the limit and size in bytes of the C **unsigned** integral data types.
 * 
 * Look up information about the named constants in limits.h 
 * 
 * SEE: http://www.cplusplus.com/reference/cstdio/printf/
 *      for full explanation of printf formatting options.
 * 
 * TODO: study this reference and understand the choices made in the printf
 *       statements in this function.
 * 
 * Note: sizeof returns a value of type size_t, which on our systems is defined as:
 *       typedef long unsigned int size_t;
 *       So to print it we use %zu  for a size_t (long unsigned value)
 */
void c_utype_sizes() {
	printf("type           |   maximum            | size (bytes)\n");
	printf("unsigned char  | %-21hhu| %zu\n", UCHAR_MAX, sizeof(unsigned char));
	printf("unsigned short | %-21hu| %zu\n", USHRT_MAX, sizeof(unsigned short));
	printf("unsigned int   | %-21u| %zu\n", UINT_MAX, sizeof(unsigned int));
	printf("unsigned long  | %-21lu| %zu\n", ULONG_MAX, sizeof(unsigned long));	
}

/**
 * Display the minimum and maximum limits and size in bytes of the C 
 * **signed** integral types (char, short, int, and long).
 * 
 * TODO: complete this function (char given)
 */
void c_stype_sizes() {
	
	printf("type   |   minimum            |   maximum            | size (bytes)\n");
	// solution
	printf(" char  | %-21hhd| %-21hhd| %zu\n", SCHAR_MIN, SCHAR_MAX, sizeof( signed char));
	printf(" short | %-21hd| %-21hd| %zu\n", SHRT_MIN, SHRT_MAX, sizeof( short));
	printf(" int   | %-21d| %-21d| %zu\n", INT_MIN, INT_MAX, sizeof( int));
	printf(" long  | %-21ld| %-21ld| %zu\n", LONG_MIN, LONG_MAX, sizeof( long));
	// solution
}

/*
 * A main() to demonstrate printf formatting, creation of strings to represent
 * the binary representation of an integer, and print out the first 16 
 * hexadecimal numbers.
 */
int main() {
	
	/////////////   Task 2:  Study data type sizes and printf directives for them
	//
	// print out the integral data types and thier sizes in bytes
	c_utype_sizes();
	printf("\n");  // add a blank line to output
	
	c_stype_sizes();  //TODO: you will complete this one above
	printf("\n");  // add a blank line to output

	////////////////////////////////////////////////////////////////////////
	//
	//	Task 3: Study how we can print out a range of values in hex and binary
	//	
	// write out the first 16 integers in decimal, hex, and binary
  	hex_table();   // see hex.c
	
	printf("\n");  // add a blank line to output

	////////////////////////////////////////////////////////////////////////
	//
	//  Task 4: Test an invalid input
	//  
	// TODO: test two incorrect values for nibble_to_bin_str by using the char * variable bin_str
	//       to hold what it returns and printing it. Then use the function called free
	//       on bin_str to remove the memory allocated for it.
	char * bin_str;                                        // keep
	bin_str = nibble_to_bin_str(16);                       // solution
	printf("result of incorrect input 16: %s\n", bin_str);    // solution
	free(bin_str);                                         // keep
	
	bin_str = nibble_to_bin_str(-2);                       // solution
	printf("result of incorrect input -2: %s\n", bin_str);    // solution
	free(bin_str);                                         // keep
	
	printf("\n");  // add a blank line to output
	
	////////////////////////////////////////////////////////////////////////
	// 	
	// 	Task 5: finish a function to print out all byte values from 0 to 255
	// 	        in hex and binary
	// 	        
	printf("\nRepresentations for all possible byte values:\n");
	
	print_all_pos_bytes();     // TODO: see hex.c and complete this function; uncomment to test
	
	printf("\n");  // add a blank line to output
	
	////////////////////////////////////////////////////////////////////////
	//
	//  Task 6: Work through the process of testing all functions in binary_convert.c/h
	
	// Simple examples of assert() usage. Note need for inlcuding <assert.h> 
	// at the top of this file.
	// If you wish, experiment with trying to change either the assignment or the
	// assert to force it to fail.
	int test_int = 47;
	assert(test_int == 47);
	char * test_str = "Hello";
	assert(strcmp(test_str,"Hello")==0);  // compare one string to another
	
	
	try_uchars();   // this function is complete below in this file as an example
	
	// TODO: work on the functions below in this file by choosing values to test.
	//       At a minimum, a rule of thumb is to try the following for integer types:
	//       0, 1, -1 (for signed), the maximum posiible value, and the 
	//       minimum possible value (for signed).
	//       
	//       You should be even more thorough by also trying some arbitrary intermediate 
	//       value(s), positive and negative (for signed).
	
	try_ushorts(); 
	
	try_uints();
	 
	try_ulongs();
	
	///// signed value tests /////////////////////////////////////////
	 
	try_chars(); 
	
	try_shorts(); 
	
	try_ints();
	
	try_longs();
	
	printf("\n");  // add a blank line to output
	printf("All tests passed.\n");
  
	return 0;
}

/////////////////////  separate testing functions for testing the range of values
/////////////////////  that can be sent to the functions in binary_convert.c


/**
 * Tests various input values for the function uchar_to_bin_str.
 * Since an unsigned char type is the input, we test positive numbers.
 */
void try_uchars() {
	char * bin_str;
	
	printf("------------ unsigned char tests --------------\n");
	// 0
	unsigned char val = 0x0;
	bin_str = uchar_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000")==0);
	free(bin_str); 
	
	// 1
	val = 0x1;
	bin_str = uchar_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0001")==0);
	free(bin_str); 
	
	// maximum char value, using limits.h constant
	val = UCHAR_MAX;
	bin_str = uchar_to_bin_str(val);
// 	printf("UCHAR_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111")==0);
	free(bin_str); 
	
	// a value in between 0 and
	// maximum char value, using limits.h constant
	val =UCHAR_MAX/2;
	bin_str = uchar_to_bin_str(val);
// 	printf("UCHAR_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111")==0);
	free(bin_str); 
}

/**
 * Tests various input values for the function ushort_to_bin_str.
 * Since an unsigned short type is the input, we test positive numbers.
 */
void try_ushorts() {
	char * bin_str;
	
	printf("------------ unsigned short tests --------------\n");
	// 0
	unsigned short val =0x0;
	bin_str = ushort_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = ushort_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// maximum short value, using limits.h constant
	val =USHRT_MAX;
	bin_str = ushort_to_bin_str(val);
// 	printf("USHRT_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// a value in between 0 and
	// maximum short value, using limits.h constant
	val =USHRT_MAX/2;
	bin_str = ushort_to_bin_str(val);
// 	printf("USHRT_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111")==0);
	free(bin_str); 
}

/**
 * Tests various input values for the function uint_to_bin_str.
 * Since an unsigned int type is the input, we test positive numbers.
 */
void try_uints() {
	char * bin_str;
	
	printf("------------ unsigned int tests --------------\n");
	// 0
	unsigned int val =0x0;
	bin_str = uint_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = uint_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// maximum int value, using limits.h constant
	val =UINT_MAX;
	bin_str = uint_to_bin_str(val);
// 	printf("UINT_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// a value in between 0 and
	// maximum int value, using limits.h constant
	val =UINT_MAX/2;
	bin_str = uint_to_bin_str(val);
// 	printf("UINT_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
}

/**
 * Tests various input values for the function ulong_to_bin_str.
 * Since an unsigned long type is the input, we test positive numbers.
 */
void try_ulongs() {
	char * bin_str;
	
	printf("------------ unsigned long tests --------------\n");
	// 0
	unsigned long val =0x0;
	bin_str = ulong_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = ulong_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// maximum long value, using limits.h constant
	val =ULONG_MAX;
	bin_str = ulong_to_bin_str(val);
// 	printf("ULONG_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// a value in between 0 and
	// maximum long value, using limits.h constant
	val =ULONG_MAX/2;
	bin_str = ulong_to_bin_str(val);
// 	printf("ULONG_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 	
}

//////////////////////  Signed integer value tests
/**
 * Tests various input values for the function char_to_bin_str.
 * Since a char type is signed, we try negative as well as positive numbers.
 */
void try_chars() {
	char * bin_str;
	
	printf("------------ char tests --------------\n");
	// 0
	char val =0x0;
	bin_str = char_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = char_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0001")==0);
	free(bin_str); 
	
	// -1
	val =-1;
	bin_str = char_to_bin_str(val);
// 	printf("-1: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111")==0);
	
	// maximum char value, using limits.h constant
	val =CHAR_MAX;
	bin_str = char_to_bin_str(val);
// 	printf("CHAR_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111")==0);
	free(bin_str); 
	
	// minimum char value using limits.h constant
	val =CHAR_MIN;
	bin_str = char_to_bin_str(val);
// 	printf("CHAR_MIN: %s\n", bin_str);
	assert(strcmp(bin_str,"1000 0000")==0);
	free(bin_str); 
	
	// arbitrary positive value 
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =CHAR_MAX/2;
	bin_str = char_to_bin_str(val);
// 	printf("CHAR_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0011 1111")==0);
	free(bin_str); 
	
	// arbitrary negative value
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =CHAR_MIN/2;
	bin_str = char_to_bin_str(val);
// 	printf("CHAR_MIN/2: %s\n", bin_str);
	assert(strcmp(bin_str,"1100 0000")==0);
	free(bin_str); 
	
}

/**
 * Tests various input values for the function char_to_bin_str.
 * Since a short type is signed, we try negative as well as positive numbers.
 */
void try_shorts() {
	char * bin_str;
	
	printf("------------ short tests --------------\n");
	// 0
	short val =0x0;
	bin_str = short_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = short_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// -1
	val =-1;
	bin_str = short_to_bin_str(val);
// 	printf("-1: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111")==0);
	
	// maximum short value, using limits.h constant
	val =SHRT_MAX;
	bin_str = short_to_bin_str(val);
// 	printf("SHRT_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111")==0);
	free(bin_str); 
	
	// minimum short value using limits.h constant
	val =SHRT_MIN;
	bin_str = short_to_bin_str(val);
// 	printf("SHRT_MIN: %s\n", bin_str);
	assert(strcmp(bin_str,"1000 0000 0000 0000")==0);
	free(bin_str); 
	
	// arbitrary positive value 
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =SHRT_MAX/2;
	bin_str = short_to_bin_str(val);
// 	printf("SHRT_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0011 1111 1111 1111")==0);
	free(bin_str); 
	
	// arbitrary negative value
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =SHRT_MIN/2;
	bin_str = short_to_bin_str(val);
// 	printf("SHRT_MIN/2: %s\n", bin_str);
	assert(strcmp(bin_str,"1100 0000 0000 0000")==0);
	free(bin_str); 
	
}

/**
 * Tests various input values for the function char_to_bin_str.
 * Since a int type is signed, we try negative as well as positive numbers.
 */
void try_ints() {
	char * bin_str;
	
	printf("------------ int tests --------------\n");
	// 0
	int val =0x0;
	bin_str = int_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = int_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// -1
	val =-1;
	bin_str = int_to_bin_str(val);
// 	printf("-1: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111 1111 1111 1111 1111")==0);
	
	// maximum int value, using limits.h constant
	val =INT_MAX;
	bin_str = int_to_bin_str(val);
// 	printf("INT_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// minimum int value using limits.h constant
	val =INT_MIN;
	bin_str = int_to_bin_str(val);
// 	printf("INT_MIN: %s\n", bin_str);
	assert(strcmp(bin_str,"1000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// arbitrary positive value 
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =INT_MAX/2;
	bin_str = int_to_bin_str(val);
// 	printf("INT_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0011 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// arbitrary negative value
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =INT_MIN/2;
	bin_str = int_to_bin_str(val);
// 	printf("INT_MIN/2: %s\n", bin_str);
	assert(strcmp(bin_str,"1100 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
}

/**
 * Tests various input values for the function char_to_bin_str.
 * Since a long type is signed, we try negative as well as positive numbers.
 */
void try_longs() {
	char * bin_str;
	
	printf("------------ long tests --------------\n");
	// 0
	long val =0x0;
	bin_str = long_to_bin_str(val);
// 	printf("0: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// 1
	val =0x1;
	bin_str = long_to_bin_str(val);
// 	printf("1: %s\n", bin_str);
	assert(strcmp(bin_str,"0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0001")==0);
	free(bin_str); 
	
	// -1
	val =-1;
	bin_str = long_to_bin_str(val);
// 	printf("-1: %s\n", bin_str);
	assert(strcmp(bin_str,"1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111")==0);
	
	// maximum long value, using limits.h constant
	val =LONG_MAX;
	bin_str = long_to_bin_str(val);
// 	printf("LONG_MAX: %s\n", bin_str);
	assert(strcmp(bin_str,"0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// minimum long value using limits.h constant
	val =LONG_MIN;
	bin_str = long_to_bin_str(val);
// 	printf("LONG_MIN: %s\n", bin_str);
	assert(strcmp(bin_str,"1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 
	
	// arbitrary positive value 
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =LONG_MAX/2;
	bin_str = long_to_bin_str(val);
// 	printf("LONG_MAX/2: %s\n", bin_str);
	assert(strcmp(bin_str,"0011 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111")==0);
	free(bin_str); 
	
	// arbitrary negative value
	// Note: /2 shifts binary value to the right by 1 digit,
	//       using arithmetic shift
	val =LONG_MIN/2;
	bin_str = long_to_bin_str(val);
// 	printf("LONG_MIN/2: %s\n", bin_str);
	assert(strcmp(bin_str,"1100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000")==0);
	free(bin_str); 	
}


