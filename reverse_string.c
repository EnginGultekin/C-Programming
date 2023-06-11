#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{

    // Take a string
    string text = get_string("Enter the text: ");

    printf("Reverse Text: ");
    //just print the string in reverse
    for(int i = 1; i<=strlen(text); i++){
        printf("%c",text[strlen(text)-i]);
    }
    printf("\n");
}
