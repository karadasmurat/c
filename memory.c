#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printArray(int *arr, int size);

int main()
{

    // Allocate memory for an array of 8 integers, with each element initialized to zero.
    int *initializedDynamicArray = (int *)calloc(8, sizeof(int));

    printArray(initializedDynamicArray, 8);

    return EXIT_SUCCESS;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}