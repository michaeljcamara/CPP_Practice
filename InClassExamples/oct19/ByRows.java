// Bob Roos
// ByRows.java -- process a Java array by rows
// Part of an experiment to compare speeds of row vs column operations.
// See ByCols.java for the other part.
//
// To compile and execute (with timing information):
//     javac ByRows.java
//     time java ByRows

public class ByRows {
  public static void main(String[] args) {
    int a[][] = new int[1000][1000];
    for (int k = 0; k < 1000; k++) {
      for (int r = 0; r < 1000; r++) {
        for (int c = 0; c < 1000; c++) {
          a[r][c] = r*c;
        }
      }
    }
  }
}
