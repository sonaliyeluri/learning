#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	FILE *fs;
	char ch, buffer[10];
	int i = 0, j = 0;
	int arr[100000];
	fs = fopen("test.txt","r");
	while(1)
	{
		ch = fgetc(fs);
		if (ch == EOF)
			break;
		else if (ch == '\n')
		{
			arr[j] = atoi(buffer);
			j = j+1;
			bzero(buffer,10);
			i = 0;
			continue;
		}
		else
		{
			buffer[i] = ch;
			i = i+1;
		}
	}
	printf("\n");
	for (i=0;i<j;i++)
		printf("%d\t",arr[i]);
}
