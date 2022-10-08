#include <stdio.h>

void increment_by_val(int arg);
void increment_by_ref(int *arg);
void swap (int *a, int* b);


int main(void){

    int n = 10, y=5;
    
    // the values of integer variables
    printf("n: %d, y: %d\n", n, y);

    int *p; // p is a pointer to int
    p = &n; // p now points to n (so *p = 10 now)

    // the address of n
    printf("&n: %p\n", &n); // i.e. 0x16d28b2a0

    // the value of p
    printf("p : %p\n", p); // i.e. 0x16d28b2a0

    // the value of *p
    printf("*p: %d\n", *p); // 10

    y = *p + 4;	// y is now 14
    *p = 1;	// n is now 1 - modified through pointer!


    // the values of integer variables
    printf("n: %d, y: %d\n", n, y); // n: 1, y: 10


    // size of a pointer to an integer (64 bits / 8 bytes on my machine)
    printf("int   :Storage size: %zu bytes\n", sizeof(int)); // 4 bytes (32bits)
    printf("int * :Storage size: %zu bytes\n", sizeof(int *)); // 8 bytes (64bits)

    // if p points to integer, then *p can occur in any context where n could, so
    *p += 4;
    printf("*p: %d, n: %d\n", *p, n); // *p: 5, n: 5


    int scores[] = {95, 90,100};
    printf("\n\nscores    : %p\n", scores); // 0x16f53b2a8
    printf("&scores[0]: %p\n", &scores[0]); // 0x16f53b2a8
    printf("scores[0]: %d\n", scores[0]);


    char *s = "Hello, world!";
    printf("\n\n*s = \"Hello, world!\"\n");
    printf("*s   : %c\n", *s); // H (The first character)
    printf("s    : %p\n", s); // 0x... (pointer, address)
    printf("&s[0]: %p\n", &s[0]); // the address of the first element


    int count = 1;
    printf("\n\ninitial value before function calls: %d\n", count);

    increment_by_val(count);
    printf("after function call by val: %d\n", count);

    increment_by_ref(&count);
    printf("after function call by ref: %d\n", count);

    return 0;
}

void increment_by_val(int arg){
    arg += 1;
}

/* 
* parameters are declared as pointers
* the operands are accessed indirectly through them 
* (caller pass the addresses of its variables, and called can modify them directly through these addresses)
*/
void increment_by_ref(int *arg){
    *arg += 1;
}

/* 
* parameters are declared as pointers
* the operands are accessed indirectly through them 
* (caller pass the addresses of its variables, and called can modify them directly through these addresses)
*/
void swap (int *a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

}