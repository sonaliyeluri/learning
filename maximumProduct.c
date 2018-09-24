#include<stdio.h>
#include<stdlib.h>

int maximumProduct(int* a, int n)
{
	int temp1, temp2, product;
	temp1 = a[n-1]*a[n-2]*a[n-3];
	temp2 = a[0]*a[1]*a[n-1];
	product = temp1>temp2?temp1:temp2;
	return product;
}
void merge(int* a, int left, int mid, int right)
{
	int nl = mid-left+1;
	int nr = right - mid;
	int i, j, k;
	int l[nl],r[nr];
	for (i=0;i<nl;i++)
		l[i] = a[left+i];
	for (j=0;j<nr;j++)
		r[j] = a[mid+1+j];
	i=0;
	j=0;
	k=left;
	while (i<nl && j<nr)
	{
		if (l[i]<r[j])
		{
			a[k] = l[i];
			i = i+1;
		}
		else
		{
			a[k] = r[j];
			j = j+1;
		}
		k = k+1;
	}
	while (i<nl)
	{
		a[k]=l[i];
		i = i+1;
		k = k+1;
	}
	while (j<nr)
	{
		a[k]=r[j];
		j = j+1;
		k = k+1;
	}
}

void mergeSort(int* a, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = left+(right-left)/2;
		mergeSort(a,left, mid);
		mergeSort(a,mid+1, right);
		merge(a,left,mid,right);
	}
}

int main()
{
	int n,i,product;
	printf("\nEnter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter Elements to array\n");
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	mergeSort(a,0,n-1);
	printf("\nElements after Sorting array\n");
	for (i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	product = maximumProduct(a,n);
	printf("\nProduct of elements is %d\n",product);
}
