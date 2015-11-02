/**
 * Bob Roos
 * Primitive linked list implementation with pointer variable "next"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This structure is a linked list node with a value and 
   a next pointer (compare to LL.java).
*/
struct node {
  char value[81];
  struct node *next; /* note that we explicitly declare it as a pointer */
};


int main() {
   struct node *first, *second, *third, *fourth;
   struct node *n;

   /* Allocate memory for the nodes: */
   first = (struct node *)malloc(sizeof (struct node));
   second = (struct node *)malloc(sizeof (struct node));
   third = (struct node *)malloc(sizeof (struct node));
   fourth = (struct node *)malloc(sizeof (struct node));

   /* The C operator "->" is used to access a field in a structure
      referenced by a pointer variable. It is shorthand for:
         (*first).value
   */
   strcpy(first->value,"first");
   first->next = NULL;
   strcpy(second->value,"second");
   second->next = first;
   strcpy(third->value,"third");
   third->next = second;
   strcpy(fourth->value,"fourth");
   fourth->next = third;

   n = fourth;
   while (n != NULL) {
      printf("%s\n",n->value);
      n = n->next;
   }
}
