#include <stdio.h>
int main()
{
int n;
printf("Enter a number :- ");
scanf("%d ",&n);
double m=n/2;
if(m%10.0==5)
{
printf("\nIt is an odd number\n");
}
else
{
printf("\nIt is an even number\n");
}
}


