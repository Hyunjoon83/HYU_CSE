i=1
for i in range(2,10):
    for j in range(1,10):
        print(str(i)+"*"+str(j)+"="+str(i*j))
        if j==9:
            print()
            break