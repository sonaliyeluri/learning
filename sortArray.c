#include<stdio.h>
#include<stdlib.h>

int main()
{
        int a[3],n,i,j,temp;
        int *ptr;
        ptr=a;
        printf("\nEnter array length: ");
        scanf("%d",&n);
        printf("\nEnter Elements to array..");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("\nSorting Array");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	printf("\nArray after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		if(a[i]!=i)
		{
			printf("\nMissing Number: %d\n",i);
			break;
		}
	}	
}
