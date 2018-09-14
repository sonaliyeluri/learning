#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n, char a_rod, char c_rod, char b_rod)
{
	if (n == 1)
	{
		printf("\nMove %d from %c to %c",n,a_rod,c_rod);
		return;
	}
	towerOfHanoi(n-1,a_rod,b_rod,c_rod);
	printf("\nMove %d from %c to %c",n,a_rod,c_rod);
	towerOfHanoi(n-1,b_rod,c_rod,a_rod);
}

int main()
{
	int n;
	printf("\nEnter height of tower: ");
	scanf("%d",&n);
	towerOfHanoi(n,'A','C','B');
	printf("\n");
}
