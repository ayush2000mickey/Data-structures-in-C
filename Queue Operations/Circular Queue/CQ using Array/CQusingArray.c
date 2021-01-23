#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front, rear;
    unsigned capacity;
    int *array;
} Queue;

Queue *createqueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isfull(Queue *queue)
{
    return (queue->rear + 1) % queue->capacity == queue->front;
}

int isempty(Queue *queue)
{
    return queue->front == -1;
}

void enqueue(Queue *queue, int item)
{
    if (isfull(queue))
    {
        printf("\nQueue is full");
        return;
    }

    if (queue->front == -1)
    {
        queue->front = 0;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue *queue)
{
    int delitem;
    if (isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }
    else
    {
        delitem = queue->array[queue->front];
        if (queue->front == queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        else
        {
            queue->front = (queue->front + 1) % queue->capacity;
        }
    }

    return delitem;
}

int front(Queue *queue)
{
    if (isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->array[queue->front];
}

int rear(Queue *queue)
{
    if (isempty(queue))
    {
        printf("\nQueue is empty");
        return INT_MIN;
    }

    return queue->array[queue->rear];
}

void display(Queue *queue)
{
    if (isempty(queue))
    {
        printf("\nQueue is empty");
        return;
    }
    int i=queue->front;
    printf("\nQueue : ");
    while(i!=queue->rear)
    {
        printf("%d ",queue->array[i]);
        i=(i+1)%queue->capacity;
    }

    printf("%d ",queue->array[i]);
}

int main()
{
    int capacity, ch, item;
    printf("********Queue Operations Using Array*********");
    printf("\n\n\n\nWhat should be the capacity of Queue : ");
    scanf("%d", &capacity);
    Queue *queue = createqueue(capacity);

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