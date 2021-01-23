#include <stdio.h>
#include <stdlib.h>

typedef struct bnode
{
    int data;
    struct bnode *left;
    struct bnode *right;
} bnode;

bnode *createnode()
{
    bnode *newnode = (bnode *)malloc(sizeof(bnode));

    int x;
    printf("\nEnter data (-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }

    newnode->data = x;
    printf("\nEnter left child of %d : ", x);
    newnode->left = createnode();
    printf("\nEnter right child of %d : ", x);
    newnode->right = createnode();

    return newnode;
}

void printlevelorder(bnode *root)
{
    int h = height(root);

    int i;

    for(i=1;i<=h;i++)
    {
        printgivenlevel(root,i);
    }
}

void printgivenlevel(bnode *root,int l)
{
    if(root==NULL)
    {
        return;
    }

    if(l==1)
    {
        printf("%d ",root->data);
    }

    else if(l>1)
    {
        printgivenlevel(root->left,l-1);
        printgivenlevel(root->right,l-1);
    }
}

int height(bnode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
            return (rheight + 1);
    }
}

int main()
{
    bnode *root = createnode();
    printf("Level Order traversal of binary tree is \n");
    printlevelorder(root);
    return 0;
}