#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Text tree (Trie) node structure
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;


// Creating a new Trie node
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

void printWords(TrieNode* node, const char* prefix);
void insertWord(TrieNode* root, const char* word);
void searchPrefix(TrieNode* root, const char* prefix);


int main() {
    const char* words[] = {"apple", "banana", "cat", "dog", "applepie", "app", "orange"};
    int length = sizeof(words) / sizeof(words[0]);
    const char* prefix = "app";

    TrieNode* root = createNode();

    // Adding words to the Trie
    for (int i = 0; i < length; i++) {
        insertWord(root, words[i]);
    }

    // Searching and printing words starting with a specific prefix
    searchPrefix(root, prefix);

    return 0;
}


// Adding words to Trie
void insertWord(TrieNode* root, const char* word) {
    int length = strlen(word);
    TrieNode* currentNode = root;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = createNode();
        }

        currentNode = currentNode->children[index];
    }

    currentNode->isEndOfWord = true;
}

// Specific previous search in Trie
void searchPrefix(TrieNode* root, const char* prefix) {
    int length = strlen(prefix);
    TrieNode* currentNode = root;

    for (int i = 0; i < length; i++) {
        int index = prefix[i] - 'a';

        if (currentNode->children[index] == NULL) {
            printf("Belirtilen onekle baslayan kelime bulunamadi.\n");
            return;
        }

        currentNode = currentNode->children[index];
    }

    // Belirtilen önekle başlayan kelimeleri yazdırma
    printWords(currentNode, prefix);
}

// Verilen düğümden itibaren önekle başlayan kelimeleri yazdırma
void printWords(TrieNode* node, const char* prefix) {
    if (node->isEndOfWord) {
        printf("%s\n", prefix);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            char* newPrefix = (char*)malloc(sizeof(char) * (strlen(prefix) + 2));
            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = 'a' + i;
            newPrefix[strlen(prefix) + 1] = '\0';
            printWords(node->children[i], newPrefix);
            free(newPrefix);
        }
    }
}