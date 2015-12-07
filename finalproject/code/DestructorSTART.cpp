/*
 * Michael Camara
 * CMPSC 220
 * Final Project
 * Honor Code Pledge: This work is mine unless otherwise cited
 */
#include <iostream>
#include <time.h>
#include <string>
#include <list>

using namespace std;

class ReallyBigObject {
public:
	ReallyBigObject() {
		 doubles = new list<double>(100000000);
	}
	~ReallyBigObject() {
		cout << "Destroying ReallyBigObject\n";
		delete doubles;
	}
private:
	list<double> *doubles;
};

// Three near-identical methods created that differ in how parameter passing is
// handled: either by value, by reference, or by const-reference
void passByValue(ReallyBigObject reallyBigObject) {
	cout << "Returning from passByValue()..." << endl;
}

void passByReference(ReallyBigObject &reallyBigObject) {
	cout << "Returning from passByReference()..." << endl;
}

void passByConstReference(const ReallyBigObject &reallyBigObject) {
	//doubles.push_back(0);  // ERROR: cannot alter since list declared as constant
	cout << "Returning from passByConstReference()..." << endl;
}

ReallyBigObject passAndReturnByValue(ReallyBigObject reallyBigObject) {
	cout << "Returning from passAndReturnByValue()..." << endl;
	return reallyBigObject;
}

ReallyBigObject & passAndReturnByReference(ReallyBigObject &reallyBigObject) {
	cout << "Returning from passAndReturnByReference()..." << endl;
	return reallyBigObject;
}

int main() {

	/**
	 * Create a large number of values to store in a list, then pass
	 * that list to methods using pass-by-value, pass-by-reference,
	 * and pass-by-const-reference techniques.  Timers are used to
	 * assess the difference in performance for each task.
	 */

	// Create start and end timers for each task
	time_t start, end;

	// First create the large list of values
	cout << "Creating large list of doubles..." << endl;
	start = time(0);
//	ReallyBigObject *reallyBigObject = new ReallyBigObject();
	ReallyBigObject reallyBigObject = ReallyBigObject();
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this list by value (i.e. copy the list within the scope of
	// passByValue() to use locally
	cout << "Passing list by value..." << endl;
	start = time(0);
	passByValue(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this list by reference (i.e. provide a copy of the memory
	// address for the list, which can then be accessed directly)
	cout << "Passing list by reference..." << endl;
	start = time(0);
	passByReference(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this list by const-reference (i.e. provide a copy of the
	// memory address for the list, but prevent any modification of the
	// list.)
	cout << "Passing list by const-reference..." << endl;
	start = time(0);
	passByConstReference(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	cout << "Passing list by value and returning by value..." << endl;
	start = time(0);
	ReallyBigObject tempObject1 = passAndReturnByValue(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	cout << "Passing list by reference and returning by reference..." << endl;
	start = time(0);
	ReallyBigObject tempObject2 = passAndReturnByReference(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;
}
