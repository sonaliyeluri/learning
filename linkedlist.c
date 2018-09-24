#include<stdio.h>
#include<stdlib.h>

struct list
{
	int data;
	struct list *next;
};
struct list* createList(int n)
{
	struct list *head, *temp1, *temp2;
	head=malloc(sizeof(struct list));
	printf("Head address %p\n",head);
	temp1=head;
	printf("Enter data to list: ");
	scanf("%d",&temp1->data);
	temp1->next=NULL;
	int i;
	for(i=0;i<n-1;i++)
	{
		temp2=malloc(sizeof(struct list));
                temp1->next=temp2;
		printf("Enter data to list: ");
		scanf("%d",&temp2->data);
		temp2->next=NULL;
		temp1=temp2;
	}
	return head;
}

void printList(struct list *head)
{
	struct list *temp;
	temp=head;
	int i;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
void printReverseList(struct list *head)
{
	if(head!=NULL)
	{
		printReverseList(head->next);
		printf("%d\n",head->data);
	}
}
struct list* removeElements(struct list* ptr,int val)
{
	struct list *t1;
	while(ptr!=NULL)
	{
		if (ptr->data == val)
			ptr=ptr->next;
		else
			break;
	}
	if (ptr==NULL)
		return ptr;
	t1=ptr;
	while(t1!=NULL)
	{
		if(t1->next == NULL)
			return ptr;
		if(t1->next->data == val)
		{
			if(t1->next->next!=NULL)
			{
				t1->next=t1->next->next;
				t1=t1->next;
			}
			else
			{
				t1->next=NULL;
				t1=t1->next;
			}
		}
		else
		{
			t1=t1->next;
			if(t1->next==NULL)
				t1=NULL;
		}
	}
	return ptr;
}
int isPalindrome(struct list* head)
{
	struct list *t1,*current,*prev,*next,*t2,*t3;
	current=head;
	prev=NULL;
	printf("\nHead address: %p\n",head);
	t3=head;
	int n=0;
	while(t3!=NULL)
		n=n+1;
	printf("\n No. of elements in list: %d",n);
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	
	t1=prev;
	t2=prev;
	printf("\nList before reversing\n");
	printList(head);
	printf("\nList elements after reversing list\n");
	printList(t2);
	printf("\n");
	while(head!=NULL)
	{
		printf("\nT1= %d Head= %d\n",t1->data,head->data); 
		if(head->data != t1->data)
		{
			printf("\nIn if\n");
			return 0;
		}
		else
		{
			printf("\nIn else\n");
			head=head->next;
			t1=t1->next;
			printf("\nT1= %d Head= %d\n",t1->data,head->data);
		}
	}
	return 1;
}
int main()
{
	int n;
	struct list *p;
	printf("Enter length of linked list: ");
	scanf("%d",&n);
	printf("\n");
	p=createList(n);
	printf("Pointer of head: %p\n",p);
	printList(p);
	//printf("Reverse elements in List\n");
	//printReverseList(p);
	//int val;
	//printf("\nEnter an element to remove from list: ");
	//scanf("%d",&val);
	//p=removeElements(p,val);
	//printf("\nList after removing %d is : %p\n ",val,p);
	//printList(p);
	int valid=isPalindrome(p);
	if (valid==1)
		printf("\nIs Palindrome\n");
	else
		printf("\nIs Not Palindrome\n");
}
