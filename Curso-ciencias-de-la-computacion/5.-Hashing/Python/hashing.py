#some methods used for python dictionaries

#creating an empty dictonary
my_dict = {}

#inserting key and values directly on my_dict
my_dict = {'a':1, 'b':2}
print(my_dict)

#creating dict with constructor
my_dict = dict(x=1, y=2)
print(my_dict)

#difference between direct and constructor is that
#constructor does not allow string keys that are not valid
#python identifiers as #my_dict = dict (1=100)
#But directly:
my_dict = {1:100} #YES!
print (my_dict)

#ACCESS AND MODIFICATIONS FOR DICTIONARIES
#Declaring my_dict again
my_dict = {'a':1, 'b':2}

#Access value by key
print(my_dict['a'])

#Safe access with default
print(my_dict.get('z,',0))

#Insert or update key-value pair
my_dict['c'] = 3
print(my_dict)

#Remove key
del my_dict['a']
print(my_dict)

#Remove and return value
print(my_dict.pop('b',0))

#Declaring my_dict again
my_dict = {'a':1, 'b':2, 'c':3}

#Remove and return the last inserted item
key, val = my_dict.popitem()
print(key, val)

#Remove all
my_dict.clear()
print(my_dict)

#INSPECTIONS
#Declaring my_dict again
d = {'a':1, 'b':2, 'c':3}

#View all keys
print(d.keys())

#View all values
print(d.values())

#View of key, value pairs
print(d.items())

#Membership test for key
print('a' in d)

#MERGING AND COPYING
#Declaring dictionaries
d1 = {'a':1, 'b':2, 'c':3}
d2 = {'d':4, 'e':5}

#Add or overwrite from another dict
d1.update(d2)
print(d1)

#Shallow copy
new_d1 = d1.copy()
print(new_d1)

#merge dictionaries
d1 = {'a':1, 'b':2, 'c':3}
merged = {**d1, **d2}
print(merged)

