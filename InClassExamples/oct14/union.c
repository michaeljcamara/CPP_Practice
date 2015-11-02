/**
 * Bob Roos
 * Examples of the "union" and "enum" types in C
 */
#include <stdio.h>

/* This is an example of a union type in C. All of the variables 
   in a union share the same memory! */
union myunion { 
  int i,j,k;
  float f,g;
};

/* This is an enum type. It assigns symbolic names to integer values */

enum weekday {mon,tue,wed,thu,fri,sat,sun}; /* by default, use 0,1, ... */

enum summermonth {jun=6,jul=7,aug=8}; /* we can specify the integers */


int main() {
  union myunion x;
  enum weekday d,e;
  enum summermonth s;

  x.i = 76567;
  printf("i = %d, j = %d, k = %d\n", x.i, x.j, x.k);
  x.f = 2.71828;
  printf("f = %f, g = %f, i = %d\n", x.f, x.g, x.i);
  x.j = 0;
  printf("f = %f, g = %f, i = %d\n", x.f, x.g, x.i);
  d = mon;
  e = tue;
  s = aug;
  printf("d = %d, e = %d, s = %d\n",d,e,s);
}
