# Data Activity 3: Operators and Masking

Folder: `3-operators-masking`

In this activity, you will:
- Create a C source code file
- Update a Makefile to build more than one executable

### What should a Makefile do?

For all of your code in this course, we expect to be able to type the following
in your directory and build all of the code at once:

  make clean

  make all
  
You will work on ensuring this in this activity.

There is a very basic start in the makefile provided. You will need to do the following:

1. Fill in the rest of target executable program called `bit_logical` that corresponds with your *bit_logical.c* file.  Note that the line that starts with all:  contains this target. You will add more executables to this line as you complete each problem in this activity. To complete this, you will need to add a line below the line already given with the target (bit_logical), a colon (:), and the C files that the target depends on (bit_logical.c, binary_convert.c, binary_convert.h). The line below this must start with a tab, and then contain the directive to compile C code file into the target executable, using the gcc compiler. In this case, this will look like this:

	${CC} -o bit_logical bit_logical.c binary_convert.c

2. Then complete the `clean:` target to your Makefile. A typical way to do this is to remove the executable targets. So to start, you can have a line like this that begins with a tab:

	rm -f bit_logical
		
The -f in the rm (remove) command above indicates that there is no need to return an error message if that file does not exist. At the terminal, you can type this to see more about the rm command:

    man rm

As you work on the other problems in this activity, you will continue adding new targets to the Makefile and you will update the `all:` target with them, and you will also need to update the `clean:` target to remove each of the executable files.

**Warning:** You cannot do this next suggestion yet until you have a bit_logical.c file with a functioning main() program in it!!!

As you work, you should practice typing

  `make all`
  
to create your executables. Note, however, that because all is the first target,
you can also type:

  `make`

## The flags to the gcc compiler

You may be wondering about this line in the Makefile:

	CC=gcc -std=C11

