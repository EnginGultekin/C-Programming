#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

void findDuplicates(int arr[], int size) {
    printf("Repeating elements: ");
    //Hash table is initialized with 0 by default
    int hash[TABLE_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        // The hashes of the elements in the array are incremented.
        hash[arr[i]]++;
    }

    for (int i = 0; i < size; i++) {
        if (hash[arr[i]] > 1) {
            printf("%d ", arr[i]);
            // The hash value is reset after finding the duplicate element
            hash[arr[i]] = 0;
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 6, 3, 7, 8, 1, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}


/*
    an integer is 4 bytes and the sizeof() method tells
    how many bytes an array is so we do this
    sizeof(arr) / sizeof(arr[0]) ==> 4* eleman sayısı / 4
*/