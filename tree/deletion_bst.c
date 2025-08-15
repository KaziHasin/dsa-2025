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

struct Node *inOrderPredecessor(struct Node *node)
{
    node = node->left;
    while (node->right != NULL)
    {

        node = node->right;
    }

    return node;
}

struct Node *deleteNode(struct Node *root, int value)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }

    return root;
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

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");
    deleteNode(root, 3);
    inOrderTraversal(root);
    return 0;
}