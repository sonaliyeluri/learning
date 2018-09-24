#include<stdio.h>
#include<stdlib.h>

struct bst{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst *getNewNode(int val)
{
	struct bst *ptr;
	ptr = malloc(sizeof(struct bst));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct bst *insertNode(struct bst *root, int val)
{
	if (root == NULL)
		root = getNewNode(val);
	else if(val > root->data)
		root->right = insertNode(root->right,val);
	else
		root->left = insertNode(root->left,val);
	return root;
}

void preOrder(struct bst *root)
{
	if (root != NULL)
	{
		printf("%d\t",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct bst *root)
{
        if (root != NULL)
        {       
                inOrder(root->left);
		printf("%d\t",root->data);
                inOrder(root->right);
        }
}

void postOrder(struct bst *root)
{
        if (root != NULL)
        {       
                postOrder(root->left);
                postOrder(root->right);
		printf("%d\t",root->data);
        }
}

int countNodes(struct bst *root)
{
	int leftCount,rightCount;
	if (root == NULL)
		return 0;
	if (root != NULL)
	{
		leftCount = countNodes(root->left);
		rightCount = countNodes(root->right);
	}
	return leftCount+rightCount+1;
}

int nonLeafNodes(struct bst *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->left == NULL)
		return 0;
	return nonLeafNodes(root->left)+nonLeafNodes(root->right)+1;
}

int leafNodes(struct bst *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return leafNodes(root->left)+leafNodes(root->right);
}
int treeHeight(struct bst *root)
{
	if (root == NULL)
		return 0;
	int leftHeight,rightHeight;
	if(root != NULL)
	{
		leftHeight = treeHeight(root->left);
		rightHeight = treeHeight(root->right);
	}
	if (leftHeight > rightHeight)
		return leftHeight+1;
	else
		return rightHeight+1;
}

int main()
{
	int val,n,i;
	struct bst *root;
	printf("\nEnter number of nodes in a binary tree: ");
	scanf("%d",&n);
	printf("\nEnter values to binary tree\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&val);
		root = insertNode(root,val);
	}
	printf("\nPre Order for Binary Tree\n");
	preOrder(root);
	printf("\nIn Order for Binary Tree\n");
        inOrder(root);
	printf("\nPost Order for Binary Tree\n");
        postOrder(root);
	int no_of_Nodes = countNodes(root);
	printf("\nNo Of Nodes in Binary Tree: %d",no_of_Nodes);
	int height = treeHeight(root);
	printf("\nHeight of Binary Tree: %d",height);
	int no_of_NLnodes = nonLeafNodes(root);
	printf("\nNo of Non Leaf Nodes: %d",no_of_NLnodes);
	int no_of_leafs = leafNodes(root);
	printf("\nNo of Leaf Nodes: %d",no_of_leafs);
	printf("\n");
}
