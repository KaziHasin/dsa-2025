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

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
};

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
};

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

struct Node *deleteAtValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
};
int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    thrid = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first node and second node
    head->data = 20;
    head->next = second;

    // Link second node and third node
    second->data = 30;
    second->next = thrid;

    // Link third node and fourth node
    thrid->data = 40;
    thrid->next = fourth;

    // Link fourth node and NULL
    fourth->data = 50;
    fourth->next = NULL;

    printf("Linked list before deletion:\n");
    traversal(head);

    head = deleteAtValue(head, 30);

    printf("Linked list after deletion of first node:\n");
    traversal(head);
    return 0;
}