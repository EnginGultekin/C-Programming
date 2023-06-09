#include <cs50.h>
#include <stdio.h>

void SortIntArr(int count, int array[]);

int main(void)
{

    int count = get_int("Enter the array size: ");
    int array[count];

    for(int i=0; i < count; i++){
        array[i] = get_int("Enter the %d. number: ", (i+1));
    }
 
    SortIntArr(count, array);
}

void SortIntArr(int count, int array[]){

    int temp = 0;

    for(int i =0; i< count; i++){
        for(int j = i+1; j< count; j++){
           if(array[i] > array[j]){
               temp = array[i];
               array[i] = array[j];
               array[j] = temp;
           }
        }
    }
    printf("\n");
     for(int i=0; i < count; i++){
         printf("%d, ", array[i]);
    }
    printf("\n\n");
}