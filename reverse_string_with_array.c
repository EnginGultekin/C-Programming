#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // take a string
    string text = get_string("Enter the text: ");
    int len = strlen(text);
    char array[len];

    // assign string to array
    for(int i = 0; i < len; i++){
        array[i] = text[i];
    }
    
    //just print the string in reverse
    printf("Reverse Text: ");
    for(int i = (len-1); i >= 0; i--){
        printf("%c",array[i]);
    }
    printf("\n");
}
 
