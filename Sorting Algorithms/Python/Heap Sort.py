def heapSort( arr, len ):
    heap = []
    heapend = -1
    for i in range( len ):
        pushHeap( heap, arr[i], heapend )
        heapend += 1

    while heapend >= 0:
        arr[heapend] = popHeap(heap, heapend)
        heapend -= 1

def pushHeap( heap, data, heapend):
    heapend += 1
    heap.append( data )

    while heapend > 0 :
        parent = int( ( heapend - 1 ) / 2 )
        if heap[parent] < heap[heapend] :
            heap[parent], heap[heapend] = heap[heapend], heap[parent]
            heapend = parent
        else :
            break

def popHeap( heap, heapend ) :
    max = heap[0]
    heap[0] = heap[heapend]
    heap.pop()
    heapend -= 1

    i = 0

    while i < heapend :
        leftchild = int( ( 2 * i ) + 1 )
        rightchild = int( ( 2 * i ) + 2 )

        if leftchild <= heapend and  rightchild <= heapend:
            if heap[leftchild] > heap[i] and heap[leftchild] > heap[rightchild]:
                heap[leftchild], heap[i] = heap[i], heap[leftchild]
                i = leftchild
            elif heap[rightchild] > heap[i]:
                heap[rightchild], heap[i] = heap[i] ,heap[rightchild]
                i = rightchild
            else :
                break
        elif leftchild <= heapend and rightchild > heapend :
            if heap[leftchild] > heap[i]:
                heap[leftchild], heap[i] = heap[i], heap[leftchild]
                i = leftchild
            else:
                break
        else:
            break
    return max


len = int( input( "Enter length of array : " ) )

arr = []

for i in range( len ):
    arr.append(int( input( "Enter value in array : " ) ) )

heapSort( arr, len )

print( "Sorted array is :", arr )
