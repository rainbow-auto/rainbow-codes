import sys
import os
import shutil

if len (sys.argv) == 2:
    if sys.argv[1] == "clear":
        shutil.copy ("model.cpp", "temp.cpp")
else:
    type = sys.argv[1]
    id = sys.argv[2]

    if type == "acwing":
        shutil.copy ("temp.cpp", "ACWing/" + str(id) + ".cpp")
        shutil.copy ("model.cpp", "temp.cpp")
    elif type == "luogu":
        shutil.copy ("temp.cpp", "Luogu/" + str(id) + ".cpp")
        shutil.copy ("model.cpp", "temp.cpp")
    elif type == "comp":
        shutil.copy ("temp.cpp", "CompRedo/" + str(id) + ".cpp")
        shutil.copy ("model.cpp", "temp.cpp")
    elif type == "uoj":
        shutil.copy ("temp.cpp", "UOJ/" + str(id) + ".cpp")
        shutil.copy ("model.cpp", "temp.cpp")
    elif type == "todo":
        shutil.copy ("temp.cpp", "TodoList/" + str(id) + ".cpp")
        shutil.copy ("model.cpp", "temp.cpp")
    else:
        print ("请检查命令是否正确")

    os.system('git add .')
    os.system("git commit -m " + str(id))
    os.system('git push RainbowCodes')
    
