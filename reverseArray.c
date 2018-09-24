#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];
void push(int);
int pop();
void display();

void push(int n)
{
	if (top == MAX-1)
	{
		printf("\nOverflow");
		return;
	}
	top = top+1;
	stack[top] = n;
}

int pop()
{
	if (top == -1)
	{
		printf("\nUnderflow");
		return -1;
	}
	int val = stack[top];
	top = top-1;
	return val;
}

int main()
{
	int a[MAX];
	int i;
	printf("\nEnter elements to array: ");
	for (i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
		push(a[i]);
	}
	printf("\nArray elements before reversing\n");
	for(i=0;i<MAX;i++)
                printf("%d\t",a[i]);
	for (i=0;i<MAX;i++)
		a[i]=pop();
	printf("\nArray elements after reversing\n");
	for(i=0;i<MAX;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
