#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* strrev(char* s)
{
    int len=strlen(s);
    char rev[len];
    char *ptr;
    ptr=rev;
    int i=len-1,j=0;
    while(s[j]!='\0')
    {
        s[i]=s[j];
        j++;
        i--;
    }
    
    return ptr;
}
bool isPalindrome(char* s)
{
    int len=strlen(s);
    int temp,i,j=0;
    char str[len];
    char *p;
    p=str;
    if(len==0)
        return 1;
    for(i=0;i<len;i++)
    {
        temp=(int)s[i];
        if((temp>=65 && temp<=90)||(temp>=97 && temp<=122))
        {
            str[j]=str[j]+s[i];
            j=j+1;
        }
    }
    if(str == strrev(p))
        return 1;
    else
        return 0;

}

int main()
{
	char str[100];
	char *ptr;
	char valid;
	ptr=s;
	printf("\nEnter a sentence to check if it is Palindrome: ");
	scanf("%s",&str);
	valid=isPalindrome(str);
	if (valid ==1)
		printf("\nIS Palindrome\n");
	else
		printf("\nIS NOT Palindrome\n");
}
