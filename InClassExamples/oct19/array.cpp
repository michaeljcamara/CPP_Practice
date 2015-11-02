/**
 * Bob Roos
 * Demonstration of arrays (two kinds) in C++
 * This simply shows how to declare ordinary (C-like) arrays as well
 * as "array containers" (C++ 2011), how to index elements, how to
 * compute sizes (NOTE: sizes are fixed at compile time!), how to
 * iterate over arrays.
 *
 * To compile and run using the standard "a.out" name for the executable:
 *     g++  -std=gnu++11  array.cpp
 *     ./a.out
 *
 * (Or, if you prefer to give a different name to the executable:)
 *     g++  -std=gnu++11  array.cpp  -o  someothername
 *     ./someothername
 */

#include <iostream>
#include <array>
#include <string>

using namespace std;

int main() {
  // First, "ordinary" arrays (similar to Java, C, many other languages:
  int i[] = {10, 20, 30, 40, 50, 60, 70};
  double d[] = {2.14159, 1.71828, 0.414, 0.732};
  string s[] = {"hello", "hi", "howdy", "g'day", "goodbye", "bye", "ta"};

  cout << "size of array i (in bytes): " << sizeof i << endl;
  cout << "size of array d (in bytes): " << sizeof d << endl;
  cout << "size of array s (in bytes): " << sizeof s << endl;

  // Use "[]" to index ordinary arrays:
  for (int j = 0; j < 4; j++) {
    d[j]++;
  }

  cout << "Contents of arrays i, d, and s:" << endl;
  for (int j : i) {
    cout << j << " ";
  }
  cout << endl;
  for (double j : d) {
    cout << j << " ";
  }
  cout << endl;
  for (string j : s) {
    cout << j << " ";
  }
  cout << endl;

  // Next, the "array" library (added to C++ in 2011)
  array<int,7> ia = {-10, -20, -30, -40, -50, -60, -70};
  array<double,4> da = {-4.14159, -3.71828, -2.414, -2.732};
  array<string,7> sa = {"olleh","ih","ydwoh","yad'g","eybdoog","eyb","at"};

  cout << "size of array ia: " << ia.size() << endl;
  cout << "size of array da: " << da.size() << endl;
  cout << "size of array sa: " << sa.size() << endl;

  // Use "[]" to index elements of the  array class:
  for (int j = 0; j < 4; j++) {
    da[j]++;
  }

  cout << "Contents of arrays ia, da, and sa:" << endl;
  for (int j : ia) {
    cout << j << " ";
  }
  cout << endl;
  for (double j : da) {
    cout << j << " ";
  }
  cout << endl;
  for (string j : sa) {
    cout << j << " ";
  }
  cout << endl;
}

