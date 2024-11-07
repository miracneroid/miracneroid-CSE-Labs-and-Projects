#include <stdio.h>
#include <math.h>
int main()
{
int a,b,c;
float area;
printf("Enter the 3 sides of the triangle");
scanf("%d,%d,%d",&a,&b,&c);
printf("\n");
if(a+b>c && b+c>a && c+a>b)
{
if(a==b && b==c && c==a)
{
printf("\nIt's an equilateral triangle");
float s=(float)((a+b+c)/2.0);
area = (float)(sqrt (s*((s-a)+(s-b)+(s-c))));
printf("\nArea = %f",area);
printf("\n");
}
else if(a==b || b==c || c==a)
{
printf("\n It's an isoceles triangle");
float s=(float)((a+b+c)/2.0);
area = (float)(sqrt (s*((s-a)+(s-b)+(s-c))));
printf("\nArea = %f",area);
printf("\n");
}
else if(a!=b && a!=c && b!=c)
{
printf("\n It's a scalene triangle");
float s=(float)((a+b+c)/2.0);
area = (float)(sqrt (s*((s-a)+(s-b)+(s-c))));
printf("\nArea = %f",area);
printf("\n");
}
}
else
{
printf("\nIt's not a triangle");
printf("\n");
}
return 0;
}

