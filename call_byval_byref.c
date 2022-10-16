/*
    By default, C uses call by value to pass arguments.

    Values of actual parameters (parameters passed to function) are COPIED 
    to function’s formal parameters (local dummy variables) and stored in different memory locations. 
    So any changes made inside functions are not reflected in actual parameters of the caller.

    But, when you pass the address of a variable, the local copy will have the same address as its value.
    Therefore, when dereferenced, it will change the actual parameter provided by calling function.

    the address of a variable is a pointer : *
    the address of a pointer is a pointer to pointer : **

    if you want to define a function to modify actual parameters (the variable of the calling function),

        Option 2:
        function definition has the same type of actual parameter, and function RETURNS that value.
        Calling function assigns the actual parameter to return value. ie:  f(int x), and call using x = f(x)

        Option 1: 
        function definition should have the type as "the address" (pointer to it.) i.e. 
        if calling function has int x, define the function to accept int* : f(int* arg), and call with the address f(&x)
        if calling function has int* x, define the function to accept int** : f(int** arg), and call with the address f(&x)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int data;
    struct _node *next;
} node;

/* Function prototypes*/
void increment_by_val(int arg);
void increment_byref(int* arg);
int return_incremented(int arg);
void modify_actual_parameter__primitive(int* arg);
void modify_actual_parameter__pointer(node** arg);
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
 
    printf("main > a: %d\n", a);    
    //printf("main > b: %d\n", b);                        // b: 95
    //printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 0

    // send the address of a primitive (pointer to it) to modify its value.
    modify_actual_parameter__primitive(&a);

    printf("main > a: %d\n", a); 

    //int result = sum(a, b, my_array);

    //printf("main > b: %d, result: %d\n", b, result);    // b: 95, result: 90
    //printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 90

    int score = 99;
    printf("main > score: %d\n", score); 
    score = return_incremented(score);
    printf("main > score: %d\n", score); 


    // allocate memory and get a pointer to it: list variable contains the beginning address.
    node* list = (node*) malloc(sizeof(node));

    printf("main > list: %p\n", list); 

    // we have a pointer, and suppose we want to modify its value (address stored in this variable)
    // send the address of this pointer 
    modify_actual_parameter__pointer(&list);

    printf("main > list: %p\n", list);  


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

// send the address of a primitive to modify its value.
void modify_actual_parameter__primitive(int* arg){

    puts("modify_actual_parameter__primitive > begin."); 

    // a local copy of arg is created. it has the same value, which is an address of int (pointer)
    // when dereferenced, it changes "the same" primitive variable anyways!
    // when you copy pointers, dereferencing any one of them alters the variable they point to!

    // dereference formal parameter to modify actual parameter provided by calling function
    (*arg)++;

}

// send the address of a pointer to modify its value. (the address value stored in the pointer)
void modify_actual_parameter__pointer(node** arg){

    puts("modify_actual_parameter__pointer > begin."); 

    // create a new struct node, get a pointer to it
    node* n = (node*) malloc(sizeof(node));

    // dereference formal parameter to modify actual parameter provided by calling function
    (*arg) = n;
}

int return_incremented(int arg){
    // a local copy of arg is created. it has the same value, which is int.
    // then this copy is incremented, and RETURNED.

    puts("return_incremented> begin."); 
    return ++arg;
}

void increment_by_val(int arg){
    // a local copy of arg is created. it has the same value, which is int.
    // then this copy is incremented. actual parameter is not modified. 
    // you can RETURN this copy and assign it to actual parameter manually. 
    arg++;
}

// when necessary, it is possible to arrange for a function to modify a variable in a calling routine.
// the caller must provide the address of the variable to be set (technically a pointer to the variable)
// and the called function must declare the parameter to be a pointer, and access the variable indirectly through it.
