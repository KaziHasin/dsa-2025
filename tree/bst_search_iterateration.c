#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node *search(struct Node *node, int key)
{
    while (node != NULL)
    {
        if (node->data == key)
        {
            return node;
        }
        else if (node->data > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return NULL;
}

int main()
{
    struct Node *root = createNode(5);
    struct Node *A = createNode(3);
    struct Node *B = createNode(6);
    struct Node *C = createNode(1);
    struct Node *D = createNode(4);

    root->left = A;
    root->right = B;

    A->left = C;
    A->right = D;

    struct Node *result = search(root, 1);
    if (result != NULL)
    {
        printf("Element found: %d\n", result->data);
    }
    else
    {
        printf("Element not found\n");
    }
    return 0;
}