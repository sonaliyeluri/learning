#include<stdio.h>
#include<string.h>

int main()
{
	char str[3][7] = {"flower","flow","flight"};
	int i, j;
	for (i=0;i<3;i++) {
		printf("%s",str[i]);
		printf("\n");
	}
}
		
