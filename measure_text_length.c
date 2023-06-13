#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main() {
    
    string text = get_string("Enter a text: ");
    printf("The length of the text you entered, %lu\n", strlen(text));

    return 0;
}