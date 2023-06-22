#include <stdio.h>
#include <string.h>

void findWordsStartingWith(const char* words[], int length, const char* prefix) {
    // We get the length of the prefix to use when comparing
    int prefixLength = strlen(prefix);

    for (int i = 0; i < length; i++) {
        const char* word = words[i];

        // Making comparisons with the first three letters of the word
        if (strncmp(word, prefix, prefixLength) == 0) {
            printf("%s\n", word);
        }
    }
}

int main() {
    const char* words[] = {"apple", "banana", "cat", "dog", "applepie", "app", "orange"};
    int length = sizeof(words) / sizeof(words[0]);
    const char* prefix = "app";

    findWordsStartingWith(words, length, prefix);

    return 0;
}

/*
    an string is 8 bytes and the sizeof() method tells
    how many bytes an array is so we do this
    sizeof(arr) / sizeof(arr[0]) ==> 8* eleman sayısı / 8
*/