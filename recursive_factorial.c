#include <stdio.h>
#include <string.h>
#include <cs50.h>

int factorial(int number);

int main() {
    
    int result = 0;
    int number = get_int("Enter a number: ");
    
    while(1){
        if(number >= 0)  break;
        else number = get_int("Enter a number: ");
    }
    
    result = factorial(number);
    printf("factorial of %d! = %d\n", number, result);

    return 0;
}

int factorial(int number){
    if(number == 0 || number == 1 ) return 1;

    return number *= factorial(number-1);
}