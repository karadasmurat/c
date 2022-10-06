#include <stdio.h>

int main(void){

    int n = 10, y=5;
    
    // the values of integer variables
    printf("n: %d, y: %d\n", n, y);

    int *p; // p is a pointer to int
    p = &n; // p now points to n

    // the address of n
    printf("&n: %p\n", &n); // i.e. 0x16d28b2a0

    // the value of p
    printf("p : %p\n", p); // i.e. 0x16d28b2a0

    // the value of *p
    printf("*p: %d\n", *p); // 10

    y = *p;	// y is now 10
    *p = 1;	// n is now 1 - modified through pointer!


    // the values of integer variables
    printf("n: %d, y: %d\n", n, y); // n: 1, y: 10


    // size of a pointer to an integer (64 bits / 8 bytes on my machine)
    printf("int   :Storage size: %zu bytes\n", sizeof(int)); // 4 bytes (32bits)
    printf("int * :Storage size: %zu bytes\n", sizeof(int *)); // 8 bytes (64bits)

    int scores[] = {95, 90,100};
    printf("\n\nscores    : %p\n", scores); // 0x16f53b2a8
    printf("&scores[0]: %p\n", &scores[0]); // 0x16f53b2a8
    printf("scores[0]: %d\n", scores[0]);


    char *s = "Hello, world!";
    printf("\n\n*s = \"Hello, world!\"\n");
    printf("*s   : %c\n", *s); // H (The first character)
    printf("s    : %p\n", s); // 0x... (pointer, address)
    printf("&s[0]: %p\n", &s[0]); // the address of the first element


    return 0;
}