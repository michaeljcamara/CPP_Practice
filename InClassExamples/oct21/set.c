/**
 * Bob Roos
 * Demonstration of a simple "set" data type in C.
 * A set is defined over the integers from 0 through 63.
 * Each set is represented by a 64-bit "long" integer; each bit
 * stands for an element (i-th bit == 1 if and only if i is in the set)
 *
 * Sets in languages like Pascal were internally represented this way.
 */

#include <stdio.h>
#include <stdarg.h>

typedef long SET;

#define EMPTY 0

/* FUNCTION PROTOTYPES: */
void printset(SET s);
SET set(int n_arg,...);
SET un(SET s1, SET s2);
SET in(SET s1, SET s2);

int main() {
  SET s1, s2, s3, s4;

  s1 = set(5,0,2,4,5,6);
  s2 = set(8,1,2,3,5,6,7,8,61);
  s3 = set(10,1,1,1,3,3,3,50,49,33,28);

  printf("s1 = ");
  printset(s1);
  printf("\ns2 = ");
  printset(s2);
  printf("\ns3 = ");
  printset(s3);
  printf("\ns1 union s2 = ");
  printset(un(s1,s2));
  printf("\ns1 intersection s3 = ");
  printset(in(s1,s3));
  printf("\ns2 intersection s3 = ");
  printset(in(s2,s3));
  printf("\n");
}

/**
 * printset(s): provides a printed representation of the set s.
 * This is a slow function since it checks every one of the 64
 * possible elements to see if it is present in the set.
 */
void printset(SET s) {
  int i;
  int comma = 0;
  printf("{");
  for (i = 0; i < 64; i++) {
    if (s & (1L << i)) {
      if (!comma) {
        printf("%d",i);
        comma = 1;
      }
      else {
        printf(",%d",i);
      }
    }
  }
  printf("}");
}

/**
 * un(s1,s2): returns the union of s1 and s2.
 */
SET un(SET s1, SET s2) {
  return s1 | s2;
}

/**
 * in(s1,s2): returns the intersection of s1 and s2.
 */
SET in(SET s1, SET s2) {
  return s1 & s2;
}

/**
 * set(n, i1,i2,..., in): creates a set containing the n 
 * values i1,...,in.
 * NOTE: i1, ... in are assumed to be in the range 0,...,63. 
 * Duplicates are allowed--e.g., set(5,1,1,1,1,1) is a set 
 * containing the single element 1.
 *
 * This uses the C built-in functions va_start, va_arg, and va_end to
 * process the variable-length argument list.
 */
SET set(int n_args, ...){
  va_list ap; /* the argument list */
  SET result;
  int i;

  result = EMPTY;

  va_start(ap, n_args); /* initialize arg list iterator */
  for(i = 1; i <= n_args; i++) {
     result = result | (1L << va_arg(ap, int)); /* get next argument */
  }
  va_end(ap); /* close the arg list iterator */

  return result;
}
