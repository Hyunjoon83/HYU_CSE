students={}
for i in range(3):
    Info=input()
    name,score=Info.split()
    students[name]=int(score)
    
print("Which student's score?")
name=str(input())

if name not in students.keys():
    print(name,"is not in the database.")
else:
    print(name,"'s score:",score)
