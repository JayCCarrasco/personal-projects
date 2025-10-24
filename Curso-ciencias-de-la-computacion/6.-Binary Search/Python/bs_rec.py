#Binary search algorithm using recursion in Python
#By JCPC

def binarySearchRecursion(array, min, max, look):
    med = round((max+min) / 2)
    if(min > max):
        print('Not found')
        return
    if (array[med] == look):
        print('Encontrado: ', array[med], 'en posición', med)
        return
    elif (array[med]> look):
        max = med-1
        binarySearchRecursion(array, min, max, look)
    else:
        min = med+1   
        binarySearchRecursion(array, min, max, look)

def main():
    array = [10, 20, 25, 33, 45, 67, 78, 112, 234, 567, 888, 1001, 2034, 3214, 4000, 5000]
    min = 0
    max = len(array)-1
    look = 1

    while(look != 0):
        look = int(input("Insert value to lookup (0 to exit):"))
        binarySearchRecursion(array, min, max, look)  

if __name__ == "__main__":
    main()

