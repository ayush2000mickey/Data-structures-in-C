#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void insertnode(node **head, int item);
void deletenode(node **head, int item);
void printdll(node *head);

void insertnode(node **head, int item)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = item;
    if(*head==NULL)
    {
    new_node->next = *head;
    *head = new_node;
    return;
    }

    if(item<((*head)->data))
    {
        new_node->next=*head;
        *head=new_node;
        return;
    }
    node *ptr=*head,*prevn=*head;
    while (ptr!=NULL && ptr->data<item)
    {
        prevn=ptr;
        ptr=ptr->next;
    }

    new_node->next=prevn->next;
    prevn->next=new_node;
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

    while (del != NULL && del->data<=item)
    {
        if(del->data==item)
        break;
        prevn = del;
        del = del->next;
    }
    
    if(del->data!=item)
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
    int n, item;
    char ch;
    printf("Do you want to enter elements in the Linked List(y or n):");
    scanf("%c", &ch);
    while (ch == 'y' || ch == 'Y')
    {
        printf("1.Insertion of node\n");
        printf("2.Delete a Node\n");
        printf("3.Quit\n");
        printf("Enter your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter the data:");
            scanf("%d", &item);
            insertnode(&head, item);
            break;
        case 2:
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