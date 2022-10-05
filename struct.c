#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char code[3];
} contact;

void printContact(contact c);


int main(void)
{
    char name[10];
    strcpy(name, "MK");
    printf("Name: %s", name);

    // contact c1;
    // c1.id=1;
    // strcpy(c1.code, "ABC"); //c1.code='ABC'; //MALLOC ? zsh: trace trap  ./a.out
    // printContact(c1);

    // printf("ID: %i, CODE: %s", c1.id, c1.code);

    contact c2 ={2, "XYZ"};
    printContact(c2);

    return 0;
}

void printContact(contact c){
    printf("\n{ID: %i, CODE: %s}", c.id, c.code);
}