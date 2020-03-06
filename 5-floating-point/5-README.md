## Data Activity 5: Floating Point representation at the bit level

Folder: `5-floating-point`

The file fp_coding_ex.c contains some code designed to examine the bit-level encodings of floating point numbers. 

This line near the top of the file is a key aspect of the code:

    typedef unsigned float_bits;

We are going to look at how the machine actually treats the single precision floating point numbers by creating their bit patterns as unsigned integers. This typedef helps us use the moniker *float_bits* to refer to the bit-level representation of a float.

The makefile takes care compiling this example.

The code contains some functions from an early activity where we broke down data representations into their individual bytes. You may find these useful (see how `show_float` is used in main(), for example).

You should be able to compile and run this code as is.  Familiarize yourself with this code.  The function `float_denorn_zero()` provides you with an example of how the machine can manipulate the bits that make up the portions of a floating point number.  The unsigned data type, which is 32 bits long and is defined to have the name *float_bits*, represents how a 32-bit floating point number could be stored as a bit pattern.  Recall that the IEEE single precision representation has:

- leftmost, or most significant bit is sign bit

- next 8 bits for the ‘exp’ value

- next 23 bits, or the least significant 23 bits for the ‘frac’ value

For this activity, it is useful to also recall that the floating point numbers fall into several categories, each of which encodes the above pieces differently and which represent a range of possible represented values as follows:

![Floating Point Numberline](./img/FPRangeLine.png)

You will now investigate each of these encodings by considering their bit level representations, just like the machine does.

## Part 1: Denormalized values 

Your first task is to determine some positive and negative denormalized bit-pattern values for 32-bit single precision and test this function, float_denorm_zero(), with them.

Recall from class (see lecture notes on moodle) that numbers are represented using this equation:

<p>(–1)<sup>s</sup> &nbsp  x &nbsp M  &nbsp x  &nbsp 2<sup>E</sup></p>

In the case of denormalized values, which are used for small numbers, the exp bits are all zero.  

1. How is the exponent E computed for the *denormalized* numbers in 32-bit single precision representation?

2. How is the significand, M, encoded?


Refer to [this useful reference by Steve Hollasch](http://steve.hollasch.net/cgindex/coding/ieeefloat.html) as you try to determine some test cases for the `float_denorn_zero()` function.

Note the range of values for single precision numbers and note the range of the denormalized numbers and the normalized numbers.

Now determine for 32-bit single precision IEEE what the largest possible and smallest possible denormalized values are.  What would their bit patterns look like?  Write those down in answer to the following question.*Hint:* Look all the way through to the summary at the bottom of [the reference by Steve Hollasch](http://steve.hollasch.net/cgindex/coding/ieeefloat.html) mentioned above.

**Thought Exercise:** Determine for 32-bit single precision IEEE what the largest possible and smallest possible denormalized values are, both positive and negative.  Most importantly, write out the largest and smallest denormalized values in hex (and binary first, if you wish), both positive and negative.

Your goal is to try the largest and smallest denormalized numbers and other denormalized values in between them in the main function. You could do this by using show_bytes on a float value and then passing the reversed hex value into `float_denorn_zero()`. Or you could create the hex version of these directly.

Convert those bit patterns to hexadecimal values and try them in main, using `float_denorn_zero()` as illustrated in the code.  Try some additional values within the range of denormalized values.

## Part 2: Normalized numbers

Now let's turn our attention to the normalized numbers. Consider the following questions for review:

1.  How is the exponent E computed for the *normalized* numbers in 32-bit single precision representation?

2.  How is the significand, M, encoded?

Now determine the largest and smallest normalized values are, both positive and negative. What should their bit patterns look like?

Write down the largest and smallest normalized values in hex (and binary first, if you wish), both positive and negative.

Convert the largest and smallest normalized values, both positive and negative, into their hex values and test out `float_denorn_zero()`.


## Part 3: Infinity and NaN 

Test for infinity or NaN. How might you write a similar function to test whether a value is either infinity or NaN (not a number)?  Write this and test it out.

## Part 4: Negation

Complete the function called float_negate and test it in main(). This also illustrates how the machine would perform this operation.

## Part 5: Challenge

Do this if you really want a challenge: Generate range of possible values and check.

Suppose you wished to test out the full range of 32-bit patterns for floats. Recall from previous activities that we can use a pointer to unsigned char (`unsigned char*`) to inspect individual bytes of various types, including floats.  This was done in the show_bytes example code early in the semester and is provided again here.

Let’s start this process by creating a function that will create a float from its given bit pattern.

You should complete a function called `generate_float` that returns a float from a given input set of bits represented by the float_bits type.   You could choose to create a separate function for denormalized values and one for normalized values, or combine it in one.  In any case, you will need to create the float value using this rule given above:

<p>(–1)<sup>s</sup> &nbsp  x &nbsp M  &nbsp x  &nbsp 2<sup>E</sup></p>

where you compute M and E from the rules for IEEE single precision floating point.  You will need to use the exp and frac portions from the original bit pattern, along with the sign bit.

Note that once you have the floating point representation, you can check whether the bytes match your original bytes from the input bit pattern.  Add a check in main() that will check this for some bit patterns.

Now that this seems to work, you can use `generate_float` on a range of denormalized bit patterns in a loop and use assert to ensure that `float_denorn_zero()` returns what you expect. The you can try it for ranges of normalized numbers.
