// If you want, you can get the length of the array and the numbers in it from the user.

#include <stdio.h>
#include <cs50.h>

// Length of the array
#define len 10

int main(void)
{
    int array[] = {6,2,9,11,54,76,81,3,34,27};
    int max = 0;

    for(int i = 0; i < len; i++)
    {
        if(max < array[i])
        {
            max = array[i];
        }
    }
    printf("Largest number in the array: %d\n", max);

    return 0;
}