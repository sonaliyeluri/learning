#include<stdio.h>
#define MAX 101
int a[MAX];
int top = -1;

void push(int x)
{
	if(top == MAX-1)
	{
		printf("\nStack Overflow\n");
		return;
	}
	top = top+1;
	a[top] = x;
}

void pop()
{
	if (top != -1)
	{
		top = top-1;
	}
	else
	{
		printf("\nNo element to Pop\n");
		return;
	}
}

int Top()
{
	return a[top];
}

void print()
{	
	int i;
	printf("\nStack\n");
	for(i=0;i<=top;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

int main()
{
	//printf("\nEnter elements to add in stack\n");
	push(5);
	print();
	push(6);
        print();
	push(10);
        print();	
        push(9);
        print();	
        push(3);
        print();
	pop();
	print();
	pop();
	print();
}

