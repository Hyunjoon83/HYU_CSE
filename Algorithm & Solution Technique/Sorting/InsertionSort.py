arr=[1,6,9,2,5,8,3,4,7]

def InsertionSort(arr):
    for i in range(1,len(arr)):
        for j in range(i,0,-1):
            if arr[j]<arr[j-1]:
                arr[j],arr[j-1]=arr[j-1],arr[j] #swap
            else:
                break

InsertionSort(arr)
print(arr)