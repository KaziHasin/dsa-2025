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

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first node and second node
    head->data = 20;
    head->next = second;

    // Link second node and third node
    second->data = 30;
    second->next = third;

    // Link third node and fourth node
    third->data = 40;
    third->next = fourth;

    // Link fourth node and NULL
    fourth->data = 60;
    fourth->next = NULL;

    traversal(head);
    return 0;
}