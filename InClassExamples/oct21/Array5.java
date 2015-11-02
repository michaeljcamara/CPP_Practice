import java.util.Arrays;

public class Array5 {
  public static void main(String[] args) {
    int a[][] = new int[3][4];  // 3 by 4 array
    int b[][] = new int[3][];   // 3 by ?? array

    b[0] = new int[10];
    b[1] = new int[5];
    b[2] = new int[4];

    Arrays.fill(a[0],10);
    Arrays.fill(a[1],20);
    Arrays.fill(a[2],30);

    Arrays.fill(b[0],40);
    Arrays.fill(b[1],50);
    Arrays.fill(b[2],60);

    print("a=",a);
    print("b=",b);
  }

  public static void print(String s, int[][] x) {
    System.out.println(s);
    for (int[] row : x) {
      for (int i : row) {
        System.out.print(i+" ");
      }
      System.out.println();
    }
  }
}
