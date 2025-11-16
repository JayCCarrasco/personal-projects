#step by step linked list mergesort implementation
#by geeksforgeeks

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def split(head):
    fast = head
    slow = head

    while fast and fast.next:
        fast = fast.next.next
        if fast:
            slow = slow.next

    #second es el puntero a la segunda mitad
    second = slow.next
    slow.next = None
    return second

def merge(first, second):

    if not first:
        return second
    if not second:
        return first
    
    if first.data < second.data:
        first.next = merge(first.next, second)
        return first
    else:
        second.next = merge(first, second.next)
        return second
    
def mergeSort(head):

    if not head or not head.next:
        return head

    #Dividimos la lista en dos mitades
    #como ya tenemos head, lo que necesitamos es second,
    #que guarda el inicio de la segunda mitad por cada
    #iteración
    second = split(head)

    #Ordenar recursivamente cada mitad
    #como mergesort returna el valor mas pequeño (return merge)
    #actualiza head o second dependiendo de la mitad de la 
    #lista enlazada en la que estemos
    head = mergeSort(head)
    second = mergeSort(second)

    return merge(head, second)

def printList(head):
    curr = head
    while curr is not None:
        print(curr.data, end=" ")
        if curr.next:
            print("->", end=" ")
        curr = curr.next
    print()
    
def menu():
    # Create a hard-coded singly linked list:
    # 9 -> 8 -> 5 -> 2
    head = Node(9)
    head.next = Node(8)
    head.next.next = Node(5)
    head.next.next.next = Node(2)

    head = mergeSort(head)
    printList(head)

if __name__ == "__main__":
    menu()