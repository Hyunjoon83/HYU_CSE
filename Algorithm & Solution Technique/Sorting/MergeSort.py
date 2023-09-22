arr=[int(x) for x in input().split()]

def Merge(left,right):
    i=0
    j=0
    result=[]
    
    while(i<len(left)) & (j<len(right)):
        if left[i]<right[j]:
            result.append(left[i])
            i+=1
        else:
            result.append(right[j])
            j+=1
    while(i<len(left)):
        result.append(left[i])
        i+=1
    while(j<len(right)):
        result.append(right[j])
        j+=1
    return result
    
def MergeSort(arr):
    if len(arr)<=1:
        return arr
    
    mid=len(arr)//2
    left=arr[:mid]
    right=arr[mid:]
    
    left1=MergeSort(left)
    left2=MergeSort(right)
    return Merge(left1,left2)

print(MergeSort(arr))
    
    