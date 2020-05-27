def binary_search( arr, len, num ) :
    ll = 0
    ul = len - 1
    mid = int( ll + ul / 2 )
    while( ll < ul and mid < len ) :
        if arr[mid] > num :
            ul = mid - 1
        elif arr[mid] < num :
            ll = mid + 1
        else:
            break;
        mid = int( ul + ll / 2 )

    if( mid < len ) :
        if( arr[mid] == num ) :
            return mid
    else :
        return -1

len = int( input( "Enter the length of array : " ) )

arr = []

print( "Enter Values in Ascending Order" )
for i in range( len ) :
    arr.append( int( input( "Enter value in array : " ) ) )

num = int( input( "Enter the number to find : " ) )

loc = binary_search( arr, len, num )

if( loc != -1 ) :
    print( "Number is found at index {}".format( loc ) )
else :
    print( "Number is not found in given array" )