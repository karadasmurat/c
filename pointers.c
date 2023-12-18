#include "mk_utils.h"
#include <stdio.h>

struct Student
{
    char name[50];
    int age;
};

/* Function prototypes*/
void pointer_sizes();
void copy_pointers();
void swap(int *a, int *b);
int increment_val(int n);
void increment_ref(int *n);
void printArray_ptr(int *arr, int size);
void printArray_arr(int arr[], int size);
void arrayOfPointers();

int main(void)
{

    /*
       The memory address is the location of where the variable is stored on the computer.
       A pointer basically is a variable storing the memory address of another variable as its value.

       A pointer variable points to a data type (like int) of the same type, and is created with the * operator.
       In other words, when you see * in variable decleration, it is a pointer to the type specified left of it.
       i.e. char *p says p is a pointer to a variable of type char. (holds the address of a char variable)

       int n = 7;           // integer type
       int* p = &n;         // pointer to integer type (holding the ADDRESS of an integer)
       int** p_to_p = &p;   // pointer to pointer (holding the ADDRESS of an ADDRESS)


        name     _p_to_p_    __  p __    __ n  __    __ x  __
                |        |  |        |  |        |  |        |
        val     | 0x200  |  | 0x100  |  |   7    |  |   3    |
                |_______ |  |________|  |________|  |________|
        addr    0x300       0x200       0x100       0x50

    To update n through a pointer to it, use DEREFERENCE -
    *p = 17; // Go get the value at address Ox100, n is now 17.

    To update p through a pointer to it, use DEREFERENCE -
    *p_to_p = &x; // Go get the value at address 0x200 (this is an address as well!), p is now 0x50.

    */

    int x = 10;
    int *ptr = &x; // initializes ptr with the address of x

    int n = 10, y = 5;

    printf("n: %d\n", n);   // the value of n (10)
    printf("&n: %p\n", &n); // memory address of n in hexadecimal form - i.e. 0x16d28b2a0

    //  A pointer variable points to a data type (like int) of the same type, and is created with the * operator.
    int *p; // p is a pointer to int
    p = &n; // p is now equal to the address of n (points to n) (so *p = 10 now)

    // the value of p
    printf("p : %p\n", p); // i.e. 0x16d28b2a0

    // Dereference: GO to the address and GET the value, using * operator
    printf("*p: %d\n", *p); // 10

    y = *p + 4; // y is now 14
    *p = 1;     // n is now 1 - modified through a pointer to it!

    // the values of integer variables
    printf("n: %d, y: %d\n", n, y); // n: 1, y: 14

    // if p points to integer, then *p can occur in any context where n could, so
    *p += 4;
    printf("*p: %d, n: %d\n", *p, n); // *p: 5, n: 5

    // size of a pointer to an integer (64 bits / 8 bytes on my machine)
    puts("---");
    printf("int   :Storage size: %zu bytes\n", sizeof(int));   // 4 bytes (32bits)
    printf("int * :Storage size: %zu bytes\n", sizeof(int *)); // 8 bytes (64bits)

    // when you copy a pointer, you copy its value, which is an address value - the address it refers to.
    copy_pointers();

    int scores[] = {95, 90, 100};
    // the name of the array is the base address of the contigious memory block allocated to it.
    // in other words, the name refers to the address of the first element.
    printf("\nscores    : %p\n", scores);   // 0x16f53b2a8
    printf("&scores[0]: %p\n", &scores[0]); // 0x16f53b2a8
    printf("*scores: %d\n", *scores);       // 95 dereferencing
    printf("scores[0] : %d\n", scores[0]);  // 95 dereferencing

    char *s = "Hello, world!";
    puts("\n\n*s = \"Hello, world!\"");
    printf("*s   : %c\n", *s);    // H (The first character)
    printf("s    : %p\n", s);     // 0x... (pointer, address)
    printf("&s[0]: %p\n", &s[0]); // the address of the first element

    int cnt = 0;

    // Pass a copy of the value of 'cnt' to the function
    // The function returns the modified copy - assign the return value back to the original argument
    cnt = increment_val(cnt);
    printf("%d\n", cnt); // 1

    // Pass the address of 'cnt' to the function
    // No return, original argument is modified directly
    increment_ref(&cnt); // 2

    printf("%d\n", cnt);

    int numbers[] = {2, 4, 6, 8, 10};
    printArray_ptr(numbers, 5); // [ 2 4 6 8 10 ]
    printArray_arr(numbers, 5); // [ 2 4 6 8 10 ]

    pointer_sizes();
    arrayOfPointers();
    return 0;
}

