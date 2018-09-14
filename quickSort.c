#include<stdio.h>
#include<stdlib.h>

int partition(int a[], int start, int end)
{
	int pivot=a[end];
	int pIndex=start;
	int i, temp;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[i];
			a[i]=a[pIndex];
			a[pIndex]=temp;
			pIndex=pIndex+1;
		}
	}
	temp=a[end];
	a[end]=a[pIndex];
	a[pIndex]=temp;
	return pIndex;
}

void quickSort(int a[], int start, int end)
{
	int pIndex;
	if(start<end)
	{
		pIndex=partition(a,start,end);
		quickSort(a,start,pIndex-1);
		quickSort(a,pIndex+1,end);
	}
}

int main()
{
	int n, i;
	printf("\nEnter size of array: ");
	scanf("%d",&n);
	printf("\nEnter elements to array.\n");
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nArray elements after sorting\n");
	quickSort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}


