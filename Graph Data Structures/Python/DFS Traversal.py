def push (data, stack):
    global ptr
    ptr += 1
    stack.append(data)

def pop(stack):
    global ptr
    x = stack[ptr]
    ptr -= 1
    return x

N = int(input("Enter No of Vertices in Graph : "))

graph = []
stack = []
ptr = -1
flag = [0]

print("Enter value of edges in matrix")
for i in range(N+1):
    arr = []
    if i == 0:
        for j in range(N+1):
            arr.append(0)
    else:
        for j in range(N+1):
            if j == 0:
                arr.append(0)
            else:
                print("Enter value in ", i, "th row and",j,"th column : ", end="")
                arr.append(int(input()))
    graph.append(arr)

for i in range(N+1):
    flag.append(-1)

startVertex = int(input("Enter Vertex to start from : "))
push(startVertex, stack)
flag[startVertex] += 1

print("DFS Traversal is : ", end="")
while( ptr != -1 ):
    if flag[startVertex] == 0:
        print(startVertex," ", end ="")
        flag[startVertex] += 1

    i = 1
    while i < N+1:
        if i <= N and graph[startVertex][i] > 0 and flag[i] == -1:
            break
        i += 1

    if i == N+1:
        pop(stack)
    else:
        push(i, stack)
        flag[i] += 1
    startVertex = stack[ptr]
