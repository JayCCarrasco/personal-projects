//Binary search algorithm in C
//By JCPC

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 16

int main(){
    int array[MAX_SIZE] = {10, 20, 25, 33, 45, 67, 78, 112, 234, 567, 888, 1001, 2034, 3214, 4000, 5000};
    int search = 0;
    bool found = false;
    int min = 0;
    int max = 15;
    int tmp = 0;
    int exit = -1;

    while(exit != 0){
        bool found = false;
        int min = 0;
        int max = 15;
        printf("Inserte un valor: ");
        scanf("%d", &search);

        while(found != true){
            int medio = (min+max)/2;
            if(array[medio] == search){
                found = true;
                printf("The position is %d\n", medio);
            } else if (array[medio] > search){
                max = medio-1;
            } else {
                min = medio + 1;
            }
        }
    }
    return 0;
}