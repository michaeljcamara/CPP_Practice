/**
 * "Reshaping" an array in C99. This program takes a 6 by 4 array of
 * integers and "reshapes it" to a 3 by 8, 12 by 2, and 1 by 24 array
 * using C99's 'resizable array' feature. (We are not actually reshaping the
 * original array, but instead we are viewing it differently!)
 *
 * To compile and run this, saving executable in a.out:
 *       gcc  -std=gnu99  array3.c
 *       ./a.out
 */

#include <stdio.h>

/* FUNCTION PROTOTYPE: */
void f(int r,int c, int a[r][c]);


int main() {
  int a[6][4];
  int row,col;

  printf("Contents of a[4][6] in main:\n");
  for (row = 0; row < 6; row++) {
    for (col = 0; col < 4; col++) {
      a[row][col] = 4*row+col+1;
      printf("%3d",a[row][col]);
    }
    printf("\n");
  }

  f(3,8,a);
  f(12,2,a);
  f(1,24,a);
}

/* f(r,c,a)  prints out the contents of array a as though it had
 * r rows and c columns.
 *
 * In order to use C99's resizable array feature, you MUST put the
 * array sizes (in this case, r and c) BEFORE the array in the
 * parameter list.
 */
void f(int r, int c, int a[r][c]) {
  int row, col;

  printf("Contents of a[%d][%d] in f:\n",r,c);
  for (row = 0; row < r; row++) {
    for (col = 0; col < c; col++) {
      printf("%3d",a[row][col]);
    }
    printf("\n");
  }
}
