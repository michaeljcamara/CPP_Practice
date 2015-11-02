/**
 * Bob Roos
 * byrows.c -- process a 2-dimensional array by rows.
 * This is part of an experiment to compare the speed of row vs column 
 * operations; the other part is in file "bycols.c".
 *
 * To compile and execute (with timing information):
 *    gcc byrows.c
 *    time ./a.out
 *
 * To save the executable under some other name:
 *    gcc byrows.c -o someothername
 *    time ./someothername
 */

int main() {
    int a[1000][1000];
    int r, c, k;

    for (k = 0; k < 1000; k++) {
       for (r = 0; r < 1000; r++) {
          for (c = 0; c < 1000; c++) {
             a[r][c] = r*c;
          }
       }
    }
}
