#Selection sort implemented in python by JCPC
#Time complexity: O(n^2)

def selectionSort(array):
    for i in range(0, len(array)):
        min = i
        for j in range(i, len(array)):
            if array[j] < array[min]:
                min = j
        array[i], array[min] = array[min], array[i]

def main():
    array = [3, 5, 1, 9, 6, 17, 7, 89, 0]
    array = selectionSort(array)
    print(array)

if __name__=="__main__":
    main()
            