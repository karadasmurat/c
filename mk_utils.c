#include <stdio.h>

void print_array(int *arr, size_t size)
{
    printf("%s", "[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    puts("]\n");
}

// Example code to test
int add(int a, int b)
{
    return a + b;
}