#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int countNodes(struct Node *top)
{
    int count = 0;
    struct Node *current = top;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int isEmpty(struct Node *top)
{
    return top == NULL;
}

int isFull(struct Node *top)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    return newNode == NULL;
}

void push(struct Node **top, int value)
{
    if (isFull(*top))
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = *top;
        *top = newNode;
        printf("Pushed %d onto stack\n", value);
    }
}

void pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow! Cannot pop from empty stack\n");
    }
    else
    {
        struct Node *temp = *top;
        *top = (*top)->next;
        printf("Popped %d from stack\n", temp->data);
        free(temp);
    }
}

void peek(struct Node *top, int value)
{
    struct Node *current = top;
    for (int i = 0; (i < value - 1 && current != NULL); i++)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        printf("Element at position %d is %d\n", value, current->data);
    }
    else
    {
        printf("Position %d is out of bounds\n", value);
    }
}

void stackTop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty, no top element\n");
    }
    else
    {
        printf("Top element is %d\n", top->data);
    }
}

void stackBottom(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty, no bottom element\n");
    }
    else
    {
        struct Node *current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        printf("Bottom element is %d\n", current->data);
    }
}

int main()
{
    struct Node *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    push(&top, 50);
    push(&top, 60);

    // traversal(top);
    int topCount = countNodes(top);

    for (int i = 1; i < topCount + 1; i++)
    {
        peek(top, i);
    }

    stackTop(top);
    stackBottom(top);

    return 0;
}