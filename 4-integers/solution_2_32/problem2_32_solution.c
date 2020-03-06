#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/*
*  Libby Shoop
* Practice Problem 2.32
*/

/*
* First, 2.30 solution.
* The overflow casses to consider are 2 very negative numbers or 2
* very positive numbers, which might overflow.
*/
int tadd_ok(int x, int y) {
  int sum = x + y;  // we will check to see if this number seems amiss
  printf("sum: %x\n", sum);  //so we can see what is happening

  // x, y, are 2 negative 2's complement numbers.
  // When they are added, they should remain negative, unless
  // the result overflows, inwhich case sum >= 0, and
  // neg_over gets set to true.
  int neg_over = (x < 0  &&  y < 0)  &&  sum >= 0;

  // x, y, are 2 positive 2's complement numbers.
  // When they are added, they ought to be positive.
  // If the addition overflowed, then sum goes negative
  // and pos_over gets set to true.
  int pos_over = (x >= 0  && y >= 0)  &&  sum < 0;

  return !neg_over  && !pos_over;
}

/*
* BUGGY if try to simply use tadd_ok
* Determine if x - y can be subtracted without overflow.
*
* Return 1 if they can be subtracted without overflow and 0 if not.
*/

int tsub_ok(int x, int y) {
  // return tadd_ok(x, -y);     //doesn't work

  int sub = x - y;
  printf("sub: %x\n", sub);  //so we can see what is happening
  int neg_over = (x < 0  &&  y > 0)  &&  sub >= 0;
  int pos_over = (x >= 0  && y < 0)  &&  sub < 0;
  return !neg_over  && !pos_over;
}

void testItSub(int u, int v, bool shouldOverflow);
void testItAdd(int u, int v, bool shouldOverflow);

/*
 *  main()  to test out the above functions and demonstrate overflow
 */
int main() {
  int u, v;  // the number we will try in the above functions

  printf("Addition Tests ===================================\n");
  // try t_add_ok with some tests
  // 1. two high positive numbers
  u = 0x7FFFFFF0;
  v = 0x000000FF;  // enough to be slightly over when added to u

  printf("Case 1: High positive numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
  if (tadd_ok(u,v)) {
    printf("Addition was okay and did not overflow.\n");
  } else {
    printf("Addition overflow!\n");
  }

  // 2. two really large negative numbers
  u = 0xBFFFFFFF;
  v = 0xBFFFFFFE;
  printf("Case 2: Large negative numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
  if (tadd_ok(u,v)) {
    printf("Addition was okay and did not overflow.\n");
  } else {
    printf("Addition overflow!\n");
  }

  // 2a. just enough to go over
  u = 0xBFFFFFFF;
  v = 0xB0000001;
  printf("Case 2a: v is just negative enough: u = %x, v = %x, u+v = %x\n", u, v, u+v);
  if (tadd_ok(u,v)) {
    printf("Addition was okay and did not overflow.\n");
  } else {
    printf("Addition overflow!\n");
  }

  // 3. two positive numbers that should not overflow
  u = 0x00000070;
  v = 0x00FF0000;
  printf("Case 3:  Good positive numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
  if (tadd_ok(u,v)) {
    printf("Addition was okay and did not overflow.\n");
  } else {
    printf("Addition overflow!\n");
  }

  // 4. two negative numbers that should not overflow
  u = 0xFFFF0000;
  v = 0x80400000;
  printf("Case 4:  Good negative numbers, u = %x, v = %x, u+v = %x\n", u, v, u+v);
  if (tadd_ok(u,v)) {
    printf("Addition was okay and did not overflow.\n");
  } else {
    printf("Addition overflow!\n");
  }

  printf("Tests using limits.h values ====================\n");
  // Using a function instead of copying and pasting print statements
  // Using limits.h to our advantage to make testing easier
  // Tests:
  testItAdd(INT_MAX, 1, true);
  testItAdd(INT_MIN, -1, true);
  testItAdd(0, INT_MAX, false);
  testItAdd(INT_MAX, INT_MAX, true);
  testItAdd(INT_MAX/4, INT_MAX/4, false);
  testItAdd(INT_MAX * 0.75, INT_MAX * 0.75, true);
  testItAdd(INT_MIN/4, INT_MIN/4, false);
  testItAdd(INT_MIN * 0.75, INT_MIN * 0.75, true);


  printf("\nSubtraction Tests ===================================\n");
  //////////////////////////////////////
  // try t_sub_ok with some tests
  // What should they be?

  testItSub(INT_MIN, 1, true);
  testItSub(INT_MAX, -1, true);
  testItSub(0, INT_MIN, true);
  testItSub(INT_MIN, INT_MAX, true);
  testItSub(INT_MIN/4, INT_MAX/4, false);
  testItSub(INT_MAX * 0.75, INT_MIN * 0.75, true);
  testItSub(INT_MAX/4, INT_MIN/4, false);
  testItSub(INT_MIN * 0.75, INT_MAX * 0.75, true);

}

void testItSub(int u, int v, bool shouldOverflow) {
  if (shouldOverflow) {
    printf("%d - %d   should overflow\n", u,v);
  } else {
    printf("%d - %d   should not overflow\n", u,v);
  }
  if (tsub_ok(u, v)) {
    printf("This was OK\n");
  } else {
    printf("Subtraction overflow!\n");
  }
}

void testItAdd(int u, int v, bool shouldOverflow) {
  if (shouldOverflow) {
    printf("%d + %d   should overflow\n", u,v);
  } else {
    printf("%d + %d   should not overflow\n", u,v);
  }
  if (tadd_ok(u, v)) {
    printf("This was OK\n");
  } else {
    printf("Addition overflow!\n");
  }
}