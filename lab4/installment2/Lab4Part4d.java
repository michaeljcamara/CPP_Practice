///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 4: Control Structures (Installment 2)
// Due: 10/8/15
///////////////////////////////////////////////////////////////

public class Lab4Part4d {
    public static void main(String[] args) {

        // Print out all values for the recur method from 0 to 9
        for(int i = 0; i < 10; i++) {
            System.out.println("i = " + i + " | " + recur(i));
        }
    }

    /** Create a String sequence, s, of 0's and 1's given an index, i.  When
     * i = 0, s(i) = ""; when i = 1, s(i) = "1".  Otherwise, follow the formula
     * s(i) = s(i - 1) + "1" + t(i-1), where t(i-1) is the reverse of s(i-1), with
     * all 0's replaced by 1's and all 1's replaced by 0's.
     * 
     * @param i The current index
     * @return A string of 0's and 1's following the formula described above.
     */
    public static String recur(int i) {

        // Base case #1
        if(i == 0)
            return "";

        // Base case #2
        else if(i == 1)
            return "1";

        // Recursive case
        else {

            // Recursively call recur for the previous index
            String forward = recur(i-1);

            // Create a new string representing the reversed "forward" string, with
            // all 0's and 1's replaced with each other
            String reversedAndReplaced = "";
            for(int j = forward.length() - 1; j >= 0; j--) {
                char c = forward.charAt(j);
                if(c == '0')
                    reversedAndReplaced += "1";
                else if(c == '1')
                    reversedAndReplaced += "0";
                else
                    System.out.println("Something went horribly wrong!");
            }

            return forward + "1" + reversedAndReplaced;  
        }
    }
}

