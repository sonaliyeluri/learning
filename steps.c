#include<stdio.h>
#include<stdlib.h>
int steps(n)
{
	if(n==1)
		return 1;
	else if(n==2)
		return 2;
	else
		return steps(n-1)+steps(n-2);
}

int main()
{
	int n, count;
	printf("Enter no.of Steps: ");
	scanf("%d",&n);
	count=steps(n);
	printf("%d\n",count);
}
