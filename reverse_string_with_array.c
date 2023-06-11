#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // take a string
    string text = get_string("Enter the text: ");
    char array[strlen(text)];

    // assign string to array
    for(int i = 0; i<strlen(text); i++){
        array[i] = text[i];
    }
    
    //just print the string in reverse
    printf("Reverse Text: ");
    for(int i = sizeof(array)-1; i>=0; i--){
        printf("%c",array[i]);
    }
    printf("\n");
}
 
