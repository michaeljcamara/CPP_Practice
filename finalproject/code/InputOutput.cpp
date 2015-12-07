#include <iostream>
#include <string>
#include <ostream>
#include <istream>
#include <iomanip>
#include <fstream>

using namespace std;

void simpleOutput() {
	int num = 10;
	string name = "Michael";
	char c = 'J';

	// Three equivalent formats for displaying the name output
	// Format 1;
	cout << num << endl;
	cout << name << endl;
	cout << c << endl;

	// Format 2.  Note the use of "chain operations" using <<
	cout << num << "\n" << name << "\n" << c << "\n";

	// Format 3;
	cout << num << endl << name << endl << c << endl;

	//----------------------------------------------------------------------//
	// Certain formatting tags can be used with cout to customize the output
	bool isTrue = true;
	bool isFalse = false;

	// Change the output of bool values from 1,0 to true,false
	cout << "Without boolalpha: " << "isTrue = " << isTrue << ", isFalse = " << isFalse << endl;			//output 1,0
	cout << "With boolalpha: " << boolalpha << "isTrue = " << isTrue << ", isFalse = " << isFalse << endl;  //output true,false

	// Enforce decimal representation of float values
	float x = 1;
	cout << "Without showpoint: " << x << endl;				// output 1
	cout << "With showpoint: " << showpoint << x << endl;	// output 1.00000
}

void simpleInput() {
	cout << "Begin simpleInput():\n";

	string name, food;
	int num;

	// "cin >>" gets input from the keyboard one token at a time
	// Note this delimits by spaces by default
	// e.g. if the string "two words" is typed by the user, "cin >> name" will only store
	// the first token ("two") into name.
	cout << "Enter your first name: ";
	cin >> name;
	cout << "Enter your favorite integer: ";
	cin >> num;
	cout << "Enter your favorite food: ";
	cin >> food;

	// The >> operator can be chained like the << operator to simplify input
	cout << "\nEnter your first name, your favorite number, and your favorite food in the format: "
			<< "name number food" << endl;
	cin >> name >> num >> food;  // store first token in name, the next in num, the last in food
	cout << "You entered: "
			<< "\nFirst Name: " << name
			<< "\nFavorite Number: " << num
			<< "\nFavorite Food: " << food;
}

void inputErrorHandling() {
	cout << "Begin inputErrorHandling():\n";
	int num;


	// cin will return 1 (true) if the input stream exits successfully,
	// or will return 0 (false) if an error is encountered
	cout << "Enter a number: ";
	cin >> num;
	if(!cin) {

		// cin.eof() == true if the stream reached the end of the file
		if(cin.eof()) {
			cout << "End of file reached";
		}

		// cin.bad() == true if it encountered some critical error that it likely cannot recover from
		else if(cin.bad()) {
			cerr << "Critical failure, aborting input operation";
		}

		// cin.fail() == true if there was some formatting error that occurred,
		// e.g. trying to store a char into an int variable
		else if(cin.fail()) {
			cout << "Incorrect input format. Try again using a valid number.";
		}
	}

	// cin.good() == true if no errors were encountered
	else if(cin.good()) {
		cout << "Congratulations! You followed the instructions!\n";
		cout << "You entered: " << num;
	}
}


int main() {

	simpleOutput();
	simpleInput();
	inputErrorHandling();

//	fileInputOutput();

}
