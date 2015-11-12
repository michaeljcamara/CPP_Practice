///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 8: Object Oriented Programming
// Due Date: 11/12/15
///////////////////////////////////////////////////////////////

#include "Gator.h"
#include <string>
using namespace std;

/* Gator is shorthand for an "alligator," which is a type of
 * reptile found in freshwater environments.  Although the alligators native
 * to the United States and China are typically green with no outstanding
 * characteristics, new reports suggest the emergence of a new strain
 * of Gator.  This group appears to utilize naming conventions, similar
 * to humans.  They further exhibit an array of color variations, including
 * red, purple, and cyan.  Perhaps most surprisingly, careful examination
 * of their daily routines reveal nuanced activities that can best be described
 * as "hobbies."  In order to account for this strange strain of alligator,
 * this Gator class was created to allow a user to represent such a creature
 * with a unique name, color, and hobby.
 */

/*
 * Instantiate Gator using given name and color.  Automatically
 * generate a hobby based on the length of the passed name.
 */
Gator::Gator(string n, string c) {
	Gator::name = n;
	Gator::color = c;
	Gator::hobby = generateHobby(n);
}

/*
 * Instantiate Gator using given name and default green color.
 * Automatically generate a hobby based on the length of the passed name.
 */
Gator::Gator(string n) {
	Gator::name = n;
	Gator::color = "green";
	Gator::hobby = generateHobby(n);
}

/*
 * Create a hobby for the Gator based on the length of its name.
 */
string Gator::generateHobby(string n) {

	// Choose from a static selection of options for hobbies,
	// based on the length of the name.
	string h = "";
	switch(n.length()) {
		case 4:
			h = "swimming";
			break;
		case 5:
			h = "biking";
			break;
		case 6:
			h = "singing";
			break;
		case 7:
			h = "doing absolutely nothing";
			break;
		case 8:
			h = "juggling";
			break;
		default:
			h = "programming in C++";
			break;
	}

	return h;
}

/*
 * Retrieve the name (string) of the Gator
 */
string Gator::getName() {
	return Gator::name;
}

/*
 * Retrieve the color (string) of the Gator
 */
string Gator::getColor() {
	return Gator::color;
}

/*
 * Retrieve the hobby (string) of the Gator
 */
string Gator::getHobby() {
	return Gator::hobby;
}

/*
 * Change the name of the Gator
 */
void Gator::setName(string c) {
	Gator::name = c;
}

/*
 * Change the color of the Gator
 */
void Gator::setColor(string c) {
	Gator::color = c;
}

/*
 * Change the hobby of the Gator
 */
void Gator::setHobby(string c) {
	Gator::hobby = c;
}
