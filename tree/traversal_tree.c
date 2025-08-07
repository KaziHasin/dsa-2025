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

// pre-order traversal root -> left -> right
void preOrderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

// in-order traversal left -> root -> right
void inOrderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}
// post-order traversal left -> right -> root
void postOrderTraversal(struct Node *node)
{
    if (node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
}

int main()
{
    struct Node *root = createNode(10);
    struct Node *A = createNode(15);
    struct Node *B = createNode(20);
    struct Node *C = createNode(25);
    struct Node *D = createNode(30);
    struct Node *E = createNode(35);
    struct Node *F = createNode(40);
    struct Node *G = createNode(45);
    root->left = A;
    root->right = B;

    A->left = C;
    A->right = D;

    B->left = E;
    B->right = F;

    F->right = G;

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}