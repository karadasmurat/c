/*
 Remember to compile all relevant source files together.
 For example, if you have main.c and mk.c, you would typically compile and link them together:

$ clang main.c mk.c -o out/main
*/

#include "mk.h"
#include <stdlib.h>

int main(void)
{
    mk("MSL"); // declared in mk.h, defined in mk.c

    return EXIT_SUCCESS;
}

#define SUM(a, b) (a + b)