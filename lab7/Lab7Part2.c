///////////////////////////////////////////////////////////////
// Michael Camara
// Honor Code Pledge: This work is mine unless otherwise cited
// Lab 7: Functions, Part 2
// Due Date: 11/12/15
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

/**
 * f1 multiples the floor of x with the ceiling of x
 **/
int f1(double x) {
    return floor(x) * ceil(x);
}

/** 
 * f2 finds the power of 2 that most closely matches the double, x.
 * E.g. f2(70.5) = 64, since 70.5 is bounded by 2^6 (64) and 2^7 (128), and
 * 64 is closer to 70.5 than 128.
 **/
int f2(double x) {

    // Store the powers of two that bound x above and below it
    int lowerBound = 0;
    int upperBound = 0;

    // Iterate through powers of 2 until x is exceeded
    for(int count = 0; upperBound < x; count++) {
        lowerBound = upperBound;
        upperBound = pow(2, count);
    }

    // Return the bound that is closest to the value of x
    // Note: if the distance is equal, lowerBound is chosen by default
    if((upperBound - x) < (x - lowerBound)) {
        return upperBound;
    }
    else {
        return lowerBound;
    }
}

/** 
 * f3 first assesses whether the floor of x is even or odd.  If even,
 * then it returns x multipled by 10; if odd, it returns x divided by 10.
 **/
int f3(double x) {

    if(((int) floor(x)) % 2 == 0) {
        return x * 10;
    }
    else {
        return x / 10;
    }
}
/**
 * calc takes the product of two values returned by the function, f.
 * The first value uses f with the argument (a % 7 * 1.5), and the second
 * value uses f with the argument (b * 3.3).  Scientists have yet to find
 * a useful application for this function.
 **/
double calc(int (*f)(double), int a, int b) {
    return f(a % 7 * 1.5) * f(b *3.3);
}

/**
 * Use the calc function with a variety of values for f, a, and b.
 **/
int main() {
    printf("Use calc with f = f1, a = 509, b = 40: %f\n", calc(f1, 509, 40));
    printf("Use calc with f = f2, a = 732, b = 17: %f\n", calc(f1, 732, 17));
    printf("Use calc with f = f3, a = 37, b = 4: %f\n", calc(f1, 37, 4));
}
