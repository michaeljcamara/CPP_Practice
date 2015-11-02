/**
 * Bob Roos
 * Example of the "struct" record type in C
 */

#include <stdio.h>
#include <string.h>

/* This is an example of a "struct" type in C. In other languages
   this is sometimes called a "record".
*/

struct person {
  char name[40]; /* person's name */
  int age;       /* person's age */
  double pay;    /* person's hourly pay rate */
};


struct animal {
  char species[40]; /* animal's species */
  int age;          /* animal's age */
};


int main() {
  struct person a,b;
  struct animal c,d;

  strcpy(a.name, "bob");
  a.age = 65;
  a.pay = 7.50;

  strcpy(b.name, "groot");
  b.age = 764;
  b.pay = 10.45;

  printf("name = %s, age = %d, pay = %5.2f\n",a.name,a.age,a.pay);
  printf("name = %s, age = %d, pay = %5.2f\n",b.name,b.age,b.pay);

  strcpy(c.species, "cat");
  c.age = 5;

  strcpy(d.species, "dog");
  d.age = 7;

  printf("species = %s, age = %d\n",c.species,c.age);
  printf("species = %s, age = %d\n",d.species,d.age);
}
