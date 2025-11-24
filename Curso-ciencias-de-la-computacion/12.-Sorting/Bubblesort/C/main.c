#include <stdio.h>
#include <stdbool.h>

#define ARR_LEN 7

void bubblesort(int arr[]){
    int swap = false;
    int tmp = 0;
    for(int i = 0; i < ARR_LEN; i++){
        swap = false;
        for(int j = 0; j < ARR_LEN-i; j++){
            if(arr[j] < arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swap = true;
            }
        }
        if(swap == false){
            break;
        }
    }
}

int main(){
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    bubblesort(arr);

    for(int i = 0; i < ARR_LEN; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
