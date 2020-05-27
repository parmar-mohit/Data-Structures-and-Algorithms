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

def inorderDisp(root):
    if root.left != None:
        inorderDisp(root.left)

    print(root.data," ",end="")

    if root.right != None:
        inorderDisp(root.right)

N = int( input("Enter no of nodes in tree : "))

arr = []
root = None

for i in range(N):
    arr.append(int(input("Enter value in array : ")))

createTree(arr,N)

print("Binary tree Created Successfully")

print("Inorder Traversal of tree is : ", end ="")
inorderDisp(root)