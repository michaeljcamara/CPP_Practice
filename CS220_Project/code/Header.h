/*****************************************************************************
 * Michael Camara
 * Honor Code Pledge: This work is mine unless otherwise cited
 * CMPSC220: Final Project (C++)
 *
 * Purpose:  This file is meant to be viewed alongside ClassesAndStructs.cpp.
 * It provides a template with declarations for members of the ExampleClass
 * while omitting any actual definitions.
 *****************************************************************************/

#include <string>

class ExampleClass {
public:
	ExampleClass(int x, std::string name);
	std::string getName();
	int getX();
	void setName(std::string name);
	void setX(int x);
private:
	int x;
	std::string name;
	void privateFunction();
};
