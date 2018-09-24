#include<stdio.h>
#include<stdlib.h>
#define MAX 5

struct node{
	int data;
	struct node *next;
};

struct queue{
	struct node *front;
	struct node *rear;
};

struct queue *q;
void create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);

void create_queue(struct queue *q)
{
	q->rear = NULL;
	q->front = NULL;
}

struct queue *insert(struct queue *q, int val)
{
	struct node *ptr;
	ptr = malloc(sizeof(struct node));
	ptr->data = val;
	if (q->front == NULL)
	{
		q->front = ptr;
		q->rear = ptr;
		q->front->next = NULL;
		q->rear->next = NULL;
	}
	else
	{
		q->rear->next = ptr;
		q->rear = ptr;
		q->rear->next = NULL;
	}
	return q;
}

struct queue *delete(struct queue *q)
{
	struct node *ptr;
	ptr = q->front;
	if (ptr == NULL)
		printf("\nQueue is empty");
	else
		q->front = q->front->next;
	free(ptr);
	return q;
}

struct queue *display(struct queue *q)
{
	struct node *ptr;
	ptr = q->front;
	if (ptr == NULL)
		printf("\nQueue is empty");
	else
	{
		while (ptr != q->rear)
		{
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
	}
	return q;
}

int main()
{
	int val, i;
	create_queue(q);
	printf("\nEnter Elements to insert into Queue:\n");
	for (i=0;i<MAX;i++)
	{
		scanf("%d",&val);
		insert(q,val);
	}
	printf("\nDisplaying elements of queue\n");
	display(q);
	printf("\nDeleting one element from Queue\n");
	delete(q);
	printf("\nDisplaying elements of queue\n");
        display(q);
	printf("\n");
}
