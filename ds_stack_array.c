/*
TODO - work on this preliminary implementation
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

struct Stack
{
    int arr[CAPACITY];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1; // Initialize top to -1 indicating an empty stack
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == CAPACITY - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack overflow: Cannot push %d, stack is full.\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow: Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

// Function to get the top element of the stack without popping
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");

    return 0;
}
