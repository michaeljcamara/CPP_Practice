/**
 * Bob Roos
 * A pointer trick: shifting the range of an array index 
 * NOTE: generally these "pointer tricks" are more dangerous to
 * use than in this fairly benign example!
 */

#include <stdio.h>
#define ARRAYSIZE 11

int main() {
   double a[ARRAYSIZE]; /* a = table of values of x**2 */
   int bound = ARRAYSIZE/2;
   double *b = &(a[bound]); /* b points to the middle element of a */
   int i;

   for (i = -bound; i <= bound; i++) { /* Note that i can be negative */
     b[i] = i*i;  /* We are using a negative index for this array! */
   }

   printf("Values of i squared, i = -%d ... +%d:\n",bound,bound);
   for (i = -bound; i <= bound; i++) { /* Note that i can be negative */
     printf("%4d %6.0f\n",i,b[i]);
   }
}
