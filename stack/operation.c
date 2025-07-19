#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("Pushed %d onto stack\n", value);
    }
}

void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from empty stack\n");
    }
    else
    {
        int poppedValue = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped %d from stack\n", poppedValue);
    }
}

void peek(struct stack *ptr, int position)
{
    int peekedValue = ptr->arr[ptr->top - position + 1];
    if (peekedValue < 0)
    {
        printf("Invalid position %d for peek operation\n", position);
    }
    else
    {
        printf("Value at position %d from top is %d\n", position, peekedValue);
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 10);
    push(sp, 20);
    push(sp, 30);
    push(sp, 40);
    push(sp, 50);
    push(sp, 60);
    push(sp, 70);
    pop(sp);

    for (int i = 1; i <= sp->top + 1; i++)
    {
        peek(sp, i);
    }
    return 0;
}