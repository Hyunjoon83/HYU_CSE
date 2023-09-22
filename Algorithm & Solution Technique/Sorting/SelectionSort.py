arr=[int(x) for x in input().split()]

def SelectionSort(arr,n):
    for i in range(n-1):
        index=i
        for j in range(i+1,n):
            if arr[j]<arr[index]:
                index=j
        arr[i],arr[index]=arr[index],arr[i]
    return arr

SelectionSort(arr,len(arr))
print(arr)