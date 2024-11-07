#include <stdio.h>

int main(int argc, char const *argv[])
{
    double centi, fahren;
    printf("Enter temperature in Centigrate -> ");
    scanf("%lf", &centi);

    fahren = (centi * 9/5) + 32;
    printf("Temperature in Fahrentine -> %.2lf\n", fahren);

    return 0;
}
