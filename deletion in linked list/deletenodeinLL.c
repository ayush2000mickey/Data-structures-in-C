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
void deletenode(node **head, int item);
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

void deletenode(node **head, int item)
{
    if (*head == NULL)
    {
        printf("No element present in Linked list\n");
        return;
    }

    node *del = *head, *prevn = *head;
    if (del->data == item)
    {
        (*head) = (*head)->next;
        free(del);
        return;
    }

    while (del != NULL && del->data != item)
    {
        prevn = del;
        del = del->next;
    }

    if (del == NULL)
    {
        printf("\nElement not found\n");
        return;
    }

    prevn->next = del->next;
    free(del);
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
        printf("4.Delete a Node\n");
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
            printf("Enter the data of the node you want to delete:");
            scanf("%d", &item);
            deletenode(&head, item);
            break;
        default:
            exit(0);
            break;
        }
        printf("Linked List: ");
        printdll(head);
        printf("\nDo you want to continue (y or n):");
        scanf(" %c", &ch);
        system("cls");
    }   
    system("pause");
    return 0;
}