#include <stdio.h>
#include "mk_utils.h"

void print_array(int argc, int* args){

    printf("[ ");
    for(int i=0; i< argc; i++){
        printf("%d ", args[i]);
    }
    printf("]\n");
}

void swap(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

}