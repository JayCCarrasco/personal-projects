#Selection sort implemented in python by JCPC
#Time complexity: O(n^2)

def selectionSort(array):
    for i in range(0, len(array)):
        min = i
        for j in range(i, len(array)):
            print(j)
            if array[j] < array[min]:
                min = j
        array[i], array[min] = array[min], array[i]
        print(array)

    return array

def main():
    array = [7, 3, 9, 5]

    array = selectionSort(array)
    print(array)

if __name__=="__main__":
    main()
            