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
        while(temp!=NULL)
        {
	        printf("\n%d\n",temp->data);
                temp=temp->next;
        }
}
struct list* mergeTwoLists(struct list* l1, struct list* l2)
{
	struct list *head, *t1, *t2;
	if(l1->data <= l2->data)
		head=l1;
	else head=l2;
	t1=l1;
	t2=l2;
	while((t1!=NULL)||(t2!=NULL))
	{
		if((t1->data)<=(t2->data))
		{
			l1=l1->next;
			l2=l2->next;
			t1->next=t2;
			t1=t2;
			t1->next=l1;
			t2=l2;
			t1=l1;
		}
		else
        	{
            		l1=l1->next;
            		l2=l2->next;
            		t2->next=t1;
            		t2=t1;
            		t2->next=l1;
            		t2=l1;
            		t1=l2;
        	}
	}
	return head;	
}


int main()
{
        int m,n;
        struct list *p1, *p2, *p3;
        printf("Enter length of first linked list: ");
        scanf("%d",&m);
        printf("\n");
        p1=createList(m);
        printf("Pointer of List 1: %p\n",p1);
        printList(p1);
        //printf("Reverse elements in List\n");
        //printReverseList(p1);
        printf("\n\n");
        printf("Enter length of second linked list: ");
        scanf("%d",&n);
        printf("\n");
        p2=createList(n);
        printf("Pointer of List 2: %p\n",p2);
        printList(p2);
	p3=mergeTwoLists(p1,p2);
	printf("\nPointer of 3rd List: %p",p3);
	printList(p3);
}
