#include <stdio.h>

void printCharNTimes(char, int);

int main(void){

    int height = 5;

    for (int i = 1; i <= height; i++)
    {
        int spaceCount = height - i;
        printCharNTimes(' ', spaceCount);
        printCharNTimes('#', i);
        printf(" ");
        printCharNTimes('#', i);
        printCharNTimes(' ', spaceCount);
        printf("\n");

    }
}

void printCharNTimes(char symbol, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%c", symbol);
    }
    
}