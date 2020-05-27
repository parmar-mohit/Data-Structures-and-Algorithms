def quickSort( arr, start, end ):
    if start < end :
        pivot = partition( arr, start, end )
        print( arr )
        quickSort( arr, start, pivot - 1 )
        print( arr )
        quickSort( arr, pivot + 1, end )
        print( arr )

def partition( arr, start, end ):
    pivot = arr[start]
    ll = start
    ul = end

    while( start < end ) :
        while start < end and arr[start] <= pivot:
            start += 1

        while arr[end] > pivot :
            end -= 1

        if start < end :
            arr[start], arr[end] = arr[start], arr[end]

    arr[ll], arr[end] = arr[end], arr[ll]

    return end


len = int( input( "Enter Length of Array : " ) )

arr = []

for i in range( len ) :
    arr.append( int( input( "Enter Value in Array : " ) ) )

quickSort( arr, 0, len  - 1 )

print( "Sorted array is :", arr )

