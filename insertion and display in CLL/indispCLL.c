#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

void insertCLL(node **head , int value)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data=value;

    if(*head==NULL)
    {
        new_node->next=new_node;
        *head=new_node;
    }

    else 
    {
        node *current=*head;
        while(current->next!=*head)
           current=current->next;
        current->next=new_node;
        new_node->next=*head;
        *head=new_node;   
    }


}

void displayCLL(node *head)
{
    node *temp=head;
    if(head!=NULL)
    {
        do
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }while(temp!=head);
        printf("Head\n");
    }
    else
    {
           printf("\nNo , Node present.....!!!!!\n");
    }
    
}


int main()
{
    node *head=NULL;
    int ch,value;
    


while(1)
{
    printf("\n---------Circular Linked List---------\n");
    printf("\n1.Insertion");
    printf("\n2.Display");
    printf("\n3.Quit\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("\nEnter the value:");
        scanf("%d",&value);
        insertCLL(&head,value);
    }

    else if(ch==2)
    {
        displayCLL(head);
    }

    else if(ch==3)
    {
      printf("\nExited succesfully......!!!!\n");
      exit(0);
    }

    else
       printf("\nWrong choice entered...Enter Again...\n");
}
    return 0;
}