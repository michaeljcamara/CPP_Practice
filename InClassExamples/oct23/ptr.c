/**
 * Bob Roos
 * Simple demonstration of pointers in C
 */
#include <stdio.h>
int main() {
   int a = 20, b = 30;
   int *c;  /* pointer variable */

   c = &a;   /* “&” = “address of” */
   *c = 40;  /* “*” = “dereference” */

   c = &b;
   *c = 50;

   printf("a=%d,b=%d\n",a,b); /* a=40,b=50 */
}
