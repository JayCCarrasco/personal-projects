#Implementing mergeSort, a beautiful algorithm using recursion in Python
#By JCPC 11/11/2025
#Space complexity O(nlog(n)).
#There is a version which uses O(n). Should be implemented in the future
#Space complexity: O(n log(n)) en todos los casos

def mergeSort(array):
    if len(array)>1:
        left_arr = array[:len(array)//2]
        right_arr = array[len(array)//2:]
    
        mergeSort(left_arr)
        mergeSort(right_arr)

        #merge
        i = 0
        j = 0
        k = 0

        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] < right_arr[j]:
                array[k] = left_arr[i]
                i+=1
            else:
                array[k] = right_arr[j]
                j+=1
            k+=1
        
        while i < len(left_arr):
            array[k] = left_arr[i]
            i+=1
            k+=1
        
        while j < len(right_arr):
            array[k] = right_arr[j]
            j+=1
            k+=1
    #return array
        
def main():
    array = [7,3,9,5,4,8,0,1]
    mergeSort(array)
    print(array)

if __name__=='__main__':
    main()

        