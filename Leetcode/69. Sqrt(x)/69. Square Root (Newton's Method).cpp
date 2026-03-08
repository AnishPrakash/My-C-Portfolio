#include <stdio.h>
double mySqrtPrecision(double x) {
    if (x < 0) return -1.0; // Error for negative numbers
    if (x == 0) return 0.0;

    double guess = x;
    double epsilon = 0.00001; // The margin of error we accept

    // Loop until the difference between guess^2 and x is tiny
    while ((guess * guess - x) > epsilon || (guess * guess - x) < -epsilon) {
        // The Formula: average of (guess) and (x / guess)
        guess = 0.5 * (guess + x / guess);
    }

    return guess;
}

int main() {
    printf("Sqrt of 10 is: %f", mySqrtPrecision(10)); // Output: ~3.1622
    return 0;
}