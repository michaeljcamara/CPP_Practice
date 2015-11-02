// Bob Roos
// Demonstration of recursion--computing binomial coefficients.
//
// See program "Binom2.java" for a closer look at what goes on.

public class Binom {

  // Main just calls binom(n,k) for various values of n and k:
  public static void main(String[] args) {
    for (int n = 0; n <= 8; n++) {
      for (int k = 0; k <= n; k++) {
        System.out.printf("%3d",binom(n,k));
      }
      System.out.println();
    }
  }

  // binom -- computes the binomial coefficient defined as:
  //        binom(n,k) = 1 if n == 0 or n == k  (base case)
  //        binom(n,k) = binom(n-1,k-1) + binom(n-1,k) otherwise
  //
  // This method is written in a slightly expanded form,
  // using several unnecessary temporary variables, to make
  // it easier to understand program Binom2.java

  public static int binom(int n, int k) {
    int retvalue, temp1, temp2;

    // Base case:
    if (k == 0 || k == n) {
       retvalue = 1;
    }
    else { // recursive case:
      temp1 = binom(n-1,k-1);
      temp2 = binom(n-1,k);
      retvalue = temp1+temp2;
    }
    return retvalue;
  }
}
