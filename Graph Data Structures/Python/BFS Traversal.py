def push(data, que):
    global start
    global end
    if start == end:
        start += 1
    end += 1
    que.append(data)

N = int(input("Enter No of Vertices in Graph : "))

graph = []
que = []
start = -1
end = -1
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

startVertex = int(input("Enter the vertex to start from : "))

push(startVertex, que)
flag[startVertex] += 1

ptr = 0

while ptr != N:
    startVertex = que[ptr]
    print(startVertex, " ", end="")

    for i in range(N+1):
        if graph[startVertex][i] > 0 and flag[i] == -1:
            push(i, que)
            flag[i] += 1

    ptr += 1