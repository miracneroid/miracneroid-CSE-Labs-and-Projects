#include <stdio.h>  
int main()
{
int n;
printf("Enter a number :- ");
scanf("%d",&n);
int m=n%2;
if(m==0)
{
printf("\nIt is an even number \n");
}
else
{
printf("\nIt is an odd number \n");
}
return 0;
}
