#include <iostream>
using namespace std;

// Simple utility function to print out values of an int[] array
void printArray(const int (&intArray)[10]) {
	cout << "\nintArray = {";
	for(int i = 0; i < 10; i++) {
		if(i > 0) cout << ", ";
		cout << intArray[i];
	}
	cout << "}\n";
}

// This function shows some simple applications of pointers
void simplePointers() {

	// Pointers are declared using the unary asterisk ("*")
	cout << "Begin simplePointers():" << endl << endl;
	int valueX, valueY;
	int *pointerA, *pointerB;

	//--------------------------------------------------------------------------------------//
	// Pointers can be assigned to the memory address of a variable using the
	// unary address-of operator ("&") to prefix the target location
	valueX = 10;
	pointerA = &valueX;

	cout << "valueX = " << valueX << endl;
	cout << "*pointerA = " << *pointerA << endl;
	cout << "pointerA = " << pointerA << endl << endl;

	//--------------------------------------------------------------------------------------//
	// When the element in the memory address is directly changed, then
	// the pointer to that memory address should likewise reflect the change
	valueX = 20;

	cout << "valueX = " << valueX << endl;
	cout << "*pointerA = " << *pointerA << endl;
	cout << "pointerA = " << pointerA << endl << endl;

	//--------------------------------------------------------------------------------------//
	// The pointer can be dereferenced, again using the * operator,
	// to access and manipulate the value stored in its target memory address
	*pointerA = 30;

	cout << "valueX = " << valueX << endl;
	cout << "*pointerA = " << *pointerA << endl;
	cout << "pointerA = " << pointerA << endl << endl;

	//--------------------------------------------------------------------------------------//
	// A pointer's target memory address can be quickly and easily changed,
	// again using the & operator for a different variable
	pointerA = &valueY;
	valueY = 40;

	cout << "valueX = " << valueX << endl;
	cout << "valueY = " << valueY << endl;
	cout << "*pointerA = " << *pointerA << endl;
	cout << "pointerA = " << pointerA << endl << endl;

	//--------------------------------------------------------------------------------------//
	// Pointers can reference other pointers, and simple equality comparisons
	// can be used on them to determine if they target they same memory address
	pointerB = pointerA;
	bool isEqual = pointerB == pointerA;

	cout << "valueX = " << valueX << endl;
	cout << "valueY = " << valueY << endl;
	cout << "*pointerA = " << *pointerA << endl;
	cout << "pointerA = " << pointerA << endl;
	cout << "*pointerB = " << *pointerB << endl;
	cout << "pointerB = " << pointerB << endl;
	cout << "(pointerB == pointerA) = " << isEqual << endl << endl;
}

// This function shows how pointers can be used effectively with arrays
void arrayPointers() {

	// Create an empty (zero-initialized) int array and set pointer to first memory address
	cout << "Begin arrayPointers():" << endl;
	int intArray[10] = {};
	int *pointerC = &intArray[0];

	printArray(intArray);
	cout << "*pointerC = " << *pointerC << endl;
	cout << "pointerC = " << pointerC << endl;

	//--------------------------------------------------------------------------------------//
	// Change value of element at pointerC's memory address (intArray[0]) by dereferencing it
	*pointerC = 10;

	printArray(intArray);
	cout << "*pointerC = " << *pointerC << endl;
	cout << "pointerC = " << pointerC << endl;

	//--------------------------------------------------------------------------------------//
	// Increment the pointer location to the next memory address (i.e. intArray[1]),
	// then change value of the element to 20
	pointerC++;
	*pointerC = 20;

	printArray(intArray);
	cout << "*pointerC = " << *pointerC << endl;
	cout << "pointerC = " << pointerC << endl;

	//--------------------------------------------------------------------------------------//
	// Move pointer to the absolute 5th index of the intArray, then change value to 30
	pointerC = &intArray[5];
	*pointerC = 30;

	printArray(intArray);
	cout << "*pointerC = " << *pointerC << endl;
	cout << "pointerC = " << pointerC << endl;

	//--------------------------------------------------------------------------------------//
	// Access memory address 2 elements "ahead" of current pointer address and change value to 40
	// **NOTE: pointerC's memory address does not change after this statement
	pointerC[2] = 40;

	// Access memory address 2 elements "behind" current pointer address and change value to 40
	// **NOTE: pointerC's memory address does not change after this statement
	pointerC[-2] = 50;

	printArray(intArray);
	cout << "*pointerC = " << *pointerC << endl;
	cout << "pointerC = " << pointerC << endl;
}

// Main method: begin with simplePointers(), then arrayPointers()
int main() {
	simplePointers();
	arrayPointers();
}
