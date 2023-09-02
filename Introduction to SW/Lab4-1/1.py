n = int(input())

for i in range(1, n+1):
    if i % 2 == 0 & i % 3 ==0:
        print(i)
    elif i % 2 == 0:
        print(i)
    elif i % 3 == 0:
        print(i)