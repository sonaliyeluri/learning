#include<stdio.h>
#include<stdlib.h>

int missingNum(int* nums, int numsSize) {
    int i,j,temp;
    printf("\nInside Missing Function");
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize;i++)
        {
            if(nums[i]>nums[j])
            {
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
            }
        }
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=i)
            break;
    }
    return i;
}

int main()
{
	int a[3],n,i,missing;
	int *ptr;
	ptr=a;
	printf("\nEnter array length: ");
	scanf("%d",&n);
	printf("\nEnter Elements to array..");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//int len=sizeof(a)/(sizeof(a[0]));
	//printf("\nLength of Array is:%d",len);
	missing=missingNum(ptr,n);
	printf("\nMissing number is: %d",missing);
}
