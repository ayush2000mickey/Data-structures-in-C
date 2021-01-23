#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

void push(node **head, int item);
void insertbefore(node **head, int item, int pos);
void insertafter(node **head, int item, int pos);
void insertlast(node **head, int item);
void deletenode(node **head, int pos);
void printdll(node *head);

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

void insertbefore(node **head, int item, int pos)
{
    node *nextn = *head;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    for (int i = 1; i < pos; i++)
    {
        nextn = nextn->next;
    }

    if (nextn == NULL) {  
        printf("the given next node cannot be NULL");  
        return;  
    } 

    new_node->next = nextn;
    new_node->prev = nextn->prev;
    nextn->prev = new_node;

    if (new_node->prev != NULL)
    {
        new_node->prev->next = new_node;
    }
    else
    {
        *head = new_node;
    }
}

void insertafter(node **head, int item, int pos)
{
    node *prevn = *head;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;

    for (int i = 1; i < pos; i++)
    {
        prevn = prevn->next;
    }
     if (prevn == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    }

    new_node->prev = prevn;
    new_node->next = prevn->next;
    prevn->next = new_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void insertlast(node **head, int item)
{
    node *last = *head;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    new_node->prev = NULL;
    new_node->next = NULL;

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
    new_node->prev = last;
}

void deletenode(node **head, int pos)
{
    node *del = *head;

    for (int i = 1; i < pos; i++)
    {
        del = del->next;
    }

    if (*head == NULL || del == NULL)
    {
        printf("No node present at this position");
        return;
    }

    if (*head == del)
        *head = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
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
    node *head = NULL;

    int n, item, pos;
    char ch;
    printf("Do you want to enter elements in the DLL(y or n):");
    scanf("%c", &ch);
    while (ch == 'y' || ch == 'Y')
    {
        printf("1.Insertion in front\n");
        printf("2.Insertion before a node\n");
        printf("3.Insertion after a node\n");
        printf("4.Insertion at end\n");
        printf("5.Delete a node from any position:\n");
        printf("6.Quit\n");
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
            printf("\nEnter the position before which you want to insert:");
            scanf("%d", &pos);
            insertbefore(&head, item, pos);
            break;
        case 3:
            printf("Enter the data:");
            scanf("%d", &item);
            printf("\nEnter the position after which you want to insert:");
            scanf("%d", &pos);
            insertafter(&head, item, pos);
            break;
        case 4:
            printf("Enter the data:");
            scanf("%d", &item);
            insertlast(&head, item);
            break;
        case 5:
            printf("Enter the position of the element you want to delete:");
            scanf("%d", &pos);
            deletenode(&head, pos);
            break;
        default:
            exit(0);
            break;
        }
        printf("Updated DLL: ");
        printdll(head);
        printf("\nDo you want to continue (y or n):");
        scanf(" %c",&ch);
        system("cls");
    }
    system("pause");
}