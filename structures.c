#include <stdio.h>
#include <string.h>

// typedef keyword adds a new name to an existing data type:
typedef struct _car{
    int year;
    char make[50]; // array of characters (String)
    char model[50];
} car;

// Define a struct named "Person"
struct Person
{
    char name[50];
    int age;
    float height;
};

void print_car(car c);


int main(void){

    // define a structure by using the struct keyword
    // a structure can contain many different data types (int, float, char, etc.).
    struct product{
        char charcode;
        int id;
    }; // End the structure with a semicolon


    // Create a structure variable of type "struct product"
    struct product product_01;
    
    // Assign values to its members
    product_01.charcode = 'A';
    product_01.id = 100;
    
    // Print values
    printf("|%8s|%8s|\n", "charcode", "id");    // title row
    printf("|%8c|%8d|\n", product_01.charcode, product_01.id); // data row

    // Assign values to members of a structure variable at declaration time, in a single line.
    struct product product_02 = {'A', 101};

    // Print values
    printf("|%8s|%8s|\n", "charcode", "id");
    printf("|%8c|%8d|\n", product_01.charcode, product_01.id);

    // use new name defined by "typedef" keyword to declare a variable
    car my_car = {2019, "Volkswagen", "T-ROC"};
    print_car(my_car);

    return 0;
}

void print_car(car c){
    printf("\n{year: %i, make: %s model: %s}", c.year, c.make, c.model);
}