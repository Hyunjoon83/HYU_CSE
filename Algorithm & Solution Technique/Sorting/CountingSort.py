def CountingSort(A, N):
    K=max(A)
    C=[0]*(K+1)
    
    for i in range(N):
        C[A[i]]+=1

    for i in range(1,K+1):
        C[i]+=C[i-1]

    B=[0]*N
    for i in range(N-1,-1,-1):
        B[C[A[i]]-1]=A[i]
        C[A[i]]-=1

    return B

N=int(input())
A=list(map(int, input().split()))

sorted_array=CountingSort(A,N)

for num in sorted_array:
    print(num,end=" ")
