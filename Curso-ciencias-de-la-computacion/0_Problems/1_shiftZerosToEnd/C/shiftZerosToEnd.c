#include <stdio.h>

#define SIZE_ARRAY 5

void shift_zeros_to_end(int* array){
    int count = 0;
    int temp = 0;

    for (int i = 0; i < SIZE_ARRAY; i++){
        if (array[i] != 0){
            temp = array[i];
            array[i] = array[count];
            array[count] = temp;
            count++;
        }       
    }
}

void printArray(int* array){
    printf("The array is: ");
    for (int i = 0; i < SIZE_ARRAY; i++){
        printf("%d ", array[i]);
    }
}


int main(){
    int array[SIZE_ARRAY] = {0, 1, 0, 3, 5};

    shift_zeros_to_end(array);
    printArray(array);
    
    return 0;
}