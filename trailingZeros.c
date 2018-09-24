#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,remainder,i,count=0;
	unsigned long long int fact=1;
	printf("\nEnter a number to find factorial: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		fact=fact*i;
	printf("\nFactorial of %d is: %llu",n,fact);
	while(fact>0)
	{
		remainder=fact%10;
		fact=fact/10;
		if(remainder!=0)
			break;
		else
			count=count+1;
	}
	printf("\nNo.of Trailing zeroes in factorial of %d is:%d\n\n",n,count);
}
