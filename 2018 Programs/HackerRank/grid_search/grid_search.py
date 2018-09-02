fileIn = open("grid_search_in.txt","r")
fileOut = open("grid_search_out.txt","w")

def testGrid(grid,searchGrid):
    gridRows = len(grid)
    gridCols = len(grid[0])
    searchRows = len(searchGrid)
    searchCols = len(searchGrid[0])
    startCoord = (0,0)
    for rowChange in range(0,abs(gridRows-searchRows)):
        for colChange in range(0,abs(gridCols-searchCols)):
            currentCoord = (startCoord[0] + rowChange,startCoord[1] + colChange)
            if testCoord(grid,searchGrid,currentCoord):
                return True
    return False

def testCoord(grid,searchGrid,currentCoord):
    searchRows = len(searchGrid)
    searchCols = len(searchGrid[0])
    for coordRowChange in range(0,searchRows):
        for coordColChange in range(0,searchCols):
            value = grid[currentCoord[0]+coordRowChange][currentCoord[1]+coordColChange]
            if value != searchGrid[coordRowChange][coordColChange]:
                return False
    return True

testCases = int(fileIn.readline())
for i in range(testCases):
    rows,cols = tuple(map(int,fileIn.readline().split()))
    grid = []
    for row in range(rows):
        gridRow = list(map(int,fileIn.readline().strip()))
        grid.append(gridRow)
    searchGrid = []
    rows,cols = tuple(map(int,fileIn.readline().split()))
    for row in range(rows):
        gridRow = list(map(int,fileIn.readline().strip()))
        searchGrid.append(gridRow)
    fileOut.write(str(testGrid(grid,searchGrid))+'\n')
    


fileIn.close()
fileOut.close()