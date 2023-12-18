#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 3

// enumerations provide a convenient way to associate constant values with names.
// the first name in an enum has value 0, the next 1, and so on, unless explicit values are specified.
enum DIRECTION
{
    North, // 0
    South, // 1
    East,  // 2
    West   // 3
};

enum MONTH
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
}; // FEB is 2, MAR is 3, etc.

typedef enum _AccountType
{
    Savings,
    Checking,
    MoneyMarket
} AccountType;

void numberBasics();
void booleanBasics();
void stringBasics();
void castingBasics();
void enum_basics();
void array_basics();
void no_initialization_garbage();
void char_basics();
void print_reverse(char *s);
enum DIRECTION redirectSouthToNorth(enum DIRECTION dir);
void acceptEnumType(AccountType accType);
void printInteger(int n);

int main(void)
{
    // numberBasics();
    // booleanBasics();
    array_basics();
    // stringBasics();
    // castingBasics();
    // char_basics();
    // enum_basics();

    // no_initialization_garbage();

    return 0;
}

void numberBasics()
{
    // puts automatically appends a newline character ('\n') at the end of the string.
    puts("Number Basics");
    puts("--------------");

    // declare a variable, assignin a type and an identifier (name)
    int n1;

    // declare and initialize a variable
    int n2 = 1;

    // We can declare multiple variables in any single declaration, but doing so can get confusing
    // Declarations can be easier to understand if each is on its own line
    int a, b, c;

    unsigned int ui; // unsigned is required, int can be omitted

    // the value of an integer can be specified in decimal, octal or hexadecimal
    // leading zero means octal, leading 0x hexadecimal.
    int decimal_val = 31; // Digits are ... 10^2, 10^1, 10^0
    int octal_val = 037;  // Digits are ... 8^2, 8^1, 8^0
    int hex_val = 0X1F;   // Digits are ... 16^2, 16^1, 16^0

    printf("Decimal: %d, Octal: %d, Hex: %d\n", decimal_val, octal_val, hex_val);

    /* Long decimal constants */
    long long_val = 10L;

    double fp1 = 10.0;       /* type double */
    float fp2 = 10.0F;       /* type float */
    long double fp3 = 10.0L; /* type long double */

    // limits defined in limits.h
    printf("INT_MAX: %d\n", INT_MAX);
    // unsigned int data type
    printf("unsigned int\nStorage size: %zu bytes \t Maximum value: %u\n\n", sizeof(unsigned int), UINT_MAX);

    // increment
    // postfix increments the variable AFTER its value is used.
    int x = 10;
    int y = x++;
    printf("x: %d, y: %d\n", x, y); // x: 11, y: 10

    // prefix increments the variable BEFORE its value is used.
    x = 10;
    y = ++x;
    printf("x: %d, y: %d\n", x, y); // x: 11, y: 11

    // Increment and Decrement Operators
    int cnt = 0;
    int res;                            // result of the expression
    res = cnt++;                        // postfix increment: res = cnt; cnt = cnt +1
    printf("res:%d, cnt:%d", res, cnt); // res:0, cnt:1

    res = cnt--;                        // postfix decrement: res = cnt; cnt = cnt -1
    printf("res:%d, cnt:%d", res, cnt); // res:1, cnt:0

    res = ++cnt;                        // prefix increment
    printf("res:%d, cnt:%d", res, cnt); // res:1, cnt:1

    res = --cnt;                        // prefix decrement:
    printf("res:%d, cnt:%d", res, cnt); // res:0, cnt:0
}

void booleanBasics()
{
    // C does not have a built-in boolean data type
    // The <stdbool.h> header, introduced in the C99 standard, provides a boolean type and associated macros to improve
    // code readability. The bool type is defined as an alias for _Bool, and the macros true and false are defined.

    // puts automatically appends a newline character ('\n') at the end of the string.
    puts("Boolean Basics");
    puts("--------------");

    bool condition = true;

    if (condition)
    {

        puts("condition is true!\n");
    }
    else
    {
        puts("condition is false!");
    }
}

