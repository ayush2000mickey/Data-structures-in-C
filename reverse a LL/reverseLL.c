#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void push(node **head, int item);
void insertafter(node **head, int item, int pos);
void insertlast(node **head, int item);
void reverseLL(node **head);
void printdll(node *head);

void push(node **head, int item)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = *head;
    *head = new_node;
}

void insertafter(node **head, int item, int pos)
{

    node *prev_node = *head;
    for (int i = 1; i < pos; i++)
    {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL)
    {
        printf("\nNo previous node present so, element cann't be entered");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertlast(node **head, int item)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->next = NULL;
    node *last = *head;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
}

void reverseLL(node **head)
{
    node *temp=NULL,*current=*head,*ptr=NULL;
    if(*head==NULL)
    {
        printf("\nCann't be reversed as no element present in LL\n");
        return;
    }
    
    printf("Reverse LL or");

    while(current!=NULL)
    {
        temp=current->next;
        current->next=ptr;
        ptr=current;
        current=temp;
    }
    *head=ptr;


}

void printdll(node *head)
{
    node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    int n, item, pos;
    char ch;
    printf("Do you want to enter elements in the Linked List(y or n):");
    scanf("%c", &ch);
    while (ch == 'y' || ch == 'Y')
    {
        printf("1.Insertion in front\n");
        printf("2.Insertion after a node\n");
        printf("3.Insertion at end\n");
        printf("4.Reverse the LL\n");
        printf("5.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &item);
            push(&head, item);
            break;
        case 2:
            printf("Enter the data:");
            scanf("%d", &item);
            printf("\nEnter the position after which you want to insert:");
            scanf("%d", &pos);
            insertafter(&head, item, pos);
            break;
        case 3:
            printf("Enter the data:");
            scanf("%d", &item);
            insertlast(&head, item);
            break;
        case 4:
            reverseLL(&head);
            break;    
        default:
            exit(0);
            break;
        }
        printf("\n\nUpdated LL: ");
        printdll(head);
        printf("\nDo you want to continue (y or n):");
        scanf(" %c", &ch);
        system("cls");
    }
    system("pause");

    return 0;
}