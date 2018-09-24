#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int deque[MAX];
int left = -1, right = -1;

void insert_left(int val)
{
	if ((left == 0 && right == MAX-1)||(left == right+1))
	{
		printf("\nOverflow");
		return;
	}
	if (left == -1)
	{
		left = 0;
		right = 0;
	}
	else
	{
		if (left == 0)
			left = MAX-1;
		else
			left = left-1;
	}
	deque[left] = val;
}
