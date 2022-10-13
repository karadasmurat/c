#include <stdio.h>
#define CACHE_SIZE 100

/* Function prototypes*/
long fibonacci(int n);
long fib_opt(int n);
void print_cache();

/* Global variables */
long fcalls = 0;
long fcalls_opt = 0;
long fib_cache[CACHE_SIZE];

int main(void){

    int n;
    puts("Enter fibonacci argument");
    scanf("%d", &n);

    printf("fibonacci(%d): %ld\n", n, fibonacci(n));

    printf("Function calls: %ld\n", fcalls);    

    // reset cache
    for(int i=0; i<CACHE_SIZE; i++){
        fib_cache[i] = 0;
    }

    printf("fib_opt(%d): %ld\n", n, fib_opt(n));
    printf("Function calls: %ld\n", fcalls_opt);  

    return 0;
}
/*

f(0) = 0 (return 0)
f(1) = 1 (return 1)
f(2) = f(1) + f(0) = 1
f(3) = f(2) + f(1) = 2
f(4) = f(3) + f(2) = 3
f(5) = f(4) + f(3) = 5
 
*/
long fibonacci(int n){

    fcalls++; // count overall calls to this function

    // base case
    if(n == 0) 
        return 0;
    if(n == 1) 
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);

}

long fib_opt(int n){

    fcalls_opt++;
    
    //base case
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    
    // before going into recursion, check if the function has been called with n before
    if(fib_cache[n] != 0)
        return fib_cache[n];

    long result = fib_opt(n-1) + fib_opt(n-2);

    // save result into the cache, with n as the index
    // the argument will be the key (the array index), and result will be the value.
    fib_cache[n] = result;

    //print_cache();

    return result;
}

void print_cache(){

    printf("cache: [");
    for(int i=0; i<CACHE_SIZE; i++ )
        printf("%ld ", fib_cache[i]);
    printf("]\n");
}