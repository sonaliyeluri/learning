#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst* getNode(int data)
{
	struct bst* newNode=malloc(sizeof(struct bst));
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}

struct bst* insertData(struct bst* root, int data)
{
	if(root==NULL)
	{
		root=getNode(data);
	}
	else if(data<=root->data)
	{
		root->left=insertData(root->left,data);
	}
	else
	{
                root->right=insertData(root->right,data);
        }
	return root;
}

void printTree(struct bst* root)
{
	if(root!=NULL)
	{
		printTree(root->left);
		printf("%d\t",root->data);
		printTree(root->right);
	}
}

int searchTree(struct bst* root, int val)
{
	if(root!=NULL)
	{
		if(root->data==val)
		{
			printf("Element found at %p\n",root);
			return 1;
		}
		else if(val<root->data)
		{
			searchTree(root->left,val);
		}
		else
		{
			searchTree(root->right,val);
		}
	}
	return 0;
}

int main()
{
	int i,n,data,val,found;
	struct bst* root;
	root=NULL;
	printf("\nEnter No. of nodes in a tree: ");
	scanf("%d",&n);
	printf("\nEnter data to insert into Tree.");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=insertData(root,data);
		//printf("\nAddress %p Data %d\n",root,data);
	}
	printf("\nPrinting Tree elements\n");
	printTree(root);
	printf("\n");
	printf("Enter a value to search in binary tree: ");
	scanf("%d",&val);
	found=searchTree(root,val);
	if(found==1)
		printf("Element Found\n");
	else
		printf("Element Not found\n");
}
		
