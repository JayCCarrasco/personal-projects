#Implementing bubblesort in python
#Time complexity O(n^2)

def bubblesort (array):
    n = len(array)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if array[j+1]<array[j]:
                array[j+1], array[j] = array[j], array[j+1]    
                swapped = True
        if swapped == False:
            break
    return array           

def main():
    array = [2, 8, 5, 9, 4, 1]
    array = bubblesort(array)
    print(array)

if __name__ == "__main__":
    main()
