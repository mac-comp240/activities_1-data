# Data Activity 1: Integer representations

Folder: `1-notation`

This is an introduction to operations on integers and alternative representations of integer values.

This is also an introduction to the use of function prototypes in C header files (.h files).

This is also an introduction to exhaustive testing and use of asserts during testing.

# Data type representation and Testing functions

Your goal will be to complete several tasks that will assist you in learning about these aspects of C programming and generally how the computer represents integral data:

- You will consider the eight different possible data types in C that can represent integers that are either unsigned (positive only) or signed (both positive and negative).
	- unsigned char, unsigned short, unsigned int, unsigned long
	- char, short, int, long
	
- You will try using printf to print each of these data types.

- You will observe the number of bytes allotted for each of these types in C on the linux server.

- You will use a provided *library* of functions that is designed to create strings of characters that represent the underlying binary representation  of a value of one of these types.

- You will write test cases for the functions in the library as a way to explore what it means to conduct exhaustive testing.

- You will begin getting used to using a handy function called *assert()* to help you avoid printing out results of tests and simplify your test suites.

## Provided Code

There are three files of code for this activity:

- binary_convert.c and binary_convert.h
    - utility functions to create strings of binary representations of numbers
- hex.c 
    - functions to print tabular lists of decimal, hexadecimal, and binary representations of numbers
- test.c 
   - main program file to study printf format specifiers and to test out functions in the above 2 files

## A library of functions

The files called binary_convert.h and binary_convert.c comprise a small *library* of functions we are providing to you. similar to standard C libraries provided by the language, the functions in this file can be used in other code files. Look at test.c and note this line near the beginning of the file:

	#include "binary_convert.h"

This enables us to use the functions declared in binary_convert.h and fully defined with C code in binary_convert.c.

### Warning 

The code in binary_convert.c uses some operators and functions that
you are not yet familiar with. Note however, that each function is documented to explain what the input parameter is and what it returns. You therefore can use these functions and write some tests to determine if they work properly.



## Multiple .c files make one executable program

Examine the code in the file called `test.c` and `hex.c`. In a moment you will use `make` to build it before you change any code. Examine the Makefile to see how three C code files are used to create one binary using gcc. Notice how the file called test.c uses the functions in the file called hex.c and tests them out.

The file called `hex.c` uses functions in the file called `binary_convert.c`. The test.c file also uses functions in 1binary_convert.c1 as a means of testing them for accuracy.

Open the Makefile. The executable program to be built is called `bin_hex`. Since this Makefile has the executable named `bin_hex` as the first target before the : in this file, you can simply build it by typing this at the terminal:

    make

### Important 

The first line that contains a target name followed by a colon (:) is by default what is built. The above command is the same as if you had typed:

	make bin_hex

Execute the program like this:

	./bin_hex
	
When coding in C, you will do this over and over again in the terminal as you make changes to your code: 

	make 
	./bin_hex
	
Note that you can retrieve previous commands at the linux terminal shell by using the up arrow key many times. Try it for these commands.

## Your tasks

Note in the code file that there are places with comments labeled TODO. These explain what needs to be done. Here are a few more details:

1. **First Thing:** Start in test.c first. Own your work on this code by documenting at the very top in the comment header what this file contains and what the program is doing. In this case you are testing out functions found in hex.c and binary_convert.c. *Write your name in the top comment header.* You will need to do this for every code file that you write for this course.

