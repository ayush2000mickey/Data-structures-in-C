#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front,rear,size;
    unsigned capacity;
    int *array;
}Queue;


Queue* createqueue(unsigned capacity)
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->capacity=capacity;
    queue->front=queue->size=0;
    queue->rear=capacity-1;
    queue->array=(int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isfull(Queue* queue)
{
    return queue->size==queue->capacity;
}

int isempty(Queue* queue)
{
    return queue->size==0;
}

void enqueue(Queue* queue,int item)
{
    if(isfull(queue))
    {
        printf("\nQueue is full");
        return;
    }
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=item;
    queue->size=queue->size+1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue)
{
    if(isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }
    int delitem=queue->array[queue->front];
    queue->front=(queue->front+1)%queue->capacity;
    queue->size=queue->size-1;
    return delitem;
}

int front(Queue* queue)
{
    if(isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->array[queue->front];
}

int rear(Queue* queue)
{
    if(isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->array[queue->rear];
}

void display(Queue* queue)
{
    int i;
    printf("\nQueue : ");
    for(i=queue->front;i<=queue->rear;i++)
    {
        printf("%d ",queue->array[i]);
    }
}

int main()
{
    int capacity,ch,item;
    printf("********Queue Operations Using Array*********");
    printf("\n\n\n\nWhat should be the capacity of Queue : ");
    scanf("%d",&capacity);
    Queue* queue=createqueue(capacity);

    while(1)
    {
        printf("\nPress 1 to Enqueue");
        printf("\nPress 2 to Dequeue");
        printf("\nPress 3 to print front");
        printf("\nPress 4 to print rear");
        printf("\nPress 5 to display");
        printf("\nPress 6 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
               printf("\nEnter the item : ");
               scanf("%d",&item);
               enqueue(queue,item);
               break;
            case 2:
               printf("%d dequeued successfully",dequeue(queue));
               break;
            case 3:
               printf("\nFront element is %d\n",front(queue));
               break;
            case 4:
               printf("\nRear element is %d\n",rear(queue));
               break;
            case 5:
               display(queue);
               break;
            case 6:
               exit(0);
        }
    }
    
    return 0;
}