void pointer_sizes()
{
    puts("Pointer Sizes");
    puts("-------------");

    int *iptr;
    char *cptr;
    struct Student *sptr;

    printf("int: %zu\n", sizeof(*iptr));            // 4 bytes
    printf("int *: %zu\n", sizeof(iptr));           // 8 bytes
    printf("char: %zu\n", sizeof(*cptr));           // 1 byte
    printf("char *: %zu\n", sizeof(cptr));          // 8 bytes
    printf("struct Person: %zu\n", sizeof(*sptr));  // 56 bytes (2 bytes padding)
    printf("struct Person *: %zu\n", sizeof(sptr)); // 8 bytes
}

void arrayOfPointers()
{
    puts("Array of Pointers");
    puts("-----------------");

    int std1_math = 50;
    int std1_eng = 51;
    int std1_sci = 52;

    // v1. declare an array of pointers
    // note that pointer can be pointing to a primitive, or an array (the first element of an array)
    int *scores_std1[] = {&std1_math, &std1_eng, &std1_sci};

    print_array(*scores_std1, 3);

    // declare and initialize math, eng and sci as an array of integers.
    // note that these arrays have different lengths.
    int math[] = {80, 90, 70};
    int eng[] = {81, 91, 71, 61, 51};
    int sci[] = {82, 92, 72, 62};

    // v2. declare an array of pointers: each array element is a pointer
    // note. the name of an array (ie, math) is a pointer - holds the address of first element.
    int *scores_all[] = {math, eng, sci};

    print_array(scores_all[0], 3); // [ 80 90 70 ]
    print_array(scores_all[1], 5); // [ 81 91 71 61 51 ]
    print_array(scores_all[2], 4); // [ 82 92 72 62 ]

    // double pointer??
    printf("%p\n", scores_all);   // pointer to array of pointers
    printf("%p\n", *scores_all);  // pointer to array of ints
    printf("%d\n", **scores_all); // 80
}
// when you copy a pointer, you copy its value, which is an address value - the address it refers to.
// dereferencing any one of them alters the variable they point to!
void copy_pointers()
{

    puts("copy_pointers>");

    int var = 0;
    printf("var: %d\n", var);

    int *p1 = &var;
    printf("p1: %p\n", p1); // 0x16d6d728c

    int *pcopy = p1;
    printf("pcopy: %p\n", pcopy); // 0x16d6d728c

    int *p3 = pcopy;
    printf("p3: %p\n", p3); // 0x16d6d728c

    // when you copy pointers, dereferencing any one of them alters the variable they point to!
    *p3 = 22;
    printf("var: %d\n", var);
}

/*
This function will make a local copy of the argument passed to this function,
increment the copy by one, and then return it.
*/
int increment_val(int n)
{

    return ++n;
}

/*
This function accepts a pointer to an integer (address of an integer), and
increments the value at the memory location pointed to by that pointer.

Changes made to the variable inside the function will persist outside the function
because the function works directly with the memory location of the original variable.
*/
void increment_ref(int *n)
{
    (*n)++;
}

/*
 * parameters are declared as pointers
 * the operands are accessed indirectly through them
 * (caller pass the addresses of its variables, and called can modify them directly through these addresses)
 */
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function that accepts an array of integers
void printArray_ptr(int *arr, int size)
{
    printf("[ ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void printArray_arr(int arr[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
