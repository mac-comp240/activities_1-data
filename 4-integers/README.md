# Data Activity 4: getting deep into integers

In this activity, you are provided working source code. You will modify the code to illustrate the representation principles of signed vs. unsigned integers, widening and narrowing during casting, and the limits/boundaries of different integer data types.

## Part 1: examine differences between signed and unsigned

Recall from Data activity 1 that you were able to observe the limits of different data types in C by knowing how many bytes each has and knowing the maximum and minimum values, which you can obtain from the named constants in limits.h. We will now do a quick observation of the difference between the unsigned numbers and the two's complement numbers.

### Makefile builds the code

This Makefile has another example of building a program whose name is different than the .c file used to build it.

**file:**   `test_tc.c` 

**target program name:** `twos_comp`

### Examining two’s complement (signed) and unsigned representations of integers.

Let’s return again to the functions in binary_convert.h/c from Activity 1.  

Observe some demonstration code in *test_tc.c*.  We are going to first consider the C data type short, whose size in bytes and max and min limits are printed with the code at the beginning of main().  Recall why we printed those values with the format string %hd. Look up the ways we do this if you've forgotten: [printf format reference](http://www.cplusplus.com/reference/cstdio/printf/).

Next, the code in main examines the binary representation of one negative number in two’s complement notation. Notice in main() in *test_tc.c* that the variable tmp is declared to be of type **short**, and we set it to -32767. Build the program with make, then run it and observe the binary representation of this negative value.  

Try  adding a few other values, printing out their binary values. Verify that the bit patterns seem correct. 

Now try it with **unsigned** short, which in essence doesn’t use two’s complement representation.  What is the largest value that you can assign to an **unsigned** short?  Print its binary representation. *Do this by using limits.h:*

	#include <limits.h>

Look up on the web what the named constants are for various values, such as the maximum unsigned short.


## Part 2: casting


### Casting signed to unsigned

Now consider casting from short to unsigned short, as in the following code (given in section 2.2.4 of your book and repeated here):

```
	short int v = -12345;

	unsigned short uv = (unsigned short) v;

	printf("v = %hd, uv = %hu\n", v, uv);
```

Try this code and print out the underlying binary representations of u and v (you can add it to main in *test_tc.c*). What do you observe? Why is this so?

In your text, the author states: "when mapping a signed number to its unsigned counterpart, negative numbers are converted to large positive numbers, while non-negative numbers remain the same." Use 2 values to illustrate this and print their binary representations out as test cases in your *test_tc.c* file.

### Casting by widening and narrowing

You could next examine what happens when you cast between short and int. Casting from short to int is generally fine, but from int to short can be problematic.  Choose some values to illustrate how this problem can be created
and why you should avoid it.


# Part 3: integral values have limits

Looking at ranges of numbers and observing overflow The last part of the main function in *test_tc.cc* that is commented out prints the table of representations of signed char values from -64 to +63. Uncomment it and re-make your code to see all of the values get printed.  


### What happens if we increase the range?

Values declared to be `signed char` type are 1 byte long, or 8 bits.  What happens when you change the range in the for loop to go through all values in the range of signed chars, which is -128  through 127.  Make the new version and run it inside the terminal. 

### STOPPING RUNAWAY CODE
IMPORTANT Note: control-c will quit any running program on the command line. You may need to wait quite a bit for the command prompt to come back, but it will eventually.

Work through in your mind what is happening when you try using the full range of values in the for loop. Discuss this with your neighbors. Improve the code and try again. 

**USEfUL TIP: Saving output.** Now switch the code to values that will not create an infinite loop, such as -64 to +63. After building with make, you can run the program this way to save what is printed:

	./twos_comp > tc_out

This puts the output into a file called tc_out. You can view that file using a program called less:

	less tc_out

Hitting the Q key will quit out of less. Space bar scrolls down, control-b or control-u goes back up.

## After running: Avoiding Overflow in a loop

There are a few ways to avoid having this loop run infinitely. Here is one that works fairly well. Add this to the bottom of the loop just before it goes back around:

```
    if (i == 127) break;
```

You can also change the loop to do one fewer value, then print the last one outside of the loop.


## Part 4: Checking Addition and Subtraction of 2’s complement numbers

See code for practice problem 2.32 called *problem2_32.c*.  Note that in this code the solution for practice problem 2.30 is provided as function *tadd_ok()*, with additional comments about how it is working. In this case the file has our main() function in it also.

Try it out with the tests provided (you will need to add it to the makefile). How might you use  assert() instead of the printf statements given? Then and add some more tests to main() for checking *tsub_ok()*  (note that only *tadd_ok* is being tested so far).  Be certain to try the interesting case of 0 - TMin.

What needs to be done to fix *tsub_ok()* so that it works correctly?  Write the code for this.

If you are not certain what needs to be done for *tsub_ok()*, look in the folder solution_2_32.

