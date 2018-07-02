import math


# costGrid = [[1,2,3],
# 			[4,8,2],
# 			[1,5,3]]
costGrid = []
with open('input.txt') as f:
	for row,line in enumerate(f):
		costGrid.append(list(map(int,line.split())))
print(costGrid)


cache = {}

def minCost(costGrid,r,c):
	if r == 0 and c == 0:
		return costGrid[r][c]
	elif r < 0 or c < 0:
		return math.inf
	else:
		cache[(r,c)] = costGrid[r][c] + min(minCost(costGrid,r-1,c-1),
									minCost(costGrid,r-1,c),
									minCost(costGrid,r,c-1))
		return cache[(r,c)]

print(minCost(costGrid,5,5))