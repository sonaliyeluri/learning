#include<stdio.h>
#include<stdlib.h>
int stepsij(int n, int i, int j)
{
	if (n==i)
		return i;
	else if (n==j)
		return j;
	else if (n>0 && n<i)
		return 1;
	else
		return stepsij(n-i,i,j)+stepsij(n-j,i,j);
}
int main()
{
	int n, i, j, count;
	printf("Enter no.of steps: ");
	scanf("%d",&n);
	printf("\nEnter min steps: ");
	scanf("%d",&i);
	printf("\nEnter max steps: ");
	scanf("%d",&j);
	count= stepsij(n,i,j);
	printf("No.of ways: %d\n",count);	
}
		

