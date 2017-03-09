/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose: This file shows how parameter passing works in C++, as well as
 * showing copy constructors and destructors and have they are used with
 * "Resource Allocation Is Initialization" (RAII) in C++.
 *****************************************************************************/
#include <iostream>
#include <time.h>
#include <string>
#include <list>

using namespace std;


/**
 * Create a ReallyBigObject that requires significant memory, then pass
 * that object to functions using pass-by-value, pass-by-reference, and pass
 * by const-reference techniques.  Timers are used to assess the difference
 * in performance for each task.  A custom copy constructor has been created
 * for the object to show when it is copied, and a custom destructor for the
 * object shows when it is destroyed (i.e. deleted from memory).  Applicative
 * order evaluation is further represented in the final function call.
 */

class ReallyBigObject {
public:

	// Initialize object with a very large list of values
	//**NOTE**: The number of elements might need to be adjusted depending on your machine
	ReallyBigObject() {
		doubles = new list<double>(50000000);
	}

	// Copy constructor
	ReallyBigObject(const ReallyBigObject &obj) {
		cout << "Copying ReallyBigObject\n";
		doubles = new list<double>;
		*doubles = *obj.doubles;
	}

	// This function has no functional purpose.  Used to illustrate applicative
	// order parameter evaluation later on.
	int uselessFunction(int num) {
		cout << "uselessFunction() called\n";
		return num;
	}

	// Simple function to add a number to the object's data structure
	void addNum(int num) {
		doubles->push_back(num);
	}

	// Destructor
	~ReallyBigObject() {
		// Print statement used to show when destructor called during RAII
		cout << "Destroying ReallyBigObject\n";
		delete doubles;
	}
private:
	list<double> *doubles;
};

// Pass-by-value will copy the parameter for use within the function body
void passByValue(ReallyBigObject reallyBigObject) {
	cout << "Returning from passByValue()..." << endl;
}

// Pass-by-reference will directly access the memory location of the parameter
void passByReference(ReallyBigObject &reallyBigObject) {
	reallyBigObject.addNum(1);  	// Object editing allowed here
	cout << "Returning from passByReference()..." << endl;
}

// Pass-by-const-reference will directly access the memory location of the parameter,
// but prevent any alteration for that element
void passByConstReference(const ReallyBigObject &reallyBigObject) {
	//reallyBigObject.addNum(1);  // ERROR: cannot alter since object declared as constant
	cout << "Returning from passByConstReference()..." << endl;
}

// This function both passes and returns by value: it copies the parameter to use within
// the function body, then it creates *another* copy to return to the calling function.
ReallyBigObject passAndReturnByValue(ReallyBigObject reallyBigObject) {
	cout << "Returning from passAndReturnByValue()..." << endl;
	return reallyBigObject;
}

// This function shows how C++ uses applicative parameter evaluation, as any parameter chosen for
// unusedParameter will be evaluated prior to entering the function body, even though it is
// never used.
void applicativeEvaluation(const ReallyBigObject &reallyBigObject, int unusedParameter) {
	cout << "Returning from applicativeEvaluation()..." << endl;
}

// Program execution starts here
int main() {

	// Create start and end timers for each task
	time_t start, end;

	// First create the ReallyBigObject (significant memory space allocation)
	cout << "Creating really big object..." << endl;
	start = time(0);
	ReallyBigObject reallyBigObject = ReallyBigObject();
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this object by value (i.e. copy the object to use within the scope of passByValue()
	cout << "Passing object by value..." << endl;
	start = time(0);
	passByValue(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this object by reference (i.e. provide a copy of the memory address for the
	// list, which can then be accessed directly)
	cout << "Passing object by reference..." << endl;
	start = time(0);
	passByReference(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	// Pass this object by const-reference (i.e. provide a copy of the memory address
	// for the list, but prevent any modification of the
	// list.)
	cout << "Passing object by const-reference..." << endl;
	start = time(0);
	passByConstReference(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;

	//
	cout << "Passing object by value and returning by value..." << endl;
	start = time(0);
	ReallyBigObject tempObject1 = passAndReturnByValue(reallyBigObject);
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;


	// Pass the object again by const reference, but include a function call to uselessFunction()
	// as part of the passed arguments.  Even though this value is not used in the body of
	// applicativeEvaluation(), C++ will still evaluate it fully, showing applicative order evaluation
	cout << "Passing list by const-reference to show applicative order evaluation..." << endl;
	start = time(0);
	applicativeEvaluation(reallyBigObject, reallyBigObject.uselessFunction(1));
	end = time(0);
	cout << "Elapsed time: " << (end - start) << endl << endl;
}
