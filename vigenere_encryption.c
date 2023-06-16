#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void encrypt(string key, string text);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] >= 'A' && 'Z' >= argv[1][i])
                continue;
            else if (argv[1][i] >= 'a' && 'z' >= argv[1][i])
                continue;
            else
            {
                printf("Usage: %s keyword\n", argv[0]);
                return 1;
            }
        }
        string key = argv[1];
        string text = get_string("plaintext: ");
        encrypt(key, text);
    }
    else
    {
        printf("Usage: %s keyword\n", argv[0]);
        return 1;
    }
    return 0;
}
void encrypt(string key, string text)
{
    int len = strlen(text);
    int keyLen = strlen(key);
    int keyCount = 0;
    for (int i = 0; i < len; i++)
    {
        if (keyLen == keyCount)
            keyCount = 0;
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = ((text[i] - 'A' + (toupper(key[keyCount]) - 'A')) % 26) + 'A';
            keyCount++;
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = ((text[i] - 'a' + (tolower(key[keyCount]) - 'a')) % 26) + 'a';
            keyCount++;
        }
    }
    printf("ciphertext: %s\n", text);
}
