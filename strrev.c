#include<stdio.h>
#include<stdlib.h>
#include<stack>

char* reverse(char* s)
{
	stack<char> st;
	int i, n=strlen(s);
	for(i=0;i<n;i++)
	{
		st.push(s[i]);
	}
	for(i=0;i<n;i++)
	{
		s[i]=st.top();
		st.pop();
	}
	return s;
}

int main()
{
	char ch[10];
	printf("\nEnter a string: ");
	gets(ch);
	reverse(ch);
	printf("\nReverse String: %s\n",ch);
}
