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

int isBST(struct Node *node)
{
    static struct Node *prev = NULL;
    if (node != NULL)
    {
        if (!isBST(node->left))
        {
            return 0;
        }
        if (prev != NULL && node->data <= prev->data)
        {
            return 0;
        }
        prev = node;
        return isBST(node->right);
    }
    else
    {
        return 1;
    }
}

int main()
{
    struct Node *root = createNode(5);
    struct Node *A = createNode(3);
    struct Node *B = createNode(6);
    struct Node *C = createNode(4);
    struct Node *D = createNode(4);

    root->left = A;
    root->right = B;

    A->left = C;
    A->right = D;

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    if (isBST(root))
    {
        printf("The tree is a Binary Search Tree (BST).\n");
    }
    else
    {
        printf("The tree is NOT a Binary Search Tree (BST).\n");
    }

    return 0;
}

//      5
//    /   \
//   3     6
//  / \   
// 1   4
