#include <stdio.h>
#include <stdlib.h>

struct Wizard
{
    char lastname[50];
    int birth_year;
};

typedef struct _Node
{
    int data;
    Node *next;
} Node;

struct Stack
{
    Node *top;
};

void initialize(struct Stack *stack)
{
    // Initialize top to NULL indicating an empty stack
    stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    // Construct a new Node by allocating memory and setting fields.
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    // Insert to the beginning
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Cannot pop from an empty stack.\n");
    }
    else
    {
        // since we will deallocate Node before returning, we need a reference to it
        Node *toBeDeleted = stack->top;
        int data = toBeDeleted->data;

        // remove from the beginning
        stack->top = stack->top->next;

        free(toBeDeleted);

        return data;
    }
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Cannot pop from an empty stack.\n");
    }
    else
    {
        return stack->top->data;
    }
}

int main(void)
{

    return EXIT_SUCCESS;
}