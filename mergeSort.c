#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int left, int mid, int right)
{
	int i,j,k;
	int nl=mid-left+1;
	int nr=right-mid;
	int l[nl],r[nr];
	for(i=0;i<nl;i++)
		l[i]=a[left+i];
	for(j=0;j<nr;j++)
		r[j]=a[mid+1+j];
	i=0;
	j=0;
	k=left;
	while(i<nl && j<nr)
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			i=i+1;
		}
		else
		{
			a[k]=r[j];
			j=j+1;
		}
		k=k+1;
	}
	while(i<nl)
	{
		a[k]=l[i];
		i=i+1;
		k=k+1;
	}
	while(j<nr)
	{
		a[k]=r[j];
		j=j+1;
		k=k+1;
	}
}

void mergeSort(int a[],int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=left+(right-left)/2;
		mergeSort(a,left,mid);
		mergeSort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}

int main()
{
	int i,n;
	printf("\nEnter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter elements to array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergeSort(a,0,n-1);
	printf("\nArray elements after sorting\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
	
