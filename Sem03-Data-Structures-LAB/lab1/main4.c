#include<stdio.h>
int main()
{
int n;
printf("Enter the number :- ");
scanf("%d",&n);
for(int i=1;i<=4;i++)
{
int m=n&255;
printf("\nByte %d is %d",i,m);
n=n>>8;
}
return 0;
}

