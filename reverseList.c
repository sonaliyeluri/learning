#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top = -1;
int stack[MAX];
struct stack *push(struct stack *,int);
struct stack *pop(struct stack *); 
struct stack{
	int data;
	struct stack *next;
};

struct stack *push(struct stack 
