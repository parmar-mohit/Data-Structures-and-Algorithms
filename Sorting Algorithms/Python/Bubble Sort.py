def bubbleSort( arr, len ) :
    for i in range(len - 1):
        for j in range(len - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


len = int( input( "Enter Length of array : " ) )

arr = []

for i in range( len ) :
    x = int( input( "Enter value in array : " ) )
    arr.append( x )

print( "Unsorted array is : ", arr )

bubbleSort( arr, len )

print( "Elements in sorted order are : ", arr )