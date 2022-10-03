#include <stdio.h>

int get_coins(int total, int coin_value );

int main(void){

    int cents = 0;
    int quarters = 0;

    printf("Enter owed cents: [1-99] ");
    scanf("%d", &cents);

    printf("Here is the change: \n");

    quarters = get_coins(cents, 25);
    printf("%d Quarters \n", quarters);

    int remain = cents - quarters * 25;
    int dimes = get_coins(remain, 10);
    printf("%d Dimes \n", dimes);

    remain = remain - dimes * 10;
    int nickels = get_coins(remain, 5);
    printf("%d Nickels \n", nickels);

    remain = remain - nickels * 5;
    int pennies = get_coins(remain, 1);
    printf("%d Pennies \n", pennies);

    return 0;
}

int get_coins(int total, int coin_value ){

    return total / coin_value;

}