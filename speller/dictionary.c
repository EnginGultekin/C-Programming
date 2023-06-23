// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

int size_words = 0; // Keep track of the number of words added

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // The output should be between 0 and N-1
    unsigned int result = 0;
    unsigned int word_lenth = strlen(word);


    for (int i = 0; i <= word_lenth; i++)
    {
        result += tolower(word[i]) + word_lenth / 2;
    }

    return result % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
// Convert word to lowercase

    // Hash the word
    int hash_index = hash(word);
    int result;

    // Create variable that points to the start of linked list
    node *cursor = table[hash_index];

    while (cursor != NULL)
    {
        result = strcasecmp(word, cursor->word); // compare without case sensitivity

        if (result == 0)
        {
            return true;
        }

        cursor = cursor->next; // check next word in linked list
    }

    return false;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }

    // Read strings from file one at a time

    char word[LENGTH + 1];

    while (fscanf(dict, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough memory.\n");
            fclose(dict);
            return false;
        }

        // Hash word and get hash-value
        int hash_index = hash(word);

        strcpy(n->word, word); // Copy word

        // Insert node into hash table at that location
        node *head = table[hash_index]; // Create variable that points to the start of linked list

        if (head != NULL)
        {
            n->next = table[hash_index];
        }
        else
        {
            n->next = NULL;
        }

        table[hash_index] = n;
        size_words ++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N ; i++)
    {
        node *cursor = table[i]; // Create variable that points to the start of linked list
        node *tmp = NULL;

        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

    }

    return true;
}