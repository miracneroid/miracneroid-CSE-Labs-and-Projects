#include<stdio.h>
#include<math.h>
int main()
{
int a,c=1,octal=0;
printf("Enter a number in decimal\n");
scanf("%d",&a);
printf("\n");
int b=a;
while(b!=0)
{
int m=b%8;
octal=octal + (m*c);
b=b/8;
c=c*10;
}
printf("Octal equivalent is :- %d",octal);
printf("\n");
return 0;
}

