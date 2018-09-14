#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
void increment(int);

int chooseFirstElementAsPivot(int *a, int start, int end)
{
	return start;
}

int chooseLastElementAsPivot(int *a, int start, int end) 
{
	int temp = a[start];
	a[start] = a[end];
	a[end] = temp;
	return start;
}

int chooseMedianElementAsPivot(int *a, int start, int end)
{
	int pivotIndex = -1;
	int mid = start+(end-start)/2;
	int b[3],i,j;
	b[0] = a[start];
	b[1] = a[mid];
	b[2] = a[end];
	for (i=1;i<2;i++)
	{
		for (j=0;j<3-i;j++)
		{
			if (b[j]>b[j+1])
			{
				int temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
			}
		}
	}
	if (b[1] == a[start])
		pivotIndex = start;
	else if (b[1] == a[mid])
                pivotIndex = mid;
	else if (b[1] == a[end])
                pivotIndex = end;
	int temp = a[start];
	a[start] = a[pivotIndex];
	a[pivotIndex] = temp;
	return start;
}

int partition(int *a, int start, int end, int pivotIndex)
{
	int pivot = a[pivotIndex];
	int index = start;
	int i, temp;
	increment(end-start);
	for (i=start;i<=end;i++)
	{
		if (a[i]<pivot)
		{
			index = index+1;
			temp = a[i];
			a[i] = a[index];
			a[index] = temp;
		}
		//increment();
	}
	temp = a[index];
	a[index] = pivot;
	a[pivotIndex] = temp;
	//printf("%d %d\n",start,end);
	return index;
}

void increment(int i)
{
	count = count+i;
}
void quickSort(int *a, int start, int end)
{
	int pIndex;
	if (start<end)
	{
		int pivotIndex = chooseFirstElementAsPivot(a,start,end);
		pIndex = partition(a,start,end,pivotIndex);
		quickSort(a,start,pIndex-1);
		quickSort(a,pIndex+1,end);
	}
}

int main(int argc, char *argv[])
{
	int a[10000];
        FILE *fs;
        char ch, buffer[6];
        int i = 0, j = 0;
        fs = fopen("quickSort.txt","r");
        while (1)
        {
                ch = fgetc(fs);
                if (ch == EOF)
                        break;
                else if (ch == '\n')
                {
			buffer[i]=0;
                        a[j] = atoi(buffer);
                        j = j+1;
                        i = 0;
                        continue;
                }
                else
                {
                        buffer[i] = ch;
                        i = i+1;
                }
        }
	printf("\n");
	quickSort(a,0,10000-1);
	printf("\nNo of comparisons: %d\n", count);
	printf("\n");
}
