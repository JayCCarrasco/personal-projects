class Node: #class node
    def __init__(self, data = None, next = None):   #constructor with the data and the next node
        self.data = data    #when creates a node, saves data for the instance
        self.next = next    #when creates a node, saves next node for the instance

class LinkedList:   #class linked list
    def __init__(self):     #constructor with the head
        self.head = None    #initialize head to None 
        self.size = 0   #linked list initial value = 0

    def insertBeg(self, data):  #method for insert node at the beginning. pass data as argument
        node = Node(data, self.head)    #creates a node 
        self.head = node    #as it is been inserted at the beginning, the new node is now the head
        self.size += 1

    
    def print(self):
        if self.head is None:
            self.isEmpty()
            return
        itr = self.head
        llstr = ''
        while itr:
            llstr += str(itr.data)+' --> ' if itr.next else str(itr.data)
            itr = itr.next
        print(llstr)
    
    def isEmpty(self):
        if self.size == 0:
            print("List is empty")
        else:
            print("List is not empty")

    

    def delete(self):
        itr = self.head

        self.head = itr.next
        itr = None
        self.size -= 1
        return
    

    
l1 = LinkedList()
l1.isEmpty()
l1.insertBeg(5)
l1.insertBeg(8)
l1.insertBeg(300)
l1.print()
l1.isEmpty()
l1.delete()
l1.print()
l1.delete()
l1.print()
l1.delete()
l1.isEmpty()