void stringBasics()
{
    puts("String Basics");
    puts("--------------");

    // The name array has been declared with a size of 100 characters, and
    // it has been initialized with the string "MK"
    char name[100] = "MK";

    // Calculate the length of the string
    size_t length = strlen(name);

    // Print the length and size
    printf("string: %s\n", name);
    printf("Length of the string: %zu\n", length);
    printf("Size of the array: %zu\n", sizeof(name));

    // COPY
    char firstname[] = "MSL";

    printf("%p: %s %c\n", firstname, firstname, *firstname); // 0x16b23ee84: MSL M

    // firstname = "ABC"; // Error: You can't assign a new value to the array

    strcpy(firstname, "BRC"); // Copy "BRC" into the array

    printf("%p: %s %c\n", firstname, firstname, *firstname); // 0x16b23ee84: BRC B
}

void castingBasics()
{
    int a = 5;
    float b = 2.5;

    float result = a + b;     // Implicit conversion of 'a' to float before addition
    printf("%.2f\n", result); // 7.50

    double pi = 3.14159;
    int roundedPi = (int)pi; // Explicitly cast double to int

    // a pointer to a string literal
    const char *numberString = "12345";

    // an array, and it provides a modifiable buffer to hold the string.
    const char text[] = "123.45";

    // Convert ASCII string to integer
    int intValue = atoi(numberString);

    // Convert ASCII string to float
    float fVal = atof(numberString);

    printf("%d %.2f\n", intValue, fVal); // 12345 12345.00
}

void enum_basics()
{

    // declare a variable of type enum DIRECTION
    enum DIRECTION nav;
    enum MONTH m;

    // assignment
    nav = South;
    m = SEP;

    printf("enum direction: %d\n", nav);
    printf("enum month: %d\n", m);

    printf("%d", redirectSouthToNorth(nav));

    // An enumeration constant can be used anywhere the C language permits an integer expression.
    printInteger(333);
    printInteger(East);

    acceptEnumType(Checking);
    acceptEnumType(0);
}

// Function that accepts a parameter and returns type enum
enum DIRECTION redirectSouthToNorth(enum DIRECTION dir)
{
    return dir == South ? North : dir;
}

void acceptEnumType(AccountType accType)
{
    switch (accType)
    {
    case Savings:
        puts("Savings account.");
        break;

    default:
        puts("Not a savings account");
        break;
    }
}

void printInteger(int n)
{
    printf("printInteger: %d", n);
}

void no_initialization_garbage()
{

    int val[5];

    for (int i = 0; i < 5; i++)
    {
        printf("val[%d]: %d\n", i, val[i]);
    }
}

void multidimensionalArrayBasics()
{
    puts("MultiDimensional Array Basics");
    puts("-----------------------------");

    // Declaration of a 2x3 char array
    char A[2][3];

    // Assigning values to the elements of the array
    A[0][0] = 'A';
    A[0][1] = 'B';
    A[0][2] = 'C';
    A[1][0] = 'D';
    A[1][1] = 'E';
    A[1][2] = 'F';

    // Declaration of a 2D array, with arrays as members:
    int scores[][3] = {{70, 77, 75}, {90, 99, 95}};

    // Loop 2-D Array to access the elements:
    // 70 77 75
    // 90 100 95
    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            printf("%d ", scores[r][c]);
        }
        printf("\n");
    }
}

void stringArrays()
{
    // We know that C  implements strings as arrays of characters.
    // Therefore, we can represent an array of strings as an array of arrays
    // using a two-dimensional character array
    // The size[20] indicates the maximum length of each string(including the null terminator).
    char fruits[4][20] = {"Apple", "Banana", "Orange", "Grapes"};

    // Access and print individual strings
    for (int i = 0; i < 4; ++i)
    {
        printf("%s ", fruits[i]);
    }
}

