from collections import deque

class Node:
    def __init__ (self, data, left = None, right = None):
        self.data = data
        self.visited = False
        self.left = left
        self.right = right

def dfs(root):
    if root == None: return None
    dfs(root.left)
    dfs(root.right)  
    if root.visited == False:
        print(root.data)
        
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

    dfs(n1)

if __name__ == "__main__":
    main()