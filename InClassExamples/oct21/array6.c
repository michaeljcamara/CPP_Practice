/**
 * Bob Roos
 * Demonstration of malloc, pointers, and simulated arrays.
 *
 * User enters three sizes, program creates an area of memory
 * that can be treated as a three-dimensional array with those dimensions.
 *
 * Instead of using actual indexing with "[]", use an index calculation formula.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  double *a;  /* points to a "three-dimensional array" (but not really) */
  int m,n,p;  /* dimensions of the "array" */
  int i,j,k;  /* loop indices */

  printf("What are the array dimensions (three positive integers)? ");
  scanf("%d %d %d",&m,&n,&p);

  /* Allocate enough memory to hold an m by n by p array of doubles: */
  a = (double *)malloc(m*n*p*sizeof(double));

  printf("Elements in a:\n");
  for (i=0; i < m; i++) {
    for (j=0; j < n; j++) {
      for (k = 0; k < p; k++) {
        /* a[i][j][k] = *(a + i*n*p + j*p +k) */
        *(a+i*n*p+j*p+k) = (i*n*p+j*p+k)/10.0;
        printf("%5.1f",*(a+i*n*p+j*p+k));
      }
      printf("\n");
    }
    printf("\n");
  }

  /* C no longer knows the array dimensions: it merely prints out
     the amount of space needed for a pointer:
  */
  printf("Size of a: %ld\n",sizeof a);
} 
