/**
 * Bob Roos
 *   Two-dimensional arrays in C++ (and C).  This demonstrates that
 *   arrays in C and C++ are stored in row-major order rather than
 *   column major order. It does this by overlaying a one-dimensional
 *   array over a two-dimensional array via a "union" structure.
 *
 * To compile and run using the standard "a.out" name for the executable:
 *     g++ -std=gnu++11  array2.cpp
 *     ./a.out
 *
 * (Or, if you prefer to give a different name to the executable:)
 *     g++ -std=gnu++11  array2.cpp -o someothername
 *     ./someothername
 */

#include <iostream>
#include <array>
#include <string>

using namespace std;


int main() {
  union {
     int i1[4][2];
     int i2[8];
  } i; // i contains space for either an int[8] array or an int [4][2] array

  cout << "Does C++ use row-major or column-major? Let's see:" << endl;
  cout << "Linear array i2 contains ";
  for (int j=0; j < 8; j++) {
    i.i2[j] = 10*(j+1);
    cout << i.i2[j] << " "; 
  }
  cout << endl;

  cout << "Printed row by row, here is the contents of 2-d array i1:" << endl;
  for (int j=0; j < 4; j++) {
    for (int k = 0; k < 2; k++) {
      cout << i.i1[j][k] << " "; 
    }
    cout << endl;
  }

}
 

