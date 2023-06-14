#include <cs50.h>
#include <string.h>
#include <stdio.h>

void convert_hexadecimal(int number);

int main(void)
{
    int number = get_int("Decimal Number: ");
    
    while(1){
        if(number >= 0)  break;
        else number = get_int("Decimal Number: ");
    }
    convert_hexadecimal(number);
    return 0;
}

char *hexa_character(int value){
    char *character_list[] = {"A", "B", "C", "D", "E", "F"};

    return character_list[value%10];
}

void print_array(int index, char array[]){
    printf("HexaDecimal Number: 0x");
    for (int i = index; i >= 0; i--)
        printf("%c", array[i]);

     printf("\n");   
}

void convert_hexadecimal(int number){
    int quotient = number, remainder = 0;
    int index = 0;
    char hexadecimal_nums[20];

    while(quotient > 0)
    {
        remainder = quotient % 16;
        if(remainder > 9){ 
            hexadecimal_nums[index++] = *hexa_character(remainder);
        } else{ 
            hexadecimal_nums[index++] = '0' + remainder;
        }
         quotient = quotient / 16;
    }
    print_array(index,hexadecimal_nums);
}
