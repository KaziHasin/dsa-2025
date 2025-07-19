#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front, rear, size;
    int *arr;
};

int isFull(struct queue *q)
{
    return (q->rear == q->size - 1);
}

int isEmpty(struct queue *q)
{
    return (q->front == q->rear);
}

void traverseQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
    }
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
    }
}

int dequeue(struct queue *q)
{
    int value = 1;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = q->front + 1;
        value = q->arr[q->front];
    }
    return value;
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if (isEmpty(q))
    {
        printf("Queue is initialized and empty\n");
    }

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 80);
    enqueue(q, 90);
    enqueue(q, 100);
    enqueue(q, 110);

    printf("Dqueue %d \n", dequeue(q));

    printf("Queue after enqueuing elements:\n");
    traverseQueue(q);

    if (isFull(q))
    {
        printf("\nQueue is full\n");
    }

    return 0;
}