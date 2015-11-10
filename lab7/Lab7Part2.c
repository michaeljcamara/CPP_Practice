/**
 * Bob Roos
 * Sample program to accompany lab 7
 *
 * Demonstration of functions as arguments to a function
 *
 * You will imitate this program in the lab assignment.
 */
#include <stdio.h>
#include <math.h>

/********
 * sqr takes an integer x and returns  x squared.
 *******/
int sqr(int x) { return x*x; }

/********
 * cube takes an integer x and returns  x cubed.
 *******/
int cube(int x) { return x*x*x; }

/********
 * weird takes an integer x and returns  either x^2+x or 10x-x^2,
 * depending on whether x is less than 5 or not.
 *******/
int weird(int x) { if (x < 5) return x*(x+1); else return x*(10-x); }

/********
 * avg finds the average of f(a) and f(b) for some int-valued function f 
 * and two integers a and b.
 *******/
double avg(int (*f)(int), int a, int b) {
  return (f(a)+f(b))/2.0;
}

/**
 * f1 multiples the floor of x with the ceiling of x
 **/
int f1(double x) {
    return floor(x) * ceil(x);
}

/** 
 * f2 finds the power of 2 that most closely matches the double, x
 * E.g. f2(70) = 64, since 2^6 (64) is closer to 70 than 2^7 (128)
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

double calc(int (*f)(double), int a, int b) {
    return f(a % 5) * f(b *3);

}

int main() {
    printf("avg of 15^2 and 20^2 is %f\n",avg(sqr,15,20));

    printf("avg of 15^3 and 20^3 is %f\n",avg(cube,15,20));

    printf("avg of weird(15) and weird(3) is %f\n",avg(weird,15,3));

    printf("Closest power of two for 70 is %d\n",f2(3));

    printf("Calc result using f1: %f\n", calc(f1, 500, 40));
    printf("Calc result using f2: %f\n", calc(f2, 100, 35));
    printf("Calc result using f3: %f\n", calc(f3, 10, 3));
}
