def getAvailablePositions(position,obstacles,size):
    availablePositions = []
    grid = [['.']*size for grid in range(size)]
    grid[position[0]-1][position[1]-1] = 'q'
    for obstacle in obstacles:
        grid[obstacle[0]-1][obstacle[1]-1] = 'o'
    directions = [(1,0),(-1,0),(0,1),(0,-1),(1,1),(1,-1),(-1,1),(-1,-1)]
    for direction in directions:
        for distance in range(1,size):
            newPosition = (position[0] + direction[0] * distance,position[1] + direction[1] * distance)
            if validCoordinate(newPosition,size):
                if grid[newPosition[0]-1][newPosition[1]-1] == 'o':
                    break
                else:
                    availablePositions.append(newPosition)
    return availablePositions

def validCoordinate(coordinate,size):
    #assumed starting from 1,1
    return coordinate[0] <= size and coordinate[0] >= 1 and coordinate[1] <= size and coordinate[1] >= 1
print(getAvailablePositions((1,1),[(5,5)],5))