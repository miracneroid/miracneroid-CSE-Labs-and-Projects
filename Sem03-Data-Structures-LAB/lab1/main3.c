#include <stdio.h>
int main()
{
int n;
printf("Enter a number");
scanf("%d",&n);
int m=n&1;
if(m!=n)
{
printf("\nEven number");
}
else
{
printf("\nOdd number");
}
return 0;
}
