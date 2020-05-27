class tree:
    def __init__(self):
        self.data = int()
        self.left = None
        self.right = None

def createTree():
    head = tree()
    x = int(input("Enter data : "))
    head = create( x )
    if head != None:
        print("Left Child of",x," ", end="")
        head.left = createTree()
        print("Right Child of",x," ", end="")
        head.right = createTree()
    return head

def create(x):
    if x == -1:
        return None
    head = tree()
    head.data = x
    head.left = None
    head.right = None
    return head

def inorderDisp(root):
    if root.left != None:
        inorderDisp(root.left)
    print(root.data, " ", end ="")
    if root.right != None:
        inorderDisp(root.right)

root = createTree()
inorderDisp(root)