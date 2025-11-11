#Time complexity:
#Best case: O(n) -> In an order array
#Worst case: O(n^2) -> In an inverse array
#Average: O(n^2)

def insertSort(array):
    for i in range(1, len(array)-1):
        key = array[i]
        j = i-1
        
        while j >= 0 and key < array[j]:
            array[j+1] = array[j]
            j-=1
        array[j+1] = key
    return array
        

def main():
    array = [7, 3, 9, 5]
    array = insertSort(array)
    print (array)

if __name__ == "__main__":
    main()