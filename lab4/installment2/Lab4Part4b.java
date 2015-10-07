///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 4: Control Structures (Installment 2)
// Due: 10/8/15
///////////////////////////////////////////////////////////////

public class Lab4Part4b {
    public static void main(String[] args) {
        for (int i = 0; i <= 5; i++) {
            for (int j = 0; j <= 5; j++) {
                System.out.println("recur("+i+","+j+") = "+recur(i,j));
            }
        }
    }

    public static int recur(int i, int j) {

        // Base case #1
        if(i <= 0 || j <= 0)
            return 0;

        // Base case #2
        else if(i == j)
            return i;

        // Base case #3
        else if(i > j)
            return j;

        // Recursive case
        else
            return 2 * recur(i - 1, j) + recur(j - 1, i);

    }
}
