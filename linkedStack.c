#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack{
	int data;
	struct stack *next;
};
struct stack *top;
struct stack *insert(struct stack *,int);
struct stack *delete(struct stack *);

struct stack *insert(struct stack *top, int val){
	struct stack *ptr;
	ptr = malloc(sizeof(struct stack));
	ptr->data = val;
	if (top == NULL)
	{
		ptr->next = NULL;
		top = ptr;
	}
	else
	{
		ptr->next = top;
		top = ptr;
	}
	return top;
}

struct stack *display(struct stack *top)
{
	struct stack *ptr;
	ptr = top;
	if (top == NULL)
		printf("\nStack is empty");
	else
	{
		while (ptr!=NULL)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
	return top;
}

struct stack *delete(struct stack *top){
	struct stack *ptr;
	if (top == NULL)
		printf("\nStack Underflow");
	else
	{
		ptr = top;
		top = top->next;
		printf("\nValue deleted from list: %d",ptr->data);
		free(ptr);
	}
	return top;
}

int main()
{
	int n,i;
	printf("\nEnter elements to Linked List: ");
	for (i=0;i<MAX;i++)
	{
		scanf("%d",&n);
		top = insert(top,n);
	}
	top = display(top);
	for (i=0;i<MAX;i++)
	{
		top = delete(top);
	}
	printf("\n");
}
