///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 4: Control Structures (Installment 2)
// Due: 10/8/15
///////////////////////////////////////////////////////////////

public class Lab4Part4a {
  public static void main(String[] args) {
    for (int i = 0; i <= 20; i++) {
      System.out.println("pow2("+i+") = "+pow2(i));
    }
  }

  // Calculate the value of 2 raised to the nth power
  public static int pow2(int n) {
    
    // Base case
    if(n <= 0)
        return 1;
    
    // Recursive case
    else
        return 2 * pow2(n - 1);
  }
}
