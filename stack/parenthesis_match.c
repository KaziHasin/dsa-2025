#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return '\0';
    }
    else
    {
        char poppedValue = ptr->arr[ptr->top];
        ptr->top--;
        return poppedValue;
    }
}

int matchParentheses(struct stack *ptr, char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(ptr, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(ptr))
            {
                return 0;
            }
            pop(ptr);
        }
    }
    return isEmpty(ptr) ? 1 : 0;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *exp = "((a+b)*(c-d))))";

    if (matchParentheses(sp, exp))
    {
        printf("Parentheses are balanced.\n");
    }
    else
    {
        printf("Parentheses are not balanced.\n");
    }

    free(sp->arr);
    free(sp);

    return 0;
}
