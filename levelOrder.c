#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *getNewNode(int val)
{
	struct tree *ptr;
	ptr = malloc(sizeof(struct tree));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void preOrder(struct tree *root)
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct tree *root)
{
        if(root != NULL)
        {
                inOrder(root->left);
		printf("%d\t", root->data);
                inOrder(root->right);
        }
}

void postOrder(struct tree *root)
{
        if(root != NULL)
        {       
                postOrder(root->left);
                postOrder(root->right);
		printf("%d\t", root->data);
        }
}

int treeHeight(struct tree *root)
{
	int leftHeight, rightHeight;
	if (root == NULL)
		return 0;
	if (root != NULL)
	{
		leftHeight = treeHeight(root->left);
		rightHeight = treeHeight(root->right);
	}
	if (leftHeight > rightHeight)
		return leftHeight+1;
	else
		return rightHeight+1;
}

void printLevel(struct tree *root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d\t", root->data);
	else if (level > 1)
	{
		printLevel(root->left, level-1);
		printLevel(root->right, level-1);
	}
}

void levelOrder(struct tree *root)
{
	int i;
	int height = treeHeight(root);
	for (i=1;i<=height;i++)
		printLevel(root,i);
}

int main()
{
	struct tree *root = getNewNode(1);
	root->left = getNewNode(2);
	root->right = getNewNode(3);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);
	printf("\nPrinting Tree Elements in Pre Order\n");
	preOrder(root);
	printf("\nPrinting Tree Elements in In Order\n");
        inOrder(root);
	printf("\nPrinting Tree Elements in Post Order\n");
        postOrder(root);
	//int height = treeHeight(root);
	printf("\nLevel Order of tree\n");
	levelOrder(root);
	printf("\n");
}
