#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void traversal(struct Queue *q)
{
    struct Node *temp = q->front;

    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL)

    {
        printf("Element %d \n", temp->data);
        temp = temp->next;
    }
}

void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = createNode(value);
    if (newNode == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        // special case if the front and rear are NULL then point the new node same
        if (q->rear == NULL)
        {
            q->front = q->rear = newNode;
        }
        q->rear->next = newNode;
        q->rear = newNode;
        printf("Enqueued %d\n", value);
    }
}

int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return val;
}

int main()
{
    struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Before dequeue: \n");
    traversal(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    printf("After dequeue: \n");
    traversal(q);
    return 0;
}