This is setting up a definition that will replace `${CC}` with the above when compiling the program. The -std=c11 flag to gcc tells the compiler that it can accept code that adheres to the ANSI C standard published in 2011. There have been many standards and dialects of those standards developed over the years (gcc itself has many of its own dialects). If you enjoy finding out about the historical aspects of the C language and how a language changes over time, please read this [article about the multitude of C standards](https://opensourceforu.com/2017/04/different-c-standards-story-c/).

The above article states that C11 is the latest ANSI standard, but in fact there is a new one now that cam out in 2017-2018. So gcc now supports a -std=c17. We likely will not need any of the new features, so we will choose to stay one standard behind for now.

You may also see examples where we have use `-std=c99`. This was a well-used standard for many years and most code we will ever write probably adheres to that standard. So we will often use this.

### Note: included files `binary_convert.c`, `binary_convert.h`

To assist with checking the values resulting from the operations that you will
attempt in these problems, we have included files called `binary_convert.c`  and
`binary_convert.h` from Data Activity 1, which have functions that return a
string with the binary representation of a given C integral data type value. 


# 1: Bit-wise vs. logical operators

**Code file you create:** 

        bit_logical.c

Create a new C code file named `bit_logical.c`. Use examples from past code
files to help determine the syntax of your headers and main function.

You will observe the difference between the bit-wise operators (&, |, and ~) and
the logical operators (&&, ||, !) by writing code that uses both. 

Note the section on `assert()` below--we use these in C to test that our code
functions, and implementing a testing suite is part of your first homework
assignment. Use them in this activity to check that you have correctly computed
the results of each operation.

## Problem Definition

Suppose `x` and `y` are **unsigned single bytes** that have the values 0x66 and
0x39 respectively. Consider what the result of the following operations are and
verify them in a main function.

<table border="0"> <tr> <th>Expression</th> <th>Value</th> </tr> <tr> <td>x &
y</td> <td></td> </tr> <tr> <td>x | y</td> <td></td> </tr> <tr> <td>~x | ~y</td>
<td></td> </tr> <tr> <td>x & !y</td> <td></td> </tr> <tr> <td>x && y</td>
<td></td> </tr> <tr> <td>x || y</td> <td></td> </tr> <tr> <td>!x || !y</td>
<td></td> </tr> <tr> <td>x && ~y</td> <td></td> </tr> </table>

### `printf` output format 

You could start by using the functions in `binary_convert.h/c` to print the
bytes and the operation so that you can see each bitwise operation result along
with its hex value:

```
0110 0110 & 
0011 1001 
---------
0010 0000     20

0110 0110 | 
0011 1001 
--------- 
0111 1111     7f

1001 1001 | 
1100 0110 
--------- 
1101 1111     df
```

Then practice adding asserts along with the prints of the results, as explained
below. 

### Using assertions in C

[This tutorial](http://ptolemy.eecs.berkeley.edu/~johnr/tutorials/assertions.html) provides an overview of how to use assert statements.

We can use assertions to test whether the result of executing our code is what
we expect. This is helpful when running a large number of tests, where we don't
want to deal with a hundred or more lines of printed output.

An example of an assert statement in code is as follows:

```
  #include <assert.h>

  int main() { 

      // set-up code omitted //

    result = x && y;
    //assert(result == 0x1);  // this should pass
    assert(result == 0);  // this should fail

    return 0;  // signifies program completed successfully 
  }
```

Try this with your own code: note that when the assertion fails, you get a
message with a line number of the code, and when the assertion passes, the code
continues to execute.

Using asserts is a good way of testing your code functionality, and it is
expected practice for your homework assignments.

### Notes

- Place your name and a description of your code in a comment at the top of your
  source file
- `main()` should return 0 when it completes successfully
- Watch your types! Which are the correct ones for `x` and `y`, below?
- You can use print statements and functions from `binary_convert.c` as you work
  on your code, but the final submission must use assertions

As you work, please note that there is typically no need to 'clean' each time
you use make. **The beauty and wonder of make is that it knows when a .c or .h
file has changed and that the program needs to be re-compiled.** Therefore, you
simply need to type `make` by itself after you have changed a .c or .h file.

# 2: Shifting

Here you will see the actual results of shifting unsigned and signed numbers.
Read through this whole page, examining the code and the Makefile, before you
begin changing them.

### Using shift operators

**target executable program name for Makefile:** 
shifts 

**provided starter code:** `shifts.c`

You are adding this target to your existing Makefile, rather than writing a new
one. Makefiles can handle building multiple separate executables; which parts of
the file will need to change in order for this executable to be built? Use the
existing target as an example.

Make sure that your function works for both signed and unsigned one-byte values.

(Note that this is practice problem 2.16 in your book.)

## Problem Definition

There is initial code in `shifts.c` to model the code you will write, examining
different shift operations on single-byte quantities. Practice on paper: convert
each value from hexadecimal to binary, perform the shit, and convert back to
hex.

This example is not as much as test as it is an observation of how shifting
works. However, as in the previous example, you could use asserts to test if you
understand what the result from a shift should be.

### Note

The important thing to note here is that unsigned numbers are shifted right logically and that signed numbers are shifted right arithmetically.

First, note that you can get the value 0XC3 as shown in the table by declaring a variable like this:

``` unsigned char x = 0xC3; ```

Next, note what happens when we cast that value to a signed variable instead:

``` char y = (char) x; ``` 

Use x for the logical shifts and y for the arithmetic shifts- the first example is given to you in the code. Try some of the rest in the following table:

<table> <tr> <td>x</td> <td></td> <td>x&lt&lt3</td> <td></td> <td>Logical
x>>2</td> <td></td> <td>Arithmetic y>>2</td> <td></td> </tr> <tr> <td>Hex</td>
<td>Binary</td> <td>Hex</td> <td>Binary</td> <td>Hex</td> <td>Binary</td>
<td>Hex</td> <td>Binary</td> </tr> <tr> <td>0xC3</td> <td></td> <td></td>
<td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr> <td>0x75</td>
<td></td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td> </tr> <tr>
<td>0x87</td> <td></td> <td></td> <td></td> <td></td> <td></td> <td></td>
<td></td> </tr> <tr> <td>0x66</td> <td></td> <td></td> <td></td> <td></td>
<td></td> <td></td> <td></td> </tr> </table>


Not how we use the functions in binary_convert.h/c in the shifts.c code to print out the binary representation of unsigned char values and char values. Convince yourself that you understand the bit patterns of each. Then shift each one and use your function to print out the result (hint: do right shift by 2 as the problem suggests, then try other shifts if you wish). Note that the behavior of the shifting done is different for the signed value than for the unsigned value. 

## Work smart

You probably are considering a lot of cutting and pasting of code for each of the examples that you chose to try. Instead, develop a function that can take in x and y and essentially does what the first example code does. Then use a call to that function as a test. You will need to add a function declaration at the top of your file for your new function.

## Update all parts of the Makefile!

Make sure to add the shifts program from shifts.c to your Makefile, including in all: so that `make all`  or `make` will work. Also add the shifts program in the rm -f line of the clean: target directive, so that `make clean` will remove the shifts program as well as the bit_logical program.

Eventually this makefile should work for all the different programs you are making for each part of this activity.

## Work smarter

Improve your print function to have it take in 2 more parameters: how much to shift the unsigned value left and how much to shift the signed values right.


# Problem 3: Masking of bits

Now let's try working with masks, which are bit patterns, typically of a series of ones followed by a series of zeros, or vise versa, or all ones and all zeroes.  

## The problem:

Given an unsigned int x and an unsigned int y, determine the C expression that:

Will yield an unsigned int consisting of the least significant byte of x and the remaining bytes of y.

Use this expression in a function and test it with several different inputs of x and y.

The approach to this problem is to consider what the binary representation is for the integers like 0xFF and ~0xFF.  Test your expression by creating new C file called mask.c. 

Create a function that takes the two values, x and y, as parameters, executes the expression, and prints the result in hexadecimal form. You should make an unsigned int called a mask and use it with the bitwise operators & and | and x and y in your expression.

**Note: You should refrain from using shifting for this task.**

The test your function on several values in main(). Don't forget our mantra about testing: try 0, 1, the maximum unsigned int, and several values in between.

### Need to think about the testing carefully 

The testing is different here than in activity 1, because we have 2 input values to the function called *least1x_most3y*. The above mentioned mantra now applies to each parameter, x and y, and combinations of them. The number of tests needed grows quickly in this circumstance!

Another thing to consider in this case is that the boundary, or edge cases are at the byte level. In other words, the 0,1, and max cases for x might be these:

0x0, 0x1, 0xFF, 0xFFFFFF00, and 0xFFFFFFFF

And for y (or x) we might want to use something with distinctive bytes, such as this:

0xABCDEF00

Also note that using hexadecimal numbers for the tests makes developing assertions easier.

*Make sure to add mask.c and its executable to your Makefile (all and clean too!).*

## A challenge if you want to keep trying masks and tests

You could try developing other expressions that provide other patterns of bytes from each of the inputs. Then develop test for them.

# Check your work

## Get the code solution

Check the solution directory to get the completed version of the code for this activity.

To try out this version, you can do this on the command line of the terminal:

    cd solution

Then you will be in the solution directory. You can then use make to compile this version.

To get back out of the solution directory, you can do the following:
    cd ..
	
### Warning 

We will not always provide solutions for every activity. This is likely the last time, since you now have quite a few examples of C code.
 
