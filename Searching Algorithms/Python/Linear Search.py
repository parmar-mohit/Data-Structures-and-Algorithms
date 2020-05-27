def linearSearch( arr, len , num):
    for i in range( len ) :
        if arr[i] == num :
            return i
    else:
        return -1

len = int( input( "Enter Length of Array : " ) )

arr = []

for i in range( len ) :
    arr.append( int( input( "Enter Value in Array : " ) ) )

num = int( input( "Enter Number to find in array : " ) )

loc = linearSearch( arr, len , num )

if loc == -1 :
    print( "Number is Not found in Given array" )
else:
    print( "Number is found at index :", loc )