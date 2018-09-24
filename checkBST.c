#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *getNewNode(int data)
{
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void printTree(struct node *root)
{
	if(root == NULL)
		return;
	printTree(root->left);
	printf("%d\t",root->data);
	printTree(root->right);
}

int isBSTUtil(struct node *root, int min, int max)
{
	if (root == NULL)
		return 1;
	if (root->data<min || root->data>max)
		return 0;
	return isBSTUtil(root->left,min,root->data-1)&&isBSTUtil(root->right,root->data+1,max);
}

int isBST(struct node *root)
{
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main()
{
	struct node *root;
	root = NULL;
	root = getNewNode(4);
	root->left = getNewNode(2);
	root->right = getNewNode(6);
	root->left->left = getNewNode(1);
	root->left->right = getNewNode(3);
	root->right->left = getNewNode(5);
	root->right->right = getNewNode(7);
	printTree(root);
	printf("\n");
	if (isBST(root))
		printf("\nTree is Binary Search Tree");
	else
		printf("\nTree is not Binary Search Tree");
	printf("\n");
}	
