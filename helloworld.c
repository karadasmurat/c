/*
 How to compile and run the first program
 Apple ships the clang/LLVM compiler with macOS, a common compiler used to compile C code.

 $ clang --version
 Apple clang version 13.1.6 (clang-1316.0.21.2.5)

 $ clang helloworld.c
 $ ./a.out
*/

#include <stdio.h>

int main(void)
{
    printf("Hello, world!");

    return 0;
}

void tmp(int score)
{
    int num1 = 10, num2 = 20, num3 = 30, num4 = 40;

    // Declare an array of pointers to integers
    int *nums[] = {&num1, &num2, &num3, &num4};
}

