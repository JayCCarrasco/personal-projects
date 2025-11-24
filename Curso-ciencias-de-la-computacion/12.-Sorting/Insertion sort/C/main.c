//Insertion sort algorithm in C
//By JCPC

//Implementing an insertion sort algorithm with swapping instead of
//displacement. Furthermore, less efficient. 

#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN 7

void insertionSort(int arr[]){
    int tmp = 0;
    for(int i = 1; i < ARR_LEN; i++){
        int j = i;
        while(j > 0 && arr[j-1]<arr[j]){
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }  
}

int main(){
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    insertionSort(arr);

    for(int i = 0; i < ARR_LEN; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