void array_basics()
{
    puts("Array Basics");
    puts("------------");

    // option 1
    // first declare the array with type, name and size, then initialize contents using index values
    int students[100];
    char house[100]; // name of house, string, as an array of characters

    printf("%zu %zu", sizeof(students), sizeof(house)); // 400, 100

    int grades[ARR_SIZE]; // use a symbolic constant ARR_SIZE whose value is 3.

    grades[0] = 9;
    grades[1] = 7;
    grades[2] = 8;

    // the name of the array is a pointer containing the address of initial element
    printf("grades      : %p\n", grades);     // 0x16f7871fc
    printf("&grades[0]  : %p\n", &grades[0]); // 0x16f7871fc

    printf("\n%20s\n", "Histogram");
    for (int i = 0; i < ARR_SIZE; i++)
    {
        printf("grades[%d]  ", i);
        for (int j = 0; j < grades[i]; j++)
        {
            printf("%c", '*');
        }
        printf("\n");
    }

    // option 2
    // declare and initialize an array using curly braces. (size is inferred)
    int val[] = {1, 2, 3, 5, 8};
    char surname[] = "Black";

    // option 2.1
    // int *favs = {3, 5, 8}; // incompatible integer to pointer conversion

    // option 3 - dynamic memory allocation
    // allocate space and point the address of first element
    // note that the name of an array is a pointer to first element
    int *years = (int *)malloc(ARR_SIZE * sizeof(int));
    *years = 2019;       // *years  = value at the (go to) first address = years[0]
    *(years + 1) = 2020; // pointer arithmetic to get the value at the next address = years[1] (offset is 1)
    years[2] = 2022;     // index, to get the specific element

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
    char name[] =
        "Murat"; // this actually is {'M','u','r','a','t','\0'}; so 6 element array is used to store 5 charecter string.
    puts("\nUse array name: ");
    printf("name: %s\n", name);

    puts("\nloop array of single characters");
    int i = 0;
    while (name[i] != '\0')
    {
        printf("%c", name[i++]); // print i then increment (postfix)
    }

    multidimensionalArrayBasics();
    stringArrays();
}

void char_basics()
{

    puts("\n--- char basics ---");

    char initials_name = 'M';
    char initials_surname = 'K';

    printf("Initials: %c%c\n", initials_name, initials_surname);
    printf("Initials as int: %d %d\n", initials_name, initials_surname);

    // C Language does not support strings out of the box.
    // Instead of strings, C uses an array of single characters.

    // initialize using double quotes
    // Option 1: square braces []
    char name[] =
        "Murat"; // this actually is {'M','u','r','a','t','\0'}; so 6 element array is used to store 5 charecter string.

    printf("name: %s\n", name);

    // Option 2: USING A POINTER *
    // string literals are designed to be constant, stored in read-only memory
    // const modifier means that your compiler will complain if you try to modify an array with that particular
    // variable.
    // const char *surname = "Karadas";
    char *surname = "Karadas";

    // if you want to modify a string, you need to make a copy in a new array.
    // surname[0] = 'Q'; // BUS ERROR

    // the variable "surname" points to the beginning of string
    // in other words, it contains the ADDRESS of the FIRST character
    printf("Address of the first character - surname: %p\n", surname); // ie. 0x10431ff28
    printf("the first character - *surname  : %c\n", *surname);        // K
    printf("the first character - surname[0]: %c\n", *surname);        // K

    // the char array (string)
    printf("Surname, Name: %s, %s\n", surname, name);

    // string.h functions
    printf("Length of surname: %lu\n", strlen(surname));

    // dynamic memory allocation
    // allocate space and point the address of first element
    char *degree = malloc(3 * sizeof(char));
    *degree = 'B';       // *degree = value at the (go to) first address = degree[0] (offset is zero)
    *(degree + 1) = 'S'; // *(degree+1) = value of (go to) next address = degree[1] (offset is one)
    degree[2] = 'c';

    printf("Degree: %s\n", degree);

    print_reverse(surname);

    // if string is an array of char: []
    // array of string is an array of array of char: [][]
}

void print_reverse(char *str)
{

    int len = 0;
    len = strlen(str);

    // while(str[len] != '\0')
    //     len++;

    char *tail = str + len - 1;

    while (tail >= str)
    {
        printf("%c", *tail);
        tail--;
        // len--;
    }
}
