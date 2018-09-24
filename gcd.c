#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
	int dividened = a>=b ? a:b;
	int divisor = a<=b ? a:b;
	int remainder;
	printf("%d\n",dividened);
	printf("%d\n",divisor);
	while(divisor !=0)
	{
		remainder=dividened%divisor;
		printf("Remainder: %d\n",remainder);
		dividened=divisor;
		printf("Dividened: %d\n",dividened);
		divisor=remainder;
		printf("Divisor: %d\n",divisor);
		printf("\n");
	}
	return dividened;
}

int main()
{
	int m, n;
	printf("Enter two numbers for which GCD is to be determined: ");
	scanf("%d%d",&m,&n);
	int gcd_mn=gcd(m,n);
	printf("\nGCD of %d and %d is: %d\n",m,n,gcd_mn);
}

