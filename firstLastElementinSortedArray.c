#include<stdio.h>
#include<stdlib.h>

int binarySearch(int* nums, int low, int high, int target) {
    if(low<=high) {
        int mid = low+(high-low)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid]<target)
            return binarySearch(nums, mid+1,high,target);
        else if (nums[mid]>target)
            return binarySearch(nums, low,mid-1,target);
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target) {
    int *a = malloc(2*sizeof(int));
    a[0] = -1;
    a[1] = -1;
    int index = binarySearch(nums,0,numsSize-1,target);
    if (nums[index-1] == target) {
        a[0] = index-1;
        a[1] = index;
    }
    else if(nums[index+1] == target) {
        a[0] = index;
        a[1] = index+1;
    }
    return a;
}

int main() {
	int a[10] = {1, 2, 3, 5, 6, 6, 7, 8, 9, 10};
	int res[2];
	int *ptr;
	ptr = &res;
	ptr = searchRange(a, 10, 6);
	printf("\nFirst and last position of element in Sorted array: [%d %d]", ptr[0], ptr[1]);
	printf("\n");
}
