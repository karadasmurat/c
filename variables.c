#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void enum_basics();
void array_basics();
void no_initialization_garbage();

int main(void){

    // limits defined in limits.h
    printf("INT_MAX: %d\n", INT_MAX);
    //unsigned int data type
    printf("unsigned int\nStorage size: %zu bytes \t Maximum value: %u\n\n", sizeof(unsigned int), UINT_MAX);

    /* Long decimal constants */
    long long_val = 10L;

    // the value of an integer can be specified in octal or hexadecimal instead of decimal
    // leading zero means octal, leading 0x hexadecimal.
    int decimal_val = 31;
    int octal_val = 037;
    int hex_val = 0X1F;

    printf("Decimal: %d, Octal: %d, Hex: %d\n", decimal_val, octal_val, hex_val);


    // increment
    // postfix increments the variable AFTER its value is used.
    int x = 10;
    int y = x++;
    printf("x: %d, y: %d\n", x, y); // x: 11, y: 10

    // prefix increments the variable BEFORE its value is used.
    x = 10;
    y = ++x;
    printf("x: %d, y: %d\n", x, y); // x: 11, y: 11

    enum_basics();

    array_basics();

    no_initialization_garbage();

    return 0;
}

void enum_basics(){
    // enumerations provide a convenient way to associate constant values with names.
    // the first name in an enum has value 0, the next 1, and so on, unless explicit values are specified.
    enum direction {North, South, East, West};
    enum month{JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC}; //FEB is 2, MAR is 3, etc.

    // declare a variable of type enum choice
    enum direction nav;
    enum month m;

    // assignment
    nav = West;
    m = SEP;

    printf("enum direction: %d\n", nav);
    printf("enum month: %d\n", m);
}
void no_initialization_garbage(){
    
    int val[5];

    for(int i = 0; i < 5; i++){
        printf("val[%d]: %d\n", i, val[i]);
    }
}

void array_basics(){

    // option 1
    // first declare the array with type, name and size, then initialize contents using index values
    int grades[3];
    
    printf("The address of first element: %p\n", grades); // i.e. 0x16bb1324c

    grades[0] = 90;
    grades[1] = 80;
    grades[2] = 95;


    // option 2
    // declare and initialize an array, size is inferred.
    int val[] = {1, 2, 3, 5, 8};


    // option 3 - dynamic memory allocation
    // point the address of first element
    int *years = malloc(3 * sizeof(int));
    *years = 2019;
    *(years + 1) = 2020;    // pointer arithmetic to get the next element
    years[2] = 2022;        // index, to get the specific element

    printf("The address of first element: %p\n", years);
    for (int i = 0; i < 3; i++)
    {
        printf("years[%d]: %d\n", i, years[i]);
    }

    // free memory
    free(years);

}

