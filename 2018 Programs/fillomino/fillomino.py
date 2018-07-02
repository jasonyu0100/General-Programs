class Fillomino:
	vectors = ((1,0),(-1,0),(0,1),(0,-1))
	def __init__(self,grid):
		self.grid = grid
		self.originalNodes = self.getNodes()
		self.updateSingleMoveNodes()
		self.nodes = self.getNodes()
		self.updateValues()
		self.iterationCount = 0

	def getNodes(self):
		nodes = set()
		for r,row in enumerate(self.grid):
			for c,col in enumerate(row):
				if col > 0:
					nodes.add((r,c))
		return nodes

	def getGroupNeighbouringZeros(self,similarConnected):
		count = 0
		for r,c in similarConnected:
			for vR,vC in self.vectors:
				newR = r + vR
				newC = c + vC
				if newR < 0 or newC < 0 or newR >= len(self.grid) or newC >= len(self.grid):
					continue
				elif self.grid[newR][newC] == 0:
					count += 1
		return count

	def updateSingleMoveNodes(self):
		self.nodes = self.getNodes()
		totalUpdates = 0
		for r,c in self.nodes:
			value = self.grid[r][c]
			similarConnected = self.getSimilarConnected(r,c)
			zeros = self.getGroupNeighbouringZeros(similarConnected)
			if len(similarConnected) >= value or zeros > 1:
				continue
			count = 0
			connected = None
			for vR,vC in self.vectors:
				newR = r + vR
				newC = c + vC
				if newR < 0 or newC < 0 or newR >= len(self.grid) or newC >= len(self.grid):
					continue
				elif self.grid[newR][newC] == 0:
					count += 1
					connected = (newR,newC)
			if count == 1:
				totalUpdates += 1
				self.grid[connected[0]][connected[1]] = value
		if totalUpdates > 0:
			self.updateSingleMoveNodes()
		return totalUpdates

	def getNodeRange(self,r,c):
		found = set()
		value = self.grid[r][c]
		stack = [(r,c)]
		similarConnected = self.getSimilarConnected(r,c)
		for i in range(value - len(similarConnected)):
			newStack = []
			while len(stack) != 0:
				r,c = stack.pop()
				for vR,vC in self.vectors:
					newR = r + vR
					newC = c + vC
					if (newR,newC) in found or (newR < 0 or newC < 0 or newR >= len(self.grid) or newC >= len(self.grid)):
						continue
					elif self.grid[newR][newC] == 0:
						newStack.append((newR,newC))
						found.add((newR,newC))
			stack = newStack
		return found

	def getCoordPossibleValues(self):
		coordValues = {}
		for r,c in self.nodes:
			found = self.getNodeRange(r,c)
			for coord in found:
				if coord in coordValues:
					coordValues[coord].add(self.grid[r][c])
				else:
					coordValues[coord] = {self.grid[r][c]}
		return coordValues

	def updateValues(self):
		self.possibleValues = self.getCoordPossibleValues()
		self.sortedCoords = sorted(self.possibleValues.items(),reverse=True)
		# self.sortedCoords = sorted(self.possibleValues.items(),reverse=False)
		# self.sortedCoords = sorted(self.possibleValues.items(),key=lambda x:(x[0][0] + x[0][1]))
		self.shiftSingularCoords()
	
	def getSimilarConnected(self,r,c):
		found = {(r,c)}
		value = self.grid[r][c]
		stack = [(r,c)]
		while len(stack) != 0:
			r,c = stack.pop()
			for vR,vC in self.vectors:
				newR = r + vR
				newC = c + vC
				if (newR,newC) in found or newR < 0 or newC < 0 or newR >= len(self.grid) or newC >= len(self.grid):
					continue
				elif self.grid[newR][newC] == value:
					stack.append((newR,newC))
					found.add((newR,newC))
		return found
		
	def checkDisconnection(self):
		for node in self.nodes:
			r,c = node
			if self.checkPointDisconnection(r,c) == False:
				return False
		return True

	def checkPointDisconnection(self,r,c):
		value = self.grid[r][c]
		similarConnected = self.getSimilarConnected(r,c)
		if len(similarConnected) >= value:
			return True
		for coord in similarConnected:
			for vR,vC in self.vectors:
				newR = coord[0] + vR
				newC = coord[1] + vC
				if newR < 0 or newC < 0 or newR >= len(self.grid) or newC >= len(self.grid):
					continue
				coordVal = self.grid[newR][newC]
				if coordVal == 0:
					return True
		return False

	def solved(self):
		for r,c in self.originalNodes:
			connected = self.getSimilarConnected(r,c)
			count = len(connected)
			value = self.grid[r][c]
			if count != value:
				return False
		return True

	def shiftSingularCoords(self):
		singularCoords = []
		for pos,coordPair in enumerate(self.sortedCoords):
			coord,values = coordPair
			if len(values) == 1:
				coordPair = self.sortedCoords.pop(pos)
				singularCoords.append(coordPair)
		for coordPair in singularCoords:
			self.sortedCoords.insert(0,coordPair)

	def solve(self):
		for coord,values in self.sortedCoords:
			r,c = coord
			if self.grid[r][c] != 0:
				continue
			for value in sorted(values):
				self.iterationCount += 1
				self.grid[r][c] = value
				check = self.checkDisconnection()
				similarCount = len(self.getSimilarConnected(r,c))
				if similarCount <= self.grid[r][c] and check == True:
					self.nodes.add((r,c))
					self.updateValues()
					if self.solve() == True:
						break
					else:
						self.nodes.remove((r,c))
			else:
				self.grid[r][c] = 0
				return False
		if self.solved() == True:
			return True
		else: 
			return False

	def displayGrid(self):
		for row in self.grid:
			print(' '.join([str(col) for col in row]))
		print('\n')

def getGrid(fileName: str):
	with open('input.txt') as f:
		lines = int(f.readline())
		grid = []
		for i in range(lines):
			row = f.readline().strip().split()
			for i,value in enumerate(row):
				if value == '.':
					row[i] = 0
				elif value.isdigit():
					row[i] = int(value)
				else:
					pass
			grid.append(row)
	return grid

#Implement a way to fill out coordinates with only one place efficiently

import time
start = time.time()
grid = getGrid("input.txt")
fillomino = Fillomino(grid)
print(fillomino.solve())
fillomino.displayGrid()
print("Iteration count: "+str(fillomino.iterationCount))
end = time.time()
print(end - start)