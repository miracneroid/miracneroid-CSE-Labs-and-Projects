/*
write a c program to take two number input from the user and add them.
*/

#include <stdio.h>

int main(){
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("The sum of %d and %d is %d\n", num1, num2, num1+num2);
    return 0;  
}