#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // take a string
    string text = get_string("Enter the text: ");
    int len = strlen(text);
    bool isPalindrom = true;
    char array[len];

    // assign string to array
    for(int i = 0; i<len; i++){
        array[i] = text[i];
    }

    // check is it the same from the beginning and the end
    for(int i = 0; i < len/2; i++){
        if(array[i] != array[len-1-i] ){
            printf("It is not a palindrom text\n");
            isPalindrom = false;
            break;
        }
    }

    if(isPalindrom) {
        printf("It is a palindrom text\n");
    }
}