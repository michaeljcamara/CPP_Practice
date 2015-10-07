package lab4;

public class Lab4Part4c {

    public static int count = 0;
    public static void main(String[] args) {
        int[][] maze = createMaze();
        boolean asd = travel(maze, 0, 0);

        System.out.println(asd);

    }

    public static boolean travel(int[][] maze, int row, int col) {
        System.out.println(count++);
        printMaze(maze);
        System.out.println("row: " + row + ", col " + col);

        boolean exitFound = false;
        if(maze[row][col] == 0) {
            maze[row][col] = 5;
            return false;
        }
        else if(maze[row][col] == 8) {
            printMaze(maze);
            return true;
        }
        else if(maze[row][col] == 1){
            maze[row][col] = 3;
            if(col > 0) {
                exitFound = travel(maze, row, col - 1);
            }
            if(row > 0 && exitFound == false) {
                exitFound = travel(maze, row - 1, col);
            }
            if(col < maze[0].length - 1 && exitFound == false) {
                exitFound = travel(maze, row, col + 1);
            }
            if(row < maze.length - 1 && exitFound == false) {
                exitFound = travel(maze, row + 1, col + 1);
            }
        }

        return exitFound;
    }

    //	public static int[][] travel(int[][] maze, int row, int col) {
    //		System.out.println(count++);
    //		if(maze[row][col] == 0) {
    //			maze[row][col] = 5;
    //			return maze;
    //		}
    //		else if(maze[row][col] == 8) {
    //			return maze;
    //		}
    //		else {
    //			maze[row][col] = 3;
    //			if(col > 0) {
    //				maze = travel(maze, row, col - 1);
    //
    //				if(maze[row][col-1] == 8)
    //					return maze;
    //			}
    //			if(row > 0) {
    //				maze = travel(maze, row - 1, col);
    //				if(maze[row-1][col] == 8)
    //					return maze;
    //			}
    //			if(col < maze[0].length - 1) {
    //				maze = travel(maze, row, col + 1);
    //				if(maze[row][col+1] == 8)
    //					return maze;
    //			}
    //			if(row < maze.length - 1) {
    //				maze = travel(maze, row + 1, col + 1);
    //				if(maze[row+1][col] == 8)
    //					return maze;
    //			}
    //
    //			return maze;
    //		}
    //	}

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

    public static void printMaze(int[][] maze) {
        for(int row = 0; row < maze.length; row++) {
            for(int col = 0; col < maze[row].length; col++) {
                System.out.print(maze[row][col] + "\t");
            }

            System.out.println();
        }
    }
}

