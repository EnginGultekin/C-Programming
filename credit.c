#include <cs50.h>
#include <math.h>
#include <stdio.h>
long int get_card_number(string prompt);
int multiple_and_sum(long int number);
bool is_valid_card(long card_number, int digit);
int main(void)
{
    long int card_number = get_card_number("Number: ");
    int digit = multiple_and_sum(card_number);
    if (digit == 3 && is_valid_card(card_number, digit))
    {
        printf("AMEX\n");
    }
    else if (digit == 4 && is_valid_card(card_number, digit))
    {
        printf("VISA\n");
    }
    else if (digit == 5 && is_valid_card(card_number, digit))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
bool is_valid_card(long card_number, int digit)
{
    int count = 0;
    while (card_number > 100)
    {
        card_number /= 10;
        count += 1;
    }
    if (digit == 3)
    {
        if (card_number == 34 || card_number == 37)
            return true;
    }
    else if (digit == 4)
    {
        if (count > 13)
            return true;
    }
    else if (digit == 5)
    {
        if (card_number >= 51 && card_number <= 55)
            return true;
    }
    return false;
}
bool is_valid(int result)
{
    if (result % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int multiple_and_sum(long int number)
{
    int digit = 0;
    int num = 0;
    int result = 0;
    int type = 0;
    while (number > 0)
    {
        result += number % 10;
        digit = number % 100;
        num = digit / 10;
        num *= 2;
        result += num % 10;
        result += num / 10;
        number /= 100;
    }
    if (digit > 10)
        digit /= 10;
    if (is_valid(result))
    {
        return digit;
    }
    else
    {
        return 0;
    }
}
long int get_card_number(string prompt)
{
    long int number;
    do
    {
        number = get_long("%s", prompt);
    } while (number <= 0);
    return number;
}