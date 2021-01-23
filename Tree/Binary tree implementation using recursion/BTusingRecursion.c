#include <stdio.h>
#include <stdlib.h>



typedef struct bnode
{
    int data;
    struct bnode *left;
    struct bnode *right;
}bnode;



bnode *createnode()
{
    bnode *newnode=(bnode*)malloc(sizeof(bnode));

    int x;
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }

    newnode->data=x;
    printf("\nEnter left child of %d : ",x);
    newnode->left=createnode();
    printf("\nEnter right child of %d : ",x);
    newnode->right=createnode();

    return newnode;
}



int main()
{
    bnode *root=createnode();
    return 0;
}