with open('input.txt') as f:
	length = float(f.readline())
	positions = list(map(float,f.readline().strip().split()))


cache = {}
def woodCutter(positions, cost, start, end, sequence):
	if (start,end) in cache:
		return cache[(start,end)]
	allCuts = {}
	cutCost = (end - start)
	for cut in positions:
		if start < cut and cut < end:
			left,leftSequence = woodCutter(positions,cost + cutCost,start,cut, sequence + [cut])
			right,rightSequence = woodCutter(positions,cost + cutCost,cut, end, sequence + [cut])
			totalCost = left + right + cutCost
			newSequence = [cut] + leftSequence + rightSequence
			allCuts[totalCost] = newSequence
	if len(allCuts) == 0:
		return 0, []
	else:
		minCost = min(allCuts)
		minSequence = allCuts[minCost]
		cache[(start,end)] = (minCost, minSequence)
		return cache[(start,end)]

print(woodCutter(positions,0,0,length,[]))