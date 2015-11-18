///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 9: Object Oriented Programming
// Due Date: 11/19/15
///////////////////////////////////////////////////////////////

/** 
 * This class creates several superheroes and then and compares their relative
 * strengths.  Can Batman ever, truly, beat Superman? Use this class to find out!
 *
 * To compile/run:
 * mcs TestSuperHeroes.cs SuperHero.cs -out:TestSuperHeroes
 * ./TestSuperHeroes
 */

using System;

class TestSuperHeroes {
    static void Main() {

        // Instantiate 4 well known superheroes (ages and ranks approximate)
        SuperHero superman = new SuperHero("Superman", 34, 1);
        SuperHero batman = new SuperHero("Batman", 35, 2);
        SuperHero flash = new SuperHero("Flash", 25, 3);
        SuperHero antman = new SuperHero("Antman", 30, 3);

        // Create an array of these superheroes
        SuperHero[] superHeroes = new SuperHero[4];
        superHeroes[0] = superman;
        superHeroes[1] = batman;
        superHeroes[2] = flash;
        superHeroes[3] = antman;

        // Print the name, age, and rank of each hero
        foreach(SuperHero hero in superHeroes) {
            Console.WriteLine(hero.toString());
        }
        Console.WriteLine();

        // Compare the ranks of each superhero
        compareRanks(superHeroes);

        // Inflict Superman with Kryptonite poisoning, because why not?
        Console.WriteLine("\nOh no! Superman has been afflicted with red, green, yellow, etc etc Kryptonite!\n");
        superman.Rank = 5;

        // Again compare the ranks of each superhero, given Superman's illness
        compareRanks(superHeroes);
    }

    /**
     * Compare the ranks of each combination of two superheroes (6 combinations total). This will
     * announce who can beat whom, or if they are equal in strength.
     */
    private static void compareRanks(SuperHero[] superHeroes) {
        
        // Iterate through all superheroes
        for(int i = 0; i < superHeroes.Length; i++) {

            SuperHero first = superHeroes[i];

            // Iterate through all subsequent superheroes
            for(int j = i+1; j < superHeroes.Length; j++) {

                SuperHero second = superHeroes[j];

                // If equal rank, then equal strength, no one wins
                if(first.Rank == second.Rank) {
                    Console.WriteLine(first.Name + " and " + second.Name + " are roughly equal in strength");
                }
                // If the first's rank is greater than the second's rank, then the first is weaker
                else if(first.Rank > second.Rank) {
                    Console.WriteLine(second.Name + " can beat " + first.Name);
                }
                // If the first's rank is lower than the second's rank, then the second is weaker
                else if(first.Rank < second.Rank) {
                    Console.WriteLine(first.Name + " can beat " + second.Name);
                }
            }
        }
    }
}
