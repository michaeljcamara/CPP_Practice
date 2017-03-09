/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose: This file is meant to be viewed alongside the Header.h file.  It
 * shows how classes can be defined with and without use of a header file,
 * the two ways in which objects can typically be instantiated, and how classes
 * and structs essentially differ.
 *****************************************************************************/

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

// Initialize functions of ExampleClass as defined in Header.h
// The scope resolution operator ("::") is used to indicate which
// class we are targeting; in this case, ExampleClass.
// Note the use of the "this" and "->" operators to specify members
// of this class implicitly.
ExampleClass::ExampleClass(int x, string name) {
	this -> x = x;
	this -> name = name;
}

int ExampleClass::getX() {
	return this -> x;
}

string ExampleClass::getName() {
	return this -> name;
}

void ExampleClass::setX(int x) {
	this -> x = x;
}

void ExampleClass::setName(string name) {
	this -> name = name;
}

void ExampleClass::privateFunction() {
	cout << "In privateFunction()" << endl;
}

// Cannot declare a function that was not specified in the header
/*
void ExampleClass::unspecifiedFunction() {
	cout << "In unspecifiedFunction()";
}
*/

// Classes can also be created without a linked header file
class AnotherClass {
public:
	AnotherClass(int y) { this -> y = y;}
private:
	int y;
};

// Structs are very similar to classes, without encapsulation
struct ExampleStruct {
	int x;
	string name;
	void someFunction() { cout << "In ExampleStruct" << endl; }
};

// Instantiate ExampleClass and ExampleStruct
int main() {

	// Instantiate ExampleStruct in the stack frame
	struct ExampleStruct s;
	s.x = 10;			// ALLOWED: able to directly access any variable
	s.name = "Fred";	// ALLOWED: able to directly access any variable
	s.someFunction();	// ALLOWED: able to directly access any function
	cout << s.x << endl << s.name << endl;

	// Instantiate ExampleClass object in the stack frame
	ExampleClass c = ExampleClass(5, "Bill");  // Create object in stack
	//c.x = 10;			// ERROR: cannot access private variable
	c.setX(10);
//	c.name = "Gary";	// ERROR: cannot access private variable
	c.setName("Fred");
//	c.privateFunction();// ERROR: cannot access private function

	// Instantiate pointer to ExampleClass object in stack frame
	// (pointer refers to object allocated in heap, due to "new" operator)
	ExampleClass *p = new ExampleClass(5, "Bill"); // Create object in heap
//	p->x = 10;			// ERROR: cannot access private variable
	p->setX(10);
//	p->name = "Fred";	// ERROR: cannot access private variable
	p->setName("Fred");
//	p->privateFunction();// ERROR: cannot access private function
}
