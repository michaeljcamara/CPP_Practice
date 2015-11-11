///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 7: Functions, Part 4
// Due Date: 11/12/15
///////////////////////////////////////////////////////////////

import java.util.*;
import java.util.function.*;

public class Lab7Part4 {
    public static void main(String[] args) {

        // Rotate a String by specified number and return the rotated String
        BiFunction<Integer,String,String> rotateThis = (num, name)->name.substring(num) + name.substring(0, num);

        // Rotate a starting name completely around
        String name = "Michael";
        System.out.println("Rotating " + name + " around and around!");
        for(int i = 0; i < name.length()+ 1; i++ ) {
            System.out.println(rotate(i, name, rotateThis));
        }

        // Determine if a character is a vowel (true) or not (false)
        Function<Character,Boolean> isVowel = letter->letter.toString().matches("[aeiou]");

        // Return a random character from an array of vowels
        Function<char[],Character> getRandVowel = vowels->vowels[(int) (Math.random() * 5)];

        // Return a random character from an array of consonants
        Function<char[],Character> getRandConsonant = consonants->consonants[(int) (Math.random() * 21)];

        // Create and print 6 randomly generated names
        System.out.println("\nCreating 6 randomly generated names!");
        for(int sizeName = 4; sizeName < 10; sizeName++) {
            String randomName = createName(sizeName, isVowel, getRandVowel, getRandConsonant);
            System.out.println(randomName);
        }
    }

    /** Create a randomly generated name that probably won't make any sense.
     * Uses the isVowel, getRandVowel, and getRandConsonant functions to create a name
     * of size = sizeName.
     *
     * @param sizeName The desired size of the generated name.
     * @param isVowel Checks to see if a character is a vowel
     * @param getRandVowel Chooses a random char from an array of vowels
     * @param getRandConsonant Chooses a random char from an array of consonants
     * @return The randomly generated name
     * */
    public static String createName(
            int sizeName,
            Function<Character,Boolean> isVowel,
            Function<char[],Character> getRandVowel,
            Function<char[],Character> getRandConsonant) {

        // Create arrays of all vowels and of all consonants
        char[] vowels = new char[5];
        char[] consonants = new char[21];

        // Iterate through these arrays to fill them with the appropriate characters
        for(char currentChar = 'a', v = 0, c = 0; currentChar <= 'z'; currentChar++) {

            // Use isVowel function to check if char is a vowel
            if(isVowel.apply(currentChar)) {
                vowels[v++] = currentChar;
            }

            // If not a vowel, it must be a consonant
            else {
                consonants[c++] = currentChar;
            }
        }

        // Create sizeName number of random letters for the generated name
        String newName = "";
        for(int i = 0; i < sizeName; i++) {

            int currentLen = newName.length();
            char previousChar = '0';

            // If this is the first character in name, randomly choose between
            // adding a vowel or a consonant
            if(currentLen ==0) {
                if(Math.random() < 0.5) {
                    newName += getRandVowel.apply(vowels);
                }
                else {
                    newName += getRandConsonant.apply(consonants);
                }
            }

            // Otherwise alternate between adding vowels and consonants
            else {
                previousChar = newName.charAt(i-1);

                // If the previous character was a consonant, add a random vowel
                if(isVowel.apply(previousChar) == false) {
                    newName += getRandVowel.apply(vowels);
                }

                // If the previous character was a vowel, add a random consonant
                else {
                    newName += getRandConsonant.apply(consonants);
                }
            }
        }

        return newName;
    }

    /** Apply the given rotateThis function on a String, name, to rotate it by num characters
     *
     * @param rotateThis Function that will rotate a String by a given int amount
     * @param name This String that will be rotated
     * @param num The number of characters to rotate name by
     * @return The rotated String */
    public static String rotate(int num, String name, BiFunction<Integer,String,String> rotateThis) {
        return rotateThis.apply(num, name);
    }
} 
