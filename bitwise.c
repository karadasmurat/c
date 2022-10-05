#include <stdio.h>

#define FLAG_1  1 // 0000 0000 0000 0001
#define FLAG_2  2 // 0000 0000 0000 0010
#define FLAG_3  4 // 0000 0000 0000 0100
#define FLAG_4  8 // 0000 0000 0000 1000

void printConfig(int config);

int main(void){

    // One hex digit can represent a nibble (4 bits or half an octal).
    // Two hex digits can represent a byte (8 bits).


    // keep a single variable (config) for holding more than one flags
    // turn a flag ON:
    int config = FLAG_1 | FLAG_3 | FLAG_4; // 0000 0000 0000 1101

    printConfig(config);


    // turn the flag OFF
    printf("\n- Disabling FLAG_3...\n");
    config = config ^ FLAG_3;

    printConfig(config);

}

void printConfig(int config){
    if(config & FLAG_1)
        printf("FLAG_1 is ON.\n");
    if(config & FLAG_2)
        printf("FLAG_2 is ON.\n");
    if(config & FLAG_3)
        printf("FLAG_3 is ON.\n");
    if(config & FLAG_4)
        printf("FLAG_4 is ON.\n");
}