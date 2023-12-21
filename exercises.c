#include <stdio.h>
#include <stdlib.h>

void draw_rect(int height, int width);

int main()
{

    draw_rect(2, 5); // note that we are passing arguments at compile time!
    return EXIT_SUCCESS;
}

void draw_rect(int height, int width)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            printf("%c", '#');
        }
        printf("\n");
    }
}