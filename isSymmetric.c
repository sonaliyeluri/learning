#include<stdio.h>
#include<stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *getNode (int data){
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

int isMirror(struct tree *root1, struct tree *root2){
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 && root2 && root1->data == root2->data)
		return isMirror(root1->left, root2->right)&&isMirror(root1->right, root2->left);
	return 0;
}

int isSymmetric(struct tree *root) {
	return isMirror(root,root);
}

int main() {
	struct tree *root;
	root = getNode(1);
	root->left = getNode(2);
	root->right = getNode(2);
	root->left->left = getNode(3);
	root->left->right = getNode(4);
	root->right->left = getNode(3);
	root->right->right = getNode(4);
	int valid = isSymmetric(root);
	if (valid == 1)
		printf(" True ");
	else
		printf(" False ");
	printf("\n");
	return 1;	
}
