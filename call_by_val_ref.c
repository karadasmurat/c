#include <stdio.h>

/* Function prototypes*/
void increment_by_val(int arg);
void increment_byref(int* arg);
int sum(int a, int b, int result[]);

int main(void){

    int var = 0;
    printf("var: %d\n", var);
    
    int* p1 = &var;
    printf("p1: %p\n", p1); // 0x16d7b732c
    
    int* p2 = p1;
    printf("p2: %p\n", p2); // 0x16d7b732c

    int* p3 = p2;
    printf("p3: %p\n", p3); // 0x16d7b732c

    // when you copy pointers, dereferencing any one of them alters the variable they point to!
    *p3 = 22;
    printf("var: %d\n", var);

    int a = 90;
    int b = 95;
    int my_array[] = {0};

    printf("main > Values before function call:\n");  
    printf("main > a: %d\n", a);    
    //printf("main > b: %d\n", b);                        // b: 95
    //printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 0

    increment(a);

    printf("main > a: %d\n", a); 

    //int result = sum(a, b, my_array);

    //printf("main > b: %d, result: %d\n", b, result);    // b: 95, result: 90
    //printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 90

    increment_byref(&a);

    printf("main > a: %d\n", a); 


}
/* Call by value */
int sum(int a, int b, int r[]){
    
    // the parameters are used as temporary variables.
    // each local variable in a function comes into existence only when the function is called and disappears when the function is exited.
    // whatsoever is  done to parameters inside this function has no effect on the argument that it has been called with.
    // in other words, this function does not directly alter a variable in the calling function.

    b = 0; // modification of the int parameter
    printf("sum  > b: %d\n", b);

    int sum = a+b;

    // the story is different for the arrays. When the name of an array is used as an argument, the value passed to the function is
    // the location or address of the beginning of the array - there is no copying of array elements.

    r[0] = sum; // modification the array parameter
    printf("sum  > r[0]: %d\n", r[0]);

    return a + b;
}

void increment_by_val(int arg){
    // a local copy of the argument is created. it has the same value
    arg += 1;
    printf("increment_by_val> arg: %d\n", arg);
}

/* 
* parameter declared as pointers and the operands are accessed indirectly through them 
* (caller pass the addresses of its variables, and called can modify them directly through these addresses)
*/
void increment_by_ref(int *arg){
    // a local copy of the argument is created. it has the same value, which is an address of int (pointer)
    // when dereferenced, it changes "the same" variable anyways!
    // when you copy pointers, dereferencing any one of them alters the variable they point to!
    *arg += 1;
    printf("increment_by_ref> arg: %d\n", *arg);
}


// when necessary, it is possible to arrange for a function to modify a variable in a calling routine.
// the caller must provide the address of the variable to be set (technically a pointer to the variable)
// and the called function must declare the parameter to be a pointer, and access the variable indirectly through it.