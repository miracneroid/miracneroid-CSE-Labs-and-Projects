#include <stdio.h>

int main(int argc, char const *argv[])
{
    double height, base, area;

    printf("Enter height of triangle -> ");
    scanf("%lf", &height);

    printf("Enter base of triangle -> ");
    scanf("%lf", &base);

    area = 0.5 * base * height;

    printf("Area of triangle -> %lf/n", area);

    return 0;
}