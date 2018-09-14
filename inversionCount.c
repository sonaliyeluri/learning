#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned long long merge(int *a, int left, int mid, int right)
{
	int nl, nr;
	unsigned long long inv_count = 0;
	nl = mid-left+1;
	nr = right-mid;
	int l[nl], r[nr];
	int i, j, k;
	for (i=0;i<nl;i++)
		l[i] = a[left+i];
	for (j=0;j<nr;j++)
		r[j] = a[mid+1+j];
	i = 0;
	j = 0;
	k = left;
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
			inv_count += nl - i;
		}
		k = k+1;
	}
	while (i<nl)
	{
		a[k] = l[i];
		i = i+1;
		k = k+1;
	}
	while (j<nr)
	{
		a[k] = r[j];
		j = j+1;
		k = k+1;
	}
	return inv_count;
}

unsigned long long mergeSort(int *a, int left, int right)
{
	unsigned long long inv_count = 0;
	if (left<right)
	{
		int mid = left+(right-left)/2;
		inv_count = mergeSort(a,left,mid);
		inv_count += mergeSort(a,mid+1,right);
		inv_count += merge(a,left,mid,right);
	}
	return inv_count;
}

int main(int argc, char *argv[])
{
	int a[100000];
	unsigned long long count;
	FILE *fs;
	char ch, buffer[10];
	int i = 0, j = 0;
	fs = fopen("test.txt","r");
	while (1)
	{
		ch = fgetc(fs);
		if (ch == EOF)
			break;
		else if (ch == '\n')
		{
			a[j] = atoi(buffer);
			j = j+1;
			bzero(buffer,10);
			i = 0;
			continue;
		}
		else
		{
			buffer[i] = ch;
			i = i+1;
		}
	} 
	count = mergeSort(a,0,99999);
	printf("\n");
	printf("No of Inversions:%llu",count);
	printf("\n");
}
