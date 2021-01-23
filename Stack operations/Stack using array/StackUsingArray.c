#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int *array;
}Stack;
 
Stack* createstack(unsigned capacity)
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int*)malloc(capacity*sizeof(int));
    return stack;
}

int isfull(Stack* stack)
{
    return stack->top==stack->capacity-1;
}

int isempty(Stack* stack)
{
    return stack->top==-1;
}

void push(Stack* stack,int item)
{
    if(isfull(stack))
    {
        printf("\nStack is full...!!!!\n");
        return;
    }

    stack->array[++stack->top]=item;
}

int pop(Stack* stack)
{
    if(isempty(stack))
    {
        printf("\nStack is empty....!!!!\n");
        return INT_MIN;
    }

    return stack->array[stack->top--];
}


int peek(Stack* stack)
{
    if(isempty(stack))
    {
        printf("\nStack is empty....!!!!\n");
        return INT_MIN;
    }

    return stack->array[stack->top];
}

void display(Stack* stack)
{
     if(isempty(stack))
    {
        printf("\nStack is empty....!!!!\n");
        return;
    }
    int ftop=stack->top;
    printf("Stack : ");
    do
    {
    printf("%d ",stack->array[ftop]);
    } while (ftop--);
    
}



int main()
{
    int capacity,ch,item;
    printf("********Stack Operations Using Array*********");
    printf("\n\n\n\nWhat should be the capacity of stack : ");
    scanf("%d",&capacity);
    Stack* stack=createstack(capacity);

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
               push(stack,item);
               break;
            case 2:
               printf("%d popped successfully",pop(stack));
               break;
            case 3:
               printf("\nTop element is %d\n",peek(stack));
               break;
            case 4:
               display(stack);
               break;
            case 5:
               exit(0);
        }
    }
        return 0;
}
