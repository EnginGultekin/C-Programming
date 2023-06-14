#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int num1, num2;
    int *ptr1 = &num1, *ptr2 = &num2;

    // take data from user with use cs50 library
    *ptr1 = get_int("Enter Number1: ");

    // take data from user with use stdio library
    printf("Enter Number2: ");
    scanf("%d", ptr2);

    printf("Number1: %d\nNumber2: %d\n", *ptr1, *ptr2);
}
