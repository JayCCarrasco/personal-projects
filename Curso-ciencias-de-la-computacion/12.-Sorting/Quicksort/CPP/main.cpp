#include <iostream>
#include <vector>

int partition(std::vector<int>&arr, int low, int high){
    int pivot = arr[high];

    int i = low-1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[high], arr[i+1]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high){
    if (high > low){

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    std::vector<int> arr = {7,3,9,5,4,8,0,1};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}