///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 8: Object Oriented Programming
// Due Date: 11/12/15
///////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "Gator.h"
#include "Lab8.h"
using namespace std;

/* Program execution begins here.  The user is queried for the names
 * of three gators.  Three Gator objects are instantiated, and then
 * a series of output is produced showing their colors changing and
 * indicating their preferred hobbies.
 */

int main() {

	// Ask user for the names of three Gators
	string name1, name2, name3;
	cout << "What is the first Gator's name?" << endl;
	cin >> name1;
	cout << "What is the second Gator's name?" << endl;
	cin >> name2;
	cout << "What is the third Gator's name?" << endl;
	cin >> name3;

	// Instantiate each Gator
	// (Note: One uses a predefined color, the others default to green)
	Gator gator1(name1, "red");
	Gator gator2(name2);
	Gator gator3(name3);

	// Announce the original colors of the Gators
	cout << gator1.getName() << "'s color before change: " << gator1.getColor() << endl;
	cout << gator2.getName() << "'s color before change: " << gator2.getColor() << endl;
	cout << gator3.getName() << "'s color before change: " << gator3.getColor() << endl << endl;

	// Change the color of each Gator
	gator1.setColor("yellow");
	gator2.setColor("purple");
	gator3.setColor("cyan");

	// Announce the altered colors of the Gators
	cout << gator1.getName() << "'s color after change: " << gator1.getColor() << endl;
	cout << gator2.getName() << "'s color after change: " << gator2.getColor() << endl;
	cout << gator3.getName() << "'s color after change: " << gator3.getColor() << endl << endl;

	// Announce the favorite hobbies of the Gators
	// (generated in the Gator constructor based on name length)
	cout << gator1.getName() << "'s favorite hobby is: " << gator1.getHobby() << endl;
	cout << gator2.getName() << "'s favorite hobby is: " << gator2.getHobby() << endl;
	cout << gator3.getName() << "'s favorite hobby is: " << gator3.getHobby() << endl;

}

