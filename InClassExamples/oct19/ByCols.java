// Bob Roos
// ByCols.java -- process a Java array by columns
// Part of an experiment to compare speeds of row vs column operations.
// See ByRows.java for the other part.
//
// To compile and execute (with timing information):
//     javac ByCols.java
//     time java ByCols

public class ByCols {
  public static void main(String[] args) {
    int a[][] = new int[1000][1000];
    for (int k = 0; k < 1000; k++) {
      for (int c = 0; c < 1000; c++) {
        for (int r = 0; r < 1000; r++) {
          a[r][c] = r*c;
        }
      }
    }
  }
}
