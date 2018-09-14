#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[], int n)
{
	int i,j,temp,flag;
	for(i=1;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}			
}

int main()
{
	int i, n;
	printf("\nEnter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements to array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubbleSort(a,n);
	printf("\nElements of array after sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

