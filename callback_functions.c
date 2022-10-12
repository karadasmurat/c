#include <stdio.h>

// the input/output schemes of add and multiply functions are the same (return types as well as type and number of args)
// therefore, they can be represented by the same pointer to function: int (*f) (int, int) 
// just replace the name of the function with (*fname)
int add(int x, int y);
int multiply(int x, int y);

int op(int x, int y, int (*f)(int, int)); // call the arg as f(x, y)

void sayHi();

// the argument is a pointer to a void function with no parameters: void (*f)() 
void greet(void (*f)());

int main(int argc, char* args[]){

    int a = 10;
    int b = 5;

    // call a function using another function as parameter
    // the name of the function is a pointer to it, so it can be used as a function pointer.

    // example 1
    greet(sayHi);

    //example 2
    int result = op(a, b, add);
    printf("a op b: %d\n", result );

    result = op(a, b, multiply);
    printf("a op b: %d\n", result );
}

// function pointer as an argument
// int (*f) (int, int)
int op(int x, int y, int (*f)(int, int)){

    puts("op> I will now call a function, and I have no idea what it will do!");

    // call the argument, which is of type function pointer
    return f(x, y);
}

int add(int x, int y){
    printf("add> %d, %d\n", x, y);
    return x + y;
}

int multiply(int x, int y){
    printf("multiply> %d, %d\n", x, y);
    return x * y;
}

void sayHi(){
    puts("sayHi> Hello, there");
}

void greet(void (*f)()){
    // call the argument, which is of type function pointer
    f();
}