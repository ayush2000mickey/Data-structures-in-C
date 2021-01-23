#include <stdio.h>
#include <stdlib.h>

typedef struct Queuenode
{
    int data;
    struct Queuenode *next;
} Queuenode;

typedef struct Queue
{
    Queuenode *front, *rear;
} Queue;

Queue* createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int data)
{
    Queuenode *qnode = (Queuenode *)malloc(sizeof(Queuenode));
    qnode->data = data;
    qnode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = qnode;
        return;
    }

    queue->rear->next = qnode;
    queue->rear = qnode;
}

int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    Queuenode *temp = queue->front;

    queue->front = queue->front->next;
    return temp->data;
}

int front(Queue *queue)
{
    if(queue->front==NULL)
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->front->data;
}


int rear(Queue *queue)
{
    if(queue->front==NULL)
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->rear->data;
}


void display(Queue *queue)
{
    if(queue->front==NULL)
    {
        printf("\nQueue is empty.....!!!!\n");
        return;
    }
    Queuenode *temp=queue->front;

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }


}

int main()
{
    Queue *queue=createQueue();
    int ch,item;
    printf("********Queue Operations Using Linked List*********");

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