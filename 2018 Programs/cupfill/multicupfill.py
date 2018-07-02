import copy

def action(cups,goal,maxValues,actions):
	if any(map(lambda cup:cup<0,cups)):
		return False
	tupleCups = tuple(cups)
	if tupleCups not in minMoves:
		minMoves[tupleCups] = actions
	elif len(minMoves[tupleCups]) < len(actions):
		return False
	else:
		minMoves[tupleCups] = actions

	if any(map(lambda cup:cup==goal,cups)):
		possiblePaths.append(actions)
		return True

	paths = []
	for index in range(len(cups)):
		fillPath = action(fill(cups,index),goal,maxValues,actions+['Fill '+str(index)])
		emptyPath = action(empty(cups,index),goal,maxValues,actions+['Empty '+str(index)])
		paths.append(fillPath)
		paths.append(emptyPath)
	
	for index1 in range(len(cups)):
		for index2 in range(len(cups)):
			if index1 == index2:
				continue
			transferPath = action(transfer(cups,index1,index2),goal,maxValues,actions+['Transfer '+str(index1)+' -> '+str(index2)])
			paths.append(transferPath)

	return any(paths)

def fill(cups,index):
	newCups = copy.deepcopy(cups)
	newCups[index] = maxValues[index]
	return newCups

def empty(cups,index):
	newCups = copy.deepcopy(cups)
	newCups[index] = 0
	return newCups

def transfer(cups,index1,index2):
	newCups = copy.deepcopy(cups)
	newCups[index1] = cups[index1] - (maxValues[index2] - cups[index2])
	newCups[index2] = maxValues[index2]
	return newCups

maxValues = [3,7,50]
goal = 40
possiblePaths = []
minMoves = {}
valid =(action([0]*len(maxValues),goal,maxValues,[]))
if valid:
	minPath = ', '.join(min(possiblePaths,key=lambda x:len(x)))
	print(minPath)
	print(len(minMoves))
else:
	print('invalid')