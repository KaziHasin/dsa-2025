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

int main()
{

    struct Node *root = createNode(10);
    struct Node *tree1 = createNode(15);
    struct Node *tree2 = createNode(20);

    root->left = tree1;
    root->right = tree1;
    return 0;
}