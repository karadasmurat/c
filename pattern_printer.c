#include <stdio.h>

void print_square_stars(int height);
void print_square_stars_alternating(int height);

int main(void){

    print_square_stars(4);
    print_square_stars_alternating(5);

    return 0;

}

void print_square_stars(int height){

    for (int i = 0; i < height; i++){
        for (int j = 0; j < height; j++){
            printf("*");
        }

        printf("\n");
    }
}
void print_square_stars_alternating(int height){

    for (int i = 0; i < height; i++){
        for (int j = 0; j < height; j++){
            if (i%2 == 0) // even rows
                printf("* ");
            else // odd rows
                printf(" *");
        }

        printf("\n"); // end of row
    }
}