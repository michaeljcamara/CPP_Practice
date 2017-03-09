/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose: This file shows how C++ permits multiple inheritance of classes
 *****************************************************************************/

#include <iostream>
using namespace std;

// This base class contains a unique function, f, and sharedFunction(),
// which shares a name with the sharedFunction() in ParentB and ParentC
class ParentA {
public:
	void f() {
		cout << "This is from ParentA\n";
	}
	void sharedFunction() {
		cout << "sharedFunction() from ParentA\n";
	}
};

// This base class contains a unique function, g, and sharedFunction(),
// which shares a name with the sharedFunction() in ParentA and ParentC
class ParentB {
public:
	void g() {
		cout << "This is from ParentB\n";
	}

	void sharedFunction() {
		cout << "sharedFunction() from ParentB\n";
	}
};

// This base class contains a unique function, h, and sharedFunction(),
// which shares a name with the sharedFunction() in ParentA and ParentB
class ParentC {
public:
	void h() {
		cout << "This is from ParentC\n";
	}

	void sharedFunction() {
		cout << "sharedFunction() from ParentC\n";
	}
};

// This class extends ParentA and ParentB and ParentC
class Child : public ParentA, public ParentB, public ParentC {
public:
	void i() {
		cout << "This is from Child\n";
	}
};

// Call inherited methods from the Child class
int main() {
	Child c = Child();
	c.f();  // "This is from ParentA"
	c.g();  // "This is from ParentB"
	c.h();  // "This is from ParentC"
	c.i();  // "This is from Child"
//	c.sharedFunction(); //ERROR: sharedFunction() is ambiguous
}
