//Selection sort algorithm in C
//By JCPC

#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN 7

void selectionSort(int arr[]){
    int min = 0;
    int temp = 0;
    for(int i = 0; i < ARR_LEN; i++){
        min = i;
        for(int j = i; j < ARR_LEN; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        } 
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }   
}

int main(){
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    selectionSort(arr);

    for(int i = 0; i < ARR_LEN; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

