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


    return 0;
}