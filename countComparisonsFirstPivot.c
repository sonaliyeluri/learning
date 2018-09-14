#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
int partition(int*,int,int);
void quickSort(int*,int,int);
void increment(int);

int partition(int *a, int start, int end)
{
	int pivot = a[start];
	int pIndex = start;
	int i, temp;
	for (i=start+1;i<=end;i++)
	{
		if (a[i]<pivot)
		{
			pIndex = pIndex+1;
			temp = a[i];
			a[i] = a[pIndex];
			a[pIndex] = temp;
		}
		//increment();
	}
	temp = a[start];
	a[start] = a[pIndex];
	a[pIndex] = temp;
	return pIndex;
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
		increment(end-start);
		pIndex = partition(a,start,end);
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
	quickSort(a,0,10000-1);
	printf("\nNo of comparisons: %d", count);
	printf("\n");
	for (i=0;i<j;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
