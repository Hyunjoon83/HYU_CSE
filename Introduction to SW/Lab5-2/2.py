import random

def getThreeNumbers():
    numbers=[]
    
    num1=random.randint(1,9)
    num2=random.randint(1,9)
    while (num2 == num1):
        num2=random.randint(1,9)
        
    numbers.append(num1)
    numbers.append(num2)
    
    num3=random.randint(1,9)
    while (num3==num2 or num3 ==num1):
        num3 = random.randint(1,9)  
    numbers.append(num3)        

    return numbers
        
def getNumbersFromUser():
    while True:
        n=input()
        if len(n)!=3 or not n.isdigit() or n[0] == n[1] or n[0] == n[2] or n[1] == n[2]:
            print(n," is an invalid input. Try again.\n")
        else:
            return [int(i) for i in n]

def checkNumber(input,output):
    strike=0
    ball=0
    out=0
    
    for i in range(3):
        if input[i]==output[i]:
            strike+=1
        elif input[i] in output:
            ball+=1
        
    if strike==0 and ball==0:
        out+=1
    
    return strike, ball, out

def Game():  
    answerNum=getThreeNumbers()
    guessesTaken=0
    outTotal=0;

    print("Baseball game starts!")
    while True:
        print("Input 3-digit numbers")
        guessesTaken+=1
    
        inputNum=getNumbersFromUser()
        result= checkNumber(inputNum,answerNum)
    
        if result[2]==1:
            print("Out!")
            if outTotal==3:
                print("You Lose! The number is ",answerNum[0],answerNum[1],answerNum[2])
            break
        else:
            output=""
            if result[0]>0:
                output+=str(result[0])+"S"
            if result[1]>0:
                output+=str(result[1])+"B"
            print(output)
            
            if result[0]==3:
                print("You win")
                break
            
        if guessesTaken==5:
            print("You Lose! The number is ",answerNum[0],answerNum[1],answerNum[2])
            break
        
Game()