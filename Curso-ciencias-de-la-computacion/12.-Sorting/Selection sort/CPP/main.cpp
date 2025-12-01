#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n-1; i++){
        int smallest = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        std::swap(arr[smallest], arr[i]);
    }
}


int main(){
    std::vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);

    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}