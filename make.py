import sys
import os
import shutil

problemTypeIndex = {
    "acwing": "ACWing/",
    "luogu": "Luogu/",
    "comp": "CompRedo/",
    "uoj": "UOJ/",
    "loj": "LibreOJ/",
    "todo": "TodoList/"
}

def gitCommit(problemId):
    os.system("git add .")
    os.system("git commit -m " + str(problemId))
    os.system("git push RainbowCodes")

def check(path):
    if os.path.exists(path):
        print("Warning: Path already existed! Add anyway? [y/N]")
        arg = input()
        if arg == 'N' or arg == 'n':
            return False
    
    return True

def move(prefix, problemId):
    filePath = prefix + str(problemId) + ".cpp"
    if check(filePath):
        shutil.copy("temp.cpp", filePath)
        shutil.copy("model.cpp", "temp.cpp")
        gitCommit(problemId)

def problemCommit(problemType, problemId):
    move(problemTypeIndex[problemType], problemId)

def problemClear():
    shutil.copy ("model.cpp", "temp.cpp")

if __name__ == "__main__":
    print("Welcome to use Problem Commit Tool")

    while True:
        print(">>>", end = " ")

        inputArgs = input().split(" ")

        if len(inputArgs) == 1:
            if inputArgs[0] == "exit":
                break
            elif inputArgs[0] == "clear":
                problemClear()
        elif len(inputArgs) == 2:
            if inputArgs[0] in problemTypeIndex.keys(): 
                problemType = inputArgs[0]
                problemId = inputArgs[1]
                problemCommit(problemType, problemId)
            else:
                print("Error: Problem Type not found")
        else:
            if inputArgs[0] == "clac":
                expression = ""
                for i in inputArgs[1:]:
                    expression += str(i)

                result = eval(expression)
            
                print(result)
            else:
                print("Error: command not found")
                print("Please check that the input is correct!")