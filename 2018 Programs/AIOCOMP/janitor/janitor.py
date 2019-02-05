import copy
inputFile = 'janitorin.txt'
outputFile = 'janitorout.txt'
fileIn = open(inputFile,'r')
fileOut = open(outputFile,'w')

def checkSolved(water,grid):
  return len(water) == len(grid) * len(grid[0])

def pour(grid,location):
  vectors = [(1,0),(-1,0),(0,1),(0,-1)]
  stack = [location]
  water = {tuple(location)}
  while len(stack) != 0:
    r,c = stack.pop()
    water.add((r,c))
    currentHeight = grid[r][c]
    for cr,cc in vectors:
      nr,nc = r+cr,c+cc
      if nr < 0 or nr >= len(grid) or nc < 0 or nc >= len(grid[0]):
        pass
      else:
        comparisonHeight = grid[nr][nc]
        if comparisonHeight <= currentHeight:
          if (nr,nc) not in stack and (nr,nc) not in water:
            stack.append((nr,nc)) #appending new locations
  return water

def getMaxHeight(grid):
  currentMax = 0
  coordinates = []
  for r,row in enumerate(grid):
    for c,col in enumerate(row):
      if col == True:
        continue
      elif col > currentMax:
        currentMax = col
        coordinates = [(r,c)]
      elif col == currentMax:
        coordinates.append((r,c))
  return coordinates

def floodRoom(grid):
  solutions = [[grid,[],set()]]
  check = True
  while check:
    newSolutions = []
    for grid,sequence,water in solutions:
      for possibleCoordinate in getMaxHeight(grid):
        newSequence=  list(sequence)+ [possibleCoordinate]
        tupleKey = tuple(sorted(newSequence))
        if tupleKey in memory:
          continue
        else:
          newWater = pour(grid,possibleCoordinate)
          water |= newWater
          newSolutions.append((grid,newSequence,water))
          memory.add(tupleKey)
    solutions = newSolutions
    for grid,sequence,water in solutions:
      if checkSolved(water,grid) == True:
        return sequence

rows,cols,replacements = map(int,fileIn.readline().split())
grid = []
for row in range(rows):
  row = list(map(int,fileIn.readline().split()))
  grid.append(row)

currentGrid= copy.deepcopy(grid)
memory = set()
solution = (floodRoom(currentGrid))
fileOut.write(str(len(solution)) + '\n')



for replacement in range(replacements):
  row,col,height = map(int,fileIn.readline().split())
  grid[row-1][col-1] = height
  currentGrid = copy.deepcopy(grid)
  memory = set()
  solution = (floodRoom(currentGrid))
  fileOut.write(str(len(solution)) + '\n')


fileIn.close()
fileOut.close()