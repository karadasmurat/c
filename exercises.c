#include <stdio.h>
#include <stdlib.h>

void multiplicationTableOf(int n);
void draw_rect(int height, int width);
void printPattern1(int n);
int sum_recursive(int n);
int factorial(int n);
void numberGuessingGame();

int main()
{

    int n = 5;

    // draw_rect(2, 5); // note that we are passing arguments at compile time!

    // printPattern1(n);

    // multiplicationTableOf(9);

    numberGuessingGame();

    int sum = sum_recursive(n); // 1+2+3+4+5 = 15
    int fact = factorial(n);    // 1*2*3*4*5 = 120
    printf("The sum of first %d integers: %d\n", n, sum);
    printf("%d!: %d\n", n, fact);

    return EXIT_SUCCESS;
}

/*
Write a function called drawRectangle. This function should take two parameters, width and height, and print a rectangle
made of # characters with the specified dimensions.
*/
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

/*
Write a function that prints the following pattern (first n lines)
#
# # #
# # # # #
*/

void printPattern1(int n)
{

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < 2 * r + 1; c++)
        {

            printf("# ");
        }
        printf("\n");
    }
}
/*
Write a program to print multiplication table of a given number n.
*/

void multiplicationTableOf(int n)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}

/*
Write a recursive program to sum first n natural numbers
*/
int sum_recursive(int n)
{
    if (n == 1)
        return 1;

    return n + sum_recursive(n - 1);
}

/*
Write a recursive program to calculate n! = 1 * 2* 3* .. *n
*/
int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

int getRandomNumber(n)
{
    return rand() % n + 1; // stdlib - Return a random integer between 0 and RAND_MAX.
}

/*
Write a number-guessing game.
*/
void numberGuessingGame()
{
    // generate a secret number
    int secret = getRandomNumber(100);
    while (1)
    {
        // ask for input
        int guess = -1;
        printf("\nMake a guess: ");
        scanf("%d", &guess);
        // check
        if (secret == guess)
        {
            printf("\nYou win!");
            break;
        }

        else if (secret > guess)
            printf("\nTry a higher number");
        else
            printf("\nTry a lower number");
    }
    printf("Gameover.\n");
}