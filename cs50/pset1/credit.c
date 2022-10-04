#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int get_digits(long cardno);
void get_issuer(long cardno);
int get_first_n_digits(long arg, int n);
bool luhns(long cardno);

int main(void) 
{
    const long VISA = 4111111111111111;
    const long MASTERCARD = 5555555555554444;
    const long AMEX = 371449635398431;
    const long INV = 1234567890;

    long card_number = VISA;

    // printf("Number: ");
    // scanf("%li", &card_number);

    get_issuer(card_number);
    //int luhns_check = luhns(card_number);

    return 0;
}

int get_digits(long cardno){
    return 1 + floor(log10(cardno));
}

int get_first_n_digits(long arg, int n){

    int digits = get_digits(arg);
    return (int) (arg / pow(10, digits-n));
}

void get_issuer(long cardno){

    // Basic validity
    if(cardno < 1000000){
        printf("INVALID\n");
        return ;
    }
    // Check against Luhn's algorithm
    if ( !luhns(cardno) ){
        printf("INVALID\n");
        return ;
    }

    int digits = get_digits(cardno);
    int first_digit = get_first_n_digits(cardno, 1);
    int first_two_digits = get_first_n_digits(cardno, 2);
        
   
    // printf("Number of digits: %d\n", digits);
    // printf("First digit: %d\n", first_digit);
    // printf("First 2 digits: %d\n", first_two_digits);

    if( (digits == 16 || digits == 13) && first_digit == 4 ){

        printf("VISA candidate\n");
        
    }else if( digits == 16  && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54 || first_two_digits == 55) ){
        printf("MASTERCARD candidate\n");
    }else{
        printf("INVALID\n");
    }
        
}

bool luhns(long cardno){
    int check_digit = cardno %10;

    short weight = 1; // toggle switch for double(1) and normal(-1) digits
    int sum = 0;
    while(1){
        cardno /= 10;
        if(cardno < 1) break;

        int current_digit = cardno % 10; // the leftmost digit
        //printf("Current digit: %i ", current_digit); 

        if(weight == 1){
            current_digit *= 2;
            if(current_digit >= 10){
                sum = sum + current_digit / 10 + current_digit % 10;
            }else{
                sum = sum + current_digit;
            }
            
        }else{
            sum = sum + current_digit;
        }

        weight *= -1; // toggle 
        //printf("Current sum: %i\n", sum);
    }

    //printf("The sum is: %i", sum);

    if( (sum + check_digit) % 10 == 0 ) {
        printf("Luhn's algorithm PASSED.");
        return true;
    }


    printf("Luhn's algorithm FAILED.");  
    return false;
    


}