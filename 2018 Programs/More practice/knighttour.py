size = 8

# vectors = [(r,c) for r in [2,-2] for c in [1,-1]] + [(c,r) for r in [2,-2] for c in [1,-1]]
vectors = list(reversed(((-2,1),(-1,2),(1,2),(2,1),(2,-1),(1,-2),(-1,-2),(-2,-1))))
grid = [[0] * size for i in range(size)]
def checkCoord(coord):
	r = coord[0]
	c = coord[1]
	return r >= 0 and c >= 0 and r < size and c < size

def knightTour(r,c,counter):
	grid[r][c] = counter
	if counter == (size**2):
		for row in grid:
			print(row)
		return True
	for rc,cc in vectors:
		coord = (rc+r,cc+c)
		if checkCoord(coord) == True and grid[coord[0]][coord[1]] == 0:
			if knightTour(coord[0],coord[1],counter+1) == True:
				return True
			else:
				grid[coord[0]][coord[1]] = 0
	else:
		return False

moves = (knightTour(0,0,1))
# if moves != False:
# 	for i,coord in enumerate(moves):
# 		grid[coord[0]][coord[1]] = str(i)
# 	for row in grid:
# 		print(row)