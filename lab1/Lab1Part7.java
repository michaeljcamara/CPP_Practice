//*********************************************************************************
// Honor Code: The work I am submitting is a result of my own thinking and efforts.
// Michael Camara
// CMPSC 220 Fall 2015 (Professor Roos)
// Lab # 1
// Date: 9/10/15
// 
// Purpose: Understanding the Java compiler and bytecode
//
//*******************************************************************************

public class Lab1Part7 {

    public static void main(String[] args) {

        final int CONSTANT4 = 4;
        final int CONSTANT5 = 5;

        int constantFolding = 0;

        constantFolding = 4 * 5;
        constantFolding = CONSTANT4 * CONSTANT5; 
    }
}
