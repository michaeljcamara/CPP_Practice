/**
 * "Reshaping" an array in older versions of C. This takes a 6 by 4 array of
 * integers and "reshapes it" to a 3 by 8, 12 by 2, and 1 by 24 array
 * using "pointer arithmetic". (We are not actually reshaping the
 * original array, but instead we are viewing it differently!)
 *
 * To compile and run this, saving executable in a.out:
 *       gcc  array4.c
 *       ./a.out
 */

#include <stdio.h>

/* FUNCTION PROTOTYPE: */
void f(int **a, int r,int c);

int main() {
  int a[6][4];
  int row,col;

  printf("Contents of a in main:\n");
  for (row = 0; row < 6; row++) {
    for (col = 0; col < 4; col++) {
      a[row][col] = 4*row+col+1;
      printf("%3d",a[row][col]);
    }
    printf("\n");
  }

  /* To be able to use pointers we must cast f as an "int **": */
  f((int **)a,3,8);
  f((int **)a,12,2);
  f((int **)a,1,24);
}

/* f(a,r,c)  prints out the contents of array a as though it had
 * r rows and c columns.
 */
void f(int **a, int r, int c) {
  int row, col;

  printf("Contents of a in f:\n");
  for (row = 0; row < r; row++) {
    for (col = 0; col < c; col++) {
      /* Note the messy pointer expression we must use! */
      printf("%3d", *((int *)a+row*c)+col);
    }
    printf("\n");
  }
}
