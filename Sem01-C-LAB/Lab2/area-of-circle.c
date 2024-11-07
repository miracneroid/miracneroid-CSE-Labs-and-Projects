#include <stdio.h>

int main(int argc, char const *argv[])
{
    double radius, area;

    printf("Enter radius of Circle -> ");
    scanf("%lf", &radius);

    area = 3.14*radius*radius;

    printf("Area of Circle -> %lf\n", area);

    return 0;
}
