
import operator
with open('input.txt') as f:
	cutSizes = map(int,f.readline().split())
	cutValues = map(int,f.readline().split())
	priceMap = dict(zip(cutSizes,cutValues))
	maxCutSize = max(priceMap)
	print(priceMap)

sequenceTotals = {}
def getMaxValue(priceMap,currentCutSize,currentValue,cutHistory):
	values = []
	for cutSize,cutValue in priceMap.items():
		if (currentCutSize - cutSize) >= 0:
			values.append(getMaxValue(priceMap,currentCutSize - cutSize,currentValue + cutValue,cutHistory+[cutSize]))
		else:
			values.append(currentValue)
			sequenceTotals[currentValue] = cutHistory
	return max(values)


maxValue = (getMaxValue(priceMap,maxCutSize,0,[]))
print(maxValue,sequenceTotals[maxValue])