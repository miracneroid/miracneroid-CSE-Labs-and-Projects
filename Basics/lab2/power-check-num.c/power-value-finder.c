/*
write a program to check the user inputed value is the power value of which number using logs

Hint : Use log, put number in the log base and then check the value is integer or not.

and then use pow function to check the value is equal to the user inputed value or not.
*/

#include <stdio.h>
#include <math.h>

int main() {
    double n;
    int isPower = 0;
    double logResult;
    printf("Enter a number: ");
    scanf("%lf", &n);

    for (int b = 2; ; b++) {
        logResult = log(n) / log(b);
        if (fabs(round(logResult) - logResult) < 1e-10) {
            printf("%.0f is a power of %d (%.0f^%d)\n", n, b, b, (int)round(logResult));
            isPower = 1;
            break;
        }
        if (b > sqrt(n)) {
            break;
        }
    }
    if (!isPower) {
        printf("%.0f is not a power of any number\n", n);
    }
    return 0;
}

