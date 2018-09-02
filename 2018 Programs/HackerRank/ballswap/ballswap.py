# idea is to go through containers and through unneccessary
# go through each container and swap unneccessary to containers that require it
# those containers will give either what the container needs or doesnt
# it is assumed at the end everything will be sorted out

def solve(containers,typeTotals):
    totalSwaps = 0
    for containerIndex,container in enumerate(containers):
        for typeIndex,total in enumerate(container):
            if containerIndex == typeIndex:
                pass
            elif total > 0:
                transferContainer = containers[typeIndex]
                while(total>0):
                    otherIndex = getOtherIndex(transferContainer,containerIndex,typeIndex)
                    container[typeIndex] -= 1
                    container[otherIndex] += 1
                    transferContainer[typeIndex] += 1
                    transferContainer[otherIndex] -= 1
                    totalSwaps += 1
                    total -= 1
            else:
                pass      
    return totalSwaps

def getOtherIndex(transferContainer,containerIndex,typeIndex):
    if transferContainer[containerIndex] > 0:
        otherIndex = containerIndex
    else:
        for checkIndex in transferContainer:
            if transferContainer[checkIndex] > 0 and checkIndex != typeIndex:
                otherIndex = checkIndex
                break
        else:
            pass
    return otherIndex

def checkPossible(containers,typeTotals):
    containerTotals = []
    for container in containers:
        containerTotals.append(sum(container))
    for total in typeTotals:
        for i,containerTotal in enumerate(containerTotals):
            if total == containerTotal:
                containerTotals.pop(i)
                break
    return len(containerTotals) == 0

fileIn  = open("ballswapin.txt")
fileOut = open("ballswapout.txt","w")
queries = int(fileIn.readline())
for i in range(queries):
    size = int(fileIn.readline())
    containers = []
    typeTotals = [0]*size
    for j in range(size):
        container = (list(map(int,fileIn.readline().split())))
        containers.append(container)
        for k,typeTotal in enumerate(container):
            typeTotals[k] += typeTotal
    if checkPossible(containers,typeTotals) == False:
        fileOut.write("IMPOSSIBLE\n")
    else:
        print(solve(containers,typeTotals))