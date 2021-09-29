import subprocess
import os
import sys
import random
ENDL="\n"
startMessage="42 Push swap tester" + ENDL

# Usage
usage="[numbers range] [instruction cap] [pass]"
numbersRangeIe="Combination lenght as argument for your push_swap"
InstrucCapIe="Intstructions limit for each pass"
passIe="pass amount for each line of test"
usageIe="I.e: 100 1000 5000 will test 100 numbers 5000 times but will result in a KO if the instructions in a single pass are higher than 1000"
addCmdPrompt="Press enter to add another command or type 'done' to start"
#

# print start message
print(startMessage)
#

#prompt
def newPrompt(message):
	if (message):
		returnValue = raw_input(message + "> ")
	else:
		returnValue = raw_input("")
	return (returnValue)
#

#print usage
def printUsage():
	print("Usage: " + usage + ENDL)
	print("numbers range: " + numbersRangeIe + ENDL)
	print("instruction cap: " + InstrucCapIe + ENDL)
	print("pass: " + passIe + ENDL)
	print(usageIe + ENDL)
#

#

def intToStr(arr, sep):
	ret = ""
	i = 0
	if not (arr):
		return (0)
	while (i < len(arr)):
		ret += str(arr[i])
		if (sep and i != len(arr) - 1):
			ret+= sep
		i += 1
	return (ret)

def execCmd(prog, concat):
	proc=subprocess.Popen(prog + " " + concat, shell=True, stdout=subprocess.PIPE)
	output=proc.communicate()[0]
	return (output)


def summary(line, ok, op, koCountCap, koNotSorted):
	if (ok):
		print(str(line[0]) + "OK")
		return (ok)
	print("[CAP]" + "KO " + "expected: " + str(line[1]) + "frequence: " + str(koCountCap) + " / " + str(line[2]))
        if (koNotSorted != 0):
            print("[! 0 - 9] KO" + str(koNotSorted) + str(line[0]))
def print_flags(n, o):
    if (len(sys.argv) == 1):
        return (0)
    i = 1
    ok = 0
    file = open("pytest_debug", "a+")
    while (i < len(sys.argv)):
        if (sys.argv[i] == "-N"):
            file.write("Comb: " + n + ENDL)
            ok = 1
        elif (sys.argv[i] == "-O"):
            file.write("Op: " + o + ENDL)
            ok = 1
        i += 1
    if (ok):
        file.write(ENDL + ENDL)
    file.close()

def runLine(line):
	y = 0
	ok = 1
	op = -1
	koCountCap = 0
        koNotSorted = 0
	while (y < int(line[2])):
		rand = random.sample(range(0, 500), int(line[0]))
		concat = intToStr(rand, " ")
		res = execCmd("./push_swap", concat)
                ko = res.find("OK", 0, len(res))
                ko = "KO"
                if (ko != -1):
                    ko = "OK"
                print_flags(concat, res)
		print(str((len(str.split(res, ENDL)) - 1)) + " [SORT ?] " + ko)
		if ((len(str.split(res, ENDL)) - 1) > int(line[1])):
			ok = 0
			koCountCap += 1
			op = (len(str.split(res, ENDL)) - 1)
                if (ko == "KO"):
                    koNotSorted += 1
                    ok = 0
		y += 1
	summary(line, ok, op, koCountCap, koNotSorted)
		

def runTest(commands):
	print("Running test . . .")
	cmdLen = len(commands)
	i = 0
	while (i < cmdLen):
		runLine(commands[i])
		i += 1
        getTestLines()
def answerIsOk(answer):
	tmp = str.split(answer)
	if (len(tmp) != 3):
		return (bool(0))
	for elem in tmp:
		if str.isdigit(elem) == 0 or int(elem) < 0:
			return (0)
	return (1)

def getTestLines():
	commands = []
	while 1:
		newCmd = newPrompt("Enter to submit or type 'done' to run " + ENDL);
		if newCmd == "done":
			return runTest(commands)
		if (answerIsOk(newCmd)):
			commands += [str.split(newCmd)]
		else:
			print("input ignored since invalid." + ENDL + "Usage: " + usage + ENDL)

while 1:
	answer = newPrompt("1: instructions 2:start test " + ENDL)
	if (answer == "1"):
		printUsage()
	elif (answer == "2"):
		getTestLines()
	elif (answer == "exit"):
		break
print("Bye !")
