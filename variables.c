#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define ARR_SIZE 3

void enum_basics();
void array_basics();
void no_initialization_garbage();
void char_basics();
void print_reverse(char * s);

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

    // char_basics();

    // enum_basics();

    array_basics();

    // no_initialization_garbage();

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

    puts("\n--- array basics ---");

    // option 1
    // first declare the array with type, name and size, then initialize contents using index values
    int students[10];

    int grades[ARR_SIZE]; // use a symbolic constant ARR_SIZE whose value is 3.
    
    grades[0] = 9;
    grades[1] = 7;
    grades[2] = 8;

    //the name of the array is a pointer containing the address of initial element
    printf("grades      : %p\n", grades);       // 0x16f7871fc
    printf("&grades[0]  : %p\n", &grades[0]);   // 0x16f7871fc

    printf("\n%20s\n", "Histogram");
    for(int i =0; i< ARR_SIZE; i++){
        printf("grades[%d]  ", i);
        for(int j =0; j< grades[i]; j++){
            printf("%c", '*');
        }
        printf("\n");
    }


    // option 2
    // declare and initialize an array using curly braces. (size is inferred)
    int val[] = {1, 2, 3, 5, 8};
    char surname[] = "Black"; 


    // option 3 - dynamic memory allocation
    // allocate space and point the address of first element
    int *years = (int*) malloc(ARR_SIZE * sizeof(int));
    *years = 2019;          // *years  = value at the (go to) first address = years[0]
    *(years + 1) = 2020;    // pointer arithmetic to get the value at the next address = years[1] (offset is 1)
    years[2] = 2022;        // index, to get the specific element

    printf("\nThe address of first element: %p\n", years);
    printf("%9s%13s\n", "Element", "Value");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("years[%d]%13d\n", i, years[i]);
    }

    // free memory
    free(years);


    // Instead of strings, C uses an array of single characters.
    // initialize using string literals (double quoted list of characters)
    char name[] = "Murat"; // this actually is {'M','u','r','a','t','\0'}; so 6 element array is used to store 5 charecter string.
    puts("\nUse array name: ");
    printf("name: %s\n", name);

    puts("\nloop array of single characters");
    int i = 0;
    while (name[i] != '\0'){
        printf("%c", name[i++]); //print i then increment (postfix)
    }
    

}

void char_basics(){

    puts("\n--- char basics ---");

    char initials_name = 'M';
    char initials_surname = 'K';

    printf("Initials: %c%c\n", initials_name, initials_surname);
    printf("Initials as int: %d %d\n", initials_name, initials_surname);

    // C Language does not support strings out of the box.
    // Instead of strings, C uses an array of single characters.

    // initialize using double quotes
    // Option 1: square braces []
    char name[] = "Murat"; // this actually is {'M','u','r','a','t','\0'}; so 6 element array is used to store 5 charecter string.
    
    printf("name: %s\n", name);

    // Option 2: USING A POINTER *
    // string literals are designed to be constant, stored in read-only memory
    // const modifier means that your compiler will complain if you try to modify an array with that particular variable.
    const char *surname = "Karadas"; 

    // if you want to modify a string, you need to make a copy in a new array.
    // surname[0] = 'Q'; // BUS ERROR

    // the variable "surname" points to the beginning of string
    // in other words, it contains the ADDRESS of the FIRST character
    printf("Address of the first character - surname: %p\n", surname); // ie. 0x10431ff28
    printf("the first character - *surname  : %c\n", *surname); // K
    printf("the first character - surname[0]: %c\n", *surname); // K
    
    // the char array (string)
    printf("Surname, Name: %s, %s\n", surname, name);


    // string.h functions
    printf("Length of surname: %lu\n", strlen(surname));

    // dynamic memory allocation
    // allocate space and point the address of first element
    char *degree = malloc(3 * sizeof(char));
    *degree = 'B';          // *degree = value at the (go to) first address = degree[0] (offset is zero)
    *(degree + 1) = 'S';    // *(degree+1) = value of (go to) next address = degree[1] (offset is one)
    degree[2] = 'c';

    printf("Degree: %s\n", degree);

    print_reverse(surname);

    // if string is an array of char: []
    // array of string is an array of array of char: [][]
    
}

void print_reverse(char *str){

    int len = 0;
    len = strlen(str);
    
    // while(str[len] != '\0')
    //     len++;
    
    char *tail = str + len - 1;

    while(tail >= str){
        printf("%c", *tail);
        tail--;
        //len--;
    }

}

