#Array methods in python

#In python an array is declared as this:
array = [1,2,3,4]
print('The array is:',array)    #see array

#Arrays in Python are dynamic and the programmer does not have to worry resizing
#memory allocation, as instance we could append one more number to array just doing:
array.append(5)
print('Now the array is:',array)

#to look size just use len method:
print('The size of the array is:',len(array))

#check if an array is empty
if (len(array ) == 0):
    print('Array is empty')
else:
    print('Array is not empty')

#check value at an index, for example at certain position
print('Insert the position to check value:')
position = int(input()) 
print(f'Value in position {position} is {array[position-1]}')

#add an item at front of the list, for example 666
array.insert(0, 666)
print('Now array is:',array)

#remove an item from front of the list
array.pop(0)
print('Now array is:',array,'again')

#to get value from the front
print('The first item in the array is',array[0])

#and to get value from last position
print('The last item in the array is:',array[len(array)-1])

#to add a value at certain position
print('Insert value to append')
value = int(input())
print("Insert position: ")
position = int(input())

array.insert(position, value)
print('Now the array is:',array)

#to remove an item from a position, for example position 4 (index 3 for array)
array.pop(3)
print('After deletion array is:',array)

#get value at n position from the end of the list, for example second position
print('Second value from the end of array is:',array[len(array)-1-1])

#reversing array
array.reverse()
print('Array reversed is:',array)

#remove first item in the list with a certain value, for example 2
array.remove(2)
print("First value 2 has been deleted in array:",array)