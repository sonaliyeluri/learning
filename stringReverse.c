#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void stringReverse(char* s)
{
	int len=0,i=0,valid=1;
	char str[100];
	int ch;
	while(s[len]!='\0')
	{
		ch=s[len];
		//printf("\nCh: %d",ch);
		if(((ch>=65)&&(ch<=90))||((ch>=97)&&(ch<=122))||((ch>=48)&&(ch<=57)))
		{	
			str[i]=s[len];
			if(str[i]>='a' && str[i]<='z')
				str[i]=str[i]-32;
			i=i+1;
		}
		len++;
	}
	int length =i;
	int end=length-1;
	printf("\nString %s",str);
	printf("\nLength of string: %d\n",length);
	char r[length];
	for(i=0;i<length;i++)
	{
		r[i]=str[end];
		end--;
	}
	printf("\nReverse of String is %s\n",r);
	for(i=0;i<length;i++)
	{
		if(str[i]!=r[i])
		{
			valid=0;
			break;
		}
	}
	if(valid==1)
		printf("\nValid Palindrome\n");
	else
		printf("\nNot Valid Palindrome\n");		
}

int main()
{
	char s[100];
	printf("\nEnter a string: ");
	scanf("%[^\n]%*c",&s);
	printf("\nActual String %s",s);
	stringReverse(s);
	//printf("\nReverse of String is %s\n",*ptr);
}
