#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* newNode (int data) {
    struct TreeNode *ptr = malloc(sizeof(struct TreeNode));
    ptr->val = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct TreeNode* arrayToBST(int* nums, int start, int end) {
    if(start > end)
        return NULL;
    int mid = (start+end)/2;
    struct TreeNode *root = newNode(nums[mid]);
    root->left = arrayToBST(nums,start,mid-1);
    root->right = arrayToBST(nums,mid+1,end);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root = arrayToBST(nums,0,numsSize-1);
    return root;
}

void inOrder(struct TreeNode *root) {
	if(root!= NULL)
	{
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
}

int main() {
	int a[5] = {-10, -3, 0, 5, 9};
	struct TreeNode *root = sortedArrayToBST(a,5);
	inOrder(root);
	printf("\n");
	return 1;
}
