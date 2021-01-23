#include <stdio.h>
#include <stdlib.h>

typedef struct Stacknode
{
    int data;
    struct Stacknode *next;
}node;



void push(node **root,int item)
{
    node* stacknode=(node*)malloc(sizeof(node));
    stacknode->data=item;
    stacknode->next=*root;
    *root=stacknode;
}

int isempty(node* root)
{
    return !root;
}

int pop(node **root)
{
     if(isempty(*root))
    {
        printf("\nStack is empty....!!!!\n");
        return INT_MIN;
    }

    node* temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    return popped;
}

int peek(node *root)
{
     if(isempty(root))
    {
        printf("\nStack is empty....!!!!\n");
        return INT_MIN;
    }

    return root->data;
}

void display(node *root)
{
     if(isempty(root))
    {
        printf("\nStack is empty....!!!!\n");
        return;
    }
    node *temp=root;
    printf("\nStack : ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int item,ch;
    node* root=NULL;
     while(1)
    {
        printf("\nPress 1 to push");
        printf("\nPress 2 to pop");
        printf("\nPress 3 to peek");
        printf("\nPress 4 to display");
        printf("\nPress 5 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the item : ");
               scanf("%d",&item);
               push(&root,item);
               break;
            case 2:
               printf("%d popped successfully",pop(&root));
               break;
            case 3:
               printf("\nTop element is %d\n",peek(root));
               break;
            case 4:
               display(root);
               break;
            case 5:
               exit(0);
        }
    }
    return 0;
}