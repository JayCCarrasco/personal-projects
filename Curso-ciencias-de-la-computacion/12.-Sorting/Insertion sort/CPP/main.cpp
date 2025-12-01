#include <vector>
#include <iostream>

void insertionSort(std::vector<int>& arr){
    int n = arr.size();
    for (int i = 1; i < n; i++){
        int j = i-1;
        int key = arr[i];
        while(j >= 0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main(){
    std::vector<int> arr = { 12, 11, 13, 5, 6 };

    insertionSort(arr);

    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }


    return 0;
}