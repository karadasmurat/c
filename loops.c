#include <stdio.h>

void printOptions(void);

int main(void){

    int size = 0;

    // do while loop executes in the first round anyway before checking for the condition
    // show the menu, get user input, then check condition in the while, a good case for do-while loop:
    do {
        printOptions();
        scanf("%d", &size);
    }while (size<1 || size>3);

    // instead of do while, we could loop forever:
    // keep in the loop untill input is OK.
    // while(1){
    //     printOptions();
    //     scanf("%d", &size);
    //     if(size >= 1 && size <=3)
    //         break;
    // }

    printf("Preparing option %d. Thanks.", size);

}

void printOptions(){
    puts("Available sizes:");
    puts("[1] Tall");
    puts("[2] Grande");
    puts("[3] Venti");
    puts("Please enter your choice: ");
}