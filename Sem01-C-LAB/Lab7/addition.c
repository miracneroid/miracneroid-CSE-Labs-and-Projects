#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1, num2, sum;
    printf("Enter first number -> ");
    scanf("%d", &num1);

    printf("Enter second number -> ");
    scanf("%d", &num2);

    sum = num1 + num2;
    printf("Sum of numbers = %d\n", sum);

    return 0;
}
