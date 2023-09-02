n=int(input())

def addTotal():
    sgm=0
    for i in range(1,n+1):
        sgm += i
    return sgm
def mulTotal():
    global gMul
    gMul=1
    for i in range(1,n+1):
        gMul *= i
print("addTotal(): ",str(addTotal()))
print("gMul: ", str(mulTotal()))