magic = [[8, 1, 6, 3, 5, 7, 4, 9, 2], [6, 1, 8, 7, 5, 3, 2, 9, 4],
         [4, 3, 8, 9, 5, 1, 2, 7, 6], [2, 7, 6, 9, 5, 1, 4, 3, 8],
         [2, 9, 4, 7, 5, 3, 6, 1, 8], [4, 9, 2, 3, 5, 7, 8, 1, 6],
         [6, 7, 2, 1, 5, 9, 8, 3, 4], [8, 3, 4, 1, 5, 9, 6, 7, 2]]

with open("magicin.txt") as f:
    grid = []
    for line in f:
        grid += map(int,line.split())

def getDifference(currentGrid,compareGrid):
    totalDif = 0
    for i in range(len(currentGrid)):
        dif = abs(currentGrid[i] - compareGrid[i])
        totalDif += dif
    return dif
currentGrid = grid
absoluteMin = 100 
for compareGrid in magic:
    currentMin = getDifference(currentGrid,compareGrid)
    if currentMin < absoluteMin:
        absoluteMin = currentMin
with open("magicout.txt","w") as f:
    f.write(str(absoluteMin))
