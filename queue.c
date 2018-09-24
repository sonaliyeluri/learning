#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int front = -1, rear = -1;
int queue[MAX];
void insert(int);
int delete(void);
int peek(void);
void display(void);

void insert(int val)
{
	if (rear == MAX-1)
		printf("\nOverflow");
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else
		rear = rear+1;
	queue[rear] = val;
}
int delete()
{
	int value;
	if (front == -1 || front>rear)
	{
		printf("\nUnderflow");
		return -1;
	}
	else 
	{
		value = queue[front];
		front = front+1;
		if (front>rear)
		{
			front = -1;
			rear = -1;
		}
	}
	return value;
}

int peek()
{
	if (front == -1 || front>rear)
	{
		printf("\nStack is empty");
		return -1;
	}
	else
		return queue[front];
}

void display()
{
	int i;
	for (i=front;i<=rear;i++)
		printf("%d\t",queue[i]);
}

int main()
{
	int i,a[MAX];
	printf("\nEnter elements to queue: ");
	for (i=0;i<MAX;i++)
	{
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	int last = peek();
	printf("\nLast element in the queue is %d\n",last);
	display();
	for (i=0;i<MAX;i++)
	{
		int val = delete();
		printf("\nValue deleted from Queue: %d",val);
	}
	printf("\n");
}
	
