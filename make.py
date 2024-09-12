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
    "cf": "CodeforcesVP/",
    "hdu": "HDU/",
    "gym": "CodeforcesGym/",
    "csg": "CSG/",
    "boj": "BOJ/",
    "codechef": "CodeChef/"
}

ignoreFiles = ["temp.cpp", "model.cpp", "std.cpp"]

class ProblemCommitTool:
    def check(self, path):
        if os.path.exists(path):
            print("Warning: Path already existed! Add anyway? [y/N]")
            arg = input()
            if arg == 'N' or arg == 'n' or arg == '\n':
                return False
        
        return True

    def gitSync(self, problemId):
        os.system("git add .")
        os.system("git commit -m " + str(problemId))
        os.system("git push RainbowCodes")
        os.system("git push RainbowCodes-Github")
    
    def move(self, prefix, problemId, problemPath):
        filePath = prefix + str(problemId) + ".cpp"
        if self.check(filePath):
            shutil.copy(problemPath, filePath)
            os.remove(problemPath)
            self.gitSync(problemId)

    def commit(self, problemType, problemId, problemPath):
        self.move(problemTypeIndex[problemType], problemId, problemPath)

    def getProblem (self):
        files = os.listdir(".")
        for filename in files:
            file_base_name, file_ext = os.path.splitext (filename)
            if file_ext != ".cpp": 
                continue
            if filename in ignoreFiles:
                continue
            t = file_base_name.split ("_")
            problem_name = t[0] + t[1]
            return problem_name, filename
        print ("Error: cannot find the problem")
        return "",""

class ComptetionTool:
    def createComp (self, compName):
        os.system(f'mkdir "Comp/{compName}"')
        os.system(f'mkdir "Comp/{compName}/After"')
        os.system(f'code "Comp/{compName}"')

    def createProblem(self, compName, problem):
        if not os.path.exists (f"Comp/{compName}/{problem}.cpp"):
            shutil.copy("model.cpp", f"Comp/{compName}/{problem}.cpp")
        os.system(f'code "Comp/{compName}/{problem}.cpp"')

    def openCompFolder(self, compName):
        os.system(f'explorer "Comp\\{compName}"')

    def commit(self, compName):
        os.system("git add Comp")
        os.system(f'git commit -m "{compName}"')
        os.system("git push RainbowCodes")

if __name__ == "__main__":
    print("Welcome to use Competitive Programming problems archive tool")

    status = "Normal"

    problemCommitter = ProblemCommitTool()
    compCommitter = ComptetionTool()

    while True:
        print(f"({status})")
        print(">>>", end = " ")
        inputArgs = input().split(" ")
        
        command = inputArgs[0]

        if command == "exit": 
            exit ()

        if status == "Normal":
            if command in problemTypeIndex.keys(): # commit this problem
                problemId, problemPath = problemCommitter.getProblem ()
                if problemId != "": 
                    problemCommitter.commit(inputArgs[0], problemId, problemPath)
            elif command == "comp":
                compName = time.strftime("%y-%m-%d", time.localtime()) + " " + inputArgs[1]
                status = compName
                compCommitter.createComp(compName)
            elif command == "oldcomp":
                compName = "" 
                for name in inputArgs[1:]:
                    compName = compName + " " + name
                compName = compName[1:]
                status = compName
            elif command == "std":
                os.system("code std.cpp")
            elif command == "temp":
                os.system("code temp.cpp")
            else:
                print("Error: command not found")
        else:
            if command == "finish":
                status = "Normal"
            elif command == "commit":
                compCommitter.commit(compName = status)
            elif command == "open":
                compCommitter.openCompFolder(compName = status)
            else:
                compCommitter.createProblem(compName = status, problem = inputArgs[0])