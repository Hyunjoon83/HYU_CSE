n=int(input())

def printLine(n):
    for i in range(1,n+1):
        print(i,end=' ')
    print()
    
    
for i in range(1,n+1):
    printLine(i)

for j in range(n,0,-1):
    printLine(j)