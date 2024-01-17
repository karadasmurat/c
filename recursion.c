#include "validation.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int sumUpTo(int n);

int main()
{

    int sum1 = sumUpTo(-1);
    printf("%d\n", sum1);

    int sum2 = sumUpTo(0);
    printf("%d\n", sum2);

    int sum3 = sumUpTo(5);
    printf("%d\n", sum3);

    return EXIT_SUCCESS;
}

int sumUpTo(int n)
{
    if (!isPositiveInteger(n))
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    // base case
    if (n == 1)
    {
        return 1;
    }

    return n + sumUpTo(n - 1);
}