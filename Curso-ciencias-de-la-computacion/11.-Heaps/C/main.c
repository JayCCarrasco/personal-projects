//Heap implementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MIN_CAPACITY 4 //Minimum capacity of the dynamic array
                       //Define in order to not reduce the capacity when size < 4 

int* safeRealloc(int* heapArr, int capacity){
    int* tmp=realloc(heapArr, sizeof(int)*capacity);
    if(!tmp){
        perror("Error in realocation\n");
        exit(1);
    }
    return tmp;
}

int insertData(int data, int** heapArr, int size, int* capacity){
    printf("%d", size);
    printf("%d", *capacity);
    if (size == *capacity){
        *capacity = (*capacity) *2;
        *heapArr = safeRealloc(*heapArr, *capacity);
    }

    (*heapArr)[size] = data;
    int i = size;
    int temp;

    //bubble up
    while (i > 0 && ((*heapArr)[i] < (*heapArr)[(int)((i-1)/2)])){
        temp = (*heapArr)[i];
        (*heapArr)[i] = (*heapArr)[(int)((i-1)/2)];
        (*heapArr)[(int)(i-1)/2] = temp;
        i = (int)((i-1)/2);
    }

    size++;
    return size;
}

int removeData(int** heapArr, int index, int size, int* capacity){
    if (size == 0) return -1;
    if(index > size-1){
        printf("Choose a correct index\n");
        return -1;
    }

    //int rm_val = (*heapArr)[index];
    (*heapArr)[index] = (*heapArr)[size-1];
    size--;

    //Now shift down
    int i = index;

    while (true){
        int left = 2*i+1;
        int right = 2*i+2;
        int smallest = i;

        if (left < size && (*heapArr)[left] < (*heapArr)[smallest]){
            smallest = left;
        }
        if (right < size && (*heapArr)[right] < (*heapArr)[smallest]){
            smallest = right;
        }
        
        if (smallest != i){
            int temp = (*heapArr)[i];
            (*heapArr)[i] = (*heapArr)[smallest];
            (*heapArr)[smallest] = temp;
            i = smallest;
        } else{
            break;
        }
    }
    if (size < (*capacity/4) && (*capacity) > MIN_CAPACITY){
        (*capacity) = (*capacity/2);
        *heapArr = safeRealloc(*heapArr, *capacity);
    }
    return size;
}

void heapify(int* heapArr2Ptr, int size, int i){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;

    if (left < size && heapArr2Ptr[left] < heapArr2Ptr[smallest]){
        smallest = left;
    }
    if (right < size && heapArr2Ptr[right] < heapArr2Ptr[smallest]){
        smallest = right;
    }
    
    if (smallest != i){
        int temp = heapArr2Ptr[i];
        heapArr2Ptr[i] = heapArr2Ptr[smallest];
        heapArr2Ptr[smallest] = temp;
        heapify(heapArr2Ptr, size, smallest);
    }
}

void heapSort(int* heapArr2Ptr, int size){
    
    for (int i = size/2-1; i >= 0; i--){
        heapify(heapArr2Ptr, size, i);
    }

    for(int i = size - 1; i > 0; i--){
        int temp = heapArr2Ptr[0];
        heapArr2Ptr[0] = heapArr2Ptr[i];
        heapArr2Ptr[i] = temp;
        heapify(heapArr2Ptr, i, 0);
    }
}

int main(){
    //max capacity of the array. Initialize to 4
    int capacity = MIN_CAPACITY;
    //Asign dynamic memory allocation to the dynamic array
    int* heapArr = malloc(sizeof(int)*capacity);
    //size to save number of data
    int size = 0;

    size = insertData(16, &heapArr, size, &capacity);
    size = insertData(20, &heapArr, size, &capacity);
    size = insertData(10, &heapArr, size, &capacity);
    size = insertData(19, &heapArr, size, &capacity);
    size = insertData(18, &heapArr, size, &capacity);
    size = insertData(5, &heapArr, size, &capacity);
    size = insertData(15, &heapArr, size, &capacity);
    printf("The array is: ");
    for (int i = 0; i < size; i++){
        printf("%d ", heapArr[i]);
    }
    printf("\n");

    size = removeData(&heapArr, 0, size, &capacity);
     printf("The array is: ");
    for (int i = 0; i < size; i++){
        printf("%d ", heapArr[i]);
    }
    printf("\n");

    //Getting min in O(1)
    int min = heapArr[0];
    printf("Min is: %d\n", min);

    //Sort heap for random array
    //Remember that in arrays derreferentiation is done by C
    //So you do not have to write *heapArr2Ptr[0] = 17 but next instead
    int* heapArr2Ptr = malloc(sizeof(int)*7);
    heapArr2Ptr[0] = 17;
    heapArr2Ptr[1] = 10;
    heapArr2Ptr[2] = 3;
    heapArr2Ptr[3] = 8;
    heapArr2Ptr[4] = 20;
    heapArr2Ptr[5] = 2;
    heapArr2Ptr[6] = 1;

    printf("The second array is: ");
    for (int i = 0; i < 7; i++){
        printf("%d ", heapArr2Ptr[i]);
    }
    printf("\n");

    heapSort(heapArr2Ptr, size);
    printf("The second array is now: ");
    for (int i = 0; i < 7; i++){
        printf("%d ", heapArr2Ptr[i]);
    }
    printf("\n");


    return 0;
}

//IMPLEMENTAR EN EL REMOVE
/*if (size < (*capacity/4) && (*capacity) > MIN_CAPACITY){
        (*capacity) = (*capacity/2);
        *heapArr = realloc(*heapArr, sizeof(int)*(*capacity));
    }*/