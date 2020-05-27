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
        print("Left Child of",x," ",end="")
        head.left = createTree()
        print("Right Child of",x," ",end="")
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

def postorderDisp(root):
    if root.left != None:
        postorderDisp(root.left)
    if root.right != None:
        postorderDisp(root.right)
    print(root.data, " ", end="")

root = createTree()
postorderDisp(root)