2. Next in test.c focus your attention on two functions, one that is complete, called *c_utype_sizes()*, and one that you will finish, called *c_stype_sizes()*. Study the first of these and notice three important aspects of this code:

	- The printf function takes a string in quotes containing zero or more optional **format specifiers** that begin with a % sign. 

	- Please open [this reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/). Look at the code and the output from running the bin_hex program to see how the code has used the - flag, a width of 21, a length specifier appropriate for each type, and a specifier of u because all of these data types are unsigned.
		
	- The macro called *sizeof* returns the number of bytes used for a particular data type by the compiler on the particular hardware where the program is compiled and run.
	
	- The capitalized variables such as UCHAR_MAX are found in a file called limits.h, which is documented in [this reference](https://www.tutorialspoint.com/c_standard_library/limits_h.htm) and many others that you might find by searching for C limits.h.
	
**You need to complete** *c_stype_sizes()* in test.c for signed data types char, short, int, and long. In this case these data types have both a maximum and a minimum negative value. Find out what the named constants for the maximum and minimum of each type should be and use them.

3. This code currently prints out a table of the binary and hexadecimal values for the first 16 positive unsigned decimal numbers, 0 through 15. This is a handy table to have as you work with hexadecimal numbers (often shorten to hex). Note that the function `hex_table` in hex.c uses another function in binary_convert.c called `nibble_to_bin_str` to accomplish this. Since all possible values for a nibble (half a byte) are being printed, this function `hex_table` is thoroughly testing **what should work properly** when calling `nibble_to_bin_str`.

### Important 

The functions in binary_convert.h generate C text strings that are allocated in memory such that you must remove it with a function called *free*. **Every time you call a function from binary_convert.h and are done using its return value, you must dispose of the memory.** Note the pattern in the hex.c file for this:

```
// declare the string pointer
char * bin_str; 
```

```
// create the string by calling a function from binary_convert.h
bin_str = nibble_to_bin_str(i); 
```

```
// After using bin_str, remove it from memory. 
free(bin_str); 
``` 

After free, bin_str is NULL until its memory is recreated. You can re-use bin_str again, but must do so by calling one of the functions in binary_convert.h to re-populate it with a new value.

4. In addition to this simple table, it is necessary to test what happens if we pass an invalid value to the *nibble_to_bin_str()* function. In test.c, complete this task by doing what is says in the TODO block under the section labeled Task Four.

### Important 

Although you could test any positive integer greater than 15, a very useful **edge case** is to try 16. This is because a possible coding mistake that is common is to accidentally get the edge of the limits incorrect in an if statement.

Note that in hex_table we have tested the other edge cases that are appropriate here: 0 and 15. Convince yourself why this is so.

5. The *nibble_to_bin_str()* function can be tested thoroughly by trying all possible valid inputs and one edge case and another invalid input. As the range of numbers whose binary representation we want to test out increase, it becomes
harder and harder to write tests that **print** results for all possible values. We can still get away with it for unsigned char data types, whose values range from 0 to 255. Complete the function in hex.c called *print_all_pos_bytes* that will loop through all 256 values and print them, which effectively tests all input to the function *uchar_to_bin_str()* documented in binary_convert.h. Uncomment the call to *print_all_pos_bytes* in test.c under the section labeled Task 5 to test your work.

6. Your previous task demonstrates the extent to which we want to attempt printing out all possible values that a function could produce. We might even argue that this much printing is overkill and certainly very tedious to read through all 256 lines of output. It is a reasonable first try, but we can do better and must do so for bigger values. So Now we will move towards a form of testing that covers the **edge cases** and some in between as a mechanism for a creating a reasonably complete test suite of each function documented in binary_convert.h. 

	- Study the function  *try_uchars()* found after main() in the file test.c. It currently uses a printf and a new function called assert() to check whether a value returned from the function *uchar_to_bin_str()* is what you expect it to be. Eventually you can comment out or remove all of the printf statements and use only the assert statements for your tests. 
	
	- You should now complete the other functions for **unsigned** values of the data types short, int, and long. **Look at the TODO comment under Task 6 and the use of try_uchars()** to see a rule of thumb for testing functions like these. Follow this for completing the other functions, using *try_uchars()* as a guide. Comment every test you develop. Note that you will add to these lines near the top of main.c for each function that you write and use in main: 
	  
	  ```
	  // declarations for functions in this file
	  void try_uchars();

	  void try_chars(); 
	  ```

### Important 

A good mode of work is to work on one function at a time, piece by piece, trying it as you go along.
	
Our goal for testing will be to use exclusively assert() statements so that our test program runs with a minimum of output. Work toward that goal as you complete these functions.

You should eventually complete the rest of the test suite by writing documentation for and completing the tests of the **signed** data type values that are inputs to the rest of the functions documented in binary_convert.h. You will want to do this after we study signed two's complement numbers next.


## Testing out the library

As you change either the hex.c or the test.c file, the make program will be aware of what has changed since the executable program called `bin_hex` was last made and will be able to rebuild it when you type `make` in the terminal. If your code has errors, the gcc compiler will print those out to the terminal.

### Feeling Stuck?

Scroll to the "Check your work" section of this README to learn about the solution.

## Exhaustive testing

This activity is a guide for how you will work on homework assignments before submitting them. *Please note that for most homework assignments we will expect you to have complete tests in your test.c file*. We will often have a full set of tests of our own that we will try when grading the code that you submit.

**Fun Fact:** When preparing this activity for you, the only way to ensure that the functions in binary_convert.c/h were all completely correct was to do this exhaustive testing. The author discovered a few small elusive bugs that she had to fix before this code passed all the tests!

## Commenting for later Documentation

You should add comments that document the remaining test functions by placing comments like this in front of a function:


	/** Describe inputs and return values and 
	 * what the function does -- this comment
	 * must start with /**, just like 
	 * javadoc comments
	 */

There are ways to generate documentation for C code that contains these comments. You could explore this on your own if you'd like. The program to do this on linux machines is called doxygen.

### References

[printf format specifier reference from cplusplus.com](http://www.cplusplus.com/reference/cstdio/printf/).

[limits.h reference in wikibooks](https://en.wikibooks.org/wiki/C_Programming/limits.h)

[limits.h reference in tutorialspoint](https://www.tutorialspoint.com/c_standard_library/limits_h.htm)



# Check your work

## Get the code solution

Change directory (`cd`) into the solution directory to get a completed version of the code for this activity.

This serves 2 purposes:

1. You will likely want to use the functions in binary_convert.c/h in other situations during the first part of this course. It is useful to see examples of this in hex.c and test.c.

2. You can look at the main function in **test.c** to see how we documented each test case and followed the rules of thumb to create them. We will be asking you to do the same for your homework in the future.

To try out this version, you can do this on the command line of the terminal:

    cd solution

Then you will be in the solution directory. You can then use make to compile this version.

To get back out of the solution directory, you can do the following:

    cd ..
	
### Warning 

We will not always provide solutions for every activity. We will do it here at the beginning so that you can have a reference example for thorough testing.

