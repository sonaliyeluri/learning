#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node* top=NULL;
struct node* push(int x)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data=x;
	temp->next=top;
	top=temp;
	return top;
}

void pop()
{
	struct node* temp;
	if (top == NULL)
		return;
	temp=top;
	top=top->next;
	free(temp);
}
void print(struct node* head)
{
	while(head!=NULL)
        {
                printf("%d\t",head->data);
                head=head->next;
        }
	printf("\n");
}

int main()
{
	struct node *root;
	printf("\nList elements after push\n");
	root=push(10);
	root=push(5);
	root=push(3);
	root=push(9);
	print(root);
	pop();
	pop();
	printf("\nList elements after pop\n");
	print(root);
}

