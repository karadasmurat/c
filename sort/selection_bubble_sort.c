#include <stdio.h>
#include "mk_utils.h"

#define SIZE 5

/* Function Prototypes*/
void bubblesort(int argc, int* args);
void selectionsort(int argc, int* args);

int main(void){
    

    int scores[SIZE] = {75, 99, 45, 90, 33};

    puts("The original array: ");
    print_array(SIZE, scores);

    // bubblesort(SIZE, scores);
    selectionsort(SIZE, scores);

    puts("Sorted array: ");
    print_array(SIZE, scores);



    return 0;
}

// Compare the current element with the one after it, swap their values if needed. 
// The algorithm, which is a comparison sort, is named for the way the larger elements "bubble" up to the top of the list.

// This simple algorithm performs poorly in real world 
// O(n^2) worst case.
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

        // result of this pass
        // print_array(SIZE, args);
    }

}

void selectionsort(int argc, int* args){

    // For each pass, select the smallest
    // Note that pass also represents the number of sorted elements
    for(int pass = 0; pass < argc; pass++){

        // Note that we can keep track of index, or a pointer to the value at that index!
        // int* min = &args[pass];
        int minIndex = pass;
        for(int j = pass; j< argc-1; j++){

            // if(args[j+1] < *min) 
            if(args[j+1] < args[minIndex]) 
                // min = &args[i+1];
                minIndex = j+1;
        }

        // swap(min, &args[pass]);
        swap(&args[minIndex], &args[pass]);

        // result of this pass
        // print_array(SIZE, args);
    }

}
