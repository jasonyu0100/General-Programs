with open('input.txt') as f:
	length = float(f.readline())
	positions = list(map(float,f.readline().strip().split()))

def woodCutter(positions,start,end,currentTotal):
	grid = {}
	currentCutCost = end - start
	for cutPosition in positions:
		if start < cutPosition and cutPosition < end:
			cutLeftCost,cutLeftSequence = woodCutter(positions,start,cutPosition,currentTotal+currentCutCost)
			cutRightCost,cutRightSequence = woodCutter(positions,cutPosition,end,currentTotal+currentCutCost)
			currentTotal = currentCutCost + cutLeftCost + cutRightCost
			currentSequence = [cutPosition] + cutLeftSequence + cutRightSequence
			if currentTotal not in grid:
				grid[currentTotal] = currentSequence
	if len(grid) == 0: return 0,[]
	else: 
		minimumValue = min(grid)
		cutSequence = grid[minimumValue]
		return minimumValue,cutSequence

values = (woodCutter(positions,0,length,0))
print(values)