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
                printf("\n%d\n",temp->data);
                temp=temp->next;
        }
}
struct list* removeDuplicates(struct list *head)
{
	struct list *t1, *t2;
	if(head != NULL)
	{
		t1=head;
		t2=t1->next;
		while(t2!=NULL)
		{
			if((t1->data)==(t2->data))
			{
				t1->next=t2->next;
				t1=t2->next;
				t2=t1->next;
				
			}	
			else
			{
				t1=t2;
				t2=t2->next;
			}
			//printf("\n%d\n",t1->data);
		}
		return head;
	}
	else
		return head;
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
        //printList(p);
        //printf("Reverse elements in List\n");
        //printReverseList(p);
	printf("List elements after removing duplicates\n");
	removeDuplicates(p);
	printList(p);
}
