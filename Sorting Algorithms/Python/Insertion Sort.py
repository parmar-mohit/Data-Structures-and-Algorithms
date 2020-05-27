def insertionSort( arr, len ):
    for i in range(1,len):
        temp = arr[i]
        j = int()
        for j in range(i-1, -1, -1):
            if arr[j] > temp:
                arr[j+1] = arr[j]
        arr[j] = temp

len = int(input("Enter length of array : "))

arr = []

for i in range(len):
    arr.append( int(input("Enter value in array : ")))

insertionSort(arr, len)

print("Sorted array is :", arr)