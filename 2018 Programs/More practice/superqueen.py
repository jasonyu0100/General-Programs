size = 8#int(input("Enter rows: "))

def getSafePositions(qr,qc,gridSize):
	safePositions = set()
	for r in range(gridSize):
		for c in range(gridSize):
			if checkSafe(r,c,qr,qc) == True:
				safePositions.add((r,c))
	return safePositions

def checkSafe(r,c,qr,qc):
	knightVectors = set(list((r,c) for r in [2,-2] for c in [1,-1]) + list((r,c) for r in [1,-1] for c in [2,-2]))
	for rc,cc in knightVectors:
		if (qr + rc) == r and (qc + cc) == c:
			return False
	if abs(qr - r) == abs(qc - c): 
		return False
	elif r == qr or qc == c:
		return False
	else:
		return True

def printSafe(safe,size):
	for r in range(size):
		string = ''
		for c in range(size):
			if (r,c) in safe:
				string += ('0')
			else:
				string += '.'
		print(string)

safe = set((r,c) for r in range(size) for c in range(size))
done = set()
combinations = set()
found = set()
def getCombinations(size,safe,queenPostions):
	if len(queenPostions) == 4:
		combinations.add(tuple(queenPostions))
		return
	if len(safe) == 0:
		return
	for r,c in safe:
		if tuple(queenPostions | {(r,c)}) in found:
			continue
		else: 
			found.add(tuple(queenPostions | {(r,c)}))
		coordSafe = getSafePositions(r,c,size)
		newSafe = coordSafe & safe
		if len(queenPostions & coordSafe) != len(queenPostions):
			continue
		else:
			getCombinations(size,newSafe,queenPostions | {(r,c)})

getCombinations(size,safe,set())
given = list(combinations)[0]
for r in range(size):
		string = ''
		for c in range(size):
			if (r,c) in given:
				string += 'X'
			else:
				string += '.'
		print(string)

print(combinations)

# printSafe(safe,size) 
# x,y = list(safe)[0]
# newSafe = getSafePositions(x,y,size)
# safe &= newSafe
# print(safe)
# printSafe(safe,size)
