/*
TODO - work on this preliminary implementation
*/

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

struct Queue
{
    int arr[CAPACITY];
    // int front; // 0
    int rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue)
{
    // queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->rear == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return queue->rear == CAPACITY - 1;
}

// Function to push an element onto the stack
void enqueue(struct Queue *queue, int data)
{
    if (isFull(queue))
    {
        printf("Queue overflow: Cannot push %d, queue is full.\n", data);
        return;
    }
    queue->arr[++queue->rear] = data;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1; // Handle empty queue differently if needed
    }

    int data = queue->arr[0];

    // Shift elements to the left

    for (int i = 0; i < queue->rear; i++)
    {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear--;

    return data;
}
void printQueue(const struct Queue *queue)
{
    printf("[ ");
    for (int i = 0; i < CAPACITY; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("]\n");
}

int main()
{
    puts("Basic Queue Implementation using Array");

    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);

    printf("dequeue: %d\n", dequeue(&queue));

    enqueue(&queue, 30);

    printQueue(&queue);

    printf("dequeue: %d\n", dequeue(&queue));
    printf("dequeue: %d\n", dequeue(&queue));
    printQueue(&queue);

    return 0;
}