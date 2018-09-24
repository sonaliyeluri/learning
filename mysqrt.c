#include<stdio.h>
#include<math.h>
int main()
{
	int x;
	float result;
	printf("\nEnter a number to find square root: ");
	scanf("%d",&x);
	result=pow(x,0.5);
	printf("\nResult: %f",result);
}
