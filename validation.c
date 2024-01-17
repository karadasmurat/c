#include <limits.h>
#include <stdbool.h>

bool isPositiveInteger(int n)
{
    // Check for valid integer and positive value
    return (n > 0 && n < INT_MAX);
}