/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose: This file shows the very basic format of a C++ program
 *****************************************************************************/

// Allow access to the standard iostream library
#include <iostream>

// Allow any references to a std library to omit specific scope resolution
// operators (e.g. allow cout instead of std::cout)
using namespace std;

// Main function where program execution begins
int main() {

	// cout is the standard output stream for C++, << used to insert tokens into stream
	cout << "Hello, World!";

	// Return 0 if function exits normally; else indicate the function did not end normally
	return 0;
}
