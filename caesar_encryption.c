#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encrypt(int number, string text);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] >= '0' && '9' >= argv[1][i])
            {
                continue;
            }
            else
            {
                printf("Usage: %s\n", argv[0]);
                return 1;
            }
        }
        int number = atoi(argv[1]);
        string text = get_string("plaintext: ");
        encrypt(number, text);
    }
    else
    {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }
    return 0;
}
void encrypt(int number, string text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' + number) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' + number) % 26) + 'a';
        }
    }
    printf("ciphertext: %s\n", text);
}