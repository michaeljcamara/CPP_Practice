#include <stdio.h>

int main() {
    

    int startNum = 4;
    int i = 4;
    int product = 1;
    printf("i = %d\n", i);



PRODUCT:
    product *= i;
    goto CONTINUE;

START:
    goto PRODUCT;

CONTINUE:
    i -= 1;
    printf("Product = %d\n", product);
    printf("i = %d\n", i);

    if(i > 1)
        goto START;
    
    goto FINISH;

FINISH:
    printf("FINISHED! Factorial of %d = %d\n", startNum, product);
}
