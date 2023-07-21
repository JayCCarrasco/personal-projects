#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 8;   //fixed size of 8
    int option = -1; //save option to perform in the program
    int items = 0;  //number of items of the array
    int position = 0; //array position
    int value = 0;  //value of the current value
    int exit = 0;   //var to exit the main program
    int *ptr = malloc(sizeof(int) * size);     //initially ptr has 8 integers size
    int i = 0;   //vars for loops

    while (exit == 0){

        printf("Please, select the operation\n");
        printf("1: Enqueue\n");
        printf("2: Dequeue\n");
        printf("3: Check if array is empty\n");
        printf("0: Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 0:
                exit = 1;
                break;
            case 1:
                items = 0;
                printf("How many items are you inserting?: ");
                scanf("%d", &items);
                if (items > size){
                    printf("Maximum size for the array is %d, try again\n", size);
                    
                } else {  
                    for (i = 0; i < items; i++){
                        printf("Insert value %d: ", i);
                        scanf("%d", &value);
                        ptr[i] = value;
                    }
                }
                break;
            case 2:
                if (items == 0){
                    printf("Queue is empty\n");
                }else{
                    for (i = items; i <= size; i++){
                        ptr[i] = 0;
                    }
                    for (i = 1; i <= items; i++){
                        ptr[i-1] = ptr[i];
                    }
                    items--;
                }
                break;
            case 3:
                if (items <= 0){
                    printf("The array is empty\n");
                } else {
                    printf("The array is not empty\n");
                }
                break;

        }
        printf("\n");
        printf("Los valores del array son: \n");
        for (i = 0; i < size; i++){
            printf("%d: %d", i, ptr[i]);
            printf("\n");
        } 
        printf("\n");

    }  

    free(ptr);  //very important to free the space

    return 0;
}
