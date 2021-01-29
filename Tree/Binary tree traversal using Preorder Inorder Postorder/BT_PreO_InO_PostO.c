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
    int x;
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d",&x);

    if(x==-1)
    {
        return NULL;
    }

    bnode *newnode=(bnode*)malloc(sizeof(bnode));

    newnode->data=x;
    printf("Enter the left child of %d",x);
    newnode->left=createnode();

    printf("Enter the right child of %d",x);
    newnode->right=createnode();

    return newnode;

}

void preorder(bnode *root)
{
    if(root==NULL)
    {
        return;
    }

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(bnode *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}



void postorder(bnode *root)
{
    if(root==NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}



int main()
{
    bnode *root=createnode();

    printf("\nPreorder Traversal : ");
    preorder(root);
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\nPostorder Traversal : ");
    postorder(root);

    return 0;
}