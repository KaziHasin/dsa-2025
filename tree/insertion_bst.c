#include <stdio.h>
#include <stdlib.h>

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

void insert(struct Node *root, int data)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == data)
        {
            return;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct Node *newNode = createNode(data);
    if (prev->data > data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

// in order traversal left -> root -> right
void inOrderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
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

    insert(root, 2);

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}