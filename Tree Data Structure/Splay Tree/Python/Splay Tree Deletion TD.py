# This Splay Tree Seletion Code is written with Top Down Approach

class tree:
    def __init__(self):
        self.data = int()
        self.left = None
        self.right = None

def create(data):
    head = tree()
    head.data = data
    return head

def createTree( arr, N ):
    global root
    for i in range(N):
        node = create(arr[i])
        if root == None:
            root = node
        else:
            temp = root
            while temp != None:
                parent  = temp
                if node.data < temp.data:
                    temp = temp.left
                else:
                    temp = temp.right
            if node.data < parent.data:
                parent.left = node
            else:
                parent.right = node
        root = splayTree(root, arr[i])

def remove(data):
    global root
    root = splayTree(root, data)
    change = root.left
    while change.right != None:
        change = change.right
    root.left = splayTree(root.left, change.data)
    temp = root
    root = root.left
    root.right = temp.right

def splayTree( root, data):
    if root.data != data:
        if data < root.data:
            root.left = splayTree(root.left, data)
            root = rightRotation(root)
        else:
            root.right  = splayTree(root.right,data)
            root = leftRotation(root)
    return root

def rightRotation(root):
    temp = root
    root = root.left
    temp.left = root.right
    root.right = temp
    return root

def leftRotation(root):
    temp = root
    root = root.right
    temp.right = root.left
    root.left = temp
    return root

def inorderDisp(root):
    if root.left != None:
        inorderDisp(root.left)

    print(root.data," ",end="")

    if root.right != None:
        inorderDisp(root.right)

def preorderDisp(root):
    print(root.data," ", end="")
    if root.left != None:
        preorderDisp(root.left)
    if root.right != None:
        preorderDisp(root.right)

N = int(input("Enter no of node in tree : "))

arr = []
root = None

for i in range(N):
    arr.append(int(input("Enter value in array : ")))

createTree(arr, N)
print("Binary tree Created Successfully")

print("Inorder Traversal is : ", end="")
inorderDisp(root)

print("Preorder Traversal is : ", end="")
preorderDisp(root)
print()

num = int(input("Enter no you want to delete : "))
remove(num)

print(num ,"Removed from tree")

print("Inorder traversal is : ",end="")
inorderDisp(root)

print("PreorderDisp is : ", end= "")
preorderDisp(root)