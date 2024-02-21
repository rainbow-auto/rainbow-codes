import os
import shutil
import time

problemTypeIndex = {
    "acwing": "ACWing/",
    "luogu": "Luogu/",
    "compredo": "CompRedo/",
    "uoj": "UOJ/",
    "loj": "LibreOJ/",
    "bzoj": "BZOJ/",
    "todo": "TodoList/",
    "cf": "CodeforcesVP/"
}

class ProblemCommitTool:
    def check(self, path):
        if os.path.exists(path):
            print("Warning: Path already existed! Add anyway? [y/N]")
            arg = input()
            if arg == 'N' or arg == 'n' or arg == '':
                return False
        
        return True

    def gitSync(self, problemId):
        os.system("git add .")
        os.system("git commit -m " + str(problemId))
        os.system("git push RainbowCodes")
    
    def move(self, prefix, problemId):
        filePath = prefix + str(problemId) + ".cpp"
        if self.check(filePath):
            shutil.copy("temp.cpp", filePath)
            shutil.copy("model.cpp", "temp.cpp")
            self.gitSync(problemId)

    def commit(self, problemType, problemId):
        self.move(problemTypeIndex[problemType], problemId)

    def clear(self):
        shutil.copy("model.cpp", "temp.cpp")

class CalculateTool:
    def calc(self, args):
        expression = ""
        for i in args:
            expression += str(i)

        return eval(expression)

class ComptetionTool:
    def createProblem(self, compName, problem):
        os.system(f'code "Comp/{compName}/{problem}.cpp"')

    def commit(self, compName):
        os.system("git add Comp")
        os.system(f'git commit -m "{compName}"')
        os.system("git push RainbowCodes")

if __name__ == "__main__":
    print("Welcome to use Problem Commit Tool")

    status = "Normal"

    problemCommitter = ProblemCommitTool()
    compCommitter = ComptetionTool()
    calculator = CalculateTool()

    while True:
        print(f"({status})")
        print(">>>", end = " ")
        inputArgs = input().split(" ")
        
        command = inputArgs[0]

        if command == "exit": 
            exit ()

        if status == "Normal":
            if command == "clear": # clear the problem
                problemCommitter.clear()
            elif command in problemTypeIndex.keys(): # commit this problem
                problemCommitter.commit(inputArgs[0], inputArgs[1])
            elif command == "calc":
                print(calculator.calc(inputArgs[1:]))
            elif command == "comp":
                compName = time.strftime("%y-%m-%d", time.localtime()) + " " + inputArgs[1]
                status = compName
            else:
                print("Error: command not found")
                print("Please check that the input is correct!")
        else:
            if command == "finish":
                status = "Normal"
            elif command == "commit":
                compCommitter.commit(compName = status)
            else:
                compCommitter.createProblem(compName = status, problem = inputArgs[0])