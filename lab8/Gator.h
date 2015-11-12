///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 8: Object Oriented Programming
// Due Date: 11/12/15
///////////////////////////////////////////////////////////////

#include <string>
using namespace std;

/* Header file for the Gator class*/

class Gator {
public:
	// Constructor: create Gator with name, n, and color, c
	Gator(string n, string c);

	// Constructor: Create Gator with name, n, and default color, green
	Gator(string n);

	string getName();			// Return Gator's name
	string getColor();			// Return Gator's color
	string getHobby();			// Return Gator's hobby
	void setName(string c);		// Change Gator's name
	void setColor(string c);	// Change Gator's color
	void setHobby(string c);	// Change Gator's hobby
private:
	string color;				// Color of the Gator
	string name;				// Name of the Gator
	string hobby;				// Hobby of the Gator

	// Create a hobby based on length of name, n
	string generateHobby(string n);
};
