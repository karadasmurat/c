#include <stdio.h>

/* Function prototypes*/
void copy_pointers();
void swap (int *a, int* b);


int main(void){

    /*
       The memory address is the location of where the variable is stored on the computer. 
       A pointer basically is a variable storing the memory address of another variable as its value.
       
       A pointer variable points to a data type (like int) of the same type, and is created with the * operator. 
       In other words, when you see * in variable decleration, it is a pointer to the type specified left of it.
       i.e. char *p says p is a pointer to a variable of type char. (holds the address of a char variable)

       int n = 10;
       int* p = &n;
       
       int   : integer type
       int * : pointer to integer type (holding the ADDRESS of an integer)


    name    | p2 |    | p  |    | n  |    |
       --------------------------------------
    val     |1280|    |1280|    | 10 |    |
       --------------------------------------
    addr    |1024|    |1052|    |1280|    |             

    */

    int n = 10, y=5;
    
    printf("n: %d\n", n);   // the value of n (10)
    printf("&n: %p\n", &n); // memory address of n in hexadecimal form - i.e. 0x16d28b2a0

    int *p; // p is a pointer to int
    p = &n; // p is now equal to the address of n (points to n) (so *p = 10 now)

    // the value of p
    printf("p : %p\n", p); // i.e. 0x16d28b2a0

    // Dereference: GO to the address and GET the value, using * operator
    printf("*p: %d\n", *p); // 10

    y = *p + 4;	// y is now 14
    *p = 1;	// n is now 1 - modified through a pointer to it!

    // the values of integer variables
    printf("n: %d, y: %d\n", n, y); // n: 1, y: 14

    // if p points to integer, then *p can occur in any context where n could, so
    *p += 4;
    printf("*p: %d, n: %d\n", *p, n); // *p: 5, n: 5

    // size of a pointer to an integer (64 bits / 8 bytes on my machine)
    puts("---");
    printf("int   :Storage size: %zu bytes\n", sizeof(int)); // 4 bytes (32bits)
    printf("int * :Storage size: %zu bytes\n", sizeof(int *)); // 8 bytes (64bits)

    // when you copy a pointer, you copy its value, which is an address value - the address it refers to. 
    copy_pointers();

    int scores[] = {95, 90,100};
    // the name of the array is the base address of the contigious memory block allocated to it.
    // in other words, the name refers to the address of the first element.
    printf("\nscores    : %p\n", scores); // 0x16f53b2a8
    printf("&scores[0]: %p\n", &scores[0]); // 0x16f53b2a8
    printf("*scores: %d\n", *scores); // dereferencing
    printf("scores[0] : %d\n", scores[0]);


    char *s = "Hello, world!";
    puts("\n\n*s = \"Hello, world!\"");
    printf("*s   : %c\n", *s); // H (The first character)
    printf("s    : %p\n", s); // 0x... (pointer, address)
    printf("&s[0]: %p\n", &s[0]); // the address of the first element

    return 0;
}

// when you copy a pointer, you copy its value, which is an address value - the address it refers to. 
// dereferencing any one of them alters the variable they point to!
void copy_pointers(){

    puts("copy_pointers>");

    int var = 0;
    printf("var: %d\n", var);
    
    int* p1 = &var;
    printf("p1: %p\n", p1); // 0x16d6d728c
    
    int* p2 = p1;
    printf("p2: %p\n", p2); // 0x16d6d728c

    int* p3 = p2;
    printf("p3: %p\n", p3); // 0x16d6d728c

    // when you copy pointers, dereferencing any one of them alters the variable they point to!
    *p3 = 22;
    printf("var: %d\n", var);
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