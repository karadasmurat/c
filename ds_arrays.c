#include <stdio.h>
#include <stdlib.h>

void declaration();
void resizeDemo();

int main()
{
    declaration();
    // resizeDemo();
    return EXIT_SUCCESS;
}

void printScores(int size, int *arr)
{
    printf("[ ");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
void declaration()
{
    int scores[] = {70, 90, 80}; // allocated on the stack (for local arrays)
    printScores(3, scores);      // [ 70 90 80 ]

    // Use case: size is not known in advance (while writing source code)
    // We can specify the desired size of the memory block at runtime - user input
    // we can allocate memory dynamically, this brings flexibility
    // However the size of each allocated block remains fixed once it's created
    int capacity = 0;
    printf("Please enter number of students: ");
    scanf("%d", &capacity);
    int *scores_dynamic = (int *)calloc(capacity, sizeof(int)); // Allocate memory for 10 integers
    scores_dynamic[0] = 100;
    printScores(capacity, scores_dynamic); //[ 100 0 0 ... ]
}

void resizeDemo()
{
    // initialize using Array Literal
    int scores[] = {70, 60, 90, 80};

    // Create a new array with the desired size:
    int *newScores = (int *)calloc(8, sizeof(int));

    // Copy elements from the old array to the new array:
    for (int i = 0; i < 4; i++)
    {
        newScores[i] = scores[i];
    }

    // add new element to scores
    newScores[4] = 100;

    // print elements of newScores
    // 70 60 90 80 100 0 0 0
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", newScores[i]);
    }

    // Free the old array:
    // free(scores); // attempt to free on non-heap object
}