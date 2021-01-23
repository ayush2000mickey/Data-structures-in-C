#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void printdll(node* head);
void push(node** head,int item);
void reversedll(node** head)
{
    node *temp = NULL;  
    node *current = *head;  
      
    /* swap next and prev for all nodes of  
    doubly linked list */
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      
    if(temp != NULL )  
        *head= temp->prev;
}

void push(node **head, int item)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}

void printdll(node *head)
{
    node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d<->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    node *head=NULL;
    int n,item;
    printf("How many values you want to add to DLL:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("\nEnter item :");
        scanf("%d",&item);
        push(&head,item);

    }
    printf("Original DLL:");
    printdll(head);
    reversedll(&head);
    printf("Reversed DLL:");
    printdll(head);
    printf("\n");
    return 0;
}
