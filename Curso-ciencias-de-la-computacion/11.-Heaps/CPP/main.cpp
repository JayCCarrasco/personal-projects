#include <iostream>
#include <vector>

class heap{
private:
    std::vector<int> arr;

    void heapify(std::vector<int>& arr, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;

        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;

        if(largest != i){
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }       
    }

public:
    void heapSort(std::vector<int> &arr){
        int n = arr.size();

        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(arr, n, i);
        }

        for (int i = n-1; i > 0; i--){
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

};

int main(){
    heap h;
    std::vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };
    h.heapSort(arr);
    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}