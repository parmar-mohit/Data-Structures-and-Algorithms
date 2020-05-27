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

def remove(data):
    global root
    node = root
    parent = None
    while node.data != data:
        parent = node
        if data < node.data:
            node  =  node.left
        else:
            node = node.right
    if node.left == None and node.right == None:
        if data < parent.data:
            parent.left = None
        else:
            parent.right = None
    elif node.left != None:
        change = node.left
        newParent = node
        while change.right != None:
            newParent = change
            change  = change.right
        newparent.left = change.left
        node.data = change.data
    else:
        change = node.right
        newParent = node
        while change.left != None:
            newParent = change
            change= change.left
        newParent.right = change.right
        node.data = change.data

def inorderDisp(root):
    if root.left != None:
        inorderDisp(root.left)

    print(root.data," ",end="")

    if root.right != None:
        inorderDisp(root.right)

N= int(input("Enter no of nodes in tree : "))

arr = []
root = None

for i in range(N):
    arr.append(int(input("Enter value in array : ")))

createTree(arr, N)

print("Binary tree created Successfully")

print("Inorder Traversal is : ", end = "")
inorderDisp(root)
print()

num = int(input("Enter no to be deleted : "))
remove(num)
print(num , "Removed From tree")

print("Inorder Traversal is : ", end ="")
inorderDisp(root)