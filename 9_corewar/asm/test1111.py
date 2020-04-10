import filecmp
import os
import glob
import sys
import subprocess
from pathlib import Path

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

myDir = '/Users/fgeorgin/Desktop/ppppppp/asm/champs/'
origDir = '/Users/fgeorgin/Desktop/ppppppp/asm/subject/vm_asm_example/champs/'

namesMyDir = []
myDirCor = []
namesOrigDir = []
OrigDirCor = []
counter = 0
# Get the list of all files in directory tree at given path
# listOfFiles = getListOfFiles(myDir)

# Print the files
# for elem in listOfFiles:
#     print(elem)

# print ("****************")

# Get the list of all files in directory tree at given path

# listOfFiles = list()
# for (dirpath, dirnames, filenames) in os.walk(myDir):
#     listOfFiles += [os.path.join(dirpath, file) for file in filenames]

	# for file in filenames:
		# listOfFiles += os.path.join(dirpath, file)
		# if not file.startswith(".") and file.endswith(".s"):

# Print the files    
# for file in listOfFiles:
#     subprocess.call(["./asm", file])

# print(os.listdir(path=myDir))

# for path in Path(myDir).rglob('*.s'):
#     namesMyDir.append(path.name)
	# print(path.name)
# for path in Path(origDir).rglob('*.s'):
	# os.replace(origDir, origDirNew)

for file in os.listdir(myDir):
	if file.endswith(".s") and not file.startswith("."):
		namesMyDir.append(file)

all = len(namesMyDir)

for file in os.listdir(origDir):
	if file.endswith(".s") and not file.startswith("."):
		namesOrigDir.append(file)

if len(namesMyDir) != len(namesOrigDir):
	print(f"{bcolors.FAIL}Different number of champions{bcolors.ENDC}")
	sys.exit()

for name in namesMyDir:
	subprocess.call(["./asm", "champs/" + name])
	print(name)

for name in namesOrigDir:
	subprocess.call(["../../subject/vm_asm_example/asm", "../../subject/vm_asm_example/champs/" + name])

for file in os.listdir(myDir):
	if file.endswith(".cor") and not file.startswith("."):
		myDirCor.append(file)

for name in myDirCor:
	if filecmp.cmp(myDir + name, origDir + name) == False:
		print(f"{bcolors.FAIL}{bcolors.BOLD}Error{bcolors.ENDC}	---	" + name)
	else:
		print(f"{bcolors.GREEN}Good{bcolors.ENDC}	---	" + name)
		counter += 1

print(f"{bcolors.HEADER}Correct: {bcolors.ENDC}" + str(counter) + " of " + str(all))