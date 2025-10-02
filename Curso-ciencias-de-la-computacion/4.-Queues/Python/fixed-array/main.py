class Queue:
    def __init__(self):
        self.data = [0,0,0,0,0,0,0,0] #8 spaces array
        self.position = 0

    def enqueue(self, data):
        self.data[self.position] = data
        self.position+=1

    def dequeue(self):
        for i in range(1, len(self.data)):
            self.data[i-1] = self.data[i]
        self.position-=1

    def printQueue(self):
        for data in self.data:
            print(data)

q1 = Queue()
q1.enqueue(10)        
q1.enqueue(20)   
q1.enqueue(30)  

q1.printQueue()  
q1.dequeue()
print("----------------")
q1.printQueue() 
q1.enqueue(40)
print("----------------")
q1.printQueue() 


