#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n)
{
	int i,key,hole;
	for(i=1;i<n;i++)
	{
		key=a[i];
		hole=i;
		while(hole>0 && a[hole-1]>key)
		{
			a[hole]=a[hole-1];
			hole=hole-1;
		}
		a[hole]=key;
	}
}

int main()
{
	int i, n;
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements to array.\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nArray elements after sorting\n");
	insertionSort(a,n);
	for(i=0;i<n;i++)
                printf("%d\t",a[i]);
	printf("\n");
}

