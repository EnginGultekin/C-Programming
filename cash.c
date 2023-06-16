#include <cs50.h>
#include <math.h>
#include <stdio.h>
float get_positive_int(string prompt);
int get_count_cent(int money);
int main(void)
{
    float positive_number = get_positive_int("Change owed: ");
    positive_number = round(positive_number * 100);
    int count_cent = get_count_cent(positive_number);
    printf("%d\n", count_cent);
}
int get_count_cent(int money)
{
    int count = 0;
    while (money > 0)
    {
        if (money >= 25)
        {
            money -= 25;
            count += 1;
        }
        else if (money >= 10)
        {
            money -= 10;
            count += 1;
        }
        else if (money >= 5)
        {
            money -= 5;
            count += 1;
        }
        else
        {
            money -= 1;
            count += 1;
        }
    }
    return count;
}
float get_positive_int(string prompt)
{
    float number;
    do
    {
        number = get_float("%s", prompt);
    } while (number <= 0);
    return number;
}