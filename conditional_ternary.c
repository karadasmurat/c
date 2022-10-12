#include <stdio.h>

int getBigger(int x, int y);

int main(void){

    int a = 0;
    int b = 0;

    puts("Enter first integer: ");
    scanf("%d", &a);

    puts("Enter second integer: ");
    scanf("%d", &b);

    printf("getBigger(%d, %d): %d\n", a,b,getBigger(a, b));

}

int getBigger(int x, int y){

    // return using ternary conditional
    // condition ? value_if_true : value_if_false
    return x > y ? x : y;
}