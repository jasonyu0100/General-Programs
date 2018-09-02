from collections import Counter
def gridSums(grid):
    counter = Counter()
    for row in grid:
        rowTotal = sum(row)
        counter[rowTotal] += 1
    for col in range(len(grid)):
        colTotal = sum(grid[row][col] for row in range(len(grid)))
        counter[colTotal] += 1
    firstDiagonalTotal = sum(grid[num][num] for num in range(len(grid)))
    counter[firstDiagonalTotal] += 1
    secondDiagonalTotal = sum(grid[len(grid) - 1 - num][num] for num in range(len(grid)))
    counter[secondDiagonalTotal] += 1
    return counter

def getMaxCountTotal(counter):
    maxCountKeys = []
    currentMaxCount = 0
    for key in counter:
        if counter[key] > currentMaxCount:
            currentMaxCount = counter[key]
            maxCountKeys = [key]
        elif counter[key] == currentMaxCount:
            maxCountKeys.append(key)
        else:
            pass
    return min(maxCountKeys)

def completeGrid(counter,magicNumber):
    for key in counter:
        if counter[key] != magicNumber:
            return False
    return True

def updateGrid(grid,magicNumber):
    currentGridSums = (gridSums(grid))
    if completeGrid(currentGridSums,magicNumber):
        return False
    else:
        
        return 0
        
with open("magicin.txt") as f:
    grid = []
    for line in f:
        grid.append(list(map(int,line.split())))

cost = 0
currentGridSums = (gridSums(grid))
magicNumber = getMaxCountTotal(currentGridSums)
currentChangeCost = updateGrid(grid,magicNumber)
while(currentChangeCost != False):
    cost += currentChangeCost
    currentChangeCost = updateGrid(grid,magicNumber)

with open("magicout.txt","w") as f:
    f.write(str(cost))