#include <stdio.h>

int sum(int a, int b, int result[]);

int main(void){

    int a = 90;
    int b = 95;
    int my_array[] = {0};

    printf("main > Values before function call:\n");   
    printf("main > b: %d\n", b);                        // b: 95
    printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 0

    int result = sum(a, b, my_array);

    printf("main > Values after function call:\n");  
    printf("main > b: %d, result: %d\n", b, result);    // b: 95, result: 90
    printf("main > my_array[0]: %d\n", my_array[0]);    // my_array[0]: 90

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


// when necessary, it is possible to arrange for a function to modify a variable in a calling routine.
// the caller must provide the address of the variable to be set (technically a pointer to the variable)
// and the called function must declare the parameter to be a pointer, and access the variable indirectly through it.