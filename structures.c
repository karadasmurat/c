#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure
struct Point
{
    int x;
    int y;
};

struct Rectangle
{
    int length;
    int width;
};

struct Student
{
    char name[50];
    int age;
};

// Define a struct named "Person"
struct Person
{
    char name[50];
    int age;
    float height;
};

// typedef keyword adds a new name to an existing data type:
typedef struct _car
{
    int year;
    char make[50]; // array of characters (String)
    char model[50];
} car;

struct House
{
    char name[30];
    int foundingYear;
};

// Define the Wizard structure containing a pointer to House structure
struct Wizard
{
    char name[50];
    struct House *house;
};

// Function Prototypes
void print_car(car c);
void pointersToStructures();
void structConstructors();
void structsWithStructPointers();
void wizardInfo(struct Wizard *wizard);
void printRectangle(struct Rectangle *ptr);
void allocateMemoryForStructures();
void structs_and_arrays();

int main(void)
{

    // define a structure by using the struct keyword
    // a structure can contain many different data types (int, float, char, etc.).
    struct product
    {
        char charcode;
        int id;
    }; // End the structure with a semicolon

    // Create a structure variable of type "struct product"
    struct product product_01;

    // Assign values to its members
    product_01.charcode = 'A';
    product_01.id = 100;

    // Print values
    printf("|%8s|%8s|\n", "charcode", "id");                   // title row
    printf("|%8c|%8d|\n", product_01.charcode, product_01.id); // data row

    // Assign values to members of a structure variable at declaration time, in a single line.
    struct product product_02 = {'A', 101};

    // Print values
    printf("|%8s|%8s|\n", "charcode", "id");
    printf("|%8c|%8d|\n", product_01.charcode, product_01.id);

    // use new name defined by "typedef" keyword to declare a variable
    car my_car = {2019, "Volkswagen", "T-ROC"};
    print_car(my_car);

    // pointersToStructures();
    structConstructors();
    // structsWithStructPointers();
    // allocateMemoryForStructures();
    // structs_and_arrays();

    return 0;
}

void structs_and_arrays()
{
    puts("Array Structs");
    puts("-------------");

    struct Rectangle rects[5]; // Array of Structs

    struct Rectangle r1 = {10, 11};
    rects[0] = r1;

    rects[1].width = 20;
    rects[1].length = 21;

    printRectangle(rects);     // Note that rects = &rects[0]
    printRectangle(&rects[1]); // Rectangle{21, 20}

    // Declare an array of pointers to structs
    struct Rectangle *rectPtrs[5];

    // Dynamically allocate memory for a structure
    // malloc() + set members(->) = (like constructor)
    struct Rectangle *ptr;
    ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    ptr->length = 30;
    ptr->width = 31;

    // set the first element to the pointer to the allocated struct.
    rectPtrs[0] = ptr;

    printRectangle(rectPtrs[0]); // Rectangle{30, 31}

    // Freeing the allocated memory using free when done.
    free(ptr);
}

// v1 Constructor Function -
// return a struct
struct House newHouse(const char *name, int year)
{

    // Creates a local variable house
    struct House house;
    strcpy(house.name, name);
    house.foundingYear = year;

    printf("newHouse: New struct House at %p\n", &house);

    // Note that returning a local variable from a function is NOT RECOMMENDED.
    // Using it outside the function can lead to undefined behavior,
    // especially if the local variable's address is accessed after the function has returned.
    return house;
}

// v2 Constructor Function -
// Allocate memory for a new House, and set fields, and return a pointer to it.
struct House *createHouse(const char *name, int year)
{
    struct House *house = (struct House *)malloc(sizeof(struct House));
    if (house != NULL)
    {
        strcpy(house->name, name);
        house->foundingYear = year;
    }

    // who will deallocate?
    return house;
}

void structConstructors()
{
    // v1
    struct House slytherin = newHouse("Slytherin", 990);

    printf("Received new House. Address: %p\n", &slytherin);
    printf("%s, %d\n", slytherin.name, slytherin.foundingYear); // Slytherin, 990

    // v2 Custom constructor function
    struct House *hufflepuff = createHouse("Hufflepuff", 990);

    printf("%p\n", hufflepuff);                                                // 0x11ce06a60
    printf("%p, %s\n", hufflepuff->name, hufflepuff->name);                    // 0x11ce06a60, Hufflepuff
    printf("%p: %d\n", &(hufflepuff->foundingYear), hufflepuff->foundingYear); // 0x11ce06a80: 990

    // Free memory allocated by the constructor function
    free(hufflepuff);
}
void structsWithStructPointers()
{
    // Create an instance of the House structure
    struct House gryffindor = {"Gryffindor", 990};

    // Create an instance of the Wizard structure with a pointer to the House structure
    struct Wizard potter = {"Harry Potter", &gryffindor};

    // Access and print information
    printf("%s, belongs to %s House.\n", potter.name, potter.house->name);

    // Custom constructor function
    struct House *slytherin = createHouse("Slytherin", 990);

    struct Wizard *wiz = (struct Wizard *)malloc(sizeof(struct Wizard));

    strcpy(wiz->name, "Draco Malfoy");
    wiz->house = slytherin;

    wizardInfo(wiz);

    free(slytherin);
    free(wiz);
}

void wizardInfo(struct Wizard *wizard)
{
    // Access and print information
    puts("Wizard Information:");
    puts("-------------------");
    printf("%s, belongs to %s House.\n", wizard->name, wizard->house->name);
}

void pointersToStructures()
{
    puts("Pointers to Structures");
    puts("----------------------");

    // Declare and initialize structure variable
    struct Point p1 = {100, 200};

    // Declare and initialize a pointer to a structure
    // Just like pointers to basic types, pointers to structures store the memory address of a structure.
    // Mevcutta stack üzerinde bulunan bir struct var, onun adresi.
    struct Point *ptr = &p1;

    // Access structure members using the pointer
    printf("Point{%d, %d}\n", ptr->x, ptr->y); // Point{100, 200}
    printf("Info: size: %zu\n", sizeof(struct Student));
    printf("Offset of name: %zu bytes\n", offsetof(struct Student, name));
    printf("Offset of age: %zu bytes\n", offsetof(struct Student, age));

    // Declare and initialize structure variable
    struct Rectangle rect = {2, 4};

    // Pass a pointer to the structure to a function
    printRectangle(&rect); // Rectangle{2, 4}
}

void allocateMemoryForStructures()
{
    // Mevcutta stack üzerinde bulunan bir struct yok, yani asagidaki ornekteki gibi direkt onun adresini kullanmıyoruz.
    // struct Point p1 = {100, 200};
    // struct Point *ptr = &p1;

    // Declare a pointer to a structure
    struct Student *ptr;

    // Dynamically allocate memory for a structure
    ptr = (struct Student *)malloc(sizeof(struct Student));

    // Check if allocation was successful
    if (ptr != NULL)
    {
        // Access and modify structure members using the pointer
        strcpy(ptr->name, "MSL");
        ptr->age = 9;

        printf("%p: Student{%s, %d}\n", ptr, ptr->name, ptr->age); // 0x145e06a60: Student{MSL, 9}

        // Free the allocated memory
        free(ptr);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
}
void print_car(car c)
{
    printf("\n{year: %i, make: %s model: %s}\n", c.year, c.make, c.model);
}

// Function that takes a pointer to a structure
void printRectangle(struct Rectangle *ptr)
{
    printf("Rectangle{%d, %d}\n", ptr->length, ptr->width);
}