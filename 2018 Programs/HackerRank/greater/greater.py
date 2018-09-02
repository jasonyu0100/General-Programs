def getGreater(string):
    string = list(string)
    currIndex = len(string) - 1
    possible = False
    while currIndex != 0:
        current = string[currIndex]
        before = string[currIndex-1]
        if ord(current) < ord(before):
            possible = False
            break
        elif ord(current) > ord(before):
            possible = True
            break
        elif ord(current) == ord(before):
            pass
        currIndex -= 1
    if possible:
        lastValue = string[-1]
        string[-1] = string[currIndex-1]
        string[currIndex-1] = lastValue

        return ''.join(string)
    else:
        return str(False)





fileIn = open('greaterin.txt','r')
fileOut = open('greaterout.txt','w')

for line in fileIn:
    value = getGreater(line)
    fileOut.write(value + '\n')
    print(value)

fileIn.close()
fileOut.close()