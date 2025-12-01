#include <iostream>
#include <vector>

void bubblesort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int swap = false;
        for(int j = 0; j < n- 1 -i; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
                swap = true;
            }
        }
        if(swap == false) break;
    }
}

void printArr(std::vector<int>& arr){
    for(int num : arr){
        std::cout << num << " ";
    }
}

int main(){
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    bubblesort(arr);
    printArr(arr);

    return 0;
}