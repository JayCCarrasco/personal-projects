from collections import deque

class Queue:
    def __init__(self):
        self.data = deque()

    def enqueue(self, node):
        self.data.append(node)

    def dequeue(self):
        self.data.popleft()

    def printQueue(self):
        for data in self.data:
            print(data)


q1 = Queue() 
q1.enqueue(10)      
q1.enqueue(20)    
q1.enqueue(30) 
q1.printQueue()   
q1.dequeue()
q1.printQueue()
q1.enqueue(40)
q1.printQueue()
q1.dequeue()
q1.printQueue()

