#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s[20];
	int i=0,count=0;
	printf("\nEnter a String: ");
	scanf("%[^\n]%*c",&s);
	printf("\n%s",s);
	for(i=0;i<(strlen(s));i++)
	{
		if(s[i]!=' ')
		{
			count++;
			printf("\n If Count %c: %d",s[i],count);
		}
		else
		{
			count=0;
			printf("\n Else Count %c: %d",s[i],count);
		}
	}
	printf("\n%d",count);
}
