#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

struct Node *createNode(int key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}

struct Node *rotateRight(struct Node *Y)
{
    struct Node *X = Y->left;
    struct Node *T2 = X->right;

    X->right = Y;
    Y->left = T2;

    X->height = max(getHeight(X->right), getHeight(X->left)) + 1;
    Y->height = max(getHeight(Y->right), getHeight(Y->left)) + 1;

    return X;
}

struct Node *rotateLeft(struct Node *X)
{
    struct Node *Y = X->right;
    struct Node *T2 = Y->left;

    Y->left = X;
    X->right = T2;

    X->height = max(getHeight(X->right), getHeight(X->left)) + 1;
    Y->height = max(getHeight(Y->right), getHeight(Y->left)) + 1;

    return Y;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // Left Left Case
    if (bf > 1 && key < node->left->key)
    {
        return rotateRight(node);
    }
    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return rotateLeft(node);
    }
    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// pre-order traversal root -> left -> right
void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}