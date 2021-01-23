#include <stdio.h>
#include <stdlib.h>
typedef struct Queuenode
{
    int data;
    struct Queuenode *next;
} Queuenode;

typedef struct Queue
{
    struct Queuenode *front, *rear;
} Queue;

Queue *createqueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, int item)
{
    Queuenode *node = (Queuenode *)malloc(sizeof(Queuenode));

    node->data = item;
    if (queue->front == NULL)
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }

    queue->rear = node;
    queue->rear->next = queue->front;
}

int isEmpty(Queue *queue)
{
    return queue->front == NULL;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Circular Queue is Empty");
        return INT_MIN;
    }

    int delitem = queue->front->data;

    if (queue->front == queue->rear)
    {

        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
        return delitem;
    }

    queue->front = queue->front->next;
    queue->rear->next = queue->front;
    return delitem;
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->front->data;
}

int rear(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->rear->data;
}

void display(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is empty");
        return;
    }

    Queuenode *temp = queue->front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }while (temp != queue->front);
}

int main()
{
    Queue *queue = createqueue();

    int ch, item;
    printf("********Queue Operations Using Linked List*********");
    while (1)
    {
        printf("\nPress 1 to Enqueue");
        printf("\nPress 2 to Dequeue");
        printf("\nPress 3 to print front");
        printf("\nPress 4 to print rear");
        printf("\nPress 5 to display");
        printf("\nPress 6 to exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the item : ");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            printf("%d dequeued successfully", dequeue(queue));
            break;
        case 3:
            printf("\nFront element is %d\n", front(queue));
            break;
        case 4:
            printf("\nRear element is %d\n", rear(queue));
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