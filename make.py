import sys
import os
import shutil

def git(problemId):
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
        git(problemId)

def problemCommit(problemType, problemId):
    index = {
        "acwing": "ACWing/",
        "luogu": "Luogu/",
        "comp": "CompRedo/",
        "uoj": "UOJ/",
        "loj": "LibreOJ/",
        "todo": "TodoList/"
    }

    if problemType in index.keys():
        move(index[problemType], problemId)
    else:
        print("Error: We don't have this dictionary!")

def problemClear():
    shutil.copy ("model.cpp", "temp.cpp")

if __name__ == "__main__":
    if len(sys.argv) == 2:
        if sys.argv[1] == "clear":
            problemClear()
    else:
        problemType = sys.argv[1]
        problemId = sys.argv[2]
        problemCommit(problemType, problemId)