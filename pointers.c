#include <stdio.h>

int main(void){

    int n = 100;
    int *p = &n;

    // the value of n
    printf("n : %d\n", n);

    // the address of n
    printf("&n: %p\n", &n);

    // the value of p
    printf("p : %p\n", p);

    // the value of *p
    printf("*p: %d\n", *p);

    // size of a pointer to an integer
    printf("int   :Storage size: %zu bytes\n", sizeof(int)); // 4 bytes (32bits)
    printf("int * :Storage size: %zu bytes\n", sizeof(int *)); // 8 bytes (64bits)


    return 0;
}