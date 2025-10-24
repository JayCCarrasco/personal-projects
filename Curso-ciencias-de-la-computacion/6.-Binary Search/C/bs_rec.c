//Binary search algorithm using recursion in C
//By JCPC

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 16

void binarySearch(int array[], int min, int max, int search){
    if (min > max){
        printf("Not found\n");
        return;
    }
    int medio = (min+max)/2;

    if(array[medio] == search){
        printf("The position is %d\n", medio);
    } else if (array[medio] > search){
        max = medio-1;
        binarySearch(array, min, max, search);
    } else {
        min = medio + 1;
        binarySearch(array, min, max, search);
    }
}

int main(){
    int array[MAX_SIZE] = {10, 20, 25, 33, 45, 67, 78, 112, 234, 567, 888, 1001, 2034, 3214, 4000, 5000};
    int search = 0;
    int min = 0;
    int max = 15;
    int tmp = 0;
    int exit = -1;

    while(exit != 0){
        int min = 0;
        int max = 15;
        printf("Insert a value (0 to exit): ");
        scanf("%d", &search);

        if (search == 0){
            exit = 0;
            printf("Exiting program...\n");
            break;
        }

        binarySearch(array, min, max, search);
    }
    return 0;
}