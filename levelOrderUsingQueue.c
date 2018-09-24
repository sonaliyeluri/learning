#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 500

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *root;
	root = malloc(sizeof(struct node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

struct node **createQueue(int *front, int*rear)
{
	struct node **queue = (struct node **)malloc(sizeof(struct node*)*MAX_SIZE);
	*front = 0;
	*rear = 0;
	return queue;
}

void enqueue(struct node **queue, int *rear, struct node *root)
{
	queue[*rear] = root;
	(*rear)++;
}

struct node *dequeue(struct node **queue, int *front)
{
	(*front)++;
	return queue[*front-1];
}
void printLevelOrder(struct node *root)
{
	int rear, front;
	struct node **queue = createQueue(&front,&rear);
	struct node *temp = root;
	while(temp)
	{
		printf("%d\t",temp->data);
		if (temp->left)
			enqueue(queue,&rear,temp->left);
		if (temp->right)
			enqueue(queue,&rear,temp->right);
		temp = dequeue(queue,&front);
	}
}

int main()
{
	struct node *root;
	root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	printf("\nLevel Order Traversal of Binary Tree\n");
	printLevelOrder(root);
	printf("\n");
}
