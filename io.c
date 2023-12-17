#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;

    printf("Enter first number: ");
    printf("[%s: %d]\n", "max in the range", INT_MAX);

    scanf("%d", &a);

    printf("Enter second number: ");
    scanf("%d", &b);

    printf("First : %d \t Second : %d\n", a, b);

    return EXIT_SUCCESS;
}