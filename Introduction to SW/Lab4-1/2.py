a=int(input())
b=int(input())

def add(a,b):
    return a+b
def sub(a,b):
    return a-b
def mul(a,b):
    return a*b
def div(a,b):
    return a/b
def mod(a,b):
    return a % b
def printMsg(msg):
    print(msg)

add_result=add(a,b)
sub_result=sub(a,b)
mul_result=mul(a,b)
div_result=div(a,b)
mod_result=mod(a,b)

printMsg("sum: "+ str(add_result))
printMsg("difference: "+ str(sub_result))
printMsg("product: "+ str(mul_result))
printMsg("division: "+ str(div_result))
printMsg("remainder: "+ str(mod_result))
printMsg("completed")