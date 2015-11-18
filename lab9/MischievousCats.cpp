///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 9: Object Oriented Programming : Multiple Inheritance
// Due Date: 11/19/15
///////////////////////////////////////////////////////////////

/** This class uses multiple inheritance to combine two synergistic categories:
 * Cats and Mischievous beings.  The resulting MischievousCat exhibits characteristics
 * of both parent classes, and (unfortunately) the Mischievous cannot be taken
 * out of this MischievousCat once created.
 *
 * To compile/run:
 * g++ mult.cpp -o mult
 * ./mult
 */

#include <iostream>
using namespace std;

/** 
 * This parent class describes a standard cat, complete with name, breed, color, and age.
 * A standard cat could be good or bad, nice or naughty, obedient or mischievous; but this
 * class only focuses on the most basic of characteristics for *any* cat.
 */
class Cat {
    private:
        string name;
        string breed;
        string color;
        int age;
    public:
        // Constructor for providing values to instance variables
        Cat(string name, string breed, string color, int age) {
            this->name = name;
            this->breed = breed;
            this->color = color;
            this->age = age;
        }

        // Simple get methods for returning values
        string getName() { return name; }
        string getBreed() { return breed; }
        string getColor() { return color; }
        int getAge() { return age; }
};

/** 
 * This parent class describes any sort of mischievous being.  These beings are often
 * up to no good and like to play pranks on others.  Further, they might find themselves
 * mixed-up with the authorities, and therefore might have a number of arrests on their
 * record.
 */
class Mischievous {
    private:
        bool upToNoGood;        // Indicate if this being is "up to no good"
        string favoritePrank;   // Describe the being's favorite prank to pull
        int numArrests;         // Indicate how many criminal arrests it has had
    public:
        // Constructor for providing values to instance variables
        Mischievous(bool upToNoGood, string favoritePrank, int numArrests) {
            this->upToNoGood = upToNoGood;
            this->favoritePrank = favoritePrank;
            this->numArrests = numArrests;
        }

        // Simple get methods for returning values
        bool getUpToNoGood() { return upToNoGood; }
        string getFavoritePrank() { return favoritePrank; }
        int getNumArrests() { return numArrests; }
};

/**
 * This composite class inherits the qualities from both a Cat and a Mischievous being.
 * These truly heinous creatures often have trivial excuses for their pranks and misdemeanors,
 * and may or may not show any remorse for their actions.
 */
class MischievousCat: public Mischievous, public Cat {
    private:
        string excuse;
        bool showsRemorse;
    public:
        // Constructor for providing values to instance variables
        MischievousCat(string name, string breed, string color, int age,
                bool upToNoGood, string favoritePrank, int numArrests,
                string excuse, bool showsRemorse):
            Mischievous(upToNoGood, favoritePrank, numArrests),
            Cat(name, breed, color, age) {
                this->excuse = excuse;
                this->showsRemorse = showsRemorse;
        }

        // Simple get methods for returning values
        string getExcuse() { return excuse; }
        bool getShowsRemorse() { return showsRemorse; }

        // Print out all relevant info for this MischievousCat
        void printRapSheet() {
            cout << getName() << " is a " << getAge() << " year old " << getColor() << " " << getBreed() << " with " << getNumArrests() << " known arrests to date." << endl;
    cout << "Is he always up to no good? " << ((getUpToNoGood() == 1)?"Yes":"No") << ".  Is he remorseful? " << ((getShowsRemorse() == 1)?"Yes":"No") << endl;
    cout << "He always gives me the same excuse: " << getExcuse() << ".  Then he proceeds to " << getFavoritePrank() << "." << endl << endl;
        }
};

/** Begin program execution.  Two truly troublesome MischievousCats are instantiated (my cats), and
 * then their criminal records are exposed to the world.
 */
int main() {

    // Instantiate two very mischievous cats
    MischievousCat baxter("Baxter", "domestic short hair", "gray", 5,
            true, "jump on the counter", 3,
            "I'm a cat", false);
    MischievousCat dexter("Dexter", "domestic short hair", "orange", 5,
            true, "scratch the furniture", 4,
            "I'm a cat", false);

    // Announce their names...
    cout << "I have two cats: " << baxter.getName() << " and " << dexter.getName() << "." << endl << endl;

    // And then reveal their criminal records
    baxter.printRapSheet();
    dexter.printRapSheet();
}
