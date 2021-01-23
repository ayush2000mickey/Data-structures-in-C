#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} node;

void enqueue(node **head, int d, int p)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    node *start = *head;

    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    if ((*head)->priority > p)
    {
        temp->next = *head;
        *head = temp;
    }

    else
    {
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int dequeue(node **head)
{
    if(*head==NULL)
    {
        printf("\nQueue is empty\n");
        return INT_MIN;
    }
    int delnode=(*head)->data;
    (*head)=(*head)->next;
    return delnode;
}

void display(node *head)
{
    node *temp=head;
    if(temp==NULL)
    {
        printf("\nQueue is empty");
        return;
    }
    printf("Queue : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    node *head = NULL;
     int ch,item,p;
    printf("********Priority Queue Operations Using Linked List*********");

    while(1)
    {
        printf("\nPress 1 to Enqueue");
        printf("\nPress 2 to Dequeue");
        printf("\nPress 3 to display");
        printf("\nPress 4 to exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the item : ");
               scanf("%d",&item);
               printf("\nEnter the priority of the item : ");
               scanf("%d",&p);
               enqueue(&head,item,p);
               break;
            case 2:
               printf("%d dequeued successfully",dequeue(&head));
               break;
            case 3:
               display(head);
               break;
            case 4:
               exit(0);
        }
    }
    return 0;
}