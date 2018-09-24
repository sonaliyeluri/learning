#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* stringReverse(char* s)
{
        int len=0,i;
        while(s[len]!='\0')
        {
                len++;
        }
	char str[len];
        int end=len-1;
	printf("\nLength of String: %d",len);
        for(i=0;i<len;i++)
        {
                str[i]=s[end];
                end--;
        }
        printf("\nReverse of String is %s\n",str);
        return str;
}

int main()
{
        char s[100];
        printf("\nEnter a string: ");
        scanf("%s",&s);
        printf("\nActual String %s",s);
        char *p=stringReverse(s);
	printf("\nReverse of String %s is %s\n",s,p);
}
