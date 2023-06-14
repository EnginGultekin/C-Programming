#include <stdio.h>
 
void convert_hexadecimal(int number);

int main()
{
    int number;
    printf("Decimal Number: ");
    scanf("%d", &number);
    
    // check if it's a decimal
    while(1){
        if(number >= 0)  break;
        else
        {
            printf("Decimal Number: ");
            scanf("%d", &number);
        }
    }
    // call function
    convert_hexadecimal(number);

    return 0;
}

void convert_hexadecimal(int number){
    int quotient = number, remainder = 0;
    int index = 0;
    char hexadecimal_nums[20];
 
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
        // 48 and 55 from ASCII
            hexadecimal_nums[index++] = 48 + remainder;
        else
            hexadecimal_nums[index++] = 55 + remainder;
        quotient = quotient / 16;
    }
 
    // display integer reverse into character
    printf("HexaDecimal Number: 0x");
    for (int i = index; i >= 0; i--)
        printf("%c", hexadecimal_nums[i]);
     printf("\n");    
}
