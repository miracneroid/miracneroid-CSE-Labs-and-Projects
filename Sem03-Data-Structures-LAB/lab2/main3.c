#include <stdio.h>
int sumdig(int a);
int main()
{
int n;
printf("Enter a number:-");
scanf("%d",&n);
printf("\n");
int r;
r=sumdig(n);
printf("sum is :- %d",r);
printf("\n");
return 0;
}
int sumdig(int a)
{
if(a==0)
return a;
return (a%10+sumdig(a/10));
}

