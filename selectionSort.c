#include<stdio.h>
#include<stdlib.h>

void selectionSort(int a[],int n)
{
	int i, imin,j,temp;
	for(i=0;i<n-1;i++)
	{
		imin=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[imin])
				imin=j;
		}
		temp=a[i];
		a[i]=a[imin];
		a[imin]=temp;
	}

}

int main()
{
	int n,i;
	printf("\nEnter size of Array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements to array: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selectionSort(a,n);
	printf("\nArray elements after sorting\n");
	for(i=0;i<n;i++)
        {
                printf("%d\t",a[i]);
        }
	printf("\n");
}
