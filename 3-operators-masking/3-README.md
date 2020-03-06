# Data Activity 3: Operators and masking

Folder: `3-operators-masking`

Here you will practice creating a whole C code file and you will update a Makefile that will build more than one executable, one for each problem described in the pages of this activity. First, a couple of notes, and then the first problem you will work on.

### Note: what a Makefile should always do

For practice for official grading, we expect to be able to type the following in your directory and build all of the code at once:

  make clean

  make all
  
You will work on ensuring this in this activity.

### Note: included files binary_convert.c, binary_convert.h

To assist with checking the values resulting from the operations that you will attempt in these problems, we have included files called *binary_convert.c*  and *binary_convert.h* from Data activity 1 that have functions that can build up a string of the binary representation of given C integral data type value. 


# Problem 1

**Code file you create yourself:** 

        bit_logical.c

Right-click on the folder named 3-operators-masking or use the File menu to create this new C code file, named bit_logical.c. To get started considering what needs to be in this file, you can look at the original "hello world" example from early in the course- it is in the folder called hello. You can also look at the starter code for the next 2 problems. These are the files shifts.c and mask.c.

## Observing bit-wise vs. logical operators.

Write C code in a file with a main() function in it that demonstrates the result of doing the operations on values, as described below (in a section labeled The Problem). Call your file *bit_logical.c*  (because here you will observe the difference between the bit-wise operators (&, |, and ~) and the logical operators (&&, ||, !). 

Note the information about assertions below the problem statement. Try using them in your code to more easily check if the answers match what you expect to get. However, as you will see, starting with printing the binary representations as strings can initially be useful to visualize how the operators work.

## For this and the following exercises, please complete a Makefile 

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

## Some notes

- Always have the habit of placing a brief description and your name in the comment heading at the very top of a .c code file.
- The main() function should return 0 when it completes successfully at the end.
- You should be careful to choose the correct type for the variables x and y mentioned in the problem below.
- An effective way to test whether a value seems correct is to use asserts instead of printing. Be sure to try this eventually.

As you work, please note that there is typically no need to 'clean' each time you use make. **The beauty and wonder of make is that it knows when a .c or .h file has changed and that the program needs to be re-compiled.** Therefore, you simply need to type `make` by itself after you have changed a .c or .h file.

## The problem

Suppose x and y are bytes that have the values 0x66 and 0x39 respectively. Consider what the result of the following operations are and verify them in a main function.

**Choose the data type that is one byte long and unsigned and convert the original values and the result of these operations into strings representing the binary value so that you can see how the operators work**

<table border="0"> <tr> <th>Expression</th> <th>Value</th> </tr> <tr> <td>x &
y</td> <td></td> </tr> <tr> <td>x | y</td> <td></td> </tr> <tr> <td>~x | ~y</td>
<td></td> </tr> <tr> <td>x & !y</td> <td></td> </tr> <tr> <td>x && y</td>
<td></td> </tr> <tr> <td>x || y</td> <td></td> </tr> <tr> <td>!x || !y</td>
<td></td> </tr> <tr> <td>x && ~y</td> <td></td> </tr> </table>

#### Suggested initial printf output format 

You could start by using the functions in binary_convert.h/c to print the bytes and the operation out like this so that you can see each bitwise operation result along with its hex value:

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

Then practice adding asserts along with the prints of the results, as explained below. After the first 3 cases above, the rest are fairly easy to simply write asserts for (instead of printing the result). You will need to recall what the result of a logical operation like &&, ||, or ! returns in order to test it properly.

Here is the code to generate the output for the first of the 3 examples shown above (you will need to create variables x, y, and result first):

```
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
```

### Using assertions in C

The document linked below provides some explanation  of  how you can use a construct called an assertion to check that certain conditions are true before your code continues executing. As you can see from it, it can be used to make sure that conditions you expect about values passed to functions are true.  For example, even when you document that a parameter value should be greater than 0, it is a good idea to check it yourself.

Look at [this tutorial](http://ptolemy.eecs.berkeley.edu/~johnr/tutorials/assertions.html) for more information about using asserts.

We can also use assertions to test whether the result of executing our code is what we expect.  When we run a large number of tests, this can be more helpful than printing out a great deal of output.  Here is an example: suppose we add the following code to the main of bit_logical.c file (you likely have started on this- below is a brief portion for one of the examples):

```
  #include <assert.h>
  //… 
  int main() { 
    unsigned char x = 0x66; 
    unsigned char y = 0x39; 
    unsigned char result;  // holds result of operation
    result = x & y;
    //assert(result == 0x20);  // this should pass
    assert(result == 0);  // this should fail

    return 0;  // signifies program completed successfully 
  }
```

Try this with your own code- see what happens when the assertion fails and note that you get a message with a line number of the code.  Uncomment the one that should pass and comment out the one that should fail. When the assertion passes, the code continues to execute.

Using asserts can be a way to test out a function that you write to be certain that it is working across a range of values that could be passed into it.  You can do this by executing the function and asserting whether the result is what you expect.  It will be good (and expected) practice to do this for your homework.  You can try it for the code files you write for this activity.

Having asserts in your code instead of print statements means that you can avoid the manual hassle of looking through large amounts of printout to check your code for accuracy.

# Problem 2: Shifting

Here you will see the actual results of shifting unsigned and signed numbers.

Read through this whole page, examining the code and the Makefile, before you begin changing them.

### Using shift operators

**target executable program name for Makefile:** 
shifts 

**starting C code file provided:** shifts.c

Complete the C code for the following problem in the file called *shifts.c*.  In the Makefile, have a target called **shifts** as the executable program. Use your own example input that should result in the use of a logical right shift in one case and and arithmetic right shift in another case.  Since the problem states that you will use 1-byte values, you will want  your function to work with unsigned char input and signed char input.

(Note that this is practice problem 2.16 in your book.)

### Makefiles can build multiple executable programs.

Include the new shifts.c code file that you will complete your Makefile as well. Add a target executable (shifts), a colon, what it depends on, and indented with a tab on the next line the command needed to build the executable from the code.

**Note:** you will be using the functions in binary_convert.c/h, so your shifts target depends on shifts.c and binary_convert.c and binary convert.h.


### The problem:

The initial code in shifts.c is designed to help you ill in the table below showing the effect of the different shift operations on single-byte quantities. The best way to think about the operations is to work with binary representations. First you could do this by hand on paper if you wish: Convert the initial values to binary, perform the shifts, and then convert back to hexadecimal. Each of the answers should be printed as 2 hexadecimal digits and 8 binary digits.

We are using printing rather than asserts for this particular problem because it is helpful at the onset of learning about these shifts to see exactly how they work by observing the result of a particular shift in hex an its binary form.

This example is not as much as test as it is an observation of how shifting works. However, as in the previous example, you could use asserts to test if you understand what the result from a shift should be.

Your ultimate goal is to write code to generate the results of these operations in the file called shifts.c that contains a main() and uses functions from binary_convert.h/c, which is already provided.

### Note

The important thing to note here is that unsigned numbers are shifted right logically and that signed numbers are shifted right arithmetically.

First, note that you can get the value 0XC3 as shown in the table by declaring a variable like this:

``` unsigned char x = 0xC3; ```

Next, note what happens when we cast that value to a signed variable instead:

``` signed char y = x;  // signed keyword is not strictly necessary ```

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
 
