def mergeSort(arr, start, end):
    if start < end :
        mid  = int((start + end) / 2)
        mergeSort(arr,start, mid)
        mergeSort(arr, mid +1, end)
        merge(arr, start, mid, end)

def merge(arr, start, mid, end):
    lenLeftArr = mid - start + 1
    lenRightArr = end - mid

    leftArr = []
    rightArr = []

    for i in range(lenLeftArr):
        leftArr.append(arr[start+i])

    for j in range(lenRightArr):
        rightArr.append(arr[mid+j+1])

    i = j = int(0)
    k = start

    while i < lenLeftArr and j < lenRightArr:
        if leftArr[i] <= rightArr[j]:
            arr[k] = leftArr[i]
            i += 1
        else:
            arr[k] = rightArr[j]
            j += 1
        k += 1

    while i < lenLeftArr:
        arr[k] = leftArr[i]
        i += 1
        k += 1

    while j < lenRightArr:
        arr[k] = rightArr[j]
        j += 1
        k += 1

len = int(input("Enter Length of array : "))

arr = []

for i in range(len):
    arr.append(int(input("Enter Value in array : ")))

mergeSort(arr, 0, len-1)

print("Sorted array is :", arr)