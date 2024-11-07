#include <stdio.h>
int loop1(int a,int b);
int loop2(int a);
int main()
{
	int n,e;
	printf("Enter limit:- ");
	scanf("%d",&n);
	printf("\nEnter 1 for ascending, 2 for descending\n");
	scanf("%d",&e);
		if(e==1)
		{
			int s=1;
			loop1(s,n);
		}
		if(e==2)
		{
			loop2(n);
		}
	return 0;
}
int loop1(int a,int b)
{
	while(a!=b+1)
	{
		printf("%d,",a);
		return loop1(a+1,b);
	}
	printf("\n");
	return 0;
}
int loop2(int a)
{
	while (a!=0)
	{
		printf ("%d ,",a);
		return loop2(a-1);
	}
	printf("\n");
	return 0;
}
