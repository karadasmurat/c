#include "mk.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    mk("MSL");

    return EXIT_SUCCESS;
}

// function definition (implementation), which is declared in mk.h header
void mk(const char *arg)
{
    printf("MK says hi, %s!\n", arg);
}