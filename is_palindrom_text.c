#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string text = get_string("Enter the text: ");
    int len = strlen(text);
    bool isPalindrom = true;
    char array[len];

    for(int i = 0; i<len; i++){
        array[i] = text[i];
    }

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