class Node: #class Node
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class linkedList:
    def __init__(self):
        self.head = None

    def insertBeg(self, data):
        node = Node(data, self.head)
        self.head = node

    def insertEnd(self, data):
        node = Node(data, None)
        itr = self.head

        while itr:
            if itr.next is None:
                itr.next = node
                return
            itr = itr.next

    def print(self):
        if self.head is None:
            print ("Linked list is empty")
            return
        itr = self.head
        llstr = ''
        while itr:
            llstr += str(itr.data) + ' --> ' if itr.next else str(itr.data)
            itr = itr.next
        print(llstr)

    def insertPosition(self, pos, data):
        node = Node(data, None)
        itr = self.head

        if (pos == 1):
            node.next = itr
            self.head = node
            return
        
        for i in range(pos-2):
            print(i)
            itr = itr.next

        node.next = itr.next
        itr.next = node

    def deletePosition(self, pos):
        itr = self.head

        if (pos == 1):
            self.head = self.head.next
            del itr
            return
        
        for i in range (pos-2):
            itr = itr.next

        itr.next = itr.next.next
        del itr

        
def menu():
    l1 = linkedList()

    while(True):
        print('SINGLY LINKED LIST MEU:')
        print('1: Insert at the beginning')
        print('2: Insert at the end')
        print('3: Insert in a position')
        print('4: Delete in a position')
        print('5: Print')
        print('6: Exit')

        option = input("Select an option: ")

        if (option == '1'):
            val = input("Insert data: ")
            l1.insertBeg(val)
        elif (option == '2'):
            val = input("Insert data: ")
            l1.insertEnd(val)
        elif (option == '3'):
            pos = input("Insert position: ")
            val = input("Insert data: ")
            pos = int(pos)
            val = int(val)
            l1.insertPosition(pos, val)
        elif (option == '4'):
            pos = input("Insert position: ")
            pos = int(pos)
            l1.deletePosition(pos)
        elif (option == '5'):
            l1.print()
        elif (option == '6'):
            print('Exiting program...')
            break
        else:
            print('Insert a correct number')

if __name__ == '__main__':
    menu()




