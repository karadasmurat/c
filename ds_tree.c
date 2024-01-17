/*
TODO - work on this preliminary implementation
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Constructor function
struct Node *newNode(int value)
{
    printf("Constructing a new Node with data: %d\n", value);

    // memory allocation
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    // ensures all fields of the Node struct are properly initialized
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool hasNoLeftChild(struct Node *node)
{
    return node->left == NULL;
}

bool hasNoRightChild(struct Node *node)
{
    return node->right == NULL;
}

bool isLeaf(struct Node *node)
{
    return hasNoLeftChild(node) && hasNoRightChild(node);
}

void traverse_inOrder(struct Node *node)
{
    // base case: out of tree
    if (node == NULL)
        return;

    traverse_inOrder(node->left); // left subtree
    printf("%d ", node->data);
    traverse_inOrder(node->right); // right subtree
}

void push(struct Node *node, struct Node *newNode)
{
    if (newNode->data <= node->data)
    {
        if (hasNoLeftChild(node))
        {
            printf("Inserting %d to the left of %d\n", newNode->data, node->data);
            node->left = newNode;
        }
        else
            push(node->left, newNode); // left subtree
    }
    else
    {
        if (node->right == NULL)
        {
            printf("Inserting %d to the right of %d\n", newNode->data, node->data);
            node->right = newNode;
        }
        else
            push(node->right, newNode); // right subtree
    }
}

int main()
{
    puts("Tree Basics");
    struct Node *root = newNode(8);
    struct Node *node4 = newNode(4);
    struct Node *node12 = newNode(12);
    struct Node *node2 = newNode(2);
    struct Node *node3 = newNode(3);

    push(root, node4);
    push(root, node12);
    push(root, node2);
    push(root, node3);

    traverse_inOrder(root);
}