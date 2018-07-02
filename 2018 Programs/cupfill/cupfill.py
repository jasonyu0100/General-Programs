maxA = 7
maxB = 5
goal = 2

possiblePaths = []
minMoves = {}

def action(a,b,goal,actions):
	if a < 0 or b < 0:
		return False
	if (a,b) not in minMoves:
		minMoves[(a,b)] = actions
	elif len(minMoves[(a,b)]) < len(actions):
		return False
	else:
		minMoves[(a,b)] = actions

	if a == goal or b == goal:
		possiblePaths.append(actions)
		return True

	path1 = action(maxA,b,goal,actions+['FA'])
	path2 = action(a,maxB,goal,actions+['FB'])

	path3 = action(0,b,goal,actions+['EA'])
	path4 = action(a,0,goal,actions+['EB'])

	path5 = action(a - (maxB - b),maxB,goal,actions+['AB'])
	path6 = action(maxA,b - (maxA - a),goal,actions+['BA'])
	return any([path1,path2,path3,path4,path5,path6])

print(action(0,0,goal,[]))
minPath = min(possiblePaths,key=lambda x:len(x))
print(minMoves)
print(minPath)