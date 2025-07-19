#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element %d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

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
    fourth->next = head; // Making it circular

    printf("Circular Linked list before insert:\n");
    traversal(head);

    head = insertAtFirst(head, 10);

    printf("Circular Linked list after insert at first:\n");
    traversal(head);
    return 0;
}