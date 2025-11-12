#Quicksort implementation in python
#By JCPC 12/11/2025
#time complexity average and best case: O(nlogn) worst case: O(n^2)

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)

        quicksort(arr, low, pi-1)
        quicksort(arr, pi+1, high)

def partition(arr, low, high):
    pivot = arr[high]

    i = low-1

    #ordering values < pivot to the left
    for j in range(low, high):
        if arr[j] < pivot:
            i+=1
            arr[i], arr[j] = arr[j], arr[i]

    #putting pivot in its position, next to last low value
    arr[high], arr[i+1] = arr[i+1], arr[high]

    return i+1


def main():
    arr = [10, 7, 8, 9, 1, 5]
    n = len(arr)
    quicksort(arr, 0, n-1)
    print(arr)

if __name__=='__main__':
    main()