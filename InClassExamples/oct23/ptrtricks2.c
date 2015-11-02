/**
 * Bob Roos
 * A pointer trick: converting a word to Pig Latin.
 * (Move the leading consonant group to the end and add "ay".)
 *
 * NOTE: the functions in <string.h> can do this more easily!
 */

#include <stdio.h>
#include <string.h>

int main() {
   char word[82]; /* The word to be converted */
   char *p;       /* Points to first vowel */
   int i;

   printf("Enter a lowercase word:\n");
   scanf("%s",word);

   /* Advance the pointer p through the word until the first vowel: */
   p = word;
   while(*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u')
     ++p;

   /* Print from vowel to the end of the word: */
   printf("%s",p);

   /* Now overwrite the vowel with a string terminator: */
   *p = '\0';

   /* Print the prefix consonant group followed by 'ay': */
   printf("%say\n",word);
}
