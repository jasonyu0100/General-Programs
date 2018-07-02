destination = (-1,2)
start = (0,0)
moves = []


forward = [(0,1),(0,-1)]
right = [(-1,0),(1,0)]
down = [(0,-1),(0,1)]
left = [(1,0),(-1,0)]
directionVectors = [forward,right,down,left]
moves = []

def getLeastMoves(start,destination,direction):
	if start == destination:
		return
	#right = 0 and left = 1
	vectors = directionVectors[direction]
	right = vectors[0]
	left =  vectors[1]
	first = (start[0] + right[0],start[1] + right[1])
	second = (start[0] + left[0],start[1] + left[1])
	distances = [getDistance(start,destination) for start in [first,second]]
	newStart = min([first,second],key=lambda x:getDistance(x,destination))
	if newStart == first: #Right
		moves.append('right')
		direction += 1
		if direction == len(directionVectors):
			direction = 0
	elif newStart == second: #Left
		moves.append('left')
		direction -= 1
		if direction == -1:
			direction = len(directionVectors) - 1
	else:
		pass
	getLeastMoves(newStart,destination,direction)

def getDistance(start,destination):
	return ((start[0] - destination[0])**2 + (start[1] - destination[1])**2)

getLeastMoves(start,destination,0)
print(moves)
