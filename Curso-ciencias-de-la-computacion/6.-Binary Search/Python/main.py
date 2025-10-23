#Binary search algorithm in Python
#By JCPC

def main():
    array = [10, 20, 25, 33, 45, 67, 78, 112, 234, 567, 888, 1001, 2034, 3214, 4000, 5000]
    min = 0
    max = len(array)-1
    look = 5000
    exit = 1

    while exit != 0:
        med = round((max+min) / 2)
        print(med)
        if (array[med] == look):
            print('Encontrado: ', array[med], 'en posición', med)
            exit = 0
        elif (array[med]> look):
            max = med-1
            #print(max)
        else:
            min = med+1   
            #print(min) 

if __name__ == "__main__":
    main()

