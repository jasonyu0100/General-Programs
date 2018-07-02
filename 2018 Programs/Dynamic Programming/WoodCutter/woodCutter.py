with open('input.txt') as f:
	length = float(f.readline())
	positions = list(map(float,f.readline().strip().split()))

minCostCuts = {}

def woodCutter(positions,start,end,currentTotal):
	#Retrieve from cache
	if (start,end) in minCostCuts: return minCostCuts[(start,end)]

	#Current Cuts Information
	currentCuts = {}
	currentCutCost = end - start
	
	for cutPosition in positions:
		#Possible Cuts
		if start < cutPosition and cutPosition < end:
			#Left and Right Cuts
			cutLeftCost,cutLeftSequence = woodCutter(positions,start,cutPosition,currentTotal+currentCutCost)
			cutRightCost,cutRightSequence = woodCutter(positions,cutPosition,end,currentTotal+currentCutCost)
			#Totals
			currentSequenceTotal = currentCutCost + cutLeftCost + cutRightCost
			currentSequence = [cutPosition] + cutLeftSequence + cutRightSequence
			#Storing Totals
			if currentSequenceTotal not in currentCuts: currentCuts[currentSequenceTotal] = currentSequence
	
	if len(currentCuts) == 0: #No available cuts
		return 0,[]
	else: #Min cut sequence
		minimumValue = min(currentCuts)
		cutSequence = currentCuts[minimumValue]
		minCostCuts[(start,end)] = (minimumValue,cutSequence)
		return minimumValue,cutSequence

values = woodCutter(positions,0,length,0)
print(values)
