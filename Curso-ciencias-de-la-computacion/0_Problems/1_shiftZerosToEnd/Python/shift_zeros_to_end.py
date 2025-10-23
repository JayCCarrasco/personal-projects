def shiftZerosToEnd(array):
    count = 0
    for i in range(0, len(array)):
        if array[i] != 0:
            temp = array[i]
            array[i] = array[count]
            array[count] = temp
            count += 1

def main():
    array = [1, 0, 3, 0, 5, 0, 0, 77, 6, 0, 0, 0, 0, 1]
    shiftZerosToEnd(array)
    print(array)

if __name__ == '__main__':
    main()