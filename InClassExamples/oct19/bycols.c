/**
 * Bob Roos
 * bycols.c -- process a 2-dimensional array by columns.
 * This is part of an experiment to compare the speed of row vs column 
 * operations; the other part is in file "byrows.c".
 *
 * To compile and execute (with timing information):
 *    gcc bycols.c
 *    time ./a.out
 *
 * To save the executable under some other name:
 *    gcc bycols.c -o someothername
 *    time ./someothername
 */

int main() {
    int a[1000][1000];
    int r, c, k;

    for (k = 0; k < 1000; k++) {
       for (c = 0; c < 1000; c++) {
          for (r = 0; r < 1000; r++) {
             a[r][c] = r*c;
          }
       }
    }
}
