# Data Activity 1: Integer representations

Folder: `1-notation`

This is an introduction to 

* Operations on integers and alternative representations of integer values.
* The use of function prototypes in C header files (.h files).

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

## Resources

- For help on how to print each type of number, see [_Format Specifiers in C_](https://www.thecrazyprogrammer.com/2016/10/format-specifiers-c.html) by The Crazy Programmer (and note that `%zu` is the correct format code for printing the result of calls to `sizeof`)
- For the constants that specify each type's size, see [_C Programming/limits.h](https://en.wikibooks.org/wiki/C_Programming/limits.h)

## Provided Code

There are three files of code for this activity:

- `binary_convert.h`
    - the header file for the binary_convert library, included in the main code file, contains declarations of functions in the library
- `binary_convert.c`
    - the code file containing the definitions of the functions declared in the header file
- `activity.c`
    - the source file which contains the main method, in which you will complete your tasks


## A library of functions

The files called `binary_convert.h` and `binary_convert.c` comprise a small
*library* of functions we are providing to you. Similar to standard C libraries
provided by the language, the functions in this file can be used in other code
files. The header file (with the extension `.h`) declares the "interface" to the library: 
what functions and constants are provided by the library. The code file (with the extension `.c`)
defines the functions and constants.

**Open `binary_convert.h` and `binary_convert.c` to see what they contain.**


### To use a user-defined libraryr

**Look at `activity.c` and note this line near the beginning of the file:**

	#include "binary_convert.h"

This enables us to use the functions declared in `binary_convert.h` and fully
defined with C code in `binary_convert.c`.


### Warning 

The code in `binary_convert.c` uses some operators and functions that you are
not yet familiar with. Note however, that each function is documented to explain
what the input parameter is and what it returns. 



## Multiple .c files make one executable program

Compiling a program like this that has two code files plus a header file, is slightly more complicated 
than other examples we've seen. We need to pass both `.c` files to the compiler.

**Open the file `Makefile` and read it carefully.**

At the top of the Makefile, we define the compiler we want to use, with one option, which chooses which variant of C to use (C99).

Recall that the Makefile defines how we compile our source code into an executable program, automating the process for us. In this case, the Makefile combines the two C files to create one binary. 

The executable program will be called `bin_hex`. Since the Makefile has
the executable named `bin_hex` as the first *target* (text before a colon) in
the file, you can simply build it by typing this in the terminal:

    make

The above command is the same as if you had typed:

	make bin_hex

Execute the program by typing this in the terminal:

	./bin_hex
	
When coding in C, you will do this over and over again in the terminal as you
make changes to your code: 

	make 
	./bin_hex
	
Note that you can retrieve previous commands at the linux terminal shell by
using the up arrow key many times. Try it for these commands.

## Your tasks

- Open `activity.c` in your editor
- Add your name in a comment at the top of the file. You must put your name at the top of every code file you edit for assignments for this course (you will lose points on homework questions if you don't!) 
- Modify `activity.c` by following the instructions in the TODO comments in the file. These 
explain what you need to do.

You will not need to modify any other files!


### Notes 

- The macro `sizeof(TYPE)` returns the number of bytes used for a particular
  data type by the compiler on the particular hardware where the program is
  compiled and run. The `%zu` code is used to print the 
- The functions in `binary_convert.h` return strings of text by allocating space
  for them in the computer's memory. This memory must always be cleared after
  you are finished using it by calling the `free()` function, as in the example below:

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

### Feeling stuck or confused?


Ask for help right away during class, from neighbors, preceptors, or instructor!

### Commenting as documentation

You should comment each function you write like you would for Java:

	/** Describe inputs and return values and 
	 * what the function does -- this comment
	 * must start with /**, just like 
	 * javadoc comments
	 */

## References

[printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).

[limits.h reference in wikibooks](https://en.wikibooks.org/wiki/C_Programming/limits.h)

[limits.h reference in tutorialspoint](https://www.tutorialspoint.com/c_standard_library/limits_h.htm)

