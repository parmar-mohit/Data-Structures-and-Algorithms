# This Splay Tree Deletion Code is written with Bottom Up Approach

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

def splayTree( root, data):
    if root.data != data:
        if data < root.data:
            root.left = splayTree(root.left, data)
            root = rightRotation(root)
        else:
            root.right  = splayTree(root.right,data)
            root = leftRotation(root)
    return root

def remove(data):
    global root
    node = root
    parent = None

    while node.data != data:
        parent = node
        if data < node.data:
            node = node.left
        else:
            node = node.right

    if node.left == None and node.right == None:
        if data < parent.data:
            parent.left = None
        else:
            parent.right = None
    elif node.left != None:
        newParent = node
        change = node.left
        while change.right != None:
            newParent = change
            change  = change.right
        newParent.right = change.left
        node.data = change.data
    else:
        newParent = node
        change = root.right
        while change.left != None:
            newParent = change
            change = change.left
        newParent.left = change.right
        node.data = change.data
    root = splayTree(root, parent.data)

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

N = int(input("Enter no of nodes in Tree : "))

arr = []
root = None

for i in range(N):
    arr.append(int(input("Enter Value in array : ")))

createTree(arr, N)
print("Binary Tree Created Successfully")

print("Inorder Traversal is : ", end="")
inorderDisp(root)
print()

print("Preorder traversal is : ", end ="")
preorderDisp(root)
print()

num = int(input("Enter no you want to remove : "))

remove(num)
print(num ,"Removed from tree")

print("Inorder Traversal is : ", end="")
inorderDisp(root)
print()

print("Preorder traversal is : ", end ="")
preorderDisp(root)