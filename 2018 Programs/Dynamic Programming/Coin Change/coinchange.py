import time

def coinChange1(coins,value):
	row = []
	for currentCost in range(0,value+1):
		combinations = []
		for coin in coins:
			if coin == currentCost:
				combinations.append([coin])
			elif coin < currentCost and row[currentCost - coin] != []:
				minRemainderCombination = row[currentCost - coin]
				combinations.append(minRemainderCombination + [coin])
			else:
				pass
		if len(combinations) == 0:
			row.append([])
		else:
			row.append(min(combinations,key=lambda x:len(x)))
	return row[value]

cache = {}
def coinChange2(coins,value):
	combinations = []
	if value == 0:
		return []
	elif value in cache:
		return cache[value]
	else:
		for coin in coins:
			if value - coin >= 0:
				subCombination = coinChange2(coins,value-coin)
				if subCombination != None:
					combination = subCombination + [coin]
					combinations.append(combination)
		if len(combinations) == 0:
			return None
	minCombination = min(combinations,key=lambda x:len(x))
	cache[sum(minCombination)] = minCombination
	return minCombination

cache2 = {}
def coinChange3(coins,value):
	combinations = [[]]
	for total,combination in cache2.items():
		combinations.append(combination)
	while len(combinations) != 0:
		combination = combinations.pop(0)
		combinationTotal = sum(combination)
		remainder = value - combinationTotal
		if combinationTotal == value: 
			return combination
		elif remainder in cache2:
			combinations.append(combination + cache2[remainder])
		else:
			for coin in coins:
				if (remainder - coin) >= 0 and (combinationTotal + coin) not in cache2:
					newCombination = combination + [coin]
					cache2[sum(newCombination)] = newCombination
					combinations.append(newCombination)
	return []

def test(coinChange):
	start = time.time()
	with open('input.txt') as f:
		coins = list(map(int,f.readline().split()))
		for line in f:
			value = int(line)
			combination = (coinChange(coins,value))
			if combination == None: combination = []
			numbers = set(combination)
			print(' '.join([':'.join(map(str,[number,combination.count(number)])) for number in numbers]))
	end = time.time()
	print(end - start)

test(coinChange1)
test(coinChange2)
test(coinChange3)

