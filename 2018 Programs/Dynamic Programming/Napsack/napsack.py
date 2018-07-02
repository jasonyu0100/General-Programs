weights = {}
with open('input.txt') as f:
	for line in f:
		weight,value = map(int,line.strip().split())
		weights[weight] = value
print(weights)

def getAlternative(r,grid,currentAllocation):
	if r < 1: return 0
	else: return grid[r-1][currentAllocation]

def napsack(weights,limit):
	grid = [[0]*limit for i in range(len(weights))]
	for row,currentWeight in enumerate(sorted(weights)):
		value = weights[currentWeight]
		for col,currentAllocation in enumerate(range(limit)):
			if (currentWeight > currentAllocation):
				grid[row][col] = getAlternative(row,grid,currentAllocation)
			else:
				remainder = currentAllocation - currentWeight
				grid[row][col] = max(value + grid[row][remainder],getAlternative(row,grid,currentAllocation))
	return grid


grid = napsack(weights,5)
print(grid[-1])