import random

wordlist=["apple","bound","nasty","seven","world","piano","green","woman","dream","death"]

def selectAnswer(wordlist):
    return random.choice(wordlist)

def getInputFromUser():
    while True:
        userInput=input()
        if len(userInput)!=5:
            print(userInput+" is an invalid input. Try again.")
        elif not userInput.isalpha() or not userInput.islower():
            print(userInput+" is an invalid input. Try again.")
        else:
            return userInput
        
def checkLetters(userInput,answer):
    result = ""
    for i in range(len(userInput)):
        if userInput[i]==answer[i]:
            result += "G"
        elif userInput[i] in answer:
            result += "Y"
        else:
            result += "B"
    return result
  
def playGame():
    answer=selectAnswer(wordlist)
    print("Wordle-like game starts!")
    tries=0
    while True:
        print("Input 5 letters")
        userInput=getInputFromUser()
        
        if userInput==answer:
            print("You win!")
            return
        else:
            result=checkLetters(userInput,answer)
            print(result)
            tries+=1
            if tries>=6:
                print("You lose!")
                print("The answer was:",answer)
                return
playGame()


