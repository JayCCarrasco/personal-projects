from collections import deque
import sys

class Node:
    def __init__ (self, data):
        self.data = data
        self.visited = False
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def insertNode(self, data):
        node = Node(data)
        if self.root == None:
            self.root = node
            return self.root
        
        current = self.root
        while True:
            if data < current.data:
                if current.left is None:
                    current.left = node
                    break
                current = current.left
            elif data > current.data:
                if current.right is None:
                    current.right = node
                    break
                current = current.right
            else:
                break
        return self.root
    
    def dfs(self, root, mode):
        if root is None: return
        if mode == 0:
            print(root.data)
        self.dfs(root.left, mode)
        if mode == 1:
            print(root.data)
        self.dfs(root.right, mode)  
        if mode == 2:
            print(root.data)

    def bfs(self, root):
        if root == None: return None

        q1 = deque()
        q1.append(root)

        while q1:
            current = q1.popleft()
            print(current.data)

            if current.left: q1.append(current.left)
            if current.right: q1.append(current.right)  

    def getHeight(self, root):
        if root == None: return 0

        lHeight = self.getHeight(root.left)
        rHeight = self.getHeight(root.right)

        if lHeight > rHeight:
            return lHeight + 1
        else:
            return rHeight + 1 
        
    def getMin(self, root):
        if root == None: return 0

        while(root.left != None):
            root = root.left

        return root.data

    def getMax(self, root):
        if root == None: return 0

        while(root.right != None):
            root = root.right

        return root.data
    
    def isBSTUtil(self, root, minSize, maxSize):
        if root is None: return True

        if (root.data <= minSize or root.data >= maxSize):
            return False
        
        return (self.isBSTUtil(root.left, minSize, root.data) and
                self.isBSTUtil(root.right, root.data, maxSize))

    def isBST(self, root):
        return self.isBSTUtil(root, -sys.maxsize, sys.maxsize)

    def deleteNode(self, root, data):
        if root is None: return None
        if data < root.data: root.left = self.deleteNode(root.left, data)
        elif data > root.data: root.right = self.deleteNode(root.right, data)
        else: #FOUND YO
            if root.right is None and root.left is None:
                del(root)
                root = None
            elif root.left is None:
                temp = root
                root = root.right
                del(temp)
            elif root.right is None:
                temp = root
                root = root.left
                del(temp)
            else:
                temp = self.getMin(root.right)
                root.data = temp
                root.right = self.deleteNode(root.right, temp)
        return root
    
    def getSuccessor(self, root, data):
        if root is None: return None

        if(root.data == data):
            return (self.getMin(root.right))
        
        curr = root
        succ = None

        while curr != None:
            if data < curr.data:
                succ = curr
                curr = curr.left
            elif data >= curr.data:
                curr = curr.right
        if succ == None:
            return
        return succ.data


def menu():
    t1 = Tree()

    while(True):
        data = 1 #Initializing data different to 0  
        print('BINARY SEARCH TREE MENU:')
        print('0: Exit')
        print('1: Insert node')
        print('2: Depth First Search')
        print('3: Breadth First Search')
        print('4: Get Height')
        print('5: Get Minimum')
        print('6: Get Maximum')
        print('7: Check if it is a tree')
        print('8: Delete node')
        print('9: Get successor')
        option = input("Choose an option: ")

        if (option == '0'):
            print("Exiting...")
            break
        elif (option == '1'):
            while True:
                data = int(input("Insert data (Insert 0 to exit): "))
                if data == 0:
                    break
                root = t1.insertNode(data)
        elif (option == '2'):
            mode = int(input('Select dfs mode || 0: Preorder || 1: Inorder || 2: PostOrder: '))
            t1.dfs(root, mode)
        elif (option == '3'):
            t1.bfs(root)
        elif (option == '4'):
            height = t1.getHeight(root)
            print('Height is: ', height)
        elif (option == '5'):
            min = t1.getMin(root)
            print('Min is: ', min)
        elif (option == '6'):
            max = t1.getMax(root)
            print('Max is: ', max)
        elif (option == '7'):
            checkTree = t1.isBST(root)
            if checkTree is True:
                print('It is a tree')
            else:
                print('It is not a tree')
            temp = root
            temp.left.right = Node(555)
            checkTree = t1.isBST(temp)
            if checkTree is True:
                print('It is a tree')
            else:
                print('It is not a tree')
        elif (option == '8'):
            data = int(input('Insert node to delete: '))
            t1.deleteNode(root, data)
        elif (option == '9'):
            data = int(input('Insert number to obtain its successor: '))
            successor = t1.getSuccessor(root, data)
            if successor != None:
                print('The successor is: ', successor)
            else:
                print('There is no successor for that number')
        else:
            print('Insert a correct number')

if __name__ == '__main__':
    menu()
        