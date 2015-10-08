///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 4: Control Structures (Installment 2)
// Due: 10/8/15
///////////////////////////////////////////////////////////////

public class Lab4Part4c {

    public static void main(String[] args) {

    	// Create the original maze
    	int[][] maze = createMaze();
        
        System.out.println("Use this key for interpreting the following mazes:");
        System.out.println("0 = a wall\n1 = an empty path that has NOT been traveled\n7 = a traveled path");
        System.out.println("8 = an undiscovered exit\n9 = a discovered exit");
        System.out.println("\nThe ORIGINAL maze:\n");
        printMaze(maze);
        
        // Travel through the maze!
        travel(maze, 0, 0);
        
        System.out.println("\nThe COMPLETED maze:\n");
        printMaze(maze);
        
    }

    // Travel through the created maze given a certain starting position
    public static boolean travel(int[][] maze, int row, int col) {
        
    	// Indicate whether the exit has been found yet
    	boolean exitFound = false;
    	
    	// If the traveler encounters a "wall," turn back
        if(maze[row][col] == 0) {
            return false;
        }
        
        // If the traveler encounters the "exit," mark this event and stop travelling
        else if(maze[row][col] == 8) {
        	maze[row][col] = 9;
            return true;
        }
        
        // If traveler encounters an "empty path"
        else if(maze[row][col] == 1){
        	
        	// Mark the current spot as a "traveled path"
            maze[row][col] = 7;
            
            // Try moving west by one space (if valid)
            if(col > 0) {
                exitFound = travel(maze, row, col - 1);
            }
            
            // Try moving north by one space (if valid)
            if(row > 0 && exitFound == false) {
                exitFound = travel(maze, row - 1, col);
            }
            
            // Try moving east by one space (if valid)
            if(col < maze[0].length - 1 && exitFound == false) {
                exitFound = travel(maze, row, col + 1);
            }
            
            // Try moving south by one space (if valid)
            if(row < maze.length - 1 && exitFound == false) {
                exitFound = travel(maze, row + 1, col);
            }
        }

        // Indicate whether the exit has been found during this run
        return exitFound;
    }

    // Create a two dimensional maze!  1 = empty path, 0 = wall.
    public static int[][] createMaze() {

        int [][] maze = {
            {1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 ,0},
            {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1 ,1},
            {1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0 ,0},
            {0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0 ,0},
            {0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 ,0},
            {1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1 ,0},
            {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1 ,1},
            {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0 ,1},
            {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1 ,1},
            {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0 ,0},
            {0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 ,8}				
        };

        return maze;
    }

    // Display the maze neatly to the user
    public static void printMaze(int[][] maze) {
        for(int row = 0; row < maze.length; row++) {
            for(int col = 0; col < maze[row].length; col++) {
                System.out.print(maze[row][col] + "\t");
            }
            System.out.println();
        }
    }
}
