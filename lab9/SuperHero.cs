///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 9: Object Oriented Programming
// Due Date: 11/19/15
///////////////////////////////////////////////////////////////

/** 
 * This class represents a super-cool superhero!  Each superhero has a name,
 * age, and rank.  The rank refers to how powerful a superhero is compared to
 * other superheros, where rank 1 is the most powerful and higher ranks indicate
 * weaker superheros.
 *
 * To compile/run:
 * mcs TestSuperHeroes.cs SuperHero.cs -out:TestSuperHeroes
 * ./TestSuperHeroes
 */
class SuperHero {

    // The catchy name citizens use to address this superhero
    private string name;

    // The disclosed age of the superhero
    private int age;

    // The relative strength of this superhero (1 = most powerful)
    private int rank;

    // Constructor to set initial values for instance variables
    public SuperHero(string name, int age, int rank) {
        this.name = name;
        this.age = age;
        this.rank = rank;
    }

    // Property for name instance variable (read-only)
    public string Name {
        get { return name; }
    }

    // Property for age instance variable
    public int Age {
        get { return age; }
        set { age = value; }
    }

    // Property for rank instance variable
    public int Rank {
        get { return rank; }
        set { rank = value; }
    }

    // Provide a concise representation of this superhero's characteristics
    public string toString() {
        return name + " is " + age + " years old and is rank " + rank;
    }
}
