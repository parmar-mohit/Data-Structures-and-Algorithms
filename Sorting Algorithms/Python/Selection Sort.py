def selectionSort( arr, len ):
    for i in range ( len - 1  ):
        min = i
        for j in range( i+1, len ):
            if arr[j] < arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]

len = int( input( "Enter length of array : " ) )
arr = []

for i in range( len ) :
    arr.append( int( input( "Enter value in arrray : " ) ) )

selectionSort( arr, len )

print( "Sorted array is", arr )