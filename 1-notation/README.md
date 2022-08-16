# Data Activity 1: Integer representations

Folder: `1-notation`

This is an introduction to 

* Operations on integers and alternative representations of integer values.
* The use of function prototypes in C header files (.h files).

# Data type representation

You will complete several tasks that involve different ways to represent integer
data.

- You will consider the eight different possible data types in C that can
  represent integers that are either unsigned (positive only) or signed (both
  positive and negative).
	- unsigned char, unsigned short, unsigned int, unsigned long
	- char, short, int, long
	
- You will try using printf to print each of these data types.

- You will observe the number of bytes allotted for each of these types in C on
  the linux server.

- You will use a provided *library* of functions that is designed to create
  strings of characters that represent the underlying binary representation  of
  a value of one of these types.

## Provided Code

There are three files of code for this activity:

- `binary_convert.c` and `binary_convert.h`
    - utility functions to create strings of binary representations of numbers
- activity.c
    - the source file which contains the main method, and in which you will
      complete your tasks

## A library of functions

The files called `binary_convert.h` and `binary_convert.c` comprise a small
*library* of functions we are providing to you. Similar to standard C libraries
provided by the language, the functions in this file can be used in other code
files. Look at `activity.c` and note this line near the beginning of the file:

	#include "binary_convert.h"

This enables us to use the functions declared in `binary_convert.h` and fully
defined with C code in `binary_convert.c`.

### Warning 

The code in `binary_convert.c` uses some operators and functions that you are
not yet familiar with. Note however, that each function is documented to explain
what the input parameter is and what it returns. 



## Multiple .c files make one executable program

Note that in our Makefile, which defines how we compile our source code into an
executable program, we use two C files to create one binary. 

The executable program to be built is called `bin_hex`. Since this Makefile has
the executable named `bin_hex` as the first *target* (text before a colon) in
this file, you can simply build it by typing this at the terminal:

    make

The above command is the same as if you had typed:

	make bin_hex

Execute the program like this:

	./bin_hex
	
When coding in C, you will do this over and over again in the terminal as you
make changes to your code: 

	make 
	./bin_hex
	
Note that you can retrieve previous commands at the linux terminal shell by
using the up arrow key many times. Try it for these commands.

## Your tasks

Note in the code file that there are places with comments labeled TODO. These
explain what needs to be done. All TODOs are in `activity.c`; it is the only
source code file that you will modify.

Make sure that you **write your name** in a comment at the top of the file. You
are expected to do this for every code file in this course (and there are points
allocated for it in homework assignments!).

	- Please open [this reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/). Look at the code and the output from running the bin_hex program to see how the code has used the - flag, a width of 21, a length specifier appropriate for each type, and a specifier of u because all of these data types are unsigned.
		
	- The macro called *sizeof* returns the number of bytes used for a particular data type by the compiler on the particular hardware where the program is compiled and run.
	
	- The capitalized variables such as UCHAR_MAX are found in a file called limits.h, which is documented in [this reference](https://www.tutorialspoint.com/c_standard_library/limits_h.htm) and many others that you might find by searching for C limits.h.
	
**You need to complete** *c_stype_sizes()* in test.c for signed data types char, short, int, and long. In this case these data types have both a maximum and a minimum negative value. Find out what the named constants for the maximum and minimum of each type should be and use them.

3. This code currently prints out a table of the binary and hexadecimal values for the first 16 positive unsigned decimal numbers, 0 through 15. This is a handy table to have as you work with hexadecimal numbers (often shorten to hex). Note that the function `hex_table` in hex.c uses another function in `binary_convert.c` called `nibble_to_bin_str` to accomplish this. Since all possible values for a nibble (half a byte) are being printed, this function `hex_table` is thoroughly testing **what should work properly** when calling `nibble_to_bin_str`.

### Notes 

- The macro `sizeof(TYPE)` returns the number of bytes used for a particular
  data type by the compiler on the particular hardware where the program is
  compiled and run.
- The functions in `binary_convert.h` return strings of text by allocating space
  for them in the computer's memory. This memory must always be cleared after
  you are finished using it by calling the `free()` function.

```
// declare the string pointer
char * bin_str; 

// create the string by calling a function from `binary_convert.h`
bin_str = nibble_to_bin_str(i); 

// After using bin_str, remove it from memory. 
free(bin_str); 
``` 

- After free, `bin_str` is NULL until its memory is recreated. You can re-use
  `bin_str` again, but must do so by calling one of the functions in
  `binary_convert.h` to re-populate it with a new value.

## Compile as you work 

As you change your source file, you will need to rebuild your executable by
typing `make` in the terminal. If your code has errors, the gcc compiler will
print those out to the terminal.

### Feeling stuck?

Talk to your neighbors or ask for help by raising your hand!

## Commenting as documentation

You should comment each function you write like you would for Java:

	/** Describe inputs and return values and 
	 * what the function does -- this comment
	 * must start with /**, just like 
	 * javadoc comments
	 */

### References

[printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).

[limits.h reference in wikibooks](https://en.wikibooks.org/wiki/C_Programming/limits.h)

[limits.h reference in tutorialspoint](https://www.tutorialspoint.com/c_standard_library/limits_h.htm)



# Check your work

## Get the code solution

Change directory (`cd`) into the solution directory to get a completed version of the code for this activity.

This serves 2 purposes:

1. You will likely want to use the functions in `binary_convert.c`/h in other situations during the first part of this course. It is useful to see examples of this in hex.c and test.c.

2. You can look at the main function in **test.c** to see how we documented each test case and followed the rules of thumb to create them. We will be asking you to do the same for your homework in the future.

To try out this version, you can do this on the command line of the terminal:

    cd solution

Then you will be in the solution directory. You can then use make to compile this version.

To get back out of the solution directory, you can do the following:

    cd ..
	
### Warning 

We will not always provide solutions for every activity. We will do it here at the beginning so that you can have a reference example for thorough testing.

