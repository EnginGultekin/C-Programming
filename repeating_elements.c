
// !!!!!!! This algorithm is very bad in terms of running time and is O(n^3). !!!!!

// ******* It would be better to use hash instead of this algorithm *******

#include <stdio.h>

void findDuplicates(int arr[], int size) {
    printf("Repeating elements: ");
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                /*When there is another repeating element,
                it overwrites the elements coming from behind.*/
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                // You are reduced by 1 because the elements that come above the repeated element are written.
                size--;
                // In the same way j is reduced
                j--;
            }
        }
        if (count > 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 6, 3, 7, 8, 1, 9, 11, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}

/*
    an integer is 4 bytes and the sizeof() method tells
    how many bytes an array is so we do this
    sizeof(arr) / sizeof(arr[0]) ==> 4* eleman sayısı / 4
*/