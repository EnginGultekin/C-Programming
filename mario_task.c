#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Height: ");
    } while (number > 8 || number < 1);

    for (int i = 1; i <= number; i++)
    {
        for (int j = number; j > 0; j--)
        {
            if (j > i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
