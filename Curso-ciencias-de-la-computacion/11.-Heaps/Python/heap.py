#code for heaps in python without using heapq library

def insertData(data, heapArr):
    heapArr.append(data)
    i = len(heapArr)-1

    #bubble up
    while i > 0 and heapArr[i] < heapArr[(i-1)//2]:
        heapArr[i], heapArr[(i-1)//2] = heapArr[(i-1)//2], heapArr[i]
        i = (i-1)//2

#this remove function is good for root and for other positions. 
#BE SURE THE ARRAY IS HEAPIFIED BEFORE USE IT!!!! OTHERWISE IT WONT WORK CORRECTLY
def remove(heapArr, index):
    if len(heapArr) == 0: return None

    rm_val = heapArr[index]

    heapArr[index] = heapArr[-1]
    heapArr.pop()

    #now shift down
    i = index
    size = len(heapArr)

    while True:
        left = 2*i + 1
        right = 2*i + 2
        smallest = i

        if left < size and heapArr[left] < heapArr[smallest]:
            smallest= left

        if right < size and heapArr[right] < heapArr[smallest]:
            smallest= right

        if smallest != i:
            heapArr[i], heapArr[smallest] = heapArr[smallest], heapArr[i]
            i = smallest
        else:
            break

    return rm_val

#heap sort in descending order as minHeap
#(For ascending order implement maxHeap)
def heapSort(heapArr):
    n = len(heapArr)

    #construir min-heap (bubbling up)
    for i in range (n // 2 - 1, -1, -1):
        heapify(heapArr, n, i)

    print(heapArr)    

    #extraccion de elementos
    for end in range(n - 1, 0, -1):
        heapArr[0], heapArr[end] = heapArr[end], heapArr[0]  # move min to end
        heapify(heapArr, end, 0) 

def heapify(heapArr, n, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and heapArr[left] < heapArr[smallest]:
        smallest = left
    if right < n and heapArr[right] < heapArr[smallest]:
        smallest = right

    if smallest != i:
        heapArr[i], heapArr[smallest] = heapArr[smallest], heapArr[i]
        heapify(heapArr, n, smallest)

def main():
    heapArr = []

    #insert data
    print(heapArr)
    #data = int(input("Insert data: "))
    insertData(16, heapArr)
    print(heapArr)
    insertData(20, heapArr)
    print(heapArr)
    insertData(10, heapArr)
    print(heapArr)
    insertData(19, heapArr)
    print(heapArr)
    insertData(18, heapArr)
    print(heapArr)
    insertData(5, heapArr)
    print(heapArr)
    insertData(15, heapArr)
    print(heapArr)

    #getting max O(n)
    print('Max is:',max(heapArr))

    #getting min O(1)
    print('Min is:',heapArr[0])

    #getting size 
    print('Length is:', len(heapArr))

    #isempty
    if len(heapArr) == 0:
        print('It is empty')
    else:
        print('It is not empty')

    #extract-min (and remove it, implement shift down)
    removed = remove(heapArr, 0)
    print('Value remove is: ',removed)
    print('New array is:', heapArr)

    #removing in a position
    position = int(input('Insert position to delete:'))
    removed = remove(heapArr, position)
    print('Value remove is: ',removed)
    print('New array is:', heapArr)

    #sort heap for random array
    arrToSort = [17, 10, 3, 8, 20, 2, 1]
    heapSort(arrToSort)
    print('Array sorted is: ', arrToSort)
 
if (__name__ == '__main__'):
    main()

