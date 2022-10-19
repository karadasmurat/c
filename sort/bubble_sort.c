#include <stdio.h>
#include "mk_utils.h"

#define SIZE 5

/* Function Prototypes*/
void bubblesort(int argc, int* args);

int main(void){
    

    int scores[SIZE] = {75, 99, 45, 90, 33};

    puts("The original array: ");
    print_array(SIZE, scores);

    bubblesort(SIZE, scores);

    puts("Sorted array: ");
    print_array(SIZE, scores);



    return 0;
}

void bubblesort(int argc, int* args){

    // as each index will be compared to the next index, n-1 total passes.
    // after each pass, max of the remaining will "buble" to last position.
    for(int pass = 0; pass < argc-1; pass++){

        // last indices are already sorted, loop untill there.
        for(int i = 0; i < argc-1-pass; i++){

            if(args[i] > args[i+1]){
                swap(&args[i], &args[i+1]);
            }

        }
    }

}
