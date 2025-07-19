#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front, rear, size;
    int *arr;
};

int isFull(struct queue *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(struct queue *q)
{
    return (q->front == q->rear);
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = val;
        printf("Enqueue %d \n", val);
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        val = q->arr[q->front];
    }
    return val;
}

void traverseQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        int i = (q->front + 1) % q->size;
        printf("Front index: %d\n", q->front);
        printf("Rear index: %d\n", q->rear);
        printf("Queue contents [index: value]:\n");
        do
        {
            printf("[%d]: %d\n", i, q->arr[i]);
            i = (i + 1) % q->size;
        } while (i != (q->rear + 1) % q->size);

        printf("\n");
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->front = q->rear = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    if (isEmpty(q))
    {
        printf("Queue is initialized and empty\n");
    }

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Dqueue %d \n", dequeue(q));

    enqueue(q, 50);

    printf("Queue after enqueuing elements:\n");
    traverseQueue(q);

    if (isFull(q))
    {
        printf("\nQueue is full\n");
    }

    return 0;
}