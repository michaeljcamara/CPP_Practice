/* Verifying solution to in-class exercise (row major version) */

#include <stdio.h>
int main() {
  int a[3][4][2][5];
  int i, j, k, l;
  long base =  (long) &a;
  long addr, actual;

  printf("Array dimensions are [3][4][2][5].\n");
  printf("Enter i,j,k,l: ");
  scanf("%d %d %d %d", &i, &j, &k, &l);
  if (i < 0 || i > 2 || j < 0 || j > 3 || k < 0 || k > 1 || l < 0 || l > 4) {
     printf("Illegal index; try again!\n");
     return 0;
  }

  /* Calculate address using the formula: */
  addr = base + (i*4*2*5 + j*2*5 + k*5 + l) * sizeof(int);
  printf("Computed address of a[%d][%d][%d][%d] = %ld\n",i,j,k,l,addr);

  /* Compare to the actual address: */
  actual = (long) &(a[i][j][k][l]);
  printf("Actual address: %ld\n",actual);
  if (addr == actual)
    printf("The formula works\n");
  else
    printf("The formula fails\n");
} 
