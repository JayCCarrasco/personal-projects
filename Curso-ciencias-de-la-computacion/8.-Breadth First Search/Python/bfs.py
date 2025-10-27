from collections import deque

class Node:
    def __init__ (self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right

class Queue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, node):
        self.queue.append(node)
    
    def dequeue(self):
        nodeDeleted = self.queue.popleft()
        return nodeDeleted


def bfs(root):
    if root == None: return None

    q1 = Queue()
    q1.enqueue(root)

    while q1.queue:
        current = q1.dequeue()
        print(' ', current.data)

        if current.left:
            q1.enqueue(current.left)
        if current.right:
            q1.enqueue(current.right)
        
def main():
    n9 = Node(90, None, None)
    n8 = Node(80, n9, None)
    n5 = Node(50, None, None)
    n6 = Node(60, None, None)
    n7 = Node(70, None, None)
    n4 = Node(40, n5, None)
    n3 = Node(30, n7, n8)
    n2 = Node(20, n4, n6)
    n1 = Node(10, n2, n3)

    bfs(n1)

if __name__ == "__main__":
    main()