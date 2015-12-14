/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose: This file shows how scoping works in C++ by providing many identical
 * functions that are each nested in different constructs.
 *****************************************************************************/

#include <iostream>

// A globally accessible namespace with a single nested class
namespace SomeLibrary {

// A nested class within a defined namespace
class SomeClass {

public:
	int someFunction() {
		x = 5;
		return x;
	}

private:
	int x;
};

// A nested variable within a defined namespace
int x;

// A nested function within a defined namespace
int someFunction() {
	x = 10;
	return x;
}

};

// A locally defined class
class WithinScopeClass {
public:
	int someFunction() {
		x = 15;
		return x;
	}

private:
	int x;
};

const int x = 100;

int someFunction() {
	int x = 20;
	return x;
}

int main() {

	// Note the use of the scope resolution operator (::) to target specific functions
	int x = SomeLibrary::SomeClass().someFunction();//Target class within SomeLibrary namespace
	std::cout << "x: " << x;                      //x = 5
	int x2 = SomeLibrary::someFunction();           //Target function within SomeLibrary namespace
	std::cout << "\nx2: " << x2;                  //x = 10
	int x3 = WithinScopeClass().someFunction();     //Target function of class in global namespace
	std::cout << "\nx3: " << x3;                  //x = 15
	int x4 = someFunction();                        //Target function in global namespace
	std::cout << "\nx4: " << x4;                  //x = 20

	// ERROR: SomeClass is nested within SomeLibrary namespace and is out of scope
	// unless scope resolution operator ("::") is used to specify namespace
	//int x = SomeClass().someFunction();

	//ERROR: OutsideScopeClass is not in scope of main() since it is declared lexically after main()
	//int z = OutsideScopeClass().someFunction();

	int cout = 1;						// Declare local variable, coincidentally named cout
	std::cout << "\nLocal x: " << x; 	// Global x being shadowed by local x
	std::cout << "\nGlobal x: " << ::x; // :: used to specify global x

	//ERROR: Need to specify cout from std namespace. This targets the local int cout declaration
	//cout << "\nLocal x: " << x;

	{
		int x = 25;	// Destroyed after execution leaves this nested block
		std::cout << "\nNested x: " << x; // Nested x shadows local x
	}

	std::cout << "\nLocal x: " << x; // Nested x declaration does not affect local x
}

// This class is outside of the scope of anything that appears before it lexically,
// including the main() function.
class OutsideScopeClass {
public:
	int someFunction() {
		x = 10;
		return x;
	}

private:
	int x;
	std::string name;
};
