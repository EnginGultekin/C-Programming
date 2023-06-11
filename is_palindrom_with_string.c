#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    // take a string
    string text = get_string("Enter the text: ");
    int len = strlen(text);
    bool isPalindrom = true;

    // check is it the same from the beginning and the end
    for(int i = 0; i < len/2; i++){
        if(text[i] != text[len-1-i] ){
            printf("It is not a palindrom text\n");
            isPalindrom = false;
            break;
        }
    }

    if(isPalindrom) {
        printf("It is a palindrom text\n");
    }
}