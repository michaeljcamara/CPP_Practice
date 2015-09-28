#include <stdio.h>
#include <stdlib.h>
int main() {
    int *i; // I is a pointer to an int

    i = (int *) malloc(4);
    *i = 99;
    printf("%d\n", *i);
    printf("%x\n", i);

    i = (int *) malloc(4);
    *i = 99;
    printf("%d\n", *i);
    printf("%x\n", i);

